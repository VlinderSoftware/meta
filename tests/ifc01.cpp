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
