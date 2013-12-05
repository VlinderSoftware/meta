/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_none_hpp
#define vlinder_meta_none_hpp

#include "equals.hpp"

namespace Vlinder { namespace Meta {
	struct None
	{
	};
	template < typename T >
	struct IsNone : Equals< None, T >
	{
	};
}}

#endif

