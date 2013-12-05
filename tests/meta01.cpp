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
#include "meta/typelist.hpp"
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

typedef TypeList< P, Q, R, S > Types;

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
	value = IfC< Equals< P, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);

	value = IfC< Equals< Q, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< Q, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 1);
	value = IfC< Equals< Q, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< Q, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< Q, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);

	value = IfC< Equals< R, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< R, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< R, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 1);
	value = IfC< Equals< R, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< R, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);

	value = IfC< Equals< S, typename At< Types, 0 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< S, typename At< Types, 1 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< S, typename At< Types, 2 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);
	value = IfC< Equals< S, typename At< Types, 3 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 1);
	value = IfC< Equals< S, typename At< Types, 4 >::type >::value, Constant< 1 >, Constant< 2 > >::type::value;
	assert(value == 2);

}
