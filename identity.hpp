/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_identity_hpp
#define vlinder_meta_identity_hpp

namespace Vlinder { namespace Meta {
	template < typename T >
	struct Identity
	{
		typedef T type;
	};
}}

#endif

