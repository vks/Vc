/*
    Copyright (C) 2010 Matthias Kretz <kretz@kde.org>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License, or (at your option) version 3.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.

*/

#include <Vc/Vc>
#include "benchmark.h"
#include <sys/mman.h>
#include <fstream>

using namespace Vc;

static size_t largestMemorySize()
{
    using namespace std;
    fstream meminfo("/proc/meminfo", fstream::in);
    string tmp;
    size_t totalMem, freeMem;
    meminfo >> tmp >> totalMem >> tmp >> tmp >> freeMem;
    meminfo.close();
    return freeMem * 1024;
}

double blackHole = 0.;

static const size_t GB = 1024ull * 1024ull * 1024ull;
static const size_t step = GB / sizeof(double_v);
typedef Memory<double_v> MemT;

struct WorkItem
{
    MemT &__restrict__ m;
    Benchmark &__restrict__ timer;
    const size_t offset;
    const size_t size;
};

void testBzero(WorkItem work)
{
    work.timer.Start();
    bzero(work.m + work.offset * double_v::Size, work.size * sizeof(double_v));
    work.timer.Stop();
}

void testAddOne(WorkItem work)
{
    const double_v one = 1.;

    double *__restrict__ m = work.m.entries() + work.offset * double_v::Size;

    work.timer.Start();
    for (size_t i = 0; i < work.size; i += 4) {
        (double_v(m + 0) + one).store(m + 0);
        (double_v(m + 2) + one).store(m + 2);
        (double_v(m + 4) + one).store(m + 4);
        (double_v(m + 6) + one).store(m + 6);
        m += 8;
    }
    work.timer.Stop();
}

void testAddOnePrefetch(WorkItem work)
{
    const double_v one = 1.;

    double *__restrict__ m = work.m.entries() + work.offset * double_v::Size;

    work.timer.Start();
    for (size_t i = 0; i < work.size; i += 4) {
        Vc::prefetchForModify(m + 1024);
        (double_v(m + 0) + one).store(m + 0);
        (double_v(m + 2) + one).store(m + 2);
        (double_v(m + 4) + one).store(m + 4);
        (double_v(m + 6) + one).store(m + 6);
        m += 8;
    }
    work.timer.Stop();
}

void testRead(WorkItem work)
{
    double *__restrict__ m = work.m.entries() + work.offset * double_v::Size;
    work.timer.Start();
    for (size_t i = 0; i < work.size; i += 4) {
        const double_v v0(m + 0);
        const double_v v1(m + 2);
        const double_v v2(m + 4);
        const double_v v3(m + 6);
        asm("" :: "x"(v0.data()), "x"(v1.data()), "x"(v2.data()), "x"(v3.data()));
        m += 8;
    }
    work.timer.Stop();
}

void testReadPrefetch(WorkItem work)
{
    double *__restrict__ m = work.m.entries() + work.offset * double_v::Size;
    work.timer.Start();
    for (size_t i = 0; i < work.size; i += 4) {
        Vc::prefetchForOneRead(m + 1024);
        const double_v v0(m + 0);
        const double_v v1(m + 2);
        const double_v v2(m + 4);
        const double_v v3(m + 6);
        asm("" :: "x"(v0.data()), "x"(v1.data()), "x"(v2.data()), "x"(v3.data()));
        m += 8;
    }
    work.timer.Stop();
}

template<typename T>
struct convertStringTo
{
    explicit convertStringTo(const std::string &s);
    operator T() { return m_data; }
    T m_data;
};

template<> convertStringTo<int>::convertStringTo(const std::string &s) : m_data(atoi(s.c_str())) {}
template<> convertStringTo<unsigned int>::convertStringTo(const std::string &s) : m_data(atoi(s.c_str())) {}
template<> convertStringTo<long>::convertStringTo(const std::string &s) : m_data(atol(s.c_str())) {}
template<> convertStringTo<unsigned long>::convertStringTo(const std::string &s) : m_data(atol(s.c_str())) {}
template<> convertStringTo<long long>::convertStringTo(const std::string &s) : m_data(atoll(s.c_str())) {}
template<> convertStringTo<unsigned long long>::convertStringTo(const std::string &s) : m_data(atoll(s.c_str())) {}
template<> convertStringTo<std::string>::convertStringTo(const std::string &s) : m_data(s) {}

template<typename T>
static T valueForArgument(const char *name, T defaultValue)
{
    ArgumentVector::iterator it = std::find(g_arguments.begin(), g_arguments.end(), name);
    if (it != g_arguments.end()) {
        ++it;
        if (it != g_arguments.end()) {
            return convertStringTo<T>(*it);
        }
    }
    return defaultValue;
}

static void executeTest(const char *name, MemT &mem, void (*testFun)(WorkItem))
{
    static std::string only = valueForArgument("--only", std::string());
    if (!only.empty() && only != name) {
        return;
    }
    for (size_t offset = 0; offset <= mem.vectorsCount() - step; offset += step) {
        std::stringstream ss;
        ss << name << ": " << offset * sizeof(double_v) / GB << " - "
            << (offset + step) * sizeof(double_v) / GB;
        Benchmark timer(ss.str().c_str(), step * 16, "Byte");
        WorkItem item = { mem, timer, offset, step };
        for (int rep = 0; rep < 2; ++rep) {
            testFun(item);
        }
        timer.Print();
    }
}

int bmain()
{
    const size_t maxMemorySize = largestMemorySize() / GB;
    const size_t memorySize = valueForArgument("--size", maxMemorySize);
    if (memorySize < 1) {
        std::cerr << "Need at least 1GB." << std::endl;
        return 1;
    }
    if (memorySize > maxMemorySize) {
        std::cerr << "Not enough memory available. Expect crashes/OOM kills." << std::endl;
    }
    Memory<double_v> mem(memorySize * GB / sizeof(double));
    mlockall(MCL_CURRENT);

    cpu_set_t cpumask;
    sched_getaffinity(0, sizeof(cpu_set_t), &cpumask);
    int cpucount = 1;
    while (CPU_ISSET(cpucount, &cpumask)) {
        ++cpucount;
    }
    Benchmark::addColumn("CPU_ID");
    for (int cpuid = valueForArgument("--firstCpu", 1); cpuid < cpucount; cpuid += valueForArgument("--cpuStep", 6)) {
        if (cpucount > 1) {
            std::ostringstream str;
            str << cpuid;
            Benchmark::setColumnData("CPU_ID", str.str());
        }
        CPU_ZERO(&cpumask);
        CPU_SET(cpuid, &cpumask);
        sched_setaffinity(0, sizeof(cpu_set_t), &cpumask);
        executeTest("bzero", mem, &testBzero);
        executeTest("read",  mem, &testRead);
        executeTest("read w/ prefetch", mem, &testReadPrefetch);
        executeTest("add 1", mem, &testAddOne);
        executeTest("add 1 w/ prefetch", mem, &testAddOnePrefetch);
        Benchmark::finalize();
    }
    return 0;
}
