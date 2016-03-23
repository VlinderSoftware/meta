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

typedef MakeTypeList< P, Q, R, S >::type Types;

int main()
{
	using namespace Vlinder::Meta;
	int value(IfC< Equals< P, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value);
	assert(value == 1);
	value = IfC< Equals< P, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< P, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< P, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	// doesn't, and shouldn't, compile
	//value = IfC< Equals< P, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	//assert(value == 2);

	value = IfC< Equals< Q, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< Q, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 1);
	value = IfC< Equals< Q, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< Q, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	//value = IfC< Equals< Q, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	//assert(value == 2);

	value = IfC< Equals< R, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< R, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< R, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 1);
	value = IfC< Equals< R, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	//value = IfC< Equals< R, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	//assert(value == 2);

	value = IfC< Equals< S, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< S, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< S, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< S, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 1);
	//value = IfC< Equals< S, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	//assert(value == 2);

}
