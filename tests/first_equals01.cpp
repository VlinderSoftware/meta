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
#include "../pair.hpp"
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

typedef MakeTypeList< Pair< P, Q >, Pair< R, S > >::type Types;

int main()
{
	bool is_none(IsNil< typename Find< Types, Pair< P, Q >, Equals >::type >::value);

	assert(!is_none);
	bool equals(Equals< typename Find< Types, Pair< P, Q >, Equals >::type, Pair< P, Q > >::value);
	assert(equals);
	bool first_equals(FirstEquals< typename Find< Types, Pair< P, Q >, Equals >::type, P >::value);
	assert(first_equals);
}
