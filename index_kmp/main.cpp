#include "indexkmp.h"
#include <iostream>

int main() {
	
	std::cout << restonce::kmp::index("182abaabc", "abaabc") << std::endl;

	return 0;
}
