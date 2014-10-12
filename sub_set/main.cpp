#include "bitarea.h"

int main() {
	
	std::vector<int> v{ 1, 3, 7, 9, 4};

	restonce::printSubSet(v.begin(), v.end(), v.size());

	return 0;
}
