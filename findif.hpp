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
#ifndef vlinder_meta_find_hpp
#define vlinder_meta_find_hpp

#include "typelist.hpp"

namespace Vlinder { namespace Meta {
	template <
		  typename InputSet
		, template < typename > class Predicate
		, class Enable = void
		>
	struct FindIf_
	{
		typedef typename FindIf_< typename InputSet::tail, Predicate >::type type;
	};
	template <
		  typename InputSet
		, template < typename > class Predicate
		>
	struct FindIf_< InputSet, Predicate, typename EnableIf< IsNil< InputSet > >::type >
	{
		typedef Nil type;
	};
	template <
		  typename InputSet
		, template < typename > class Predicate
		>
	struct FindIf_<
		  InputSet
		, Predicate
		, typename EnableIf< typename Predicate< typename InputSet::head >::type >::type 
		>
	{
		typedef FindIf_< InputSet, Predicate > type;
		typedef typename InputSet::head head;
		typedef typename FindIf_< typename InputSet::tail, Predicate >::type tail;
	};
	template < typename InputSet, template < typename > class Predicate >
	struct FindIf
	{
		typedef typename FindIf_< InputSet, Predicate >::type type;
	};
}}

#endif

