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


