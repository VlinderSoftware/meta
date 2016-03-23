/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_removeconstvolatile_hpp
#define vlinder_meta_removeconstvolatile_hpp

namespace Vlinder { namespace Meta {
    template < typename T >
    struct RemoveConstVolatile
    {
        typedef T type;
    };
    template < typename T >
    struct RemoveConstVolatile< T volatile >
    {
        typedef T type;
    };
    template < typename T >
    struct RemoveConstVolatile< T const >
    {
        typedef T type;
    };
    template < typename T >
    struct RemoveConstVolatile< T const volatile >
    {
        typedef T type;
    };
}}

#endif

