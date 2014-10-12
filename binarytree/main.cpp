#include "binarytree.h"

bool print(char ch) {
	std::cout << ch << "\t";
	return true;
}

int main() {
	restonce::BinaryTree<char> t;
	
	t.readFrom(std::cin, '0');
	
	restonce::BinaryTree<char> bt(t);

	bt.preTraverse(print);
	std::cout << std::endl;

	bt.midTraverse(print);
	std::cout << std::endl;
	
	bt.aftTraverse(print);
	std::cout << std::endl;

	return 0;
}
