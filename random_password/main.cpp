#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>

/*
 *  create a random password length [12,16),
 *  	and a-z && A-Z && 0-9 
 * */
int main() {
	std::vector<char> contains ;	// contain all charactors which have chance to appear 
	
	for (char c='a' ; c <= 'z'; ++c) {
		contains.push_back(c);			// push ['a', 'z']
		contains.push_back(c- ('a' - 'A') );	// push ['A', 'Z']
	}	
	for (char c='0'; c <= '9'; ++c) {		// push ['0', '9']
		contains.push_back(c);
	}

	srand(time(nullptr) + clock() );	// set time and runtime as a random seed
	
	std::string password;			// store random password 
	
	for (int i=0; i< rand()%4 + 12; ++i) {	// random stop , but greater than 12 and less than 16
		password.push_back( contains[ rand() % contains.size()] );	// random select
	}
	
	std::cout << password << std::endl;	// output password

	return EXIT_SUCCESS;	// end
}
