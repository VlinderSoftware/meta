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

#include "nil.hpp"
#include "identity.hpp"

namespace Vlinder { namespace Meta {
	template < typename First, typename Second >
	struct Pair
	{
		typedef First first;
		typedef Second second;
	};
	template < typename P >
	struct GetFirst
	{
		typedef typename P::first type;
	};
	template < typename P >
	struct GetSecond
	{
		typedef typename P::second type;
	};
	template < typename Pair, typename Needle >
	struct FirstEquals : Equals< typename Pair::first, Needle >
	{};
	template < typename Pair, typename Needle >
	struct SecondEquals : Equals< typename Pair::second, Needle >
	{};
}}

#endif

