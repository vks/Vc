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

#ifndef AVX_VECTORHELPER_H
#define AVX_VECTORHELPER_H

#include <limits>
#include "types.h"
#include "intrinsics.h"
#include "casts.h"

namespace Vc
{
namespace AVX
{
#define OP0(name, code) static inline VectorType name() { return code; }
#define OP1(name, code) static inline VectorType name(const VectorType a) { return code; }
#define OP2(name, code) static inline VectorType name(const VectorType a, const VectorType b) { return code; }
#define OP3(name, code) static inline VectorType name(const VectorType a, const VectorType b, const VectorType c) { return code; }

        template<> struct VectorHelper<_M256>
        {
            typedef _M256 VectorType;
            template<typename A> static VectorType load(const float *x, A) Vc_PURE;
            static void store(float *mem, const VectorType x, AlignedFlag);
            static void store(float *mem, const VectorType x, UnalignedFlag);
            static void store(float *mem, const VectorType x, StreamingAndAlignedFlag);
            static void store(float *mem, const VectorType x, StreamingAndUnalignedFlag);
            static void store(float *mem, const VectorType x, const VectorType m, AlignedFlag);
            static void store(float *mem, const VectorType x, const VectorType m, UnalignedFlag);
            static void store(float *mem, const VectorType x, const VectorType m, StreamingAndAlignedFlag);
            static void store(float *mem, const VectorType x, const VectorType m, StreamingAndUnalignedFlag);

            static VectorType cdab(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(2, 3, 0, 1)); }
            static VectorType badc(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(1, 0, 3, 2)); }
            static VectorType aaaa(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(0, 0, 0, 0)); }
            static VectorType bbbb(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(1, 1, 1, 1)); }
            static VectorType cccc(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(2, 2, 2, 2)); }
            static VectorType dddd(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(3, 3, 3, 3)); }
            static VectorType dacb(VectorType x) { return _permute_ps(x, _MM_SHUFFLE(3, 0, 2, 1)); }

            OP0(allone, _setallone_ps())
            OP0(zero, _setzero_ps())
            OP2(or_, _or_ps(a, b))
            OP2(xor_, _xor_ps(a, b))
            OP2(and_, _and_ps(a, b))
            OP2(andnot_, _andnot_ps(a, b))
            OP3(blend, _blendv_ps(a, b, c))
        };

        template<> struct VectorHelper<_M256D>
        {
            typedef _M256D VectorType;
            template<typename A> static VectorType load(const double *x, A) Vc_PURE;
            static void store(double *mem, const VectorType x, AlignedFlag);
            static void store(double *mem, const VectorType x, UnalignedFlag);
            static void store(double *mem, const VectorType x, StreamingAndAlignedFlag);
            static void store(double *mem, const VectorType x, StreamingAndUnalignedFlag);
            static void store(double *mem, const VectorType x, const VectorType m, AlignedFlag);
            static void store(double *mem, const VectorType x, const VectorType m, UnalignedFlag);
            static void store(double *mem, const VectorType x, const VectorType m, StreamingAndAlignedFlag);
            static void store(double *mem, const VectorType x, const VectorType m, StreamingAndUnalignedFlag);

            static VectorType cdab(VectorType x) { return _permute_pd(x, 5); }
            static VectorType badc(VectorType x) { return _permute2f128_pd(x, x, 1); }
            // aaaa bbbb cccc dddd specialized in vector.tcc
            static VectorType dacb(VectorType x) {
                const __m128d cb = avx_cast<__m128d>(_mm_alignr_epi8(avx_cast<__m128i>(lo128(x)),
                            avx_cast<__m128i>(hi128(x)), sizeof(double))); // XXX: lo and hi swapped?
                const __m128d da = _mm_blend_pd(lo128(x), hi128(x), 0 + 2); // XXX: lo and hi swapped?
                return concat(cb, da);
            }

            OP0(allone, _setallone_pd())
            OP0(zero, _setzero_pd())
            OP2(or_, _or_pd(a, b))
            OP2(xor_, _xor_pd(a, b))
            OP2(and_, _and_pd(a, b))
            OP2(andnot_, _andnot_pd(a, b))
            OP3(blend, _blendv_pd(a, b, c))
        };

        template<> struct VectorHelper<_M256I>
        {
            typedef _M256I VectorType;
            template<typename T> static VectorType load(const T *x, AlignedFlag) Vc_PURE;
            template<typename T> static VectorType load(const T *x, UnalignedFlag) Vc_PURE;
            template<typename T> static VectorType load(const T *x, StreamingAndAlignedFlag) Vc_PURE;
            template<typename T> static VectorType load(const T *x, StreamingAndUnalignedFlag) Vc_PURE;
            template<typename T> static void store(T *mem, const VectorType x, AlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, UnalignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, StreamingAndAlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, StreamingAndUnalignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, AlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, UnalignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, StreamingAndAlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, StreamingAndUnalignedFlag);

            static VectorType cdab(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(2, 3, 0, 1))); }
            static VectorType badc(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(1, 0, 3, 2))); }
            static VectorType aaaa(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(0, 0, 0, 0))); }
            static VectorType bbbb(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(1, 1, 1, 1))); }
            static VectorType cccc(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(2, 2, 2, 2))); }
            static VectorType dddd(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(3, 3, 3, 3))); }
            static VectorType dacb(VectorType x) { return avx_cast<VectorType>(_permute_ps(avx_cast<__m256>(x), _MM_SHUFFLE(3, 0, 2, 1))); }

            OP0(allone, _setallone_si256())
            OP0(zero, _setzero_si256())
            OP2(or_, _or_si256(a, b))
            OP2(xor_, _xor_si256(a, b))
            OP2(and_, _and_si256(a, b))
            OP2(andnot_, _andnot_si256(a, b))
            OP3(blend, _blendv_epi8(a, b, c))
        };

        template<> struct VectorHelper<__m128i>
        {
            typedef __m128i VectorType;
            template<typename T> static VectorType load(const T *x, AlignedFlag) Vc_PURE;
            template<typename T> static VectorType load(const T *x, UnalignedFlag) Vc_PURE;
            template<typename T> static VectorType load(const T *x, StreamingAndAlignedFlag) Vc_PURE;
            template<typename T> static VectorType load(const T *x, StreamingAndUnalignedFlag) Vc_PURE;
            template<typename T> static void store(T *mem, const VectorType x, AlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, UnalignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, StreamingAndAlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, StreamingAndUnalignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, AlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, UnalignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, StreamingAndAlignedFlag);
            template<typename T> static void store(T *mem, const VectorType x, const VectorType m, StreamingAndUnalignedFlag);

            static VectorType cdab(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(2, 3, 0, 1)), _MM_SHUFFLE(2, 3, 0, 1)); }
            static VectorType badc(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(1, 0, 3, 2)), _MM_SHUFFLE(1, 0, 3, 2)); }
            static VectorType aaaa(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(0, 0, 0, 0)), _MM_SHUFFLE(0, 0, 0, 0)); }
            static VectorType bbbb(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(1, 1, 1, 1)), _MM_SHUFFLE(1, 1, 1, 1)); }
            static VectorType cccc(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(2, 2, 2, 2)), _MM_SHUFFLE(2, 2, 2, 2)); }
            static VectorType dddd(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(3, 3, 3, 3)), _MM_SHUFFLE(3, 3, 3, 3)); }
            static VectorType dacb(VectorType x) { return _mm_shufflehi_epi16(_mm_shufflelo_epi16(x, _MM_SHUFFLE(3, 0, 2, 1)), _MM_SHUFFLE(3, 0, 2, 1)); }

            OP0(allone, _mm_setallone_si128())
            OP0(zero, _mm_setzero_si128())
            OP2(or_, _mm_or_si128(a, b))
            OP2(xor_, _mm_xor_si128(a, b))
            OP2(and_, _mm_and_si128(a, b))
            OP2(andnot_, _mm_andnot_si128(a, b))
            OP3(blend, _mm_blendv_epi8(a, b, c))
        };
