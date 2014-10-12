#include "lineeditor.h"
#include <iostream>
#include <string>

int main() {
	
	std::string line;

	while ( getline(std::cin, line) ) {
		std::cout << restonce::line_editor(line) << std::endl;
	}

	return 0;
}
