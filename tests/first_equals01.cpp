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
	bool is_none(IsNone< typename Find< Types, Pair< P, Q >, Equals >::type::head >::value);
	assert(!is_none);
	bool equals(Equals< typename Find< Types, Pair< P, Q >, Equals >::type::head, Pair< P, Q > >::value);
	assert(equals);
	bool first_equals(FirstEquals< typename Find< Types, Pair< P, Q >, Equals >::type::head, P >::value);
	assert(first_equals);
}
