/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_foreach_hpp
#define vlinder_meta_foreach_hpp

#include "typelist.hpp"

namespace Vlinder { namespace Meta {
	template < typename Types >
	struct ForEach;
	template < >
	struct ForEach< Nil >
	{
		template < typename Functor >
		static void perform(Functor functor)
		{
			(void)functor; // unused
		}
	};
	template < typename Types >
	struct ForEach
	{
		template < typename Functor >
		static void perform(Functor functor)
		{
			functor(Identity< typename Types::head >());
			ForEach< typename Types::tail >::perform(functor);
		}
	};
	template < typename Types, typename Functor >
	void forEach(Functor functor)
	{
		ForEach< Types >::perform(functor);
	}
}}

#endif

