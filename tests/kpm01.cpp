/* meta: meta-programming library for C++
 * small object allocator, fast allocator for small blocks
 * Copyright (C) 2012  Ronald Landheer-Cieslak
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#include <cassert>
#include <iostream>
#include <cstring>
#include "../kpm.hpp"
#include "../gettype.hpp"
#include "../if.hpp"
#include "../foreach.hpp"

using namespace Vlinder::Meta;

template < char c >
struct C
{
	enum { value = c };
};

struct F
{
	F(int *v)
		: v_(v)
		, index_(0)
	{ /* no-op */ }

	template < typename C >
	void operator()(C const &)
	{
		v_[index_++] = C::type::value;
	}
	int *v_;
	unsigned int index_;
};

int main()
{
	typedef MakeTypeList< C< 'p' >, C< 'a' >, C< 'r' >, C< 't' >, C< 'i' >, C< 'c' >, C< 'i' >, C< 'p' >, C< 'a' >, C< 't' >, C< 'e' >, C< ' ' >, C< 'i' >, C< 'n' >, C< ' ' >, C< 'p' >, C< 'a' >, C< 'r' >, C< 'a' >, C< 'c' >, C< 'h' >, C< 'u' >, C< 't' >, C< 'e' > >::type Phrase;
	assert(Length< Phrase >::value == 24);
	int c(IfC< (25 >= Length< Phrase >::value), typename At< Phrase, 23 >::type, Identity< None > >::type::value);
	assert(c == 'e');
	typedef KPMTable< Phrase >::type T;
	int t[Length< T >::value];
	int expected_t[Length< T >::value] = { -1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0 };
	forEach<T>(F(t));
	assert(memcmp(t, expected_t, sizeof(expected_t)) == 0);
}
