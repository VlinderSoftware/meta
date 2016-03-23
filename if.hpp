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
	namespace Details {
		template < typename First, typename Second >
		struct ResultIfTrue
		{
			typedef First type;
		};
		
		template < typename First, typename Second >
		struct ResultIfFalse
		{
			typedef Second type;
		};
	}
	template < bool value, typename First, typename Second >
	struct IfC_
	{
		typedef typename Details::ResultIfTrue< First, Second >::type type;
	};
	template < typename First, typename Second >
	struct IfC_< false, First, Second >
	{
		typedef typename Details::ResultIfFalse< First, Second >::type type;
	};


	template < int value, typename First, typename Second >
	struct IfC
	{
		typedef typename IfC_< value != 0, First, Second >::type type;
	};
	template < typename Pred, typename First, typename Second >
	struct If : IfC< Pred::value, First, Second >
	{};
}}

#endif

