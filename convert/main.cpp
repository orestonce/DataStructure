#include "convert.h"
#include <iostream>
#include <string>

int main() {
	
	int origin_10;

	std::cin >> origin_10;
	
	std::cout << convert(origin_10, 8) << std::endl;

	return 0;
}

