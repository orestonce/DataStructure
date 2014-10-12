#include "mfset.h"
#include <iostream>

int main() {
	
	restonce::MFSet m(10);
	
	m.parseRelation( std::vector<std::pair<std::size_t, std::size_t>>{
			{1 ,2 },
			{3 ,4 },
			{5 ,6 },
			{7 ,8 },
			{1 ,3 },
			{5 ,7 },
			{1 ,5 }
		});
	
	for(std::size_t i=0; i<m.size(); ++i) {
		if (m.isRoot(i) ) {
			std::cout << i << std::endl;
		}
	}

	return 0;
}
