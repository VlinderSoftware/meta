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
#include <iostream>
#include <cstring>
#include "../kpm.hpp"
#include "../gettype.hpp"
#include "../if.hpp"
#include "../foreach.hpp"

using namespace Vlinder::Meta;

template < char c >
struct C
{
	enum { value = c };
};

struct F
{
	F(int *v)
		: v_(v)
		, index_(0)
	{ /* no-op */ }

	template < typename C >
	void operator()(C const &)
	{
		v_[index_++] = C::type::value;
	}
	int *v_;
	unsigned int index_;
};

int main()
{
	typedef MakeTypeList< C< 'p' >, C< 'a' >, C< 'r' >, C< 't' >, C< 'i' >, C< 'c' >, C< 'i' >, C< 'p' >, C< 'a' >, C< 't' >, C< 'e' >, C< ' ' >, C< 'i' >, C< 'n' >, C< ' ' >, C< 'p' >, C< 'a' >, C< 'r' >, C< 'a' >, C< 'c' >, C< 'h' >, C< 'u' >, C< 't' >, C< 'e' > >::type Phrase;
	assert(Length< Phrase >::value == 24);
	int c(IfC< (25 >= Length< Phrase >::value), typename At< Phrase, 23 >::type, Identity< Nil > >::type::value);
	assert(c == 'e');
	typedef KPMTable< Phrase >::type T;
	int t[Length< T >::value];
	int expected_t[Length< T >::value] = { -1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0 };
	forEach<T>(F(t));
	assert(memcmp(t, expected_t, sizeof(expected_t)) == 0);
}
