/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_not_hpp
#define vlinder_meta_not_hpp

namespace Vlinder { namespace Meta {
	template < int cond__ >
	struct NotC
	{
		typedef NotC< cond__ > type;
		enum { value = !cond__ };
	};

	template < typename Cond >
	struct Not
	{
		typedef Not< Cond > type;
		enum { value = !Cond::value };
	};
}}

#endif

