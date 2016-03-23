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
#ifndef vlinder_meta_enableif_hpp
#define vlinder_meta_enableif_hpp

namespace Vlinder { namespace Meta {
	template < bool cond__, typename T = void >
	struct EnableIfC_
	{
		typedef T type;
	};
	template < typename T >
	struct EnableIfC_< false, T >
	{
	};
	template < int cond__, typename T = void >
	struct EnableIfC : EnableIfC_< cond__ != 0, T >
	{};
	template < typename Cond, typename T = void >
	struct EnableIf : EnableIfC< Cond::value, T >
	{};
	template < int cond__, typename T = void >
	struct DisableIfC : EnableIfC_< cond__ == 0, T >
	{};
	template < typename Cond, typename T = void >
	struct DisableIf : EnableIfC< !Cond::value, T >
	{};
	template < bool cond__, typename T >
	struct LazyEnableIfC_
	{
		typedef typename T::type type;
	};
	template < int cond__, typename T > struct LazyEnableIfC : LazyEnableIfC_< cond__ != 0, T > {};
	template < int cond__, typename T > struct LazyDisableIfC : LazyEnableIfC_< cond__ == 0, T > {};
	template < typename Cond, typename T > struct LazyEnableIf : LazyEnableIfC< Cond::value, T > {};
	template < typename Cond, typename T > struct LazyDisableIf : LazyEnableIfC< !Cond::value, T > {};
}}

#endif


