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
#include "../isderivedfrom.hpp"

using namespace Vlinder::Meta;

struct B
{
};
struct D : private B
{
};

int main()
{
	using namespace Vlinder::Meta;

	bool value(IsDerivedFrom< B, D >::type::value);
	assert(value);
	return 0;
}
