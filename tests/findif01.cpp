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
#include "../findif.hpp"
#include "../constants.hpp"

using namespace Vlinder::Meta;


typedef Constants5< 1, 2, 3, 4, 5 >::type Types;
template < typename C >
struct IsEven
{
	typedef IsEven< C > type;
	enum { value = ((C::value % 2) == 0) };
};
typedef typename FindIf< Types, IsEven >::type EvenTypes;

int main()
{
	unsigned int length(Length< EvenTypes >::value);
	if (2 != length) return 1;
	unsigned int at0(At< EvenTypes, 0 >::type::value);
	if (2 != at0) return 1;
	unsigned int at1(At< EvenTypes, 1 >::type::value);
	if (4 != at1) return 1;

	return 0;
}
