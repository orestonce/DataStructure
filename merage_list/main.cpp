#include "meragelist.h"
#include <list>
#include <iostream>

int main() {
	
	std::list<int> 	l1 = {1, 2, 5, 8, 9, 15},
			l2 = {3, 6, 7, 9, 13, 16},
			r ;

	r = restonce::merageList(l1, l2);
	
	for (auto x: l1) {
		std::cout << x << "\t";
	}
	std::cout << std::endl;
	for (auto x: l2) {
		std::cout << x << "\t";
	}
	std::cout << std::endl;
	for (auto x: r) {
		std::cout << x << "\t";
	}
	std::cout << std::endl;

	return 0;
}
