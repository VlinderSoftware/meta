/* Copyright 2016  Vlinder Software
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */
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

