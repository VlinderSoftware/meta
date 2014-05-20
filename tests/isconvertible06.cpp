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
#include "../isconvertible.hpp"

using namespace Vlinder::Meta;

struct P
{
};
struct Q
{
};

int main()
{
	using namespace Vlinder::Meta;
	int value(IsConvertible< P[], Q[] >::type::value);
	assert(!value);
	return 0;
}
