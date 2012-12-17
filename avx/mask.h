/*  This file is part of the Vc library.

    Copyright (C) 2009-2012 Matthias Kretz <kretz@kde.org>

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

#ifndef VC_AVX_MASK_H
#define VC_AVX_MASK_H

#include "intrinsics.h"
#include "../common/bitscanintrinsics.h"

namespace Vc
{
namespace AVX
{

template<unsigned int VectorSize> class Mask<VectorSize, 32u>
{
    friend class Mask<4u, 32u>; // double_v
    friend class Mask<8u, 32u>; // float_v, (u)int_v
    friend class Mask<8u, 16u>; // (u)short_v
    friend class Mask<16u, 16u>; // (u)char_v
    public:
        FREE_STORE_OPERATORS_ALIGNED(32)

        // abstracts the way Masks are passed to functions, it can easily be changed to const ref here
#if defined VC_MSVC && defined _WIN32
        typedef const Mask<VectorSize, 32u> &AsArg;
#else
        typedef Mask<VectorSize, 32u> AsArg;
#endif

        inline Mask() {}
        inline Mask(const __m256  &x) : k(x) {}
        inline Mask(const __m256d &x) : k(_castpd_ps(x)) {}
        inline Mask(const __m256i &x) : k(_castsi256_ps(x)) {}
        inline explicit Mask(VectorSpecialInitializerZero::ZEnum) : k(_setzero_ps()) {}
        inline explicit Mask(VectorSpecialInitializerOne::OEnum) : k(_setallone_ps()) {}
        inline explicit Mask(bool b) : k(b ? _setallone_ps() : _setzero_ps()) {}
        inline Mask(const Mask &rhs) : k(rhs.k) {}
        inline Mask(const Mask<VectorSize, 16u> &rhs) : k(avx_cast<__m256>(concat(
                        _mm_unpacklo_epi16(rhs.dataI(), rhs.dataI()),
                        _mm_unpackhi_epi16(rhs.dataI(), rhs.dataI())))) {}
        inline Mask(const Mask<VectorSize * 2, 32u> &m);
        inline Mask(const Mask<VectorSize / 2, 32u> &m);

        inline bool operator==(const Mask &rhs) const { return 0 != _testc_ps(k, rhs.k); }
        inline bool operator!=(const Mask &rhs) const { return 0 == _testc_ps(k, rhs.k); }

        inline Mask operator&&(const Mask &rhs) const { return _and_ps(k, rhs.k); }
        inline Mask operator& (const Mask &rhs) const { return _and_ps(k, rhs.k); }
        inline Mask operator||(const Mask &rhs) const { return _or_ps (k, rhs.k); }
        inline Mask operator| (const Mask &rhs) const { return _or_ps (k, rhs.k); }
        inline Mask operator^ (const Mask &rhs) const { return _xor_ps(k, rhs.k); }
        inline Mask operator!() const { return _andnot_ps(data(), _setallone_ps()); }

        inline Mask &operator&=(const Mask &rhs) { k = _and_ps(k, rhs.k); return *this; }
        inline Mask &operator|=(const Mask &rhs) { k = _or_ps (k, rhs.k); return *this; }
        inline Mask &operator^=(const Mask &rhs) { k = _xor_ps(k, rhs.k); return *this; }

        // no need for expression template optimizations because cmp(n)eq for floats are not bitwise
        // compares
        inline bool isFull () const { return 0 != _testc_ps(k, _setallone_ps()); }
        inline bool isEmpty() const { return 0 != _testz_ps(k, k); }
        inline bool isMix  () const { return 0 != _testnzc_ps(k, _setallone_ps()); }

#ifndef VC_NO_AUTOMATIC_BOOL_FROM_MASK
        inline operator bool() const { return isFull(); }
#endif

        inline int Vc_CONST_L shiftMask() const Vc_CONST_R;
        int Vc_CONST_L toInt() const Vc_CONST_R;

        inline _M256  data () const { return k; }
        inline _M256I dataI() const { return _castps_si256(k); }
        inline _M256D dataD() const { return _castps_pd(k); }

        bool operator[](int index) const;

        int count() const;
        int firstOne() const;

    private:
        _M256 k;
};

template<unsigned int VectorSize> class Mask<VectorSize, 16u>
{
    friend class Mask<4u, 32u>; // double_v
    friend class Mask<8u, 32u>; // float_v, (u)int_v
    friend class Mask<8u, 16u>; // (u)short_v
    friend class Mask<16u, 16u>; // (u)char_v
    public:
        FREE_STORE_OPERATORS_ALIGNED(16)

        // abstracts the way Masks are passed to functions, it can easily be changed to const ref here
#if defined VC_MSVC && defined _WIN32
        typedef const Mask<VectorSize, 16u> &AsArg;
#else
        typedef Mask<VectorSize, 16u> AsArg;
#endif

        inline Mask() {}
        inline Mask(const __m128  &x) : k(x) {}
        inline Mask(const __m128d &x) : k(_mm_castpd_ps(x)) {}
        inline Mask(const __m128i &x) : k(_mm_castsi128_ps(x)) {}
        inline explicit Mask(VectorSpecialInitializerZero::ZEnum) : k(_mm_setzero_ps()) {}
        inline explicit Mask(VectorSpecialInitializerOne::OEnum) : k(_mm_setallone_ps()) {}
        inline explicit Mask(bool b) : k(b ? _mm_setallone_ps() : _mm_setzero_ps()) {}
        inline Mask(const Mask &rhs) : k(rhs.k) {}
        inline Mask(const Mask<VectorSize, 32u> &rhs) : k(avx_cast<__m128>(
                _mm_packs_epi32(avx_cast<__m128i>(rhs.data()), _extractf128_si256(rhs.dataI(), 1)))) {}
        inline Mask(const Mask<VectorSize / 2, 16u> *a) : k(avx_cast<__m128>(
                _mm_packs_epi16(a[0].dataI(), a[1].dataI()))) {}

        inline bool operator==(const Mask &rhs) const { return 0 != _mm_testc_si128(dataI(), rhs.dataI()); }
        inline bool operator!=(const Mask &rhs) const { return 0 == _mm_testc_si128(dataI(), rhs.dataI()); }

        inline Mask operator&&(const Mask &rhs) const { return _mm_and_ps(k, rhs.k); }
        inline Mask operator& (const Mask &rhs) const { return _mm_and_ps(k, rhs.k); }
        inline Mask operator||(const Mask &rhs) const { return _mm_or_ps (k, rhs.k); }
        inline Mask operator| (const Mask &rhs) const { return _mm_or_ps (k, rhs.k); }
        inline Mask operator^ (const Mask &rhs) const { return _mm_xor_ps(k, rhs.k); }
        inline Mask operator!() const { return _mm_andnot_ps(data(), _mm_setallone_ps()); }

        inline Mask &operator&=(const Mask &rhs) { k = _mm_and_ps(k, rhs.k); return *this; }
        inline Mask &operator|=(const Mask &rhs) { k = _mm_or_ps (k, rhs.k); return *this; }
        inline Mask &operator^=(const Mask &rhs) { k = _mm_xor_ps(k, rhs.k); return *this; }

        // TODO: use expression templates to optimize (v1 == v2).isFull() and friends
        inline bool isFull () const { return 0 != _mm_testc_si128(dataI(), _mm_setallone_si128()); }
        inline bool isEmpty() const { return 0 != _mm_testz_si128(dataI(), dataI()); }
        inline bool isMix  () const { return 0 != _mm_testnzc_si128(dataI(), _mm_setallone_si128()); }

#ifndef VC_NO_AUTOMATIC_BOOL_FROM_MASK
        inline operator bool() const { return isFull(); }
#endif

        inline int Vc_CONST_L shiftMask() const Vc_CONST_R;
        int Vc_CONST_L toInt() const Vc_CONST_R;

        inline __m128  data () const { return k; }
        inline __m128i dataI() const { return avx_cast<__m128i>(k); }
        inline __m128d dataD() const { return avx_cast<__m128d>(k); }

        bool operator[](int index) const;

        int count() const;
        int firstOne() const;

    private:
        __m128 k;
};

struct ForeachHelper
{
    size_t mask;
    bool brk;
    bool outerBreak;
    inline ForeachHelper(size_t _mask) : mask(_mask), brk(false), outerBreak(false) {}
    inline bool outer() const { return mask != 0 && !outerBreak; }
    inline bool inner() { return (brk = !brk); }
    inline void noBreak() { outerBreak = false; }
    inline size_t next() {
        outerBreak = true;
#ifdef VC_GNU_ASM
        const size_t bit = __builtin_ctzl(mask);
        __asm__("btr %1,%0" : "+r"(mask) : "r"(bit));
#else
#ifdef VC_MSVC
#pragma warning(suppress : 4267) // conversion from 'size_t' to 'unsigned long', possible loss of data
#endif
        const size_t bit = _bit_scan_forward(mask);
        mask &= ~(1 << bit);
#endif
        return bit;
    }
};

#define Vc_foreach_bit(_it_, _mask_) \
    for (Vc::AVX::ForeachHelper _Vc_foreach_bit_helper((_mask_).toInt()); _Vc_foreach_bit_helper.outer(); ) \
        for (_it_ = _Vc_foreach_bit_helper.next(); _Vc_foreach_bit_helper.inner(); _Vc_foreach_bit_helper.noBreak())

} // namespace AVX
} // namespace Vc

#include "mask.tcc"

#endif // VC_AVX_MASK_H
