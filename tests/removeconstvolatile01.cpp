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
#include "../equals.hpp"
#include "../removeconstvolatile.hpp"

using namespace Vlinder::Meta;

struct P
{
};

int testPrelims01()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P, P >::type::value);
	if (!value1) return 1;
	bool value2(Equals< P const, P >::type::value);
	if (value2) return 1;
	bool value3(Equals< P, P const >::type::value);
	if (value3) return 1;
	bool value4(Equals< P const, P const >::type::value);
	if (!value4) return 1;
	return 0;
}

int testPrelims02()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P, P >::type::value);
	if (!value1) return 1;
	bool value2(Equals< P volatile, P >::type::value);
	if (value2) return 1;
	bool value3(Equals< P, P volatile >::type::value);
	if (value3) return 1;
	bool value4(Equals< P volatile, P volatile >::type::value);
	if (!value4) return 1;
	return 0;
}

int testPrelims03a()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P, P >::type::value);
	if (!value1) return 1;
	bool value2(Equals< P const volatile, P >::type::value);
	if (value2) return 1;
	bool value3(Equals< P, P const volatile >::type::value);
	if (value3) return 1;
	bool value4(Equals< P const volatile, P const volatile >::type::value);
	if (!value4) return 1;
	return 0;
}

int testPrelims03b()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P const, P const >::type::value);
	if (!value1) return 1;
	bool value2(Equals< P const volatile, P const >::type::value);
	if (value2) return 1;
	bool value3(Equals< P const, P const volatile >::type::value);
	if (value3) return 1;
	bool value4(Equals< P const volatile, P const volatile >::type::value);
	if (!value4) return 1;
	return 0;
}

int testPrelims03c()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P volatile, P volatile >::type::value);
	if (!value1) return 1;
	bool value2(Equals< P const volatile, P volatile >::type::value);
	if (value2) return 1;
	bool value3(Equals< P volatile, P const volatile >::type::value);
	if (value3) return 1;
	bool value4(Equals< P const volatile, P const volatile >::type::value);
	if (!value4) return 1;
	return 0;
}

int test01()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P, P >::type::value);
	if (!value1) return 1;
	bool value2(Equals< typename RemoveConstVolatile< P const >::type, P >::type::value);
	if (!value2) return 1;
	bool value3(Equals< P, typename RemoveConstVolatile< P const >::type >::type::value);
	if (!value3) return 1;
	bool value4(Equals< typename RemoveConstVolatile< P const >::type, typename RemoveConstVolatile< P const >::type >::type::value);
	if (!value4) return 1;
	return 0;
}

int test02()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P, P >::type::value);
	if (!value1) return 1;
	bool value2(Equals< typename RemoveConstVolatile< P volatile >::type, P >::type::value);
	if (!value2) return 1;
	bool value3(Equals< P, typename RemoveConstVolatile< P volatile >::type >::type::value);
	if (!value3) return 1;
	bool value4(Equals< typename RemoveConstVolatile< P volatile >::type, typename RemoveConstVolatile< P volatile >::type >::type::value);
	if (!value4) return 1;
	return 0;
}

int test03()
{
	using namespace Vlinder::Meta;
	bool value1(Equals< P, P >::type::value);
	if (!value1) return 1;
	bool value2(Equals< typename RemoveConstVolatile< P const volatile >::type, P >::type::value);
	if (!value2) return 1;
	bool value3(Equals< P, typename RemoveConstVolatile< P const volatile >::type >::type::value);
	if (!value3) return 1;
	bool value4(Equals< typename RemoveConstVolatile< P const volatile >::type, typename RemoveConstVolatile< P const volatile >::type >::type::value);
	if (!value4) return 1;
	return 0;
}

int main()
{
    return 0
		|| testPrelims01()
		|| testPrelims02()
		|| testPrelims03a()
		|| testPrelims03b()
		|| testPrelims03c()
		|| test01()
		|| test02()
		|| test03()
		;
}
