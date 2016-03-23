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
#include "../findif.hpp"
#include "../constants.hpp"

using namespace Vlinder::Meta;


typedef Constants5< 1, 2, 3, 4, 5 >::type Types;
template < typename C >
struct IsEven
{
	typedef IsEven< C > type;
	enum { value = ((C::value % 2) == 0) };
};
typedef typename FindIf< Types, IsEven >::type EvenTypes;

int main()
{
	unsigned int length(Length< EvenTypes >::value);
	if (2 != length) return 1;
	unsigned int at0(At< EvenTypes, 0 >::type::value);
	if (2 != at0) return 1;
	unsigned int at1(At< EvenTypes, 1 >::type::value);
	if (4 != at1) return 1;

	return 0;
}
