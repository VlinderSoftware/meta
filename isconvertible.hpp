/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_isconvertible_hpp
#define vlinder_meta_isconvertible_hpp

namespace Vlinder { namespace Meta {
template< class To, class From > struct IsConvertible
{
    typedef char (&yes) [1];
    typedef char (&no)  [2];

    static yes f( To* );
    static no  f( ... );

	typedef IsConvertible< To, From > type;
	
    enum result { value = sizeof( (f)( static_cast<From*>(0) ) ) == sizeof(yes) };
};
template< class To, class From > struct IsConvertible< To, From[] >
{
    enum result { value = 0 };
};
template< class To, class From > struct IsConvertible< To[], From[] >
: IsConvertible< To[1], From[1] >
{
};

}}

#endif

