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

#include "nil.hpp"

namespace Vlinder { namespace Meta {
	template < bool value, typename First, typename Second >
	struct IfC_;
	template < typename First, typename Second >
	struct IfC_< true, First, Second >
	{
		typedef First type;
	};
	template < typename First, typename Second >
	struct IfC_< false, First, Second >
	{
		typedef Second type;
	};


	template < int value, typename First, typename Second >
	struct IfC
	{
		typedef IfC_< value != 0, First, Second > intermediate;
		typedef typename intermediate::type type;
	};
	template < typename Pred, typename First, typename Second >
	struct If : IfC< Pred::value, First, Second >
	{};
}}

#endif

