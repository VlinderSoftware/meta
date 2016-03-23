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
struct Q : P
{
};

int main()
{
	using namespace Vlinder::Meta;
	bool value(IsConvertible< Q, P >::type::value);
	assert(!value);
	return 0;
}
