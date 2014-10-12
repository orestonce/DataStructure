#include <vector>
#include <iostream>
#include "mazepath.h"

int main() {
	typedef restonce::PositionType PT;
    using restonce::ptWall;
    using restonce::ptSpace;

	std::vector<PT> ve = {
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,1,0,0,0,1,0,1,
		1,0,0,1,0,0,0,1,0,1,
		1,0,0,0,0,1,1,0,0,1,
		1,0,1,1,1,0,0,0,0,1,
		1,0,0,0,1,0,0,0,0,1,
		1,0,1,0,0,0,1,0,0,1,
		1,0,1,1,1,0,1,1,0,1,
		1,1,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1
		};

	restonce::Map map(10, 10, ve);
	restonce::Position begin(1, 1), end(8,8);

    	auto x = restonce::mazePath(map, begin, end);
	
	for (auto& i : x ) {
		i.print ();
	}

	return 0;
}
