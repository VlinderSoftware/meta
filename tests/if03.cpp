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

template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
struct F_
{
	typedef typename If<
		Predicate< typename Haystack::head, Needle >,
		Haystack,
		typename F_< typename Haystack::tail, Needle, Predicate >::type
	>::type type;
};
template < typename Needle, template < typename, typename > class Predicate >
struct F_< Nil, Needle, Predicate >
{
	typedef Nil type;
};

int main()
{
	bool equals(Equals< typename F_< Types, Q, Equals >::type::head, Q >::value);
	assert(equals);
}
