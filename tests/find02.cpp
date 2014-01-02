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

typedef MakeTypeList< P, Q, R, S >::type Types;


int main()
{
	bool is_none(IsNone< typename Find< Types, S, Equals >::type::head >::value);
	assert(!is_none);
	bool equals(Equals< typename Find< Types, S, Equals >::type::head, S >::value);
	assert(equals);
}
