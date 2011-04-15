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

#ifndef VC_AVX_VECTORBASE_TCC
#define VC_AVX_VECTORBASE_TCC

#include "macros.h"

namespace Vc
{
namespace AVX
{

#ifdef VC_IMPL_XOP
template<> inline Vector<int> &VectorBase<int>::operator<<=(const VectorBase<int> &x)
{
    d.v() = concat(_mm_shl_epi32(lo128(d.v()), lo128(x.d.v())),
            _mm_shl_epi32(hi128(d.v()), hi128(x.d.v())));
    return *static_cast<Vector<int> *>(this);
}
template<> inline Vector<int>  VectorBase<int>::operator<<(const VectorBase<int> &x) const
{
    return Vector<int>(concat(_mm_shl_epi32(lo128(d.v()), lo128(x.d.v())),
                _mm_shl_epi32(hi128(d.v()), hi128(x.d.v()))));
}
template<> inline Vector<unsigned int> &VectorBase<unsigned int>::operator<<=(const VectorBase<unsigned int> &x)
{
    d.v() = concat(_mm_shl_epi32(lo128(d.v()), lo128(x.d.v())),
            _mm_shl_epi32(hi128(d.v()), hi128(x.d.v())));
    return *static_cast<Vector<unsigned int> *>(this);
}
template<> inline Vector<unsigned int>  VectorBase<unsigned int>::operator<<(const VectorBase<unsigned int> &x) const
{
    return Vector<unsigned int>(concat(_mm_shl_epi32(lo128(d.v()), lo128(x.d.v())),
                _mm_shl_epi32(hi128(d.v()), hi128(x.d.v()))));
}
template<> inline Vector<short> &VectorBase<short>::operator<<=(const VectorBase<short> &x)
{
    d.v() = _mm_shl_epi16(d.v(), x.d.v());
    return *static_cast<Vector<short> *>(this);
}
template<> inline Vector<short>  VectorBase<short>::operator<<(const VectorBase<short> &x) const
{
    return Vector<short>(_mm_shl_epi16(d.v(), x.d.v()));
}
template<> inline Vector<unsigned short> &VectorBase<unsigned short>::operator<<=(const VectorBase<unsigned short> &x)
{
    d.v() = _mm_shl_epi16(d.v(), x.d.v());
    return *static_cast<Vector<unsigned short> *>(this);
}
template<> inline Vector<unsigned short>  VectorBase<unsigned short>::operator<<(const VectorBase<unsigned short> &x) const
{
    return Vector<unsigned short>(_mm_shl_epi16(d.v(), x.d.v()));
}
template<> inline Vector<int> &VectorBase<int>::operator>>=(const VectorBase<int> &x)
{
    d.v() = concat(_mm_shl_epi32(lo128(d.v()), _mm_sign_epi32(lo128(x.d.v()), _mm_setallone_si128())),
            _mm_shl_epi32(hi128(d.v()), _mm_sign_epi32(hi128(x.d.v()), _mm_setallone_si128())));
    return *static_cast<Vector<int> *>(this);
}
template<> inline Vector<int>  VectorBase<int>::operator>>(const VectorBase<int> &x) const
{
    return Vector<int>(concat(_mm_shl_epi32(lo128(d.v()), _mm_sign_epi32(lo128(x.d.v()), _mm_setallone_si128())),
            _mm_shl_epi32(hi128(d.v()), _mm_sign_epi32(hi128(x.d.v()), _mm_setallone_si128()))));
}
template<> inline Vector<unsigned int> &VectorBase<unsigned int>::operator>>=(const VectorBase<unsigned int> &x)
{
    d.v() = concat(_mm_shl_epi32(lo128(d.v()), _mm_sign_epi32(lo128(x.d.v()), _mm_setallone_si128())),
            _mm_shl_epi32(hi128(d.v()), _mm_sign_epi32(hi128(x.d.v()), _mm_setallone_si128())));
    return *static_cast<Vector<unsigned int> *>(this);
}
template<> inline Vector<unsigned int>  VectorBase<unsigned int>::operator>>(const VectorBase<unsigned int> &x) const
{
    return Vector<unsigned int>(concat(_mm_shl_epi32(lo128(d.v()), _mm_sign_epi32(lo128(x.d.v()), _mm_setallone_si128())),
            _mm_shl_epi32(hi128(d.v()), _mm_sign_epi32(hi128(x.d.v()), _mm_setallone_si128()))));
}
template<> inline Vector<short> &VectorBase<short>::operator>>=(const VectorBase<short> &x)
{
    d.v() = _mm_shl_epi16(d.v(), _mm_sign_epi16(x.d.v(), _mm_setallone_si128()));
    return *static_cast<Vector<short> *>(this);
}
template<> inline Vector<short>  VectorBase<short>::operator>>(const VectorBase<short> &x) const
{
    return Vector<short>(_mm_shl_epi16(d.v(), _mm_sign_epi16(x.d.v(), _mm_setallone_si128())));
}
template<> inline Vector<unsigned short> &VectorBase<unsigned short>::operator>>=(const VectorBase<unsigned short> &x)
{
    d.v() = _mm_shl_epi16(d.v(), _mm_sign_epi16(x.d.v(), _mm_setallone_si128()));
    return *static_cast<Vector<unsigned short> *>(this);
}
template<> inline Vector<unsigned short>  VectorBase<unsigned short>::operator>>(const VectorBase<unsigned short> &x) const
{
    return Vector<unsigned short>(_mm_shl_epi16(d.v(), _mm_sign_epi16(x.d.v(), _mm_setallone_si128())));
}
#else
#define OP_IMPL(T, symbol) \
template<> inline Vector<T> &VectorBase<T>::operator symbol##=(const VectorBase<T> &x) \
{ \
    for_all_vector_entries(i, \
            d.m(i) symbol##= x.d.m(i); \
            ); \
    return *static_cast<Vector<T> *>(this); \
} \
template<> inline Vector<T>  VectorBase<T>::operator symbol(const VectorBase<T> &x) const \
{ \
    Vector<T> r; \
    for_all_vector_entries(i, \
            r.d.m(i) = d.m(i) symbol x.d.m(i); \
            ); \
    return r; \
}
OP_IMPL(int, <<)
OP_IMPL(int, >>)
OP_IMPL(unsigned int, <<)
OP_IMPL(unsigned int, >>)
OP_IMPL(short, <<)
OP_IMPL(short, >>)
OP_IMPL(unsigned short, <<)
OP_IMPL(unsigned short, >>)
#undef OP_IMPL
#endif

#define OP_IMPL(T, PREFIX, SUFFIX) \
template<> inline Vector<T> & INTRINSIC CONST VectorBase<T>::operator<<=(int x) \
{ \
    d.v() = CAT3(PREFIX, _slli_epi, SUFFIX)(d.v(), x); \
    return *static_cast<Vector<T> *>(this); \
} \
template<> inline Vector<T> & INTRINSIC CONST VectorBase<T>::operator>>=(int x) \
{ \
    d.v() = CAT3(PREFIX, _srli_epi, SUFFIX)(d.v(), x); \
    return *static_cast<Vector<T> *>(this); \
} \
template<> inline Vector<T> INTRINSIC CONST VectorBase<T>::operator<<(int x) const \
{ \
    return CAT3(PREFIX, _slli_epi, SUFFIX)(d.v(), x); \
} \
template<> inline Vector<T> INTRINSIC CONST VectorBase<T>::operator>>(int x) const \
{ \
    return CAT3(PREFIX, _srli_epi, SUFFIX)(d.v(), x); \
}
OP_IMPL(int, _mm256, 32)
OP_IMPL(unsigned int, _mm256, 32)
OP_IMPL(short, _mm, 16)
OP_IMPL(unsigned short, _mm, 16)
#undef OP_IMPL

} // namespace AVX
} // namespace Vc

#include "undomacros.h"

#endif // VC_AVX_VECTORBASE_TCC
