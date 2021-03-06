/*  This file is part of the Vc library. {{{
Copyright © 2010-2015 Matthias Kretz <kretz@kde.org>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

#ifndef VC_COMMON_MACROS_H_
#define VC_COMMON_MACROS_H_

#include <Vc/global.h>


#ifdef Vc_MSVC
#define Vc_ALIGNED_TYPEDEF(n__, type__, new_type__)                                      \
    typedef __declspec(align(n__)) type__ new_type__
#elif __GNUC__
#define Vc_ALIGNED_TYPEDEF(n__, type__, new_type__)                                      \
    typedef type__ new_type__[[gnu::aligned(n__)]]
#else  // the following is actually ill-formed according to C++1[14]
#define Vc_ALIGNED_TYPEDEF(n__, type__, new_type__)                                      \
    using new_type__ alignas(sizeof(n__)) = type__
#endif

#ifdef Vc_CLANG
#  define Vc_INTRINSIC_L inline
#  define Vc_INTRINSIC_R __attribute__((always_inline))
#  define Vc_INTRINSIC Vc_INTRINSIC_L Vc_INTRINSIC_R
#  define Vc_FLATTEN
#  define Vc_CONST __attribute__((const))
#  define Vc_CONST_L
#  define Vc_CONST_R Vc_CONST
#  define Vc_PURE __attribute__((pure))
#  define Vc_PURE_L
#  define Vc_PURE_R Vc_PURE
#  define Vc_MAY_ALIAS __attribute__((may_alias))
#  define Vc_ALWAYS_INLINE_L inline
#  define Vc_ALWAYS_INLINE_R __attribute__((always_inline))
#  define Vc_ALWAYS_INLINE Vc_ALWAYS_INLINE_L Vc_ALWAYS_INLINE_R
#  define Vc_IS_UNLIKELY(x) __builtin_expect(x, 0)
#  define Vc_IS_LIKELY(x) __builtin_expect(x, 1)
#  define Vc_RESTRICT __restrict__
#  define Vc_DEPRECATED(msg)
#  define Vc_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#elif defined(__GNUC__)
#  if defined Vc_GCC && !defined __OPTIMIZE__
#    define Vc_MAY_ALIAS
#  else
#    define Vc_MAY_ALIAS __attribute__((__may_alias__))
#  endif
#  define Vc_INTRINSIC_R __attribute__((__always_inline__, __artificial__))
#  define Vc_INTRINSIC_L inline
#  define Vc_INTRINSIC Vc_INTRINSIC_L Vc_INTRINSIC_R
#  define Vc_FLATTEN __attribute__((__flatten__))
#  define Vc_ALWAYS_INLINE_L inline
#  define Vc_ALWAYS_INLINE_R __attribute__((__always_inline__))
#  define Vc_ALWAYS_INLINE Vc_ALWAYS_INLINE_L Vc_ALWAYS_INLINE_R
#  ifdef Vc_ICC
     // ICC miscompiles if there are functions marked as pure or const
#    define Vc_PURE
#    define Vc_CONST
#  else
#    define Vc_PURE __attribute__((__pure__))
#    define Vc_CONST __attribute__((__const__))
#  endif
#  define Vc_CONST_L
#  define Vc_CONST_R Vc_CONST
#  define Vc_PURE_L
#  define Vc_PURE_R Vc_PURE
#  define Vc_IS_UNLIKELY(x) __builtin_expect(x, 0)
#  define Vc_IS_LIKELY(x) __builtin_expect(x, 1)
#  define Vc_RESTRICT __restrict__
#  ifdef Vc_ICC
#    define Vc_DEPRECATED(msg)
#  else
#    define Vc_DEPRECATED(msg) __attribute__((__deprecated__(msg)))
#  endif
#  define Vc_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#else
#  define Vc_FLATTEN
#  ifdef Vc_PURE
#    undef Vc_PURE
#  endif
#  define Vc_MAY_ALIAS
#  ifdef Vc_MSVC
#    define Vc_ALWAYS_INLINE inline __forceinline
#    define Vc_ALWAYS_INLINE_L Vc_ALWAYS_INLINE
#    define Vc_ALWAYS_INLINE_R
#    define Vc_CONST __declspec(noalias)
#    define Vc_CONST_L Vc_CONST
#    define Vc_CONST_R
#    define Vc_PURE /*Vc_CONST*/
#    define Vc_PURE_L Vc_PURE
#    define Vc_PURE_R
#    define Vc_INTRINSIC inline __forceinline
#    define Vc_INTRINSIC_L Vc_INTRINSIC
#    define Vc_INTRINSIC_R
#  else
#    define Vc_ALWAYS_INLINE
#    define Vc_ALWAYS_INLINE_L
#    define Vc_ALWAYS_INLINE_R
#    define Vc_CONST
#    define Vc_CONST_L
#    define Vc_CONST_R
#    define Vc_PURE
#    define Vc_PURE_L
#    define Vc_PURE_R
#    define Vc_INTRINSIC
#    define Vc_INTRINSIC_L
#    define Vc_INTRINSIC_R
#  endif
#  define Vc_IS_UNLIKELY(x) x
#  define Vc_IS_LIKELY(x) x
#  define Vc_RESTRICT __restrict
#  define Vc_DEPRECATED(msg) __declspec(deprecated(msg))
#  define Vc_WARN_UNUSED_RESULT
#endif

