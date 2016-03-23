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
#include <cassert>
#include "../typelist.hpp"
#include "../constants.hpp"

using namespace Vlinder::Meta;

struct P
{
};
struct Q
{
};
struct R
{
};
struct S
{
};
struct T
{
};

typedef MakeTypeList< P, Q, R, S >::type Types;

template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
struct F_
{
	typedef typename If<
		Predicate< typename Haystack::head, Needle >,
		Haystack,
		typename F_< typename Haystack::tail, Needle, Predicate >::type
	>::type type;
};
template < typename Needle, template < typename, typename > class Predicate >
struct F_< Nil, Needle, Predicate >
{
	typedef Nil type;
};

int main()
{
	bool equals(Equals< typename F_< Types, P, Equals >::type::head, P >::value);
	assert(equals);
}
