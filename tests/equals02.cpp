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

struct T
{
};
struct U
{
};

int main()
{
	using namespace Vlinder::Meta;
	bool equals(Equals<T, U>::value);
	assert(!equals);
}
