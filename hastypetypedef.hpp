/* meta: meta-programming library for C++
 * small object allocator, fast allocator for small blocks
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_hastypetypedef_hpp
#define vlinder_meta_hastypetypedef_hpp

#include "enableif.hpp"

namespace Vlinder { namespace Meta {
	template < typename T >
	struct HasTypeTypedef
	{
		typedef char yes[1];
		typedef char no[2];

		template < typename C >
		static yes& test(typename C::type*);
		template < typename >
		static no& test(...);

		enum { value = (sizeof(test<T>(0)) == sizeof(yes)) };
	};
}}

#endif


