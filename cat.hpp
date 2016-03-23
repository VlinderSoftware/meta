/* meta: meta-programming library for C++
 * Copyright (C) $$__YEAR__$$  Vlinder Software
 *
 * $$__LICENSE__$$
 *
 * To obtain a different license, or for more information about this 
 * and related software, contact us at <support@vlinder.ca>
 */
#ifndef vlinder_meta_cat_hpp
#define vlinder_meta_cat_hpp

#ifndef VLINDER_META_CAT
#define VLINDER_META_CAT_2(x,y)	x##y
#define VLINDER_META_CAT_1(x,y)	VLINDER_META_CAT_2(x,y)
#define VLINDER_META_CAT(x,y)	VLINDER_META_CAT_1(x,y)
#endif

#endif

