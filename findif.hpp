/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_find_hpp
#define vlinder_meta_find_hpp

#include "typelist.hpp"

namespace Vlinder { namespace Meta {
	template <
		  typename InputSet
		, template < typename > class Predicate
		, class Enable = void
		>
	struct FindIf_
	{
		typedef typename FindIf_< typename InputSet::tail, Predicate >::type type;
	};
	template <
		  typename InputSet
		, template < typename > class Predicate
		>
	struct FindIf_< InputSet, Predicate, typename EnableIf< IsNil< InputSet > >::type >
	{
		typedef Nil type;
	};
	template <
		  typename InputSet
		, template < typename > class Predicate
		>
	struct FindIf_<
		  InputSet
		, Predicate
		, typename EnableIf< typename Predicate< typename InputSet::head >::type >::type 
		>
	{
		typedef FindIf_< InputSet, Predicate > type;
		typedef typename InputSet::head head;
		typedef typename FindIf_< typename InputSet::tail, Predicate >::type tail;
	};
	template < typename InputSet, template < typename > class Predicate >
	struct FindIf
	{
		typedef typename FindIf_< InputSet, Predicate >::type type;
	};
}}

#endif