#define Vc_FREE_STORE_OPERATORS_ALIGNED(alignment) \
        Vc_ALWAYS_INLINE void *operator new(size_t size) { return Vc::Common::aligned_malloc<alignment>(size); } \
        Vc_ALWAYS_INLINE void *operator new(size_t, void *p) { return p; } \
        Vc_ALWAYS_INLINE void *operator new[](size_t size) { return Vc::Common::aligned_malloc<alignment>(size); } \
        Vc_ALWAYS_INLINE void *operator new[](size_t , void *p) { return p; } \
        Vc_ALWAYS_INLINE void operator delete(void *ptr, size_t) { Vc::Common::free(ptr); } \
        Vc_ALWAYS_INLINE void operator delete(void *, void *) {} \
        Vc_ALWAYS_INLINE void operator delete[](void *ptr, size_t) { Vc::Common::free(ptr); } \
        Vc_ALWAYS_INLINE void operator delete[](void *, void *) {}

#ifdef Vc_ASSERT
#define Vc_EXTERNAL_ASSERT 1
#else
#ifdef NDEBUG
#define Vc_ASSERT(x)
#else
#include <assert.h>
#define Vc_ASSERT(x) assert(x);
#endif
#endif

#ifdef Vc_CLANG
#define Vc_HAS_BUILTIN(x) __has_builtin(x)
#else
#define Vc_HAS_BUILTIN(x) 0
#endif

#define Vc_CAT_HELPER_(a, b, c, d) a##b##c##d
#define Vc_CAT(a, b, c, d) Vc_CAT_HELPER_(a, b, c, d)

#define Vc_CAT_IMPL(a, b) a##b
#define Vc_CAT2(a, b) Vc_CAT_IMPL(a, b)

#define Vc_APPLY_IMPL_1_(macro, a, b, c, d, e) macro(a)
#define Vc_APPLY_IMPL_2_(macro, a, b, c, d, e) macro(a, b)
#define Vc_APPLY_IMPL_3_(macro, a, b, c, d, e) macro(a, b, c)
#define Vc_APPLY_IMPL_4_(macro, a, b, c, d, e) macro(a, b, c, d)
#define Vc_APPLY_IMPL_5_(macro, a, b, c, d, e) macro(a, b, c, d, e)

#define Vc_LIST_FLOAT_VECTOR_TYPES(size, macro, a, b, c, d) \
    size(macro, double_v, a, b, c, d) \
    size(macro,  float_v, a, b, c, d)
#define Vc_LIST_INT_VECTOR_TYPES(size, macro, a, b, c, d) \
    size(macro,    int_v, a, b, c, d) \
    size(macro,   uint_v, a, b, c, d) \
    size(macro,  short_v, a, b, c, d) \
    size(macro, ushort_v, a, b, c, d)
#define Vc_LIST_VECTOR_TYPES(size, macro, a, b, c, d) \
    Vc_LIST_FLOAT_VECTOR_TYPES(size, macro, a, b, c, d) \
    Vc_LIST_INT_VECTOR_TYPES(size, macro, a, b, c, d)
#define Vc_LIST_COMPARES(size, macro, a, b, c, d) \
    size(macro, ==, a, b, c, d) \
    size(macro, !=, a, b, c, d) \
    size(macro, <=, a, b, c, d) \
    size(macro, >=, a, b, c, d) \
    size(macro, < , a, b, c, d) \
    size(macro, > , a, b, c, d)
