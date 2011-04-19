/*  This file is part of the Vc library.

    Copyright (C) 2011 Matthias Kretz <kretz@kde.org>

    Vc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    Vc is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Vc.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef VC_AVX_STORAGE_H
#define VC_AVX_STORAGE_H

#include "macros.h"

namespace Vc
{
namespace AVX
{

template<typename VectorType1, typename VectorType2, typename EntryType>
class VectorMemoryUnion
{
    VC_STATIC_ASSERT_NC(sizeof(VectorType1) >= sizeof(VectorType2), VectorType1_must_be_larger_than_VectorType2);
    public:
        typedef EntryType AliasingEntryType MAY_ALIAS;
        typedef VectorType2 AliasingVectorType MAY_ALIAS;
        inline VectorMemoryUnion() {}
#ifdef __INTEL_COMPILER
        inline VectorMemoryUnion(VectorType1 y) { data.y = y; }
        inline VectorMemoryUnion &operator=(VectorType1 y) {
            data.y = y; return *this;
        }

        VectorType1 &v() { return data.v; }
        const VectorType1 &v() const { return data.v; }

        VectorType2 &x(int index) { return data.x[index]; }
        VectorType2 x(int index) const { return data.x[index]; }

        EntryType &m(int index) { return data.m[index]; }
        EntryType m(int index) const { return data.m[index]; }

    private:
        union {
            VectorType1 y; // ymm
            VectorType2 x[sizeof(VectorType1)/sizeof(VectorType2)]; // xmm
            EntryType m[sizeof(VectorType1)/sizeof(EntryType)];
        } data;
#else
        inline VectorMemoryUnion(VectorType1 y) : data(y) {}
        inline VectorMemoryUnion &operator=(VectorType1 y) {
            data = y; return *this;
        }

        VectorType1 &v() { return data; }
        const VectorType1 &v() const { return data; }

        AliasingVectorType &x(int index) {
            return reinterpret_cast<AliasingVectorType *>(&data)[index];
        }

        VectorType2 x(int index) const {
            return reinterpret_cast<const AliasingVectorType *>(&data)[index];
        }

        AliasingEntryType &m(int index) {
            return reinterpret_cast<AliasingEntryType *>(&data)[index];
        }

        EntryType m(int index) const {
            return reinterpret_cast<const AliasingEntryType *>(&data)[index];
        }

    private:
        VectorType1 data;
#endif
};
} // namespace AVX
} // namespace Vc

#include "undomacros.h"

#endif // VC_AVX_STORAGE_H
