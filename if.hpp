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
#ifndef vlinder_meta_if_hpp
#define vlinder_meta_if_hpp

#include "nil.hpp"

namespace Vlinder { namespace Meta {
	namespace Details {
		template < typename First, typename Second >
		struct ResultIfTrue
		{
			typedef First type;
		};
		
		template < typename First, typename Second >
		struct ResultIfFalse
		{
			typedef Second type;
		};
	}
	template < bool value, typename First, typename Second >
	struct IfC_
	{
		typedef typename Details::ResultIfTrue< First, Second >::type type;
	};
	template < typename First, typename Second >
	struct IfC_< false, First, Second >
	{
		typedef typename Details::ResultIfFalse< First, Second >::type type;
	};


	template < int value, typename First, typename Second >
	struct IfC
	{
		typedef typename IfC_< value != 0, First, Second >::type type;
	};
	template < typename Pred, typename First, typename Second >
	struct If : IfC< Pred::value, First, Second >
	{};
}}

#endif

