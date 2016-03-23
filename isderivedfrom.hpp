/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_isderivedfrom_hpp
#define vlinder_meta_isderivedfrom_hpp

#include "removeconstvolatile.hpp"
#include "staticassert.hpp"

namespace Vlinder { namespace Meta {
	namespace Details {
		template< class Base, class Derived >
		struct IsDerivedFromImplHelper1
		{
			typedef char(&yes)[1];
			typedef char(&no)[2];

            template < typename T >
            static yes check(Derived const volatile *, T);
            static no check(Base const volatile *, int);
		};
		template< class Base, class Derived >
        struct IsDerivedFromImplHelper2
        {
            operator Base const volatile *() const;
            operator Derived const volatile *();
        };
		template< class Base, class Derived >
		struct IsDerivedFromImpl
		{
            VLINDER_META_STATIC_ASSERT(sizeof(Base) != 0);
            VLINDER_META_STATIC_ASSERT(sizeof(Derived) != 0);
            
            typedef IsDerivedFromImpl< Base, Derived > type;
			static IsDerivedFromImplHelper2< Base, Derived > helper__;

            enum {
                value =    sizeof(IsDerivedFromImplHelper1< Base, Derived >::check(helper__, 0))
                        == sizeof(typename IsDerivedFromImplHelper1< Base, Derived >::yes)
                };
		};
	}
	template< class Base, class Derived >
	struct IsDerivedFrom
	{
		typedef typename RemoveConstVolatile< Base >::type CleanBase;
		typedef typename RemoveConstVolatile< Derived >::type CleanDerived;

		typedef typename Details::IsDerivedFromImpl< CleanBase, CleanDerived >::type type;
	};
}}

#endif

