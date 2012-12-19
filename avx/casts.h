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

#ifndef AVX_CASTS_H
#define AVX_CASTS_H

#include "intrinsics.h"
#include "types.h"

namespace Vc
{
namespace AVX
{
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(__m128  v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(__m128i v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(__m128d v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(__m256  v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(__m256i v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(__m256d v) Vc_INTRINSIC_R;

    // 128 -> 128
    template<> inline __m128  Vc_INTRINSIC avx_cast(__m128  v) { return v; }
    template<> inline __m128  Vc_INTRINSIC avx_cast(__m128i v) { return _mm_castsi128_ps(v); }
    template<> inline __m128  Vc_INTRINSIC avx_cast(__m128d v) { return _mm_castpd_ps(v); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(__m128  v) { return _mm_castps_si128(v); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(__m128i v) { return v; }
    template<> inline __m128i Vc_INTRINSIC avx_cast(__m128d v) { return _mm_castpd_si128(v); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(__m128  v) { return _mm_castps_pd(v); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(__m128i v) { return _mm_castsi128_pd(v); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(__m128d v) { return v; }

    // 128 -> 256
    template<> inline __m256  Vc_INTRINSIC avx_cast(__m128  v) { return _castps128_ps256(v); }
    template<> inline __m256  Vc_INTRINSIC avx_cast(__m128i v) { return _castps128_ps256(_mm_castsi128_ps(v)); }
    template<> inline __m256  Vc_INTRINSIC avx_cast(__m128d v) { return _castps128_ps256(_mm_castpd_ps(v)); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(__m128  v) { return _castsi128_si256(_mm_castps_si128(v)); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(__m128i v) { return _castsi128_si256(v); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(__m128d v) { return _castsi128_si256(_mm_castpd_si128(v)); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(__m128  v) { return _castpd128_pd256(_mm_castps_pd(v)); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(__m128i v) { return _castpd128_pd256(_mm_castsi128_pd(v)); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(__m128d v) { return _castpd128_pd256(v); }

    // 256 -> 128
    template<> inline __m128  Vc_INTRINSIC avx_cast(__m256  v) { return _castps256_ps128(v); }
    template<> inline __m128  Vc_INTRINSIC avx_cast(__m256i v) { return _castps256_ps128(_castsi256_ps(v)); }
    template<> inline __m128  Vc_INTRINSIC avx_cast(__m256d v) { return _castps256_ps128(_castpd_ps(v)); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(__m256  v) { return _castsi256_si128(_castps_si256(v)); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(__m256i v) { return _castsi256_si128(v); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(__m256d v) { return _castsi256_si128(_castpd_si256(v)); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(__m256  v) { return _castpd256_pd128(_castps_pd(v)); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(__m256i v) { return _castpd256_pd128(_castsi256_pd(v)); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(__m256d v) { return _castpd256_pd128(v); }

    // 256 -> 256
    template<> inline __m256  Vc_INTRINSIC avx_cast(__m256  v) { return v; }
    template<> inline __m256  Vc_INTRINSIC avx_cast(__m256i v) { return _castsi256_ps(v); }
    template<> inline __m256  Vc_INTRINSIC avx_cast(__m256d v) { return _castpd_ps(v); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(__m256  v) { return _castps_si256(v); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(__m256i v) { return v; }
    template<> inline __m256i Vc_INTRINSIC avx_cast(__m256d v) { return _castpd_si256(v); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(__m256  v) { return _castps_pd(v); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(__m256i v) { return _castsi256_pd(v); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(__m256d v) { return v; }

    // simplify splitting 256-bit registers in 128-bit registers
    inline __m128  Vc_INTRINSIC lo128(__m256  v) { return avx_cast<__m128>(v); }
    inline __m128d Vc_INTRINSIC lo128(__m256d v) { return avx_cast<__m128d>(v); }
    inline __m128i Vc_INTRINSIC lo128(__m256i v) { return avx_cast<__m128i>(v); }
    inline __m128  Vc_INTRINSIC hi128(__m256  v) { return _extractf128_ps(v, 1); }
    inline __m128d Vc_INTRINSIC hi128(__m256d v) { return _extractf128_pd(v, 1); }
    inline __m128i Vc_INTRINSIC hi128(__m256i v) { return _extractf128_si256(v, 1); }

    // simplify combining 128-bit registers in 256-bit registers
    inline __m256  Vc_INTRINSIC concat(__m128  a, __m128  b) { return _insertf128_ps   (avx_cast<__m256 >(a), b, 1); }
    inline __m256d Vc_INTRINSIC concat(__m128d a, __m128d b) { return _insertf128_pd   (avx_cast<__m256d>(a), b, 1); }
    inline __m256i Vc_INTRINSIC concat(__m128i a, __m128i b) { return _insertf128_si256(avx_cast<__m256i>(a), b, 1); }

    template<typename From, typename To> struct StaticCastHelper {};
    template<> struct StaticCastHelper<float         , int           > { static _M256I  cast(const _M256   v) { return _cvttps_epi32(v); } };
    template<> struct StaticCastHelper<double        , int           > { static _M256I  cast(const _M256D  v) { return avx_cast<_M256I>(_cvttpd_epi32(v)); } };
    template<> struct StaticCastHelper<int           , int           > { static _M256I  cast(const _M256I  v) { return v; } };
    template<> struct StaticCastHelper<unsigned int  , int           > { static _M256I  cast(const _M256I  v) { return v; } };
    template<> struct StaticCastHelper<short         , int           > { static _M256I  cast(const __m128i v) { return concat(_mm_srai_epi32(_mm_unpacklo_epi16(v, v), 16), _mm_srai_epi32(_mm_unpackhi_epi16(v, v), 16)); } };
    template<> struct StaticCastHelper<float         , unsigned int  > { static _M256I  cast(const _M256   v) {
        return _castps_si256(_blendv_ps(
                _castsi256_ps(_cvttps_epi32(v)),
                _castsi256_ps(_add_epi32(_cvttps_epi32(_sub_ps(v, _set2power31_ps())), _set2power31_epu32())),
                _cmpge_ps(v, _set2power31_ps())
                ));

    } };
    template<> struct StaticCastHelper<double        , unsigned int  > { static _M256I  cast(const _M256D  v) { return avx_cast<_M256I>(_cvttpd_epi32(v)); } };
    template<> struct StaticCastHelper<int           , unsigned int  > { static _M256I  cast(const _M256I  v) { return v; } };
    template<> struct StaticCastHelper<unsigned int  , unsigned int  > { static _M256I  cast(const _M256I  v) { return v; } };
    template<> struct StaticCastHelper<unsigned short, unsigned int  > { static _M256I  cast(const __m128i v) { return concat(_mm_srli_epi32(_mm_unpacklo_epi16(v, v), 16), _mm_srli_epi32(_mm_unpackhi_epi16(v, v), 16)); } };
    template<> struct StaticCastHelper<float         , float         > { static _M256   cast(const _M256   v) { return v; } };
    template<> struct StaticCastHelper<double        , float         > { static _M256   cast(const _M256D  v) { return avx_cast<_M256>(_cvtpd_ps(v)); } };
    template<> struct StaticCastHelper<int           , float         > { static _M256   cast(const _M256I  v) { return _cvtepi32_ps(v); } };
    template<> struct StaticCastHelper<unsigned int  , float         > { static _M256   cast(const _M256I  v) {
        return _blendv_ps(
                _cvtepi32_ps(v),
                _add_ps(_cvtepi32_ps(_sub_epi32(v, _set2power31_epu32())), _set2power31_ps()),
                _castsi256_ps(_cmplt_epi32(v, _setzero_si256()))
                );
    } };
    template<> struct StaticCastHelper<short         , float         > { static _M256   cast(const __m128i v) { return _cvtepi32_ps(StaticCastHelper<short, int>::cast(v)); } };
    template<> struct StaticCastHelper<unsigned short, float         > { static _M256   cast(const __m128i v) { return _cvtepi32_ps(StaticCastHelper<unsigned short, unsigned int>::cast(v)); } };
    template<> struct StaticCastHelper<float         , double        > { static _M256D  cast(const _M256   v) { return _cvtps_pd(avx_cast<__m128>(v)); } };
    template<> struct StaticCastHelper<double        , double        > { static _M256D  cast(const _M256D  v) { return v; } };
    template<> struct StaticCastHelper<int           , double        > { static _M256D  cast(const _M256I  v) { return _cvtepi32_pd(avx_cast<__m128i>(v)); } };
    template<> struct StaticCastHelper<unsigned int  , double        > { static _M256D  cast(const _M256I  v) { return _cvtepi32_pd(avx_cast<__m128i>(v)); } };
    template<> struct StaticCastHelper<int           , short         > { static __m128i cast(const _M256I  v) { return _mm_packs_epi32(lo128(v), hi128(v)); } };
    template<> struct StaticCastHelper<float         , short         > { static __m128i cast(const _M256   v) { return StaticCastHelper<int, short>::cast(StaticCastHelper<float, int>::cast(v)); } };
    template<> struct StaticCastHelper<short         , short         > { static __m128i cast(const __m128i v) { return v; } };
    template<> struct StaticCastHelper<unsigned short, short         > { static __m128i cast(const __m128i v) { return v; } };
    template<> struct StaticCastHelper<unsigned int  , unsigned short> { static __m128i cast(const _M256I  v) { return _mm_packus_epi32(lo128(v), hi128(v)); } };
    template<> struct StaticCastHelper<float         , unsigned short> { static __m128i cast(const _M256   v) { return StaticCastHelper<unsigned int, unsigned short>::cast(StaticCastHelper<float, unsigned int>::cast(v)); } };
    template<> struct StaticCastHelper<short         , unsigned short> { static __m128i cast(const __m128i v) { return v; } };
    template<> struct StaticCastHelper<unsigned short, unsigned short> { static __m128i cast(const __m128i v) { return v; } };
    template<> struct StaticCastHelper<sfloat        , short         > { static __m128i cast(const _M256   v) { return StaticCastHelper<int, short>::cast(StaticCastHelper<float, int>::cast(v)); } };
    template<> struct StaticCastHelper<sfloat        , unsigned short> { static __m128i cast(const _M256   v) { return StaticCastHelper<unsigned int, unsigned short>::cast(StaticCastHelper<float, unsigned int>::cast(v)); } };
    template<> struct StaticCastHelper<short         , sfloat        > { static _M256   cast(const __m128i v) { return _cvtepi32_ps(StaticCastHelper<short, int>::cast(v)); } };
    template<> struct StaticCastHelper<unsigned short, sfloat        > { static _M256   cast(const __m128i v) { return _cvtepi32_ps(StaticCastHelper<unsigned short, unsigned int>::cast(v)); } };
} // namespace AVX
} // namespace Vc

#endif // AVX_CASTS_H
