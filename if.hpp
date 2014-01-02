/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_if_hpp
#define vlinder_meta_if_hpp

#include "none.hpp"

namespace Vlinder { namespace Meta {
	template < bool value >
	struct IfC_
	{
		template < typename First, typename Second >
		struct result
		{
			typedef First type;
		};
	};
	template <  >
	struct IfC_< false >
	{
		template < typename First, typename Second >
		struct result
		{
			typedef Second type;
		};
	};


	template < int value, typename First, typename Second >
	struct IfC
	{
		typedef typename IfC_< value != 0 >::result< First, Second >::type type;
	};
	template < typename Pred, typename First, typename Second >
	struct If : IfC< Pred::value, First, Second >
	{};
}}

#endif

