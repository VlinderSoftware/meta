/* Copyright 2016  Vlinder Software
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */
//  (C) Copyright John Maddock 2000.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/static_assert for documentation.

/*
 Revision history:
   02 August 2000
      Initial version.
   25 February 2012
      Adaptation to inclusion in Acari
   21 December 2013
      Adaptation to inclusion in Meta
*/

#ifndef vlinder_meta_static_assert_hpp
#define vlinder_meta_static_assert_hpp

#include "cat.hpp"

#if defined(__GNUC__) && (__GNUC__ == 3) && ((__GNUC_MINOR__ == 3) || (__GNUC_MINOR__ == 4))
// gcc 3.3 and 3.4 don't produce good error messages with the default version:
#  define VLINDER_META_SA_GCC_WORKAROUND
#endif

//
// If the compiler issues warnings about old C style casts,
// then enable this:
//
#if defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 4)))
#  define VLINDER_META_STATIC_ASSERT_BOOL_CAST( x ) ((x) == 0 ? false : true)
#else
#  define VLINDER_META_STATIC_ASSERT_BOOL_CAST(x) (bool)(x)
#endif

#ifdef VLINDER_META_HAS_STATIC_ASSERT
#  define VLINDER_META_STATIC_ASSERT( B ) static_assert(B, #B)
#else

namespace Vlinder { namespace Meta {

// HP aCC cannot deal with missing names for template value parameters
template <bool x> struct STATIC_ASSERTION_FAILURE;

template <> struct STATIC_ASSERTION_FAILURE<true> { enum { value = 1 }; };

// HP aCC cannot deal with missing names for template value parameters
template<int x> struct static_assert_test{};

}}

//
// Implicit instantiation requires that all member declarations be
// instantiated, but that the definitions are *not* instantiated.
//
// It's not particularly clear how this applies to enum's or typedefs;
// both are described as declarations [7.1.3] and [7.2] in the standard,
// however some compilers use "delayed evaluation" of one or more of
// these when implicitly instantiating templates.  We use typedef declarations
// by default, but try defining VLINDER_META_USE_ENUM_STATIC_ASSERT if the enum
// version gets better results from your compiler...
//
// Implementation:
// Both of these versions rely on sizeof(incomplete_type) generating an error
// message containing the name of the incomplete type.  We use
// "STATIC_ASSERTION_FAILURE" as the type name here to generate
// an eye catching error message.  The result of the sizeof expression is either
// used as an enum initialiser, or as a template argument depending which version
// is in use...
// Note that the argument to the assert is explicitly cast to bool using old-
// style casts: too many compilers currently have problems with static_cast
// when used inside integral constant expressions.
//
#if defined(_MSC_VER ) && (_MSC_VER  < 1300)
// __LINE__ macro broken when -ZI is used see Q199057
// fortunately MSVC ignores duplicate typedef's.
#define VLINDER_META_STATIC_ASSERT( B ) \
   typedef ::Vlinder::Meta::static_assert_test<\
      sizeof(::Vlinder::Meta::STATIC_ASSERTION_FAILURE< (bool)( B ) >)\
      > vlinder_meta_static_assert_typedef_
#elif defined(_MSC_VER )
#define VLINDER_META_STATIC_ASSERT( B )																			\
   typedef ::Vlinder::Meta::static_assert_test<																	\
      sizeof(::Vlinder::Meta::STATIC_ASSERTION_FAILURE< VLINDER_META_STATIC_ASSERT_BOOL_CAST ( B ) >)>			\
         VLINDER_META_CAT(vlinder_meta_static_assert_typedef_, __COUNTER__)
#else
// generic version
#define VLINDER_META_STATIC_ASSERT( B )																			\
   typedef ::Vlinder::Meta::static_assert_test<																	\
      sizeof(::Vlinder::Meta::STATIC_ASSERTION_FAILURE< VLINDER_META_STATIC_ASSERT_BOOL_CAST( B ) >)>			\
         VLINDER_META_CAT(vlinder_meta_static_assert_typedef_, __LINE__)
#endif

#endif // ndef VLINDER_META_HAS_STATIC_ASSERT

#endif
