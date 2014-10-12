#include "suitpair.h"
#include <iostream>
#include <string>

int main() {
	
	std::string line ;
	
	while ( getline( std::cin, line) ) {
		std::cout << restonce::suit_pair(line) << std::endl;
	}

	return 0;
}
