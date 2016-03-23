/* meta: meta-programming library for C++
 * small object allocator, fast allocator for small blocks
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_gettype_hpp
#define vlinder_meta_gettype_hpp

#include "enableif.hpp"
#include "hastypetypedef.hpp"

namespace Vlinder { namespace Meta {
	template < typename T, class Enable = void >
	struct GetType
	{
		typedef T type;
	};
	template < typename T >
	struct GetType< T, typename EnableIf< HasTypeTypedef< T > >::type >
	{
		typedef typename T::type type;
	};
}}

#endif


