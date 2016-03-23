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

