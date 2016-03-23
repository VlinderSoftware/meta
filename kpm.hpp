/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_kpm_hpp
#define vlinder_meta_kpm_hpp

#include "constants.hpp"
#include "if.hpp"

namespace Vlinder { namespace Meta {
	namespace Details {
		template < typename W, typename T, int pos, unsigned int cnd  >
		struct BuildKPMTable;
		template < typename W, typename T, int pos, unsigned int cnd, class Enable = void >
		struct BuildKPMTable1_;
		template < typename W, typename T, int pos, unsigned int cnd, class Enable = void >
		struct BuildKPMTable2_;
		template < typename W, typename T, int pos, unsigned int cnd, class Enable = void >
		struct BuildKPMTable3_;

		template < typename W, typename T, int pos, unsigned int cnd, class Enable >
		struct BuildKPMTable1_
		{
			typedef T type;
		};
		template < typename W, typename T, int pos, unsigned int cnd >
		struct BuildKPMTable1_< W, T, pos, cnd, typename EnableIfC< (pos < Length< W >::value) >::type >
		{
			typedef typename BuildKPMTable3_< W, T, pos, cnd >::type type;
		};

		template < typename W, typename T, int pos, unsigned int cnd, class Enable >
		struct BuildKPMTable3_
		{
			typedef typename BuildKPMTable2_< W, T, pos, cnd >::type type;
		};
		template < typename W, typename T, int pos, unsigned int cnd >
		struct BuildKPMTable3_< W, T, pos, cnd, typename EnableIf< Equals< typename At< W, pos - 1 >::type, typename At< W, cnd >::type > >::type >
		{
			typedef typename BuildKPMTable< W, typename Append< T, Constant< cnd + 1 > >::type, pos + 1, cnd + 1 >::type type;
		};

		template < typename W, typename T, int pos, unsigned int cnd, class Enable >
		struct BuildKPMTable2_
		{
			typedef typename BuildKPMTable< W, T, pos, At< T, cnd >::type::value >::result type;
		};
		template < typename W, typename T, int pos, unsigned int cnd >
		struct BuildKPMTable2_< W, T, pos, cnd, typename EnableIfC< cnd == 0 >::type >
		{
			typedef typename BuildKPMTable< W, typename Append< T, Constant< 0 > >::type, pos + 1, 0 >::result type;
		};

		template < typename W, typename T, int pos, unsigned int cnd  >
		struct BuildKPMTable
		{
			typedef typename BuildKPMTable1_< W, T, pos, cnd >::type result;
			typedef result type;
		};
	}
	template < typename W >
	struct KPMTable
	{
		typedef typename Constants2< -1, 0 >::list initial_t;
		typedef typename Details::BuildKPMTable< W, initial_t, 2, 0 >::result result;
		typedef result type;
	};
}}

#endif

