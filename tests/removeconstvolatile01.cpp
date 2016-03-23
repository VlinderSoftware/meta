/* upool2: version 2 of the micro-pool allocator
 * small object allocator, fast allocator for small blocks
 * Copyright (C) 2012  Ronald Landheer-Cieslak
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
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
