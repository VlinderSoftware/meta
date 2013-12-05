/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_equals_hpp
#define vlinder_meta_equals_hpp

namespace Vlinder { namespace Meta {
	template < typename LHS, typename RHS >
	struct Equals
	{
		enum { value = 0 };
	};
	template < typename LHS >
	struct Equals< LHS, LHS >
	{
		enum { value = 1 };
	};
}}

#endif