#undef OP1
#undef OP2
#undef OP3

#define OP1(op) \
        static inline VectorType Vc_INTRINSIC Vc_CONST op(const VectorType a) { return CAT(_##op##_, SUFFIX)(a); }
#define OP(op) \
        static inline VectorType Vc_INTRINSIC Vc_CONST op(const VectorType a, const VectorType b) { return CAT(_##op##_ , SUFFIX)(a, b); }
#define OP_(op) \
        static inline VectorType Vc_INTRINSIC Vc_CONST op(const VectorType a, const VectorType b) { return CAT(_##op    , SUFFIX)(a, b); }
#define OPx(op, op2) \
        static inline VectorType Vc_INTRINSIC Vc_CONST op(const VectorType a, const VectorType b) { return CAT(_##op2##_, SUFFIX)(a, b); }
#define OPcmp(op) \
        static inline VectorType Vc_INTRINSIC Vc_CONST cmp##op(const VectorType a, const VectorType b) { return CAT(_cmp##op##_, SUFFIX)(a, b); }
#define OP_CAST_(op) \
        static inline VectorType Vc_INTRINSIC Vc_CONST op(const VectorType a, const VectorType b) { return CAT(_castps_, SUFFIX)( \
            _##op##ps(CAT(CAT(_cast, SUFFIX), _ps)(a), \
              CAT(CAT(_cast, SUFFIX), _ps)(b))); \
        }
#define MINMAX \
        static inline VectorType Vc_INTRINSIC Vc_CONST min(VectorType a, VectorType b) { return CAT(_min_, SUFFIX)(a, b); } \
        static inline VectorType Vc_INTRINSIC Vc_CONST max(VectorType a, VectorType b) { return CAT(_max_, SUFFIX)(a, b); }

        template<> struct VectorHelper<double> {
            typedef _M256D VectorType;
            typedef double EntryType;
            typedef double ConcatType;
#define SUFFIX pd

            static inline VectorType notMaskedToZero(VectorType a, _M256 mask) { return CAT(_and_, SUFFIX)(_castps_pd(mask), a); }
            static inline VectorType set(const double a) { return CAT(_set1_, SUFFIX)(a); }
            static inline VectorType set(const double a, const double b, const double c, const double d) {
                return CAT(_set_, SUFFIX)(a, b, c, d);
            }
            static inline VectorType zero() { return CAT(_setzero_, SUFFIX)(); }
            static inline VectorType one()  { return CAT(_setone_, SUFFIX)(); }// set(1.); }

            static inline void fma(VectorType &v1, VectorType v2, VectorType v3) {
#ifdef VC_IMPL_FMA4
                v1 = _macc_pd(v1, v2, v3);
#else
                const VectorType h1 = _and_pd(v1, _broadcast4(reinterpret_cast<const double *>(&c_general::highMaskDouble)));
                const VectorType l1 = _sub_pd(v1, h1);
                const VectorType h2 = _and_pd(v2, _broadcast4(reinterpret_cast<const double *>(&c_general::highMaskDouble)));
                const VectorType l2 = _sub_pd(v2, h2);
                const VectorType ll = mul(l1, l2);
                const VectorType lh = add(mul(l1, h2), mul(h1, l2));
                const VectorType hh = mul(h1, h2);
                // ll < lh < hh for all entries is certain
                const VectorType lh_lt_v3 = cmplt(abs(lh), abs(v3)); // |lh| < |v3|
                const VectorType b = _blendv_pd(v3, lh, lh_lt_v3);
                const VectorType c = _blendv_pd(lh, v3, lh_lt_v3);
                v1 = add(add(ll, b), add(c, hh));
#endif
            }
            static inline VectorType mul(VectorType a, VectorType b, _M256 _mask) {
                _M256D mask = _castps_pd(_mask);
                return _or_pd(
                    _and_pd(mask, _mul_pd(a, b)),
                    _andnot_pd(mask, a)
                    );
            }
            static inline VectorType div(VectorType a, VectorType b, _M256 _mask) {
                _M256D mask = _castps_pd(_mask);
                return _or_pd(
                    _and_pd(mask, _div_pd(a, b)),
                    _andnot_pd(mask, a)
                    );
            }

            OP(add) OP(sub) OP(mul)
            OPcmp(eq) OPcmp(neq)
            OPcmp(lt) OPcmp(nlt)
            OPcmp(le) OPcmp(nle)

            OP1(sqrt)
            static inline VectorType rsqrt(VectorType x) {
                return _div_pd(one(), sqrt(x));
            }
            static inline VectorType reciprocal(VectorType x) {
                return _div_pd(one(), x);
            }
            static inline VectorType isNaN(VectorType x) {
                return _cmpunord_pd(x, x);
            }
            static inline VectorType isFinite(VectorType x) {
                return _cmpord_pd(x, _mul_pd(zero(), x));
            }
            static inline VectorType abs(const VectorType a) {
                return CAT(_and_, SUFFIX)(a, _setabsmask_pd());
            }

            MINMAX
            static inline EntryType min(VectorType a) {
                __m128d b = _mm_min_pd(avx_cast<__m128d>(a), _extractf128_pd(a, 1));
                b = _mm_min_sd(b, _mm_unpackhi_pd(b, b));
                return _mm_cvtsd_f64(b);
            }
            static inline EntryType max(VectorType a) {
                __m128d b = _mm_max_pd(avx_cast<__m128d>(a), _extractf128_pd(a, 1));
                b = _mm_max_sd(b, _mm_unpackhi_pd(b, b));
                return _mm_cvtsd_f64(b);
            }
            static inline EntryType mul(VectorType a) {
                __m128d b = _mm_mul_pd(avx_cast<__m128d>(a), _extractf128_pd(a, 1));
                b = _mm_mul_sd(b, _mm_shuffle_pd(b, b, _MM_SHUFFLE2(0, 1)));
                return _mm_cvtsd_f64(b);
            }
            static inline EntryType add(VectorType a) {
                __m128d b = _mm_add_pd(avx_cast<__m128d>(a), _extractf128_pd(a, 1));
                b = _mm_hadd_pd(b, b); // or: b = _mm_add_sd(b, _shuffle_pd(b, b, _MM_SHUFFLE2(0, 1)));
                return _mm_cvtsd_f64(b);
            }
#undef SUFFIX
            static inline VectorType round(VectorType a) {
                return _round_pd(a, _MM_FROUND_NINT);
            }
        };

        template<> struct VectorHelper<float> {
            typedef float EntryType;
            typedef _M256 VectorType;
            typedef double ConcatType;
#define SUFFIX ps

            static inline VectorType notMaskedToZero(VectorType a, _M256 mask) { return CAT(_and_, SUFFIX)(mask, a); }
            static inline VectorType set(const float a) { return CAT(_set1_, SUFFIX)(a); }
            static inline VectorType set(const float a, const float b, const float c, const float d,
                    const float e, const float f, const float g, const float h) {
                return CAT(_set_, SUFFIX)(a, b, c, d, e, f, g, h); }
            static inline VectorType zero() { return CAT(_setzero_, SUFFIX)(); }
            static inline VectorType one()  { return CAT(_setone_, SUFFIX)(); }// set(1.f); }
            static inline _M256 concat(_M256D a, _M256D b) { return _insertf128_ps(avx_cast<_M256>(_cvtpd_ps(a)), _cvtpd_ps(b), 1); }

            static inline void fma(VectorType &v1, VectorType v2, VectorType v3) {
#ifdef VC_IMPL_FMA4
                v1 = _macc_ps(v1, v2, v3);
#else
                __m256d v1_0 = _cvtps_pd(lo128(v1));
                __m256d v1_1 = _cvtps_pd(hi128(v1));
                __m256d v2_0 = _cvtps_pd(lo128(v2));
                __m256d v2_1 = _cvtps_pd(hi128(v2));
                __m256d v3_0 = _cvtps_pd(lo128(v3));
                __m256d v3_1 = _cvtps_pd(hi128(v3));
                v1 = AVX::concat(
                        _cvtpd_ps(_add_pd(_mul_pd(v1_0, v2_0), v3_0)),
                        _cvtpd_ps(_add_pd(_mul_pd(v1_1, v2_1), v3_1)));
#endif
            }
            static inline VectorType mul(VectorType a, VectorType b, _M256 mask) {
                return _or_ps(
                    _and_ps(mask, _mul_ps(a, b)),
                    _andnot_ps(mask, a)
                    );
            }
            static inline VectorType div(VectorType a, VectorType b, _M256 mask) {
                return _or_ps(
                    _and_ps(mask, _div_ps(a, b)),
                    _andnot_ps(mask, a)
                    );
            }

            OP(add) OP(sub) OP(mul)
            OPcmp(eq) OPcmp(neq)
            OPcmp(lt) OPcmp(nlt)
            OPcmp(le) OPcmp(nle)

            OP1(sqrt) OP1(rsqrt)
            static inline VectorType isNaN(VectorType x) {
                return _cmpunord_ps(x, x);
            }
            static inline VectorType isFinite(VectorType x) {
                return _cmpord_ps(x, _mul_ps(zero(), x));
            }
            static inline VectorType reciprocal(VectorType x) {
                return _rcp_ps(x);
            }
            static inline VectorType abs(const VectorType a) {
                return CAT(_and_, SUFFIX)(a, _setabsmask_ps());
            }

            MINMAX
            static inline EntryType min(VectorType a) {
                __m128 b = _mm_min_ps(avx_cast<__m128>(a), _extractf128_ps(a, 1));
                b = _mm_min_ps(b, _mm_movehl_ps(b, b));   // b = min(a0, a2), min(a1, a3), min(a2, a2), min(a3, a3)
                b = _mm_min_ss(b, _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1))); // b = min(a0, a1), a1, a2, a3
                return _mm_cvtss_f32(b);
            }
            static inline EntryType max(VectorType a) {
                __m128 b = _mm_max_ps(avx_cast<__m128>(a), _extractf128_ps(a, 1));
                b = _mm_max_ps(b, _mm_movehl_ps(b, b));   // b = max(a0, a2), max(a1, a3), max(a2, a2), max(a3, a3)
                b = _mm_max_ss(b, _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1))); // b = max(a0, a1), a1, a2, a3
                return _mm_cvtss_f32(b);
            }
            static inline EntryType mul(VectorType a) {
                __m128 b = _mm_mul_ps(avx_cast<__m128>(a), _extractf128_ps(a, 1));
                b = _mm_mul_ps(b, _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 1, 2, 3)));
                b = _mm_mul_ss(b, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 2, 0, 1)));
                return _mm_cvtss_f32(b);
            }
            static inline EntryType add(VectorType a) {
                __m128 b = _mm_add_ps(avx_cast<__m128>(a), _extractf128_ps(a, 1));
                b = _mm_add_ps(b, _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 1, 2, 3)));
                b = _mm_add_ss(b, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 2, 0, 1)));
                return _mm_cvtss_f32(b);
            }
