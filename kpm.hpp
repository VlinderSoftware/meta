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

