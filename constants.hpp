/* upool2: version 2 of the micro-pool allocator
 * small object allocator, fast allocator for small blocks
 * Copyright (C) 2012  Ronald Landheer-Cieslak
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef upool2_constants_hpp
#define upool2_constants_hpp

#include "typelist.hpp"

namespace Vlinder { namespace Meta {
	template < unsigned int v__ >
	struct Constant
	{
		enum { value = v__ };
		typedef Constant< v__ > type;
	};
	template < unsigned int v1__ >
	struct Constants1
	{
		typedef TypeList<
			Constant< v1__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__ >
	struct Constants2
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__ >
	struct Constants3
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__ >
	struct Constants4
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__ >
	struct Constants5
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__ >
	struct Constants6
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__ >
	struct Constants7
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__ >
	struct Constants8
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__ >
	struct Constants9
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__ >
	struct Constants10
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__, unsigned int v11__ >
	struct Constants11
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >,
			Constant< v11__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__, unsigned int v11__, unsigned int v12__ >
	struct Constants12
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >,
			Constant< v11__ >,
			Constant< v12__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__, unsigned int v11__, unsigned int v12__, unsigned int v13__ >
	struct Constants13
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >,
			Constant< v11__ >,
			Constant< v12__ >,
			Constant< v13__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__, unsigned int v11__, unsigned int v12__, unsigned int v13__, unsigned int v14__ >
	struct Constants14
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >,
			Constant< v11__ >,
			Constant< v12__ >,
			Constant< v13__ >,
			Constant< v14__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__, unsigned int v11__, unsigned int v12__, unsigned int v13__, unsigned int v14__, unsigned int v15__ >
	struct Constants15
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >,
			Constant< v11__ >,
			Constant< v12__ >,
			Constant< v13__ >,
			Constant< v14__ >,
			Constant< v15__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};
	template < unsigned int v1__, unsigned int v2__, unsigned int v3__, unsigned int v4__, unsigned int v5__, unsigned int v6__, unsigned int v7__, unsigned int v8__, unsigned int v9__, unsigned int v10__, unsigned int v11__, unsigned int v12__, unsigned int v13__, unsigned int v14__, unsigned int v15__, unsigned int v16__ >
	struct Constants16
	{
		typedef TypeList<
			Constant< v1__ >,
			Constant< v2__ >,
			Constant< v3__ >,
			Constant< v4__ >,
			Constant< v5__ >,
			Constant< v6__ >,
			Constant< v7__ >,
			Constant< v8__ >,
			Constant< v9__ >,
			Constant< v10__ >,
			Constant< v11__ >,
			Constant< v12__ >,
			Constant< v13__ >,
			Constant< v14__ >,
			Constant< v15__ >,
			Constant< v16__ >
		> list;
		typedef list type;
		typedef typename list::head head;
	};

	template < typename C >
	struct GetValue
	{
		enum { value = C::value };
	};
}}

#endif
