/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_pair_hpp
#define vlinder_meta_pair_hpp

#include "none.hpp"
#include "identity.hpp"

namespace Vlinder { namespace Meta {
	template < typename First, typename Second >
	struct Pair
	{
		typedef Identity< First > first;
		typedef Identity< Second > second;
	};
	template < typename P >
	struct GetFirst
	{
		typedef typename P::first type;
	};
	template <>
	struct GetFirst< None >
	{
		typedef None type;
	};
	template < typename P >
	struct GetSecond
	{
		typedef typename P::second type;
	};
	template < >
	struct GetSecond< None >
	{
		typedef None type;
	};
}}

#endif