#undef SUFFIX
            static inline VectorType round(VectorType a) {
                return _round_ps(a, _MM_FROUND_NINT);
            }
        };

        template<> struct VectorHelper<sfloat> : public VectorHelper<float> {};

        template<> struct VectorHelper<int> {
            typedef int EntryType;
            typedef _M256I VectorType;
            typedef long long ConcatType;
#define SUFFIX si256

            OP_(or_) OP_(and_) OP_(xor_)
            static inline VectorType Vc_INTRINSIC Vc_CONST zero() { return CAT(_setzero_, SUFFIX)(); }
            static inline VectorType Vc_INTRINSIC Vc_CONST notMaskedToZero(VectorType a, _M256 mask) { return CAT(_and_, SUFFIX)(_castps_si256(mask), a); }
#undef SUFFIX
#define SUFFIX epi32
            static inline VectorType Vc_INTRINSIC Vc_CONST one() { return CAT(_setone_, SUFFIX)(); }

            static inline VectorType Vc_INTRINSIC Vc_CONST set(const int a) { return CAT(_set1_, SUFFIX)(a); }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const int a, const int b, const int c, const int d,
                    const int e, const int f, const int g, const int h) {
                return CAT(_set_, SUFFIX)(a, b, c, d, e, f, g, h); }

            static inline void Vc_INTRINSIC fma(VectorType &v1, VectorType v2, VectorType v3) { v1 = add(mul(v1, v2), v3); }

            static inline VectorType shiftLeft(VectorType a, int shift) {
                return CAT(_slli_, SUFFIX)(a, shift);
            }
            static inline VectorType shiftRight(VectorType a, int shift) {
                return CAT(_srai_, SUFFIX)(a, shift);
            }
            OP1(abs)

            MINMAX
            static inline EntryType Vc_INTRINSIC Vc_CONST min(VectorType a) {
                __m128i b = _mm_min_epi32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_min_epi32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_min_epi32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2))); // using lo_epi16 for speed here
                return _mm_cvtsi128_si32(b);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST max(VectorType a) {
                __m128i b = _mm_max_epi32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_max_epi32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_max_epi32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2))); // using lo_epi16 for speed here
                return _mm_cvtsi128_si32(b);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST add(VectorType a) {
                __m128i b = _mm_add_epi32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_add_epi32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_add_epi32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2)));
                return _mm_cvtsi128_si32(b);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST mul(VectorType a) {
                __m128i b = _mm_mullo_epi32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_mullo_epi32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_mullo_epi32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2)));
                return _mm_cvtsi128_si32(b);
            }

            static inline VectorType Vc_INTRINSIC Vc_CONST mul(VectorType a, VectorType b) { return _mullo_epi32(a, b); }

            OP(add) OP(sub)
            OPcmp(eq)
            OPcmp(lt)
            OPcmp(gt)
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpneq(const VectorType a, const VectorType b) { _M256I x = cmpeq(a, b); return _andnot_si256(x, _setallone_si256()); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpnlt(const VectorType a, const VectorType b) { _M256I x = cmplt(a, b); return _andnot_si256(x, _setallone_si256()); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmple (const VectorType a, const VectorType b) { _M256I x = cmpgt(a, b); return _andnot_si256(x, _setallone_si256()); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpnle(const VectorType a, const VectorType b) { return cmpgt(a, b); }
#undef SUFFIX
            static inline VectorType Vc_INTRINSIC Vc_CONST round(VectorType a) { return a; }
        };

        template<> struct VectorHelper<unsigned int> {
            typedef unsigned int EntryType;
            typedef _M256I VectorType;
            typedef unsigned long long ConcatType;
#define SUFFIX si256
            OP_CAST_(or_) OP_CAST_(and_) OP_CAST_(xor_)
            static inline VectorType Vc_INTRINSIC Vc_CONST zero() { return CAT(_setzero_, SUFFIX)(); }
            static inline VectorType Vc_INTRINSIC Vc_CONST notMaskedToZero(VectorType a, _M256 mask) { return CAT(_and_, SUFFIX)(_castps_si256(mask), a); }

#undef SUFFIX
#define SUFFIX epu32
            static inline VectorType Vc_INTRINSIC Vc_CONST one() { return CAT(_setone_, SUFFIX)(); }

            MINMAX
            static inline EntryType Vc_INTRINSIC Vc_CONST min(VectorType a) {
                __m128i b = _mm_min_epu32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_min_epu32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_min_epu32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2))); // using lo_epi16 for speed here
                return _mm_cvtsi128_si32(b);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST max(VectorType a) {
                __m128i b = _mm_max_epu32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_max_epu32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_max_epu32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2))); // using lo_epi16 for speed here
                return _mm_cvtsi128_si32(b);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST add(VectorType a) {
                __m128i b = _mm_add_epi32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_add_epi32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_add_epi32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2)));
                return _mm_cvtsi128_si32(b);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST mul(VectorType a) {
                __m128i b = _mm_mullo_epi32(avx_cast<__m128i>(a), _extractf128_si256(a, 1));
                b = _mm_mullo_epi32(b, _mm_shuffle_epi32(b, _MM_SHUFFLE(1, 0, 3, 2)));
                b = _mm_mullo_epi32(b, _mm_shufflelo_epi16(b, _MM_SHUFFLE(1, 0, 3, 2)));
                return _mm_cvtsi128_si32(b);
            }

            static inline VectorType Vc_INTRINSIC Vc_CONST mul(VectorType a, VectorType b) { return _mullo_epi32(a, b); }
            static inline void Vc_INTRINSIC fma(VectorType &v1, VectorType v2, VectorType v3) { v1 = add(mul(v1, v2), v3); }

