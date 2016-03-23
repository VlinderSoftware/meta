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
#include "../isderivedfrom.hpp"

using namespace Vlinder::Meta;

struct B
{
};
struct D : B
{
};

int main()
{
	using namespace Vlinder::Meta;

	bool value(IsDerivedFrom< B, D >::type::value);
	assert(value);
	return 0;
}
