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

struct T
{
};
struct U : T
{
};

int main()
{
	using namespace Vlinder::Meta;
	int value(IfC< Equals<T, U>::value, Constant< 1 >, Constant< 2 > >::type::value);
	assert(value == 2);
}