#undef SUFFIX
#define SUFFIX epi32
            static inline VectorType shiftLeft(VectorType a, int shift) {
                return CAT(_slli_, SUFFIX)(a, shift);
            }
            static inline VectorType shiftRight(VectorType a, int shift) {
                return CAT(_srli_, SUFFIX)(a, shift);
            }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const unsigned int a) { return CAT(_set1_, SUFFIX)(a); }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const unsigned int a, const unsigned int b, const unsigned int c, const unsigned int d,
                    const unsigned int e, const unsigned int f, const unsigned int g, const unsigned int h) {
                return CAT(_set_, SUFFIX)(a, b, c, d, e, f, g, h); }

            OP(add) OP(sub)
            OPcmp(eq)
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpneq(const VectorType a, const VectorType b) { return _andnot_si256(cmpeq(a, b), _setallone_si256()); }

#ifndef USE_INCORRECT_UNSIGNED_COMPARE
            static inline VectorType Vc_INTRINSIC Vc_CONST cmplt(const VectorType a, const VectorType b) {
                return _cmplt_epu32(a, b);
            }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpgt(const VectorType a, const VectorType b) {
                return _cmpgt_epu32(a, b);
            }
#else
            OPcmp(lt)
            OPcmp(gt)
#endif
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpnlt(const VectorType a, const VectorType b) { return _andnot_si256(cmplt(a, b), _setallone_si256()); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmple (const VectorType a, const VectorType b) { return _andnot_si256(cmpgt(a, b), _setallone_si256()); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpnle(const VectorType a, const VectorType b) { return cmpgt(a, b); }

#undef SUFFIX
            static inline VectorType Vc_INTRINSIC Vc_CONST round(VectorType a) { return a; }
        };

        template<> struct VectorHelper<signed short> {
            typedef VectorTypeHelper<signed short>::Type VectorType;
            typedef signed short EntryType;
            typedef int ConcatType;

            static inline VectorType Vc_INTRINSIC Vc_CONST or_(VectorType a, VectorType b) { return _mm_or_si128(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST and_(VectorType a, VectorType b) { return _mm_and_si128(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST xor_(VectorType a, VectorType b) { return _mm_xor_si128(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST zero() { return _mm_setzero_si128(); }
            static inline VectorType Vc_INTRINSIC Vc_CONST notMaskedToZero(VectorType a, __m128 mask) { return _mm_and_si128(_mm_castps_si128(mask), a); }

#define SUFFIX epi16
            static inline VectorType Vc_INTRINSIC Vc_CONST one() { return CAT(_mm_setone_, SUFFIX)(); }

            static inline VectorType shiftLeft(VectorType a, int shift) {
                return CAT(_mm_slli_, SUFFIX)(a, shift);
            }
            static inline VectorType shiftRight(VectorType a, int shift) {
                return CAT(_mm_srai_, SUFFIX)(a, shift);
            }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const EntryType a) { return CAT(_mm_set1_, SUFFIX)(a); }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const EntryType a, const EntryType b, const EntryType c, const EntryType d,
                    const EntryType e, const EntryType f, const EntryType g, const EntryType h) {
                return CAT(_mm_set_, SUFFIX)(a, b, c, d, e, f, g, h);
            }

            static inline void Vc_INTRINSIC fma(VectorType &v1, VectorType v2, VectorType v3) {
                v1 = add(mul(v1, v2), v3);
            }

            static inline VectorType Vc_INTRINSIC Vc_CONST abs(VectorType a) { return _mm_abs_epi16(a); }
            static inline VectorType Vc_INTRINSIC Vc_CONST mul(VectorType a, VectorType b) { return _mm_mullo_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST min(VectorType a, VectorType b) { return _mm_min_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST max(VectorType a, VectorType b) { return _mm_max_epi16(a, b); }

            static inline EntryType Vc_INTRINSIC Vc_CONST min(VectorType a) {
                // reminder: _MM_SHUFFLE(3, 2, 1, 0) means "no change"
                a = min(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = min(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = min(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST max(VectorType a) {
                // reminder: _MM_SHUFFLE(3, 2, 1, 0) means "no change"
                a = max(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = max(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = max(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST mul(VectorType a) {
                a = mul(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = mul(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = mul(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST add(VectorType a) {
                a = add(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = add(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = add(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }

            static inline VectorType Vc_INTRINSIC Vc_CONST add(VectorType a, VectorType b) { return _mm_add_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST sub(VectorType a, VectorType b) { return _mm_sub_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpeq(VectorType a, VectorType b) { return _mm_cmpeq_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmplt(VectorType a, VectorType b) { return _mm_cmplt_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpgt(VectorType a, VectorType b) { return _mm_cmpgt_epi16(a, b); }
            static inline VectorType cmpneq(const VectorType a, const VectorType b) { __m128i x = cmpeq(a, b); return _mm_andnot_si128(x, _mm_setallone_si128()); }
            static inline VectorType cmpnlt(const VectorType a, const VectorType b) { __m128i x = cmplt(a, b); return _mm_andnot_si128(x, _mm_setallone_si128()); }
            static inline VectorType cmple (const VectorType a, const VectorType b) { __m128i x = cmpgt(a, b); return _mm_andnot_si128(x, _mm_setallone_si128()); }
            static inline VectorType cmpnle(const VectorType a, const VectorType b) { return cmpgt(a, b); }
#undef SUFFIX
            static inline VectorType round(VectorType a) { return a; }
        };

        template<> struct VectorHelper<unsigned short> {
            typedef VectorTypeHelper<unsigned short>::Type VectorType;
            typedef unsigned short EntryType;
            typedef unsigned int ConcatType;

            static inline VectorType Vc_INTRINSIC Vc_CONST or_(VectorType a, VectorType b) { return _mm_or_si128(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST and_(VectorType a, VectorType b) { return _mm_and_si128(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST xor_(VectorType a, VectorType b) { return _mm_xor_si128(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST zero() { return _mm_setzero_si128(); }
            static inline VectorType Vc_INTRINSIC Vc_CONST notMaskedToZero(VectorType a, __m128 mask) { return _mm_and_si128(_mm_castps_si128(mask), a); }
            static inline VectorType Vc_INTRINSIC Vc_CONST one() { return _mm_setone_epu16(); }

            static inline VectorType Vc_INTRINSIC Vc_CONST mul(VectorType a, VectorType b) { return _mm_mullo_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST min(VectorType a, VectorType b) { return _mm_min_epu16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST max(VectorType a, VectorType b) { return _mm_max_epu16(a, b); }

#define SUFFIX epi16
            static inline VectorType shiftLeft(VectorType a, int shift) {
                return CAT(_mm_slli_, SUFFIX)(a, shift);
            }
            static inline VectorType shiftRight(VectorType a, int shift) {
                return CAT(_mm_srli_, SUFFIX)(a, shift);
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST min(VectorType a) {
                // reminder: _MM_SHUFFLE(3, 2, 1, 0) means "no change"
                a = min(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = min(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = min(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST max(VectorType a) {
                // reminder: _MM_SHUFFLE(3, 2, 1, 0) means "no change"
                a = max(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = max(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = max(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST mul(VectorType a) {
                // reminder: _MM_SHUFFLE(3, 2, 1, 0) means "no change"
                a = mul(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = mul(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = mul(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline EntryType Vc_INTRINSIC Vc_CONST add(VectorType a) {
                // reminder: _MM_SHUFFLE(3, 2, 1, 0) means "no change"
                a = add(a, _mm_shuffle_epi32(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = add(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 0, 3, 2)));
                a = add(a, _mm_shufflelo_epi16(a, _MM_SHUFFLE(1, 1, 1, 1)));
                return _mm_cvtsi128_si32(a); // & 0xffff is implicit
            }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const EntryType a) { return CAT(_mm_set1_, SUFFIX)(a); }
            static inline VectorType Vc_INTRINSIC Vc_CONST set(const EntryType a, const EntryType b, const EntryType c,
                    const EntryType d, const EntryType e, const EntryType f,
                    const EntryType g, const EntryType h) {
                return CAT(_mm_set_, SUFFIX)(a, b, c, d, e, f, g, h);
            }
            static inline void Vc_INTRINSIC fma(VectorType &v1, VectorType v2, VectorType v3) { v1 = add(mul(v1, v2), v3); }

            static inline VectorType Vc_INTRINSIC Vc_CONST add(VectorType a, VectorType b) { return _mm_add_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST sub(VectorType a, VectorType b) { return _mm_sub_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpeq(VectorType a, VectorType b) { return _mm_cmpeq_epi16(a, b); }
            static inline VectorType cmpneq(const VectorType a, const VectorType b) { return _mm_andnot_si128(cmpeq(a, b), _mm_setallone_si128()); }

#ifndef USE_INCORRECT_UNSIGNED_COMPARE
            static inline VectorType Vc_INTRINSIC Vc_CONST cmplt(VectorType a, VectorType b) { return _mm_cmplt_epu16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpgt(VectorType a, VectorType b) { return _mm_cmpgt_epu16(a, b); }
#else
            static inline VectorType Vc_INTRINSIC Vc_CONST cmplt(VectorType a, VectorType b) { return _mm_cmplt_epi16(a, b); }
            static inline VectorType Vc_INTRINSIC Vc_CONST cmpgt(VectorType a, VectorType b) { return _mm_cmpgt_epi16(a, b); }
#endif
            static inline VectorType cmpnlt(const VectorType a, const VectorType b) { return _mm_andnot_si128(cmplt(a, b), _mm_setallone_si128()); }
            static inline VectorType cmple (const VectorType a, const VectorType b) { return _mm_andnot_si128(cmpgt(a, b), _mm_setallone_si128()); }
            static inline VectorType cmpnle(const VectorType a, const VectorType b) { return cmpgt(a, b); }
#undef SUFFIX
            static inline VectorType round(VectorType a) { return a; }
        };
#undef OP1
#undef OP
#undef OP_
#undef OPx
#undef OPcmp

template<> struct VectorHelper<char>
{
    typedef VectorTypeHelper<char>::Type VectorType;
    typedef char EntryType;
    typedef short ConcatType;
};

template<> struct VectorHelper<unsigned char>
{
    typedef VectorTypeHelper<unsigned char>::Type VectorType;
    typedef unsigned char EntryType;
    typedef unsigned short ConcatType;
};

} // namespace AVX
} // namespace Vc

#include "vectorhelper.tcc"

#endif // AVX_VECTORHELPER_H
