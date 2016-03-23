/* Copyright 2016  Vlinder Software
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */
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

