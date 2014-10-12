#include "indexkmp.h"
#ifdef DBUG
#include <iostream>
#endif
using namespace restonce::kmp;

size_type restonce::kmp::index(	std::string const& mainString, 
				std::string const& modelString, 
				size_type beginPosition) {
	size_type i = beginPosition;
	// j is point at model string
	size_type j = 0;	
	// get the next array first
	next_type&& next = getNext(modelString);

#ifdef DBUG
	std::cout << mainString << "\t" << modelString << std::endl;
#endif	
	while( i<mainString.length() && j < modelString.length()) {
#ifdef DBUG
		std::cout << i << "\t" << j << std::endl;
#endif	
		// suit success , both increase
		if ( mainString[i] == modelString[j]) {
			++i;
			++j;
		} else {
			// can't suit , only j move to next[j] , 
			//  if next[j] == npos , increase i
			j = next[j];
			if ( j == npos) {
				++i;
				j = 0;
			}
		}
	}
	/*
	 * use out of model string, 
	 * 	then main string contains model string
	 * */
	if ( j == modelString.length() ) {
		return i - modelString.length() ;
	}

#ifdef DBUG
	std::cout << i << "\t" << j << "\t" << mainString.length() << "\t" << modelString.length() << std::endl;
#endif
	return npos;
}

next_type restonce::kmp::getNext( std::string const& modelString){
	
	next_type next(modelString.length()); // init a next array

	size_type i =0, j = npos;

	// the [0] next is npos
	next[0] = npos ;	
	
	// get next[i+1]'s value
	// 	so i < length()-1
	while( i < modelString.length()-1 ) {
		
		if ( j == npos) {	// no suit, and j is end
			next[i+1] = 0;	// [i+1] shuold move to [0]
			++i;		// get next i+1
			j = 0;		// j is the next[i]
		} else if ( modelString[i] == modelString[j] ) {	// suit success
			next[i+1] = j+1;	// greater 1 than j 
			++i;	// get next i+1
			++j;	// j is the next[i]
		} else {
			j = next[j];	// not suit , j move to next[j]
		}
	}
#ifdef DBUG
	std::cout << modelString << std::endl;
	for (auto& i :next) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif
	return next;
}
