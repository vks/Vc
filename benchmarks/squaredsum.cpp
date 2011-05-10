/*
    Copyright (C) 2011 Matthias Kretz <kretz@kde.org>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "benchmark.h"
#include <x86intrin.h>

enum {
    Repetitions = 100000
};

#define MULMULADD(type) \
asm volatile( \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vmulp"type" %[a],%[a],%[b2]\n" \
        "vaddp"type" %[a2],%[b2],%[a]\n" \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vmulp"type" %[a],%[a],%[b2]\n" \
        "vaddp"type" %[a2],%[b2],%[a]\n" \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vmulp"type" %[a],%[a],%[b2]\n" \
        "vaddp"type" %[a2],%[b2],%[a]\n" \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vmulp"type" %[a],%[a],%[b2]\n" \
        "vaddp"type" %[a2],%[b2],%[a]\n" \
        : [a] "+x" (a), [a2]"=x"(a2), [b2]"=x"(b2) \
        )
#define MULFMA(type) \
asm volatile( \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vfmaddp"type" %[a2],%[a],%[a],%[a]\n" \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vfmaddp"type" %[a2],%[a],%[a],%[a]\n" \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vfmaddp"type" %[a2],%[a],%[a],%[a]\n" \
        "vmulp"type" %[a],%[a],%[a2]\n" \
        "vfmaddp"type" %[a2],%[a],%[a],%[a]\n" \
        : [a] "+x" (a), [a2]"=x"(a2) \
        )

int bmain()
{
    Benchmark::addColumn("datatype");

    Benchmark::setColumnData("datatype", "__m128");
    {
        __m128 a = _mm_set1_ps(1.0f);
        __m128 a2 = _mm_set1_ps(1.0f);
        __m128 b2 = _mm_set1_ps(1.0f);

        benchmark_loop(Benchmark("mul-mul-add", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULMULADD("s");
            }
        }

        benchmark_loop(Benchmark("mul-fma", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULFMA("s");
            }
        }
    }

    Benchmark::setColumnData("datatype", "__m256");
    {
        __m256 a = _mm256_set1_ps(1.0f);
        __m256 a2 = _mm256_set1_ps(1.0f);
        __m256 b2 = _mm256_set1_ps(1.0f);

        benchmark_loop(Benchmark("mul-mul-add", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULMULADD("s");
            }
        }

        benchmark_loop(Benchmark("mul-fma", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULFMA("s");
            }
        }
    }

    Benchmark::setColumnData("datatype", "__m128d");
    {
        __m128d a = _mm_set1_pd(1.0f);
        __m128d a2 = _mm_set1_pd(1.0f);
        __m128d b2 = _mm_set1_pd(1.0f);

        benchmark_loop(Benchmark("mul-mul-add", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULMULADD("d");
            }
        }

        benchmark_loop(Benchmark("mul-fma", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULFMA("d");
            }
        }
    }

    Benchmark::setColumnData("datatype", "__m256d");
    {
        __m256d a = _mm256_set1_pd(1.0f);
        __m256d a2 = _mm256_set1_pd(1.0f);
        __m256d b2 = _mm256_set1_pd(1.0f);

        benchmark_loop(Benchmark("mul-mul-add", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULMULADD("d");
            }
        }

        benchmark_loop(Benchmark("mul-fma", 4 * Repetitions, "Loop")) {
            for (int i = 0; i < Repetitions; ++i) {
                MULFMA("d");
            }
        }
    }

    return 0;
}
