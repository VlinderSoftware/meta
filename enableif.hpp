/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
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


