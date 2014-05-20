/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_typelist_hpp
#define vlinder_meta_typelist_hpp

#include "nil.hpp"
#include "if.hpp"
#include "not.hpp"
#include "enableif.hpp"
#include "identity.hpp"

namespace Vlinder { namespace Meta {
	template < typename T, typename Tail >
	struct TypeList;
	template < typename T >
	struct TypeList< T, Nil >
	{
		typedef T head;
		typedef Nil tail;
	};
	template < typename T, typename Tail >
	struct TypeList
	{
		typedef T head;
		typedef Tail tail;
	};

	template <
		  typename  T1       , typename  T2 = Nil, typename  T3 = Nil, typename  T4 = Nil
		, typename  T5 = Nil, typename  T6 = Nil, typename  T7 = Nil, typename  T8 = Nil
		, typename  T9 = Nil, typename T10 = Nil, typename T11 = Nil, typename T12 = Nil
		, typename T13 = Nil, typename T14 = Nil, typename T15 = Nil, typename T16 = Nil
		, typename T17 = Nil, typename T18 = Nil, typename T19 = Nil, typename T20 = Nil
		, typename T21 = Nil, typename T22 = Nil, typename T23 = Nil, typename T24 = Nil
		, typename T25 = Nil, typename T26 = Nil, typename T27 = Nil, typename T28 = Nil
		, typename T29 = Nil, typename T30 = Nil, typename T31 = Nil, typename T32 = Nil
	>
	struct MakeTypeList;
	template < typename T >
	struct MakeTypeList<
		     T, Nil, Nil, Nil, Nil, Nil, Nil, Nil
		, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil
		, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil
		, Nil, Nil, Nil, Nil, Nil, Nil, Nil, Nil
	>
	{
		typedef TypeList< T, Nil > type;
	};
	template <
		  typename  T1, typename  T2, typename  T3, typename  T4
		, typename  T5, typename  T6, typename  T7, typename  T8
		, typename  T9, typename T10, typename T11, typename T12
		, typename T13, typename T14, typename T15, typename T16
		, typename T17, typename T18, typename T19, typename T20
		, typename T21, typename T22, typename T23, typename T24
		, typename T25, typename T26, typename T27, typename T28
		, typename T29, typename T30, typename T31, typename T32
	>
	struct MakeTypeList
	{
		typedef TypeList< T1, typename MakeTypeList<
			   T2,  T3,  T4,  T5,  T6,  T7,  T8,  T9
			, T10, T11, T12, T13, T14, T15, T16, T17
			, T18, T19, T20, T21, T22, T23, T24, T25
			, T26, T27, T28, T29, T30, T31, T32
		>::type > type;
	};

	template < typename TL >
	struct Length;
	template <>
	struct Length< Nil >
	{
		enum { value = 0 };
	};
	template < typename TL >
	struct Length
	{
		enum { value = 1 + Length< typename TL::tail >::value };
	};

	template < typename TL, unsigned int index__, class Enable = void >
	struct At;
	template < typename TL >
	struct At< TL, 0, typename EnableIf< Not< IsNil< TL > > >::type >
	{
		typedef typename TL::head type;
	};
	template < typename TL, unsigned int index__ >
	struct At< TL, index__, typename EnableIf< Not< IsNil< TL > > >::type >
	{
		typedef typename At< typename TL::tail, index__ - 1 >::type type;
	};
	template < typename T1, typename T2, typename TL >
	struct MakeList2
	{
		typedef TypeList< T1, TypeList< T2, TL> > type;
	};
	template < typename TL, unsigned int begin__, unsigned int end__ >
	struct Splice;
	template < typename TL >
	struct Splice< TL, 0, 0 >
	{
		typedef Nil type;
	};
	template <>
	struct Splice< Nil, 0, 0 >
	{
		typedef Nil type;
	};
	template < unsigned int end__ >
	struct Splice< Nil, 0, end__ >
	{
		typedef Nil type;
	};
	template < typename TL, unsigned int end__ >
	struct Splice< TL, 0, end__ >
	{
		typedef TypeList< typename TL::head, typename Splice< typename TL::tail, 0, end__ - 1 >::type > type;
	};
	template < typename TL, unsigned int begin__, unsigned int end__ >
	struct Splice
	{
		typedef typename Splice< typename TL::tail, begin__ - 1, end__ - 1 >::type type;
	};

	template < template < class, class > class F, typename T,typename TL >
	struct FoldR;
	template < template < class, class > class F, typename T >
	struct FoldR< F, T, Nil >
	{
		typedef T type;
	};
	template < template < class, class > class F, typename T, typename TL >
	struct FoldR
	{
		typedef typename F< typename TL::head, typename FoldR< F, T, typename TL::tail >::type >::type type;
	};

	template < typename T, typename TL >
	struct AppendList_
	{
		typedef TypeList< T, TL > type;
	};

	template < typename TL1, typename TL2 >
	struct AppendList
	{
		typedef typename FoldR< AppendList_, TL2, TL1 >::type type;
	};

	template < typename TL, unsigned int index__, typename T >
	struct Insert;
	template < typename TL, typename T >
	struct Insert< TL, 0, T >
	{
		typedef typename TypeList< T, TL >::type type;
	};
	template < typename TL, unsigned int index__, typename T >
	struct Insert
	{
		typedef typename AppendList<
			  typename Splice< TL, 0, index__ >::type
			, TypeList< T, typename Splice< TL, index__, Length< TL >::value - index__ >::type >
			>::type type;
	};

	template < typename TL, typename T >
	struct Append
	{
		typedef typename Insert< TL, Length< TL >::value, T >::type type;
	};
	template < typename TL1, template < class > class F >
	struct Transform;
	template < template < class > class F >
	struct Transform< Nil, F >
	{
		typedef Nil type;
	};
	template < typename TL1, template < class > class F >
	struct Transform
	{
		typedef TypeList< typename F< typename TL1::head >::type, typename Transform< typename TL1::tail, F >::type > type;
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate, class Enable = void >
	struct Find_
	{
		typedef typename Find_< typename Haystack::tail, Needle, Predicate >::type type;
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
	struct Find_< Haystack, Needle, Predicate, typename EnableIf< IsNil< Haystack > >::type >
	{
		typedef Nil type;
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
	struct Find_< Haystack, Needle, Predicate, typename EnableIf< typename Predicate< typename Haystack::head, Needle >::type >::type >
	{
		typedef typename Haystack::head type;
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
	struct Find
	{
		typedef typename Find_< Haystack, Needle, Predicate >::type type;
	};
}}

#endif