#define Vc_LIST_LOGICAL(size, macro, a, b, c, d) \
    size(macro, &&, a, b, c, d) \
    size(macro, ||, a, b, c, d)
#define Vc_LIST_BINARY(size, macro, a, b, c, d) \
    size(macro, |, a, b, c, d) \
    size(macro, &, a, b, c, d) \
    size(macro, ^, a, b, c, d)
#define Vc_LIST_SHIFTS(size, macro, a, b, c, d) \
    size(macro, <<, a, b, c, d) \
    size(macro, >>, a, b, c, d)
#define Vc_LIST_ARITHMETICS(size, macro, a, b, c, d) \
    size(macro, +, a, b, c, d) \
    size(macro, -, a, b, c, d) \
    size(macro, *, a, b, c, d) \
    size(macro, /, a, b, c, d) \
    size(macro, %, a, b, c, d)

#define Vc_APPLY_0(_list, macro)             _list(Vc_APPLY_IMPL_1_, macro, 0, 0, 0, 0)
#define Vc_APPLY_1(_list, macro, a)          _list(Vc_APPLY_IMPL_2_, macro, a, 0, 0, 0)
#define Vc_APPLY_2(_list, macro, a, b)       _list(Vc_APPLY_IMPL_3_, macro, a, b, 0, 0)
#define Vc_APPLY_3(_list, macro, a, b, c)    _list(Vc_APPLY_IMPL_4_, macro, a, b, c, 0)
#define Vc_APPLY_4(_list, macro, a, b, c, d) _list(Vc_APPLY_IMPL_5_, macro, a, b, c, d)

#define Vc_ALL_COMPARES(macro)     Vc_APPLY_0(Vc_LIST_COMPARES, macro)
#define Vc_ALL_LOGICAL(macro)      Vc_APPLY_0(Vc_LIST_LOGICAL, macro)
#define Vc_ALL_BINARY(macro)       Vc_APPLY_0(Vc_LIST_BINARY, macro)
#define Vc_ALL_SHIFTS(macro)       Vc_APPLY_0(Vc_LIST_SHIFTS, macro)
#define Vc_ALL_ARITHMETICS(macro)  Vc_APPLY_0(Vc_LIST_ARITHMETICS, macro)
#define Vc_ALL_FLOAT_VECTOR_TYPES(macro) Vc_APPLY_0(Vc_LIST_FLOAT_VECTOR_TYPES, macro)
#define Vc_ALL_VECTOR_TYPES(macro) Vc_APPLY_0(Vc_LIST_VECTOR_TYPES, macro)

#define Vc_EXACT_TYPE(_test, _reference, _type) \
    typename std::enable_if<std::is_same<_test, _reference>::value, _type>::type

#ifdef Vc_PASSING_VECTOR_BY_VALUE_IS_BROKEN
#define Vc_ALIGNED_PARAMETER(_Type) const _Type &
#else
#define Vc_ALIGNED_PARAMETER(_Type) const _Type
#endif

#define Vc__make_unique(name) Vc_CAT(Vc__,name,_,__LINE__)

#if defined(Vc_ICC) || defined(Vc_CLANG)
#define Vc_OFFSETOF(Type, member) (reinterpret_cast<const char *>(&reinterpret_cast<const Type *>(0)->member) - reinterpret_cast<const char *>(0))
#elif defined(Vc_GCC) && Vc_GCC < 0x40500
#define Vc_OFFSETOF(Type, member) (reinterpret_cast<const char *>(&reinterpret_cast<const Type *>(0x1000)->member) - reinterpret_cast<const char *>(0x1000))
#else
#define Vc_OFFSETOF(Type, member) offsetof(Type, member)
#endif

#if defined(Vc__NO_NOEXCEPT)
#define Vc_NOEXCEPT throw()
#else
#define Vc_NOEXCEPT noexcept
#endif

#ifdef Vc_NO_ALWAYS_INLINE
#undef Vc_ALWAYS_INLINE
#undef Vc_ALWAYS_INLINE_L
#undef Vc_ALWAYS_INLINE_R
#define Vc_ALWAYS_INLINE inline
#define Vc_ALWAYS_INLINE_L inline
#define Vc_ALWAYS_INLINE_R
#undef Vc_INTRINSIC
#undef Vc_INTRINSIC_L
#undef Vc_INTRINSIC_R
#define Vc_INTRINSIC inline
#define Vc_INTRINSIC_L inline
#define Vc_INTRINSIC_R
#endif

#endif // VC_COMMON_MACROS_H_
