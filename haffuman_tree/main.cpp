#include "haffumantree.h"
#include <iostream>

int main() {
	std::vector<double> src = {1 ,28 , 6, 8};

	restonce::HaffumanTree ht( src.begin(), src.end() );
	
	for(std::size_t index=0; index< ht.size(); ++index) {
		std::cout << src[index] << "\t";

		for( auto i : ht[index] ) {
			std::cout << i ;
		}
		std::cout << std::endl;
	}
	return 0;
}
