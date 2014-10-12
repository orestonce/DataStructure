#include "hanoi.h"
#include <iostream>

/*
 *	certainly move a plate prucedure , from 'source' to dest
 * */
void move(int number, const std::string& source, const std::string& dest) ;

void restonce::hanoi(int n, const std::string&  source, const std::string& pass, const std::string& dest) {
	if ( n == 1) {			// only one plate , directly move
		move(1, source, dest);
	} else {
		hanoi(n-1, source, dest, pass);	// move the ups to 'pass' by 'dest'
		move(n, source, dest);		// move the biggest plate from 'source' to 'dest'
		hanoi(n-1, pass, source, dest);	// move the ups to 'dest' by 'source'
	}
}

void move(int number, const std::string& source, const std::string& dest) {
	std::cout << number << "\t" << source << " -> " << dest << std::endl;
}
