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
#ifndef vlinder_meta_equals_hpp
#define vlinder_meta_equals_hpp

namespace Vlinder { namespace Meta {
	template < typename LHS, typename RHS >
	struct Equals
	{
		typedef Equals< LHS, RHS > type;
		enum { value = 0 };
	};
	template < typename LHS >
	struct Equals< LHS, LHS >
	{
		typedef Equals< LHS, LHS > type;
		enum { value = 1 };
	};
}}

#endif

