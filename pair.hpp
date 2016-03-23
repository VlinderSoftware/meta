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
#ifndef vlinder_meta_pair_hpp
#define vlinder_meta_pair_hpp

#include "nil.hpp"
#include "identity.hpp"

namespace Vlinder { namespace Meta {
	template < typename First, typename Second >
	struct Pair
	{
		typedef First first;
		typedef Second second;
	};
	template < typename P >
	struct GetFirst
	{
		typedef typename P::first type;
	};
	template < typename P >
	struct GetSecond
	{
		typedef typename P::second type;
	};
	template < typename Pair, typename Needle >
	struct FirstEquals : Equals< typename Pair::first, Needle >
	{};
	template < typename Pair, typename Needle >
	struct SecondEquals : Equals< typename Pair::second, Needle >
	{};
}}

#endif

