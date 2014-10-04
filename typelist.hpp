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

#include "none.hpp"
#include "if.hpp"
#include "not.hpp"
#include "enableif.hpp"
#include "identity.hpp"

namespace Vlinder { namespace Meta {
	template < typename T, typename Tail >
	struct TypeList;
	template < typename T >
	struct TypeList< T, None >
	{
		typedef T head;
		typedef None tail;
	};
	template < typename T, typename Tail >
	struct TypeList
	{
		typedef T head;
		typedef Tail tail;
	};

	template <
		  typename  T1       , typename  T2 = None, typename  T3 = None, typename  T4 = None
		, typename  T5 = None, typename  T6 = None, typename  T7 = None, typename  T8 = None
		, typename  T9 = None, typename T10 = None, typename T11 = None, typename T12 = None
		, typename T13 = None, typename T14 = None, typename T15 = None, typename T16 = None
		, typename T17 = None, typename T18 = None, typename T19 = None, typename T20 = None
		, typename T21 = None, typename T22 = None, typename T23 = None, typename T24 = None
		, typename T25 = None, typename T26 = None, typename T27 = None, typename T28 = None
		, typename T29 = None, typename T30 = None, typename T31 = None, typename T32 = None
	>
	struct MakeTypeList;
	template < typename T >
	struct MakeTypeList<
		     T, None, None, None, None, None, None, None
		, None, None, None, None, None, None, None, None
		, None, None, None, None, None, None, None, None
		, None, None, None, None, None, None, None, None
	>
	{
		typedef TypeList< T, None > type;
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
	struct Length< None >
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
	struct At< TL, 0, typename EnableIf< Not< IsNone< TL > > >::type >
	{
		typedef typename TL::head type;
	};
	template < typename TL, unsigned int index__ >
	struct At< TL, index__, typename EnableIf< Not< IsNone< TL > > >::type >
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
		typedef None type;
	};
	template <>
	struct Splice< None, 0, 0 >
	{
		typedef None type;
	};
	template < unsigned int end__ >
	struct Splice< None, 0, end__ >
	{
		typedef None type;
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
	struct FoldR< F, T, None >
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
			  typename Splice< 
			  	  TL
				, 0
				, index__ 
				>::type
			, TypeList<
				  T
				, typename Splice<
					  TL
					, index__
					, Length< TL >::value - index__
					>::type
				>
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
	struct Transform< None, F >
	{
		typedef None type;
	};
	template < typename TL1, template < class > class F >
	struct Transform
	{
		typedef TypeList<
			  typename F< typename TL1::head >::type
			, typename Transform< typename TL1::tail, F >::type
			> type;
	};
	template <
		  typename Haystack
		, typename Needle
		, template < typename, typename > class Predicate
		, class Enable = void
		>
	struct Find_
	{
		typedef typename Find_< typename Haystack::tail, Needle, Predicate >::type type;
	};
	template <
		  typename Haystack
		, typename Needle
		, template < typename, typename > class Predicate
		>
	struct Find_< Haystack, Needle, Predicate, typename EnableIf< IsNone< Haystack > >::type >
	{
		typedef None type;
	};
	template <
		  typename Haystack
		, typename Needle
		, template < typename, typename > class Predicate
		>
	struct Find_<
		  Haystack
		, Needle
		, Predicate
		, typename EnableIf< typename Predicate< typename Haystack::head, Needle >::type >::type 
		>
	{
		typedef typename Haystack::head type;
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
	struct Find
	{
		typedef typename Find_<
			  Haystack
			, Needle
			, Predicate
			>::type type;
	};
}}

#endif

