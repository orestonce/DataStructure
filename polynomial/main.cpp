#include <iostream>
#include "polynomial.h"

int main() {
	
	restonce::Polynomial p1, p2;

	std::cin >> p1 >> p2;
	
	std::cerr << p1 << " + " << p2 << " = " << ( p1+ p2) << std::endl;

	return 0;
}
