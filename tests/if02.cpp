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
struct T
{
};

typedef TypeList< P, Q, R, S > Types;

template < typename Haystack, typename Needle, template < typename, typename > class Predicate >
struct F_
{
	typedef typename If<
		Predicate< typename Haystack::type, Needle >,
		Haystack,
		typename F_< typename Haystack::next, Needle, Predicate >::type
	>::type type;
};
template < typename Needle, template < typename, typename > class Predicate >
struct F_< TLNode< None, TypeList< None > >, Needle, Predicate >
{
	typedef None type;
};

int main()
{
	bool equals(Equals< typename F_< typename Types::head, P, Equals >::type::type, P >::value);
	assert(equals);
}
