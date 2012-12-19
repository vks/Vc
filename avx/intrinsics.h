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
#ifndef VC_AVX_INTRINSICS_H
#define VC_AVX_INTRINSICS_H
#include "../common/windows_fix_intrin.h"
// AVX
#include <immintrin.h>
#include "macros.h"
inline Vc_INTRINSIC __m256d _add_pd(__m256d __A, __m256d __B) { return _mm256_add_pd(__A, __B); }
inline Vc_INTRINSIC __m256 _add_ps (__m256 __A, __m256 __B) { return _mm256_add_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _addsub_pd (__m256d __A, __m256d __B) { return _mm256_addsub_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _addsub_ps (__m256 __A, __m256 __B) { return _mm256_addsub_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _and_pd (__m256d __A, __m256d __B) { return _mm256_and_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _and_ps (__m256 __A, __m256 __B) { return _mm256_and_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _andnot_pd (__m256d __A, __m256d __B) { return _mm256_andnot_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _andnot_ps (__m256 __A, __m256 __B) { return _mm256_andnot_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _blend_pd (__m256d __X, __m256d __Y, const int __M) { return _mm256_blend_pd (__X, __Y, __M); }
inline Vc_INTRINSIC __m256 _blend_ps (__m256 __X, __m256 __Y, const int __M) { return _mm256_blend_ps (__X, __Y, __M); }
inline Vc_INTRINSIC __m256d _blendv_pd (__m256d __X, __m256d __Y, __m256d __M) { return _mm256_blendv_pd (__X, __Y, __M); }
inline Vc_INTRINSIC __m256 _blendv_ps (__m256 __X, __m256 __Y, __m256 __M) { return _mm256_blendv_ps (__X, __Y, __M); }
inline Vc_INTRINSIC __m256d _div_pd (__m256d __A, __m256d __B) { return _mm256_div_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _div_ps (__m256 __A, __m256 __B) { return _mm256_div_ps (__A, __B); }
inline Vc_INTRINSIC __m256 _dp_ps (__m256 __X, __m256 __Y, const int __M) { return _mm256_dp_ps (__X, __Y, __M); }
inline Vc_INTRINSIC __m256d _hadd_pd (__m256d __X, __m256d __Y) { return _mm256_hadd_pd (__X, __Y); }
inline Vc_INTRINSIC __m256 _hadd_ps (__m256 __X, __m256 __Y) { return _mm256_hadd_ps (__X, __Y); }
inline Vc_INTRINSIC __m256d _hsub_pd (__m256d __X, __m256d __Y) { return _mm256_hsub_pd (__X, __Y); }
inline Vc_INTRINSIC __m256 _hsub_ps (__m256 __X, __m256 __Y) { return _mm256_hsub_ps (__X, __Y); }
inline Vc_INTRINSIC __m256d _max_pd (__m256d __A, __m256d __B) { return _mm256_max_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _max_ps (__m256 __A, __m256 __B) { return _mm256_max_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _min_pd (__m256d __A, __m256d __B) { return _mm256_min_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _min_ps (__m256 __A, __m256 __B) { return _mm256_min_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _mul_pd (__m256d __A, __m256d __B) { return _mm256_mul_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _mul_ps (__m256 __A, __m256 __B) { return _mm256_mul_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _or_pd (__m256d __A, __m256d __B) { return _mm256_or_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _or_ps (__m256 __A, __m256 __B) { return _mm256_or_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _shuffle_pd (__m256d __A, __m256d __B, const int __mask) { return _mm256_shuffle_pd (__A, __B, __mask); }
inline Vc_INTRINSIC __m256 _shuffle_ps (__m256 __A, __m256 __B, const int __mask) { return _mm256_shuffle_ps (__A, __B, __mask); }
inline Vc_INTRINSIC __m256d _sub_pd (__m256d __A, __m256d __B) { return _mm256_sub_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _sub_ps (__m256 __A, __m256 __B) { return _mm256_sub_ps (__A, __B); }
inline Vc_INTRINSIC __m256d _xor_pd (__m256d __A, __m256d __B) { return _mm256_xor_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _xor_ps (__m256 __A, __m256 __B) { return _mm256_xor_ps (__A, __B); }
inline Vc_INTRINSIC __m128d _cmp_pd (__m128d __X, __m128d __Y, const int __P) { return _mm_cmp_pd (__X, __Y, __P); }
inline Vc_INTRINSIC __m128 _cmp_ps (__m128 __X, __m128 __Y, const int __P) { return _mm_cmp_ps (__X, __Y, __P); }
inline Vc_INTRINSIC __m256d _cmp_pd (__m256d __X, __m256d __Y, const int __P) { return _mm256_cmp_pd (__X, __Y, __P); }
inline Vc_INTRINSIC __m256 _cmp_ps (__m256 __X, __m256 __Y, const int __P) { return _mm256_cmp_ps (__X, __Y, __P); }
inline Vc_INTRINSIC __m128d _cmp_sd (__m128d __X, __m128d __Y, const int __P) { return _mm_cmp_sd (__X, __Y, __P); }
inline Vc_INTRINSIC __m128 _cmp_ss (__m128 __X, __m128 __Y, const int __P) { return _mm_cmp_ss (__X, __Y, __P); }
inline Vc_INTRINSIC __m256d _cvtepi32_pd (__m128i __A) { return _mm256_cvtepi32_pd (__A); }
inline Vc_INTRINSIC __m256 _cvtepi32_ps (__m256i __A) { return _mm256_cvtepi32_ps (__A); }
inline Vc_INTRINSIC __m128 _cvtpd_ps (__m256d __A) { return _mm256_cvtpd_ps (__A); }
inline Vc_INTRINSIC __m256i _cvtps_epi32 (__m256 __A) { return _mm256_cvtps_epi32 (__A); }
inline Vc_INTRINSIC __m256d _cvtps_pd (__m128 __A) { return _mm256_cvtps_pd (__A); }
inline Vc_INTRINSIC __m128i _cvttpd_epi32 (__m256d __A) { return _mm256_cvttpd_epi32 (__A); }
inline Vc_INTRINSIC __m128i _cvtpd_epi32 (__m256d __A) { return _mm256_cvtpd_epi32 (__A); }
inline Vc_INTRINSIC __m256i _cvttps_epi32 (__m256 __A) { return _mm256_cvttps_epi32 (__A); }
inline Vc_INTRINSIC __m128d _extractf128_pd (__m256d __X, const int __N) { return _mm256_extractf128_pd (__X, __N); }
inline Vc_INTRINSIC __m128 _extractf128_ps (__m256 __X, const int __N) { return _mm256_extractf128_ps (__X, __N); }
inline Vc_INTRINSIC __m128i _extractf128_si256 (__m256i __X, const int __N) { return _mm256_extractf128_si256 (__X, __N); }
inline Vc_INTRINSIC int _extract_epi32 (__m256i __X, int const __N) { return _mm256_extract_epi32 (__X, __N); }
inline Vc_INTRINSIC int _extract_epi16 (__m256i __X, int const __N) { return _mm256_extract_epi16 (__X, __N); }
inline Vc_INTRINSIC int _extract_epi8 (__m256i __X, int const __N) { return _mm256_extract_epi8 (__X, __N); }
#ifdef __x86_64__
inline Vc_INTRINSIC long long __extract_epi64 (__m256i __X, const int __N) { return _mm256_extract_epi64 (__X, __N); }
#endif
inline Vc_INTRINSIC void _zeroall (void) { return _mm256_zeroall (); }
inline Vc_INTRINSIC void _zeroupper (void) { return _mm256_zeroupper (); }
inline Vc_INTRINSIC __m128d rmutevar_pd (__m128d __A, __m128i __C) { return _mm_permutevar_pd (__A, __C); }
inline Vc_INTRINSIC __m256d _permutevar_pd (__m256d __A, __m256i __C) { return _mm256_permutevar_pd (__A, __C); }
inline Vc_INTRINSIC __m128 rmutevar_ps (__m128 __A, __m128i __C) { return _mm_permutevar_ps (__A, __C); }
inline Vc_INTRINSIC __m256 _permutevar_ps (__m256 __A, __m256i __C) { return _mm256_permutevar_ps (__A, __C); }
inline Vc_INTRINSIC __m128d _permute_pd (__m128d __X, const int __C) { return _mm_permute_pd (__X, __C); }
inline Vc_INTRINSIC __m256d _permute_pd (__m256d __X, const int __C) { return _mm256_permute_pd (__X, __C); }
inline Vc_INTRINSIC __m128 _permute_ps (__m128 __X, const int __C) { return _mm_permute_ps (__X, __C); }
inline Vc_INTRINSIC __m256 _permute_ps (__m256 __X, const int __C) { return _mm256_permute_ps (__X, __C); }
inline Vc_INTRINSIC __m256d _permute2f128_pd (__m256d __X, __m256d __Y, const int __C) { return _mm256_permute2f128_pd (__X, __Y, __C); }
inline Vc_INTRINSIC __m256 _permute2f128_ps (__m256 __X, __m256 __Y, const int __C) { return _mm256_permute2f128_ps (__X, __Y, __C); }
inline Vc_INTRINSIC __m256i _permute2f128_si256 (__m256i __X, __m256i __Y, const int __C) { return _mm256_permute2f128_si256 (__X, __Y, __C); }
inline Vc_INTRINSIC __m128 _broadcast4 (float const *__X) { return _mm_broadcast_ss (__X); }
inline Vc_INTRINSIC __m256d _broadcast4 (double const *__X) { return _mm256_broadcast_sd (__X); }
inline Vc_INTRINSIC __m256 _broadcast8 (float const *__X) { return _mm256_broadcast_ss (__X); }
inline Vc_INTRINSIC __m256d _broadcast_pd (__m128d const *__X) { return _mm256_broadcast_pd (__X); }
inline Vc_INTRINSIC __m256 _broadcast_ps (__m128 const *__X) { return _mm256_broadcast_ps (__X); }
inline Vc_INTRINSIC __m256d _insertf128_pd (__m256d __X, __m128d __Y, const int __O) { return _mm256_insertf128_pd (__X, __Y, __O); }
inline Vc_INTRINSIC __m256 _insertf128_ps (__m256 __X, __m128 __Y, const int __O) { return _mm256_insertf128_ps (__X, __Y, __O); }
inline Vc_INTRINSIC __m256i _insertf128_si256 (__m256i __X, __m128i __Y, const int __O) { return _mm256_insertf128_si256 (__X, __Y, __O); }
inline Vc_INTRINSIC __m256i _insert_epi32 (__m256i __X, int __D, int const __N) { return _mm256_insert_epi32 (__X, __D, __N); }
inline Vc_INTRINSIC __m256i _insert_epi16 (__m256i __X, int __D, int const __N) { return _mm256_insert_epi16 (__X, __D, __N); }
inline Vc_INTRINSIC __m256i _insert_epi8 (__m256i __X, int __D, int const __N) { return _mm256_insert_epi8 (__X, __D, __N); }
#ifdef __x86_64__
inline Vc_INTRINSIC __m256i _insert_epi64 (__m256i __X, long long __D, int const __N) { return _mm256_insert_epi64 (__X, __D, __N); }
#endif
inline Vc_INTRINSIC __m256d _load_pd (double const *__P) { return _mm256_load_pd (__P); }
inline Vc_INTRINSIC void _store_pd (double *__P, __m256d __A) { return _mm256_store_pd (__P, __A); }
inline Vc_INTRINSIC __m256 _load_ps (float const *__P) { return _mm256_load_ps (__P); }
inline Vc_INTRINSIC void _store_ps (float *__P, __m256 __A) { return _mm256_store_ps (__P, __A); }
inline Vc_INTRINSIC __m256d _loadu_pd (double const *__P) { return _mm256_loadu_pd (__P); }
inline Vc_INTRINSIC void _storeu_pd (double *__P, __m256d __A) { return _mm256_storeu_pd (__P, __A); }
inline Vc_INTRINSIC __m256 _loadu_ps (float const *__P) { return _mm256_loadu_ps (__P); }
inline Vc_INTRINSIC void _storeu_ps (float *__P, __m256 __A) { return _mm256_storeu_ps (__P, __A); }
inline Vc_INTRINSIC __m256i _load_si256 (__m256i const *__P) { return _mm256_load_si256 (__P); }
inline Vc_INTRINSIC void _store_si256 (__m256i *__P, __m256i __A) { return _mm256_store_si256 (__P, __A); }
inline Vc_INTRINSIC __m256i _loadu_si256 (__m256i const *__P) { return _mm256_loadu_si256 (__P); }
inline Vc_INTRINSIC void _storeu_si256 (__m256i *__P, __m256i __A) { return _mm256_storeu_si256 (__P, __A); }
inline Vc_INTRINSIC __m128d _maskload_pd (double const *__P, __m128i __M) { return _mm_maskload_pd (__P, __M); }
inline Vc_INTRINSIC void _maskstore_pd (double *__P, __m128i __M, __m128d __A) { return _mm_maskstore_pd (__P, __M, __A); }
inline Vc_INTRINSIC __m256d _maskload_pd (double const *__P, __m256i __M) { return _mm256_maskload_pd (__P, __M); }
inline Vc_INTRINSIC void _maskstore_pd (double *__P, __m256i __M, __m256d __A) { return _mm256_maskstore_pd (__P, __M, __A); }
inline Vc_INTRINSIC __m128 _maskload_ps (float const *__P, __m128i __M) { return _mm_maskload_ps (__P, __M); }
inline Vc_INTRINSIC void _maskstore_ps (float *__P, __m128i __M, __m128 __A) { return _mm_maskstore_ps (__P, __M, __A); }
inline Vc_INTRINSIC __m256 _maskload_ps (float const *__P, __m256i __M) { return _mm256_maskload_ps (__P, __M); }
inline Vc_INTRINSIC void _maskstore_ps (float *__P, __m256i __M, __m256 __A) { return _mm256_maskstore_ps (__P, __M, __A); }
inline Vc_INTRINSIC __m256 _movehdup_ps (__m256 __X) { return _mm256_movehdup_ps (__X); }
inline Vc_INTRINSIC __m256 _moveldup_ps (__m256 __X) { return _mm256_moveldup_ps (__X); }
inline Vc_INTRINSIC __m256d _movedup_pd (__m256d __X) { return _mm256_movedup_pd (__X); }
inline Vc_INTRINSIC __m256i _lddqu_si256 (__m256i const *__P) { return _mm256_lddqu_si256 (__P); }
inline Vc_INTRINSIC void _stream_si256 (__m256i *__A, __m256i __B) { return _mm256_stream_si256 (__A, __B); }
inline Vc_INTRINSIC void _stream_pd (double *__A, __m256d __B) { return _mm256_stream_pd (__A, __B); }
inline Vc_INTRINSIC void _stream_ps (float *__P, __m256 __A) { return _mm256_stream_ps (__P, __A); }
inline Vc_INTRINSIC __m256 _rcp_ps (__m256 __A) { return _mm256_rcp_ps (__A); }
inline Vc_INTRINSIC __m256 _rsqrt_ps (__m256 __A) { return _mm256_rsqrt_ps (__A); }
inline Vc_INTRINSIC __m256d _sqrt_pd (__m256d __A) { return _mm256_sqrt_pd (__A); }
inline Vc_INTRINSIC __m256 _sqrt_ps (__m256 __A) { return _mm256_sqrt_ps (__A); }
inline Vc_INTRINSIC __m256d _round_pd (__m256d __V, const int __M) { return _mm256_round_pd (__V, __M); }
inline Vc_INTRINSIC __m256 _round_ps (__m256 __V, const int __M) { return _mm256_round_ps (__V, __M); }
inline Vc_INTRINSIC __m256d _ceil_pd (__m256d V) { return _mm256_round_pd (V, _MM_FROUND_CEIL); }
inline Vc_INTRINSIC __m256d _floor_pd(__m256d V) { return _mm256_round_pd (V, _MM_FROUND_FLOOR); }
inline Vc_INTRINSIC __m256  _ceil_ps (__m256  V) { return _mm256_round_ps (V, _MM_FROUND_CEIL); }
inline Vc_INTRINSIC __m256  _floor_ps(__m256  V) { return _mm256_round_ps (V, _MM_FROUND_FLOOR); }
inline Vc_INTRINSIC __m256d _unpackhi_pd (__m256d __A, __m256d __B) { return _mm256_unpackhi_pd (__A, __B); }
inline Vc_INTRINSIC __m256d _unpacklo_pd (__m256d __A, __m256d __B) { return _mm256_unpacklo_pd (__A, __B); }
inline Vc_INTRINSIC __m256 _unpackhi_ps (__m256 __A, __m256 __B) { return _mm256_unpackhi_ps (__A, __B); }
inline Vc_INTRINSIC __m256 _unpacklo_ps (__m256 __A, __m256 __B) { return _mm256_unpacklo_ps (__A, __B); }
inline Vc_INTRINSIC int _testz_pd (__m128d __M, __m128d __V) { return _mm_testz_pd (__M, __V); }
inline Vc_INTRINSIC int _testc_pd (__m128d __M, __m128d __V) { return _mm_testc_pd (__M, __V); }
inline Vc_INTRINSIC int _testnzc_pd (__m128d __M, __m128d __V) { return _mm_testnzc_pd (__M, __V); }
inline Vc_INTRINSIC int _testz_ps (__m128 __M, __m128 __V) { return _mm_testz_ps (__M, __V); }
inline Vc_INTRINSIC int _testc_ps (__m128 __M, __m128 __V) { return _mm_testc_ps (__M, __V); }
inline Vc_INTRINSIC int _testnzc_ps (__m128 __M, __m128 __V) { return _mm_testnzc_ps (__M, __V); }
inline Vc_INTRINSIC int _testz_pd (__m256d __M, __m256d __V) { return _mm256_testz_pd (__M, __V); }
inline Vc_INTRINSIC int _testc_pd (__m256d __M, __m256d __V) { return _mm256_testc_pd (__M, __V); }
inline Vc_INTRINSIC int _testnzc_pd (__m256d __M, __m256d __V) { return _mm256_testnzc_pd (__M, __V); }
inline Vc_INTRINSIC int _testz_ps (__m256 __M, __m256 __V) { return _mm256_testz_ps (__M, __V); }
inline Vc_INTRINSIC int _testc_ps (__m256 __M, __m256 __V) { return _mm256_testc_ps (__M, __V); }
inline Vc_INTRINSIC int _testnzc_ps (__m256 __M, __m256 __V) { return _mm256_testnzc_ps (__M, __V); }
inline Vc_INTRINSIC int _testz_si256 (__m256i __M, __m256i __V) { return _mm256_testz_si256 (__M, __V); }
inline Vc_INTRINSIC int _testc_si256 (__m256i __M, __m256i __V) { return _mm256_testc_si256 (__M, __V); }
inline Vc_INTRINSIC int _testnzc_si256 (__m256i __M, __m256i __V) { return _mm256_testnzc_si256 (__M, __V); }
inline Vc_INTRINSIC int _movemask_pd (__m256d __A) { return _mm256_movemask_pd (__A); }
inline Vc_INTRINSIC int _movemask_ps (__m256 __A) { return _mm256_movemask_ps (__A); }
inline Vc_INTRINSIC __m256d _setzero_pd (void) { return _mm256_setzero_pd (); }
inline Vc_INTRINSIC __m256 _setzero_ps (void) { return _mm256_setzero_ps (); }
inline Vc_INTRINSIC __m256i _setzero_si256 (void) { return _mm256_setzero_si256 (); }
inline Vc_INTRINSIC __m256d _set_pd (double __A, double __B, double __C, double __D) { return _mm256_set_pd (__A, __B, __C, __D); }
inline Vc_INTRINSIC __m256 _set_ps (float __A, float __B, float __C, float __D, float __E, float __F, float __G, float __H) {
    return _mm256_set_ps (__A, __B, __C, __D, __E, __F, __G, __H);
}
inline Vc_INTRINSIC __m256i _set_epi32 (int __A, int __B, int __C, int __D, int __E, int __F, int __G, int __H) {
    return _mm256_set_epi32 (__A, __B, __C, __D, __E, __F, __G, __H);
}
inline Vc_INTRINSIC __m256i _set_epi16 (short __q15, short __q14, short __q13, short __q12, short __q11, short __q10, short __q09, short __q08,
        short __q07, short __q06, short __q05, short __q04, short __q03, short __q02, short __q01, short __q00) {
    return _mm256_set_epi16 (__q15, __q14, __q13, __q12, __q11, __q10, __q09, __q08,
            __q07, __q06, __q05, __q04, __q03, __q02, __q01, __q00);
}
inline Vc_INTRINSIC __m256i _set_epi8  (char __q31, char __q30, char __q29, char __q28, char __q27,
        char __q26, char __q25, char __q24, char __q23, char __q22, char __q21, char __q20, char __q19,
        char __q18, char __q17, char __q16, char __q15, char __q14, char __q13, char __q12, char __q11,
        char __q10, char __q09, char __q08, char __q07, char __q06, char __q05, char __q04, char __q03,
        char __q02, char __q01, char __q00) {
    return _mm256_set_epi8(__q31, __q30, __q29, __q28, __q27, __q26, __q25, __q24, __q23, __q22,
            __q21, __q20, __q19, __q18, __q17, __q16, __q15, __q14, __q13, __q12, __q11, __q10, __q09,
            __q08, __q07, __q06, __q05, __q04, __q03, __q02, __q01, __q00);
}
inline Vc_INTRINSIC __m256i _set_epi64x (long long __A, long long __B, long long __C, long long __D) {
    return _mm256_set_epi64x (__A, __B, __C, __D);
}
inline Vc_INTRINSIC __m256d _set1_pd (double __A) { return _mm256_set1_pd (__A); }
inline Vc_INTRINSIC __m256 _set1_ps (float __A) { return _mm256_set1_ps (__A); }
inline Vc_INTRINSIC __m256i _set1_epi32 (int __A) { return _mm256_set1_epi32 (__A); }
inline Vc_INTRINSIC __m256i _set1_epi16 (short __A) { return _mm256_set1_epi16 (__A); }
inline Vc_INTRINSIC __m256i _set1_epi8 (char __A) { return _mm256_set1_epi8 (__A); }
inline Vc_INTRINSIC __m256i _set1_epi64x (long long __A) { return _mm256_set1_epi64x (__A); }
inline Vc_INTRINSIC __m256d _setr_pd (double __A, double __B, double __C, double __D) { return _mm256_setr_pd (__A, __B, __C, __D); }
inline Vc_INTRINSIC __m256 _setr_ps (float __A, float __B, float __C, float __D, float __E, float __F, float __G, float __H) {
    return _mm256_setr_ps (__A, __B, __C, __D, __E, __F, __G, __H);
}
inline Vc_INTRINSIC __m256i _setr_epi32 (int __A, int __B, int __C, int __D, int __E, int __F, int __G, int __H) {
    return _mm256_setr_epi32 (__A, __B, __C, __D, __E, __F, __G, __H);
}
inline Vc_INTRINSIC __m256i _setr_epi16 (short __q15, short __q14, short __q13, short __q12, short __q11,
        short __q10, short __q09, short __q08, short __q07, short __q06, short __q05, short __q04,
        short __q03, short __q02, short __q01, short __q00) {
    return _mm256_setr_epi16 (__q15, __q14, __q13, __q12, __q11, __q10, __q09, __q08, __q07, __q06,
            __q05, __q04, __q03, __q02, __q01, __q00);
}
inline Vc_INTRINSIC __m256i _setr_epi8  (char __q31, char __q30, char __q29, char __q28, char __q27,
        char __q26, char __q25, char __q24, char __q23, char __q22, char __q21, char __q20, char __q19,
        char __q18, char __q17, char __q16, char __q15, char __q14, char __q13, char __q12, char __q11,
        char __q10, char __q09, char __q08, char __q07, char __q06, char __q05, char __q04, char __q03,
        char __q02, char __q01, char __q00) {
    return _mm256_setr_epi8  (__q31, __q30, __q29, __q28, __q27, __q26, __q25, __q24, __q23, __q22,
            __q21, __q20, __q19, __q18, __q17, __q16, __q15, __q14, __q13, __q12, __q11, __q10, __q09,
            __q08, __q07, __q06, __q05, __q04, __q03, __q02, __q01, __q00);
}
inline Vc_INTRINSIC __m256i _setr_epi64x (long long __A, long long __B, long long __C, long long __D) {
    return _mm256_setr_epi64x (__A, __B, __C, __D);
}
/* Casts between various SP, DP, INT vector types.  Note that these do no
   conversion of values, they just change the type.  */
inline Vc_INTRINSIC __m256 _castpd_ps (__m256d __A) { return _mm256_castpd_ps (__A); }
inline Vc_INTRINSIC __m256i _castpd_si256 (__m256d __A) { return _mm256_castpd_si256 (__A); }
inline Vc_INTRINSIC __m256d _castps_pd (__m256 __A) { return _mm256_castps_pd (__A); }
inline Vc_INTRINSIC __m256i _castps_si256(__m256 __A) { return _mm256_castps_si256(__A); }
inline Vc_INTRINSIC __m256 _castsi256_ps (__m256i __A) { return _mm256_castsi256_ps (__A); }
inline Vc_INTRINSIC __m256d _castsi256_pd (__m256i __A) { return _mm256_castsi256_pd (__A); }
inline Vc_INTRINSIC __m128d _castpd256_pd128 (__m256d __A) { return _mm256_castpd256_pd128 (__A); }
inline Vc_INTRINSIC __m128 _castps256_ps128 (__m256 __A) { return _mm256_castps256_ps128 (__A); }
inline Vc_INTRINSIC __m128i _castsi256_si128 (__m256i __A) { return _mm256_castsi256_si128 (__A); }
inline Vc_INTRINSIC __m256d _castpd128_pd256 (__m128d __A) { return _mm256_castpd128_pd256 (__A); }
inline Vc_INTRINSIC __m256 _castps128_ps256 (__m128 __A) { return _mm256_castps128_ps256 (__A); }
inline Vc_INTRINSIC __m256i _castsi128_si256 (__m128i __A) { return _mm256_castsi128_si256 (__A); }
#include "undomacros.h"

#if (defined(VC_IMPL_XOP) || defined(VC_IMPL_FMA4)) && !defined(VC_MSVC)
#include <x86intrin.h>
#endif
#if defined(VC_CLANG) && VC_CLANG < 0x30100
// _mm_permute_ps is broken: http://llvm.org/bugs/show_bug.cgi?id=12401
#undef _mm_permute_ps
#define _mm_permute_ps(A, C) __extension__ ({ \
  __m128 __A = (A); \
  (__m128)__builtin_shufflevector((__v4sf)__A, (__v4sf) _mm_setzero_ps(), \
                                   (C) & 0x3, ((C) & 0xc) >> 2, \
                                   ((C) & 0x30) >> 4, ((C) & 0xc0) >> 6); })
#endif
#include <Vc/global.h>
#include "const_data.h"
#include "macros.h"
#include <cstdlib>
#if defined(VC_CLANG) || defined(VC_MSVC) || (defined(VC_GCC) && !defined(__OPTIMIZE__))
#define VC_REQUIRES_MACRO_FOR_IMMEDIATE_ARGUMENT
#endif
#if defined(VC_CLANG) && VC_CLANG <= 0x30000
// _mm_alignr_epi8 doesn't specify its return type, thus breaking overload resolution
#undef _mm_alignr_epi8
#define _mm_alignr_epi8(a, b, n) ((__m128i)__builtin_ia32_palignr128((a), (b), (n)))
#endif
namespace Vc
{
namespace AVX
{
#if defined(VC_GNU_ASM) && !defined(NVALGRIND)
    static inline __m128i Vc_CONST _mm_setallone() { __m128i r; __asm__("pcmpeqb %0,%0":"=x"(r)); return r; }
#else
    static inline __m128i Vc_CONST _mm_setallone() { __m128i r = _mm_setzero_si128(); return _mm_cmpeq_epi8(r, r); }
#endif
    static inline __m128i Vc_CONST _mm_setallone_si128() { return _mm_setallone(); }
    static inline __m128d Vc_CONST _mm_setallone_pd() { return _mm_castsi128_pd(_mm_setallone()); }
    static inline __m128  Vc_CONST _mm_setallone_ps() { return _mm_castsi128_ps(_mm_setallone()); }
    static inline __m128i Vc_CONST _mm_setone_epi8 ()  { return _mm_set1_epi8(1); }
    static inline __m128i Vc_CONST _mm_setone_epu8 ()  { return _mm_setone_epi8(); }
    static inline __m128i Vc_CONST _mm_setone_epi16()  { return _mm_castps_si128(_mm_broadcast_ss(reinterpret_cast<const float *>(c_general::one16))); }
    static inline __m128i Vc_CONST _mm_setone_epu16()  { return _mm_setone_epi16(); }
    static inline __m128i Vc_CONST _mm_setone_epi32()  { return _mm_castps_si128(_mm_broadcast_ss(reinterpret_cast<const float *>(&_IndexesFromZero32[1]))); }
#if defined(VC_GNU_ASM) && !defined(NVALGRIND)
    static inline __m256 Vc_CONST _setallone() { __m256 r; __asm__("vcmpps $8,%0,%0,%0":"=x"(r)); return r; }
#else
    static inline __m256 Vc_CONST _setallone() { __m256 r = _setzero_ps(); return _cmp_ps(r, r, _CMP_EQ_UQ); }
#endif
    static inline __m256i Vc_CONST _setallone_si256() { return _castps_si256(_setallone()); }
    static inline __m256d Vc_CONST _setallone_pd() { return _castps_pd(_setallone()); }
    static inline __m256  Vc_CONST _setallone_ps() { return _setallone(); }
    static inline __m256i Vc_CONST _setone_epi8 ()  { return _set1_epi8(1); }
    static inline __m256i Vc_CONST _setone_epu8 ()  { return _setone_epi8(); }
    static inline __m256i Vc_CONST _setone_epi16()  { return _castps_si256(_mm256_broadcast_ss(reinterpret_cast<const float *>(c_general::one16))); }
    static inline __m256i Vc_CONST _setone_epu16()  { return _setone_epi16(); }
    static inline __m256i Vc_CONST _setone_epi32()  { return _castps_si256(_mm256_broadcast_ss(reinterpret_cast<const float *>(&_IndexesFromZero32[1]))); }
    static inline __m256i Vc_CONST _setone_epu32()  { return _setone_epi32(); }
    static inline __m256  Vc_CONST _setone_ps()     { return _mm256_broadcast_ss(&c_general::oneFloat); }
    static inline __m256d Vc_CONST _setone_pd()     { return _mm256_broadcast_sd(&c_general::oneDouble); }
    static inline __m256d Vc_CONST _setabsmask_pd() { return _mm256_broadcast_sd(reinterpret_cast<const double *>(&c_general::absMaskFloat[0])); }
    static inline __m256  Vc_CONST _setabsmask_ps() { return _mm256_broadcast_ss(reinterpret_cast<const float *>(&c_general::absMaskFloat[1])); }
    static inline __m256d Vc_CONST _setsignmask_pd(){ return _mm256_broadcast_sd(reinterpret_cast<const double *>(&c_general::signMaskFloat[0])); }
    static inline __m256  Vc_CONST _setsignmask_ps(){ return _mm256_broadcast_ss(reinterpret_cast<const float *>(&c_general::signMaskFloat[1])); }
    static inline __m256  Vc_CONST _set2power31_ps()    { return _mm256_broadcast_ss(&c_general::_2power31); }
    static inline __m256i Vc_CONST _set2power31_epu32() { return _castps_si256(_mm256_broadcast_ss(reinterpret_cast<const float *>(&c_general::signMaskFloat[1]))); }
    //X         static inline __m256i Vc_CONST _mm256_setmin_epi8 () { return _mm256_slli_epi8 (_mm256_setallone_si256(),  7); }
    static inline __m128i Vc_CONST _mm_setmin_epi16() { return _mm_castps_si128(_mm_broadcast_ss(reinterpret_cast<const float *>(c_general::minShort))); }
    static inline __m128i Vc_CONST _mm_setmin_epi32() { return _mm_castps_si128(_mm_broadcast_ss(reinterpret_cast<const float *>(&c_general::signMaskFloat[1]))); }
    static inline __m256i Vc_CONST _setmin_epi16() { return _castps_si256(_mm256_broadcast_ss(reinterpret_cast<const float *>(c_general::minShort))); }
    static inline __m256i Vc_CONST _setmin_epi32() { return _castps_si256(_mm256_broadcast_ss(reinterpret_cast<const float *>(&c_general::signMaskFloat[1]))); }
#ifdef VC_REQUIRES_MACRO_FOR_IMMEDIATE_ARGUMENT
#define _mm_extract_epu8 _mm_extract_epi8
#define _mm_extract_epu16 _mm_extract_epi16
#define _mm_extract_epu32 _mm_extract_epi32
#else
    static inline unsigned char Vc_INTRINSIC Vc_CONST _mm_extract_epu8(__m128i x, const int i) { return _mm_extract_epi8(x, i); }
    static inline unsigned short Vc_INTRINSIC Vc_CONST _mm_extract_epu16(__m128i x, const int i) { return _mm_extract_epi16(x, i); }
    static inline unsigned int Vc_INTRINSIC Vc_CONST _mm_extract_epu32(__m128i x, const int i) { return _mm_extract_epi32(x, i); }
#endif
    /////////////////////// COMPARE OPS ///////////////////////
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmpeq_pd   (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_EQ_OQ); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmpneq_pd  (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_NEQ_UQ); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmplt_pd   (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_LT_OS); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmpnlt_pd  (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_NLT_US); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmple_pd   (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_LE_OS); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmpnle_pd  (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_NLE_US); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmpord_pd  (__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_ORD_Q); }
    static inline __m256d Vc_INTRINSIC Vc_CONST _cmpunord_pd(__m256d a, __m256d b) { return _cmp_pd(a, b, _CMP_UNORD_Q); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpeq_ps   (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_EQ_OQ); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpneq_ps  (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_NEQ_UQ); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmplt_ps   (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_LT_OS); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpnlt_ps  (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_NLT_US); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpge_ps   (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_NLT_US); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmple_ps   (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_LE_OS); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpnle_ps  (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_NLE_US); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpgt_ps   (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_NLE_US); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpord_ps  (__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_ORD_Q); }
    static inline __m256  Vc_INTRINSIC Vc_CONST _cmpunord_ps(__m256  a, __m256  b) { return _cmp_ps(a, b, _CMP_UNORD_Q); }
    static inline __m128i _mm_cmplt_epu16(__m128i a, __m128i b) {
        return _mm_cmplt_epi16(_mm_xor_si128(a, _mm_setmin_epi16()), _mm_xor_si128(b, _mm_setmin_epi16()));
    }
    static inline __m128i _mm_cmpgt_epu16(__m128i a, __m128i b) {
        return _mm_cmpgt_epi16(_mm_xor_si128(a, _mm_setmin_epi16()), _mm_xor_si128(b, _mm_setmin_epi16()));
    }
    /////////////////////// INTEGER OPS ///////////////////////
#define AVX_TO_SSE_2(name) \
    static inline __m256i Vc_INTRINSIC Vc_CONST _##name(__m256i a0, __m256i b0) { \
        __m128i a1 = _extractf128_si256(a0, 1); \
        __m128i b1 = _extractf128_si256(b0, 1); \
        __m128i r0 = _mm_##name(_castsi256_si128(a0), _castsi256_si128(b0)); \
        __m128i r1 = _mm_##name(a1, b1); \
        return _insertf128_si256(_castsi128_si256(r0), r1, 1); \
    }
#define AVX_TO_SSE_2_si128_si256(name) \
    static inline __m256i Vc_INTRINSIC Vc_CONST _##name##_si256(__m256i a0, __m256i b0) { \
        __m128i a1 = _extractf128_si256(a0, 1); \
        __m128i b1 = _extractf128_si256(b0, 1); \
        __m128i r0 = _mm_##name##_si128(_castsi256_si128(a0), _castsi256_si128(b0)); \
        __m128i r1 = _mm_##name##_si128(a1, b1); \
        return _insertf128_si256(_castsi128_si256(r0), r1, 1); \
    }
#define AVX_TO_SSE_1(name) \
    static inline __m256i Vc_INTRINSIC Vc_CONST _##name(__m256i a0) { \
        __m128i a1 = _extractf128_si256(a0, 1); \
        __m128i r0 = _mm_##name(_castsi256_si128(a0)); \
        __m128i r1 = _mm_##name(a1); \
        return _insertf128_si256(_castsi128_si256(r0), r1, 1); \
    }
#define AVX_TO_SSE_1i(name) \
    static inline __m256i Vc_INTRINSIC Vc_CONST _##name(__m256i a0, const int i) { \
        __m128i a1 = _extractf128_si256(a0, 1); \
        __m128i r0 = _mm_##name(_castsi256_si128(a0), i); \
        __m128i r1 = _mm_##name(a1, i); \
        return _insertf128_si256(_castsi128_si256(r0), r1, 1); \
    }
    AVX_TO_SSE_2(cmplt_epi8)
    AVX_TO_SSE_2(cmplt_epi16)
    AVX_TO_SSE_2(cmplt_epi32)
#ifndef VC_UNCONDINTIONAL_AVX2_INTRINSICS
    AVX_TO_SSE_2(cmpeq_epi8)
    AVX_TO_SSE_2(cmpeq_epi16)
    AVX_TO_SSE_2(cmpeq_epi32)
    AVX_TO_SSE_2(cmpgt_epi8)
    AVX_TO_SSE_2(cmpgt_epi16)
    AVX_TO_SSE_2(cmpgt_epi32)
#ifdef VC_REQUIRES_MACRO_FOR_IMMEDIATE_ARGUMENT
#   define _srli_si256(a, i) \
        _insertf128_si256( \
                _castsi128_si256(_mm_srli_si128(_castsi256_si128((a)), i)), \
                _mm_srli_si128(_extractf128_si256((a), 1), i), 1);
#   define _slli_si256(a, i) \
        _insertf128_si256( \
                _castsi128_si256( _mm_slli_si128(_castsi256_si128((a)), i)), \
                _mm_slli_si128(_extractf128_si256((a), 1), i), 1);
#else
    static inline __m256i Vc_INTRINSIC Vc_CONST _srli_si256(__m256i a0, const int i) {
        const __m128i r0 = _mm_srli_si128(_castsi256_si128(a0), i);
        const __m128i r1 = _mm_srli_si128(_extractf128_si256(a0, 1), i);
        return _insertf128_si256(_castsi128_si256(r0), r1, 1);
    }
    static inline __m256i Vc_INTRINSIC Vc_CONST _slli_si256(__m256i a0, const int i) {
        const __m128i r0 = _mm_slli_si128(_castsi256_si128(a0), i);
        const __m128i r1 = _mm_slli_si128(_extractf128_si256(a0, 1), i);
        return _insertf128_si256(_castsi128_si256(r0), r1, 1);
    }
#endif
    static inline __m256i Vc_INTRINSIC Vc_CONST _and_si256(__m256i x, __m256i y) {
        return _castps_si256(_and_ps(_castsi256_ps(x), _castsi256_ps(y)));
    }
    static inline __m256i Vc_INTRINSIC Vc_CONST _andnot_si256(__m256i x, __m256i y) {
        return _castps_si256(_andnot_ps(_castsi256_ps(x), _castsi256_ps(y)));
    }
    static inline __m256i Vc_INTRINSIC Vc_CONST _or_si256(__m256i x, __m256i y) {
        return _castps_si256(_or_ps(_castsi256_ps(x), _castsi256_ps(y)));
    }
    static inline __m256i Vc_INTRINSIC Vc_CONST _xor_si256(__m256i x, __m256i y) {
        return _castps_si256(_xor_ps(_castsi256_ps(x), _castsi256_ps(y)));
    }
    AVX_TO_SSE_2(packs_epi16)
    AVX_TO_SSE_2(packs_epi32)
    AVX_TO_SSE_2(packus_epi16)
    AVX_TO_SSE_2(unpackhi_epi8)
    AVX_TO_SSE_2(unpackhi_epi16)
    AVX_TO_SSE_2(unpackhi_epi32)
    AVX_TO_SSE_2(unpackhi_epi64)
    AVX_TO_SSE_2(unpacklo_epi8)
    AVX_TO_SSE_2(unpacklo_epi16)
    AVX_TO_SSE_2(unpacklo_epi32)
    AVX_TO_SSE_2(unpacklo_epi64)
    AVX_TO_SSE_2(add_epi8)
    AVX_TO_SSE_2(add_epi16)
    AVX_TO_SSE_2(add_epi32)
    AVX_TO_SSE_2(add_epi64)
    AVX_TO_SSE_2(adds_epi8)
    AVX_TO_SSE_2(adds_epi16)
    AVX_TO_SSE_2(adds_epu8)
    AVX_TO_SSE_2(adds_epu16)
    AVX_TO_SSE_2(sub_epi8)
    AVX_TO_SSE_2(sub_epi16)
    AVX_TO_SSE_2(sub_epi32)
    AVX_TO_SSE_2(sub_epi64)
    AVX_TO_SSE_2(subs_epi8)
    AVX_TO_SSE_2(subs_epi16)
    AVX_TO_SSE_2(subs_epu8)
    AVX_TO_SSE_2(subs_epu16)
    AVX_TO_SSE_2(madd_epi16)
    AVX_TO_SSE_2(mulhi_epi16)
    AVX_TO_SSE_2(mullo_epi16)
    AVX_TO_SSE_2(mul_epu32)
    AVX_TO_SSE_1i(slli_epi16)
    AVX_TO_SSE_1i(slli_epi32)
    AVX_TO_SSE_1i(slli_epi64)
    AVX_TO_SSE_1i(srai_epi16)
    AVX_TO_SSE_1i(srai_epi32)
    AVX_TO_SSE_1i(srli_epi16)
    AVX_TO_SSE_1i(srli_epi32)
    AVX_TO_SSE_1i(srli_epi64)
    AVX_TO_SSE_2(sll_epi16)
    AVX_TO_SSE_2(sll_epi32)
    AVX_TO_SSE_2(sll_epi64)
    AVX_TO_SSE_2(sra_epi16)
    AVX_TO_SSE_2(sra_epi32)
    AVX_TO_SSE_2(srl_epi16)
    AVX_TO_SSE_2(srl_epi32)
    AVX_TO_SSE_2(srl_epi64)
    AVX_TO_SSE_2(max_epi16)
    AVX_TO_SSE_2(max_epu8)
    AVX_TO_SSE_2(min_epi16)
    AVX_TO_SSE_2(min_epu8)
    inline int Vc_INTRINSIC Vc_CONST _movemask_epi8(__m256i a0)
    {
        __m128i a1 = _extractf128_si256(a0, 1);
        return (_mm_movemask_epi8(a1) << 16) | _mm_movemask_epi8(_castsi256_si128(a0));
    }
    AVX_TO_SSE_2(mulhi_epu16)
    // shufflehi_epi16
    // shufflelo_epi16 (__m128i __A, const int __mask)
    // shuffle_epi32 (__m128i __A, const int __mask)
    // maskmoveu_si128 (__m128i __A, __m128i __B, char *__C)
    AVX_TO_SSE_2(avg_epu8)
    AVX_TO_SSE_2(avg_epu16)
    AVX_TO_SSE_2(sad_epu8)
    // stream_si32 (int *__A, int __B)
    // stream_si128 (__m128i *__A, __m128i __B)
    // cvtsi32_si128 (int __A)
    // cvtsi64_si128 (long long __A)
    // cvtsi64x_si128 (long long __A)
    AVX_TO_SSE_2(hadd_epi16)
    AVX_TO_SSE_2(hadd_epi32)
    AVX_TO_SSE_2(hadds_epi16)
    AVX_TO_SSE_2(hsub_epi16)
    AVX_TO_SSE_2(hsub_epi32)
    AVX_TO_SSE_2(hsubs_epi16)
    AVX_TO_SSE_2(maddubs_epi16)
    AVX_TO_SSE_2(mulhrs_epi16)
    AVX_TO_SSE_2(shuffle_epi8)
    AVX_TO_SSE_2(sign_epi8)
    AVX_TO_SSE_2(sign_epi16)
    AVX_TO_SSE_2(sign_epi32)
    // alignr_epi8(__m128i __X, __m128i __Y, const int __N)
    AVX_TO_SSE_1(abs_epi8)
    AVX_TO_SSE_1(abs_epi16)
    AVX_TO_SSE_1(abs_epi32)
#if !defined(VC_REQUIRES_MACRO_FOR_IMMEDIATE_ARGUMENT)
    __m256i inline Vc_INTRINSIC Vc_CONST _blend_epi16(__m256i a0, __m256i b0, const int m) {
        __m128i a1 = _extractf128_si256(a0, 1);
        __m128i b1 = _extractf128_si256(b0, 1);
        __m128i r0 = _mm_blend_epi16(_castsi256_si128(a0), _castsi256_si128(b0), m & 0xff);
        __m128i r1 = _mm_blend_epi16(a1, b1, m >> 8);
        return _insertf128_si256(_castsi128_si256(r0), r1, 1);
    }
#else
#   define _blend_epi16(a0, b0, m) \
    _insertf128_si256( \
            _castsi128_si256( \
                _mm_blend_epi16( \
                    _castsi256_si128(a0), _castsi256_si128(b0), m & 0xff)), \
            _mm_blend_epi16(_extractf128_si256(a0, 1), _extractf128_si256(b0, 1), m >> 8);, 1)
#endif
    inline __m256i Vc_INTRINSIC Vc_CONST _blendv_epi8(__m256i a0, __m256i b0, __m256i m0) {
        __m128i a1 = _extractf128_si256(a0, 1);
        __m128i b1 = _extractf128_si256(b0, 1);
        __m128i m1 = _extractf128_si256(m0, 1);
        __m128i r0 = _mm_blendv_epi8(_castsi256_si128(a0), _castsi256_si128(b0), _castsi256_si128(m0));
        __m128i r1 = _mm_blendv_epi8(a1, b1, m1);
        return _insertf128_si256(_castsi128_si256(r0), r1, 1);
    }
    AVX_TO_SSE_2(cmpeq_epi64)
    AVX_TO_SSE_2(min_epi8)
    AVX_TO_SSE_2(max_epi8)
    AVX_TO_SSE_2(min_epu16)
    AVX_TO_SSE_2(max_epu16)
    AVX_TO_SSE_2(min_epi32)
    AVX_TO_SSE_2(max_epi32)
    AVX_TO_SSE_2(min_epu32)
    AVX_TO_SSE_2(max_epu32)
    AVX_TO_SSE_2(mullo_epi32)
    AVX_TO_SSE_2(mul_epi32)
#if !defined(VC_CLANG) || VC_CLANG > 0x30100
    // clang is missing _mm_minpos_epu16 from smmintrin.h
    // http://llvm.org/bugs/show_bug.cgi?id=12399
    AVX_TO_SSE_1(minpos_epu16)
#endif
    AVX_TO_SSE_1(cvtepi8_epi32)
    AVX_TO_SSE_1(cvtepi16_epi32)
    AVX_TO_SSE_1(cvtepi8_epi64)
    AVX_TO_SSE_1(cvtepi32_epi64)
    AVX_TO_SSE_1(cvtepi16_epi64)
    AVX_TO_SSE_1(cvtepi8_epi16)
    AVX_TO_SSE_1(cvtepu8_epi32)
    AVX_TO_SSE_1(cvtepu16_epi32)
    AVX_TO_SSE_1(cvtepu8_epi64)
    AVX_TO_SSE_1(cvtepu32_epi64)
    AVX_TO_SSE_1(cvtepu16_epi64)
    AVX_TO_SSE_1(cvtepu8_epi16)
    AVX_TO_SSE_2(packus_epi32)
    // mpsadbw_epu8 (__m128i __X, __m128i __Y, const int __M)
    // stream_load_si128 (__m128i *__X)
    AVX_TO_SSE_2(cmpgt_epi64)
#endif
//X     static inline __m256i _cmplt_epu8 (__m256i a, __m256i b) { return _cmplt_epi8 (
//X             _xor_si256(a, _setmin_epi8 ()), _xor_si256(b, _setmin_epi8 ())); }
//X     static inline __m256i _cmpgt_epu8 (__m256i a, __m256i b) { return _cmpgt_epi8 (
//X             _xor_si256(a, _setmin_epi8 ()), _xor_si256(b, _setmin_epi8 ())); }
    static inline __m256i Vc_CONST _cmplt_epu32(__m256i a, __m256i b) {
        a = _castps_si256(_xor_ps(_castsi256_ps(a), _castsi256_ps(_setmin_epi32())));
        b = _castps_si256(_xor_ps(_castsi256_ps(b), _castsi256_ps(_setmin_epi32())));
        return _insertf128_si256(_castsi128_si256(
                    _mm_cmplt_epi32(_castsi256_si128(a), _castsi256_si128(b))),
                _mm_cmplt_epi32(_extractf128_si256(a, 1), _extractf128_si256(b, 1)), 1);
    }
    static inline __m256i Vc_CONST _cmpgt_epu32(__m256i a, __m256i b) {
        a = _castps_si256(_xor_ps(_castsi256_ps(a), _castsi256_ps(_setmin_epi32())));
        b = _castps_si256(_xor_ps(_castsi256_ps(b), _castsi256_ps(_setmin_epi32())));
        return _insertf128_si256(_castsi128_si256(
                    _mm_cmpgt_epi32(_castsi256_si128(a), _castsi256_si128(b))),
                _mm_cmpgt_epi32(_extractf128_si256(a, 1), _extractf128_si256(b, 1)), 1);
    }
        static inline void Vc_INTRINSIC _maskstore(float *mem, const __m256 mask, const __m256 v) {
#ifndef VC_MM256_MASKSTORE_WRONG_MASK_TYPE
            _maskstore_ps(mem, _castps_si256(mask), v);
#else
            _maskstore_ps(mem, mask, v);
#endif
        }
        static inline void Vc_INTRINSIC _maskstore(double *mem, const __m256d mask, const __m256d v) {
#ifndef VC_MM256_MASKSTORE_WRONG_MASK_TYPE
            _maskstore_pd(mem, _castpd_si256(mask), v);
#else
            _maskstore_pd(mem, mask, v);
#endif
        }
        static inline void Vc_INTRINSIC _maskstore(int *mem, const __m256i mask, const __m256i v) {
#ifndef VC_MM256_MASKSTORE_WRONG_MASK_TYPE
            _maskstore_ps(reinterpret_cast<float *>(mem), mask, _castsi256_ps(v));
#else
            _maskstore_ps(reinterpret_cast<float *>(mem), _castsi256_ps(mask), _castsi256_ps(v));
#endif
        }
        static inline void Vc_INTRINSIC _maskstore(unsigned int *mem, const __m256i mask, const __m256i v) {
            _maskstore(reinterpret_cast<int *>(mem), mask, v);
        }
} // namespace AVX
} // namespace Vc
#include "shuffle.h"
#endif // VC_AVX_INTRINSICS_H
