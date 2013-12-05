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
#include "identity.hpp"

namespace Vlinder { namespace Meta {
	template <
		typename  T1,
		typename  T2,
		typename  T3,
		typename  T4,
		typename  T5,
		typename  T6,
		typename  T7,
		typename  T8,
		typename  T9,
		typename T10,
		typename T11,
		typename T12,
		typename T13,
		typename T14,
		typename T15,
		typename T16
	>
	struct TypeList;
	template < typename N, typename L >
	struct TLNode
	{
		typedef N type;
		typedef L next_list;
		typedef typename L::head next;
	};
	template <
		typename  T1,
		typename  T2 = None,
		typename  T3 = None,
		typename  T4 = None,
		typename  T5 = None,
		typename  T6 = None,
		typename  T7 = None,
		typename  T8 = None,
		typename  T9 = None,
		typename T10 = None,
		typename T11 = None,
		typename T12 = None,
		typename T13 = None,
		typename T14 = None,
		typename T15 = None,
		typename T16 = None
	>
	struct TypeList
	{
		typedef TLNode< T1, TypeList< T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16 > > head;
	};
	template < typename TL >
	struct GetSize;
	template <>
	struct GetSize< TypeList<
		None, None, None, None,
		None, None, None, None,
		None, None, None, None,
		None, None, None, None > >
	{
		enum { value = 0 };
	};
	template < typename TL >
	struct GetSize
	{
		enum { value = 1 + GetSize< typename TL::head::next_list >::value };
	};
	template < typename TL, unsigned int index__ >
	struct At;
	template < typename TL >
	struct At< TL, 0 >
	{
		typedef typename TL::head::type type;
	};
	template < typename TL, unsigned int index__ >
	struct At
	{
		typedef typename At< typename TL::head::next_list, index__ - 1 >::type type;
	};
	template < typename TL, unsigned int index__, typename T >
	struct Insert;
	template < typename TL, typename T >
	struct Insert< TL, 0, T >
	{
		typedef TypeList<
			T,
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 1, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			T,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 2, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			T,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 3, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			T,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 4, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			T,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 5, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			T,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 6, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			T,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 7, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			T,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 8, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			T,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 9, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			T,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 10, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			T,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 11, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			T,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 12, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			T,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 13, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			T,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 14, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			T,
			typename At< TL, 14 >::type
		> type;
	};
	template < typename TL, typename T >
	struct Insert< TL, 15, T >
	{
		typedef TypeList<
			typename At< TL, 0 >::type,
			typename At< TL, 1 >::type,
			typename At< TL, 2 >::type,
			typename At< TL, 3 >::type,
			typename At< TL, 4 >::type,
			typename At< TL, 5 >::type,
			typename At< TL, 6 >::type,
			typename At< TL, 7 >::type,
			typename At< TL, 8 >::type,
			typename At< TL, 9 >::type,
			typename At< TL, 10 >::type,
			typename At< TL, 11 >::type,
			typename At< TL, 12 >::type,
			typename At< TL, 13 >::type,
			typename At< TL, 14 >::type,
			T
		> type;
	};
	template < typename TL, typename T >
	struct Append
	{
		typedef typename Insert< TL, GetSize< TL >::value, T >::type type;
	};
	template < typename TL1, template < class > class F >
	struct Transform
	{
		typedef TypeList<
			typename F< typename At< TL1, 0 >::type >::type,
			typename F< typename At< TL1, 1 >::type >::type,
			typename F< typename At< TL1, 2 >::type >::type,
			typename F< typename At< TL1, 3 >::type >::type,
			typename F< typename At< TL1, 4 >::type >::type,
			typename F< typename At< TL1, 5 >::type >::type,
			typename F< typename At< TL1, 6 >::type >::type,
			typename F< typename At< TL1, 7 >::type >::type,
			typename F< typename At< TL1, 8 >::type >::type,
			typename F< typename At< TL1, 9 >::type >::type,
			typename F< typename At< TL1, 10 >::type >::type,
			typename F< typename At< TL1, 11 >::type >::type,
			typename F< typename At< TL1, 12 >::type >::type,
			typename F< typename At< TL1, 13 >::type >::type,
			typename F< typename At< TL1, 14 >::type >::type,
			typename F< typename At< TL1, 15 >::type >::type
		> type;
	};
	template < typename P, typename T >
	struct FirstEquals
	{
		enum { value = Equals< typename P::first::type, T >::value };
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
	struct Find_
	{
		typedef typename If<
			Predicate< typename Haystack::type, Needle >,
			Haystack,
			typename Find_< typename Haystack::next, Needle, Predicate >::type
		>::type type;
	};
	template < typename Needle, template < typename, typename > class Predicate >
	struct Find_< TLNode< None, TypeList< None > >, Needle, Predicate >
	{
		typedef Identity< None > type;
	};
	template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
	struct Find
	{
		typedef typename Find_< typename Haystack::head, Needle, Predicate >::type type;
	};
}}

#endif

