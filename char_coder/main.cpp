#include "charcoder.h"
#include <iostream>

int main() {
	std::string old = "12345sajasdjkjiowji";
	std::string enc = restonce::encoder(old);
	std::string dec = restonce::decoder(enc);
	
	std::cout << old << std::endl;
	std::cout << enc << std::endl;
	std::cout << dec << std::endl;

	return 0;
}
