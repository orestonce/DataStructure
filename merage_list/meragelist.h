#ifndef _MERGAELIST_H_
#define _MERGAELIST_H_

#include <list>

namespace restonce{
	/*
	 * mearge two list , requre both of them increament 
	 * */
	template<typename T>
	std::list<T> merageList(std::list<T> const& la, std::list<T> const& lb) {
		std::list<T> result;				// store result
		auto ita = la.begin() , itb = lb.begin();	

		while ( ita != la.end() && itb != lb.end() ) {
			if ( *ita < *itb ) {			// select the smaller one save to result
				result.push_back( *ita );
				++ ita;
			} else {
				result.push_back( *itb );
				++itb;
			}
		}

		while ( ita != la.end() ) {		// append the rest elements
			result.push_back(*ita);
			++ita ;
		}
		while ( itb != lb.end() ) {
			result.push_back(*itb);
			++itb ;
		}
		return result;
	}
}

#endif // _MERGAELIST_H_
