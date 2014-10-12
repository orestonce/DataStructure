#ifndef _HANOI_H_
#define _HANOI_H_

#include <string>

namespace restonce{
	/*
	 *	display the prucedure of move n element 
	 *		from 'source' pass by 'pass' to 'dest'
	 * */
	void hanoi(int n, const std::string&  source, const std::string& pass, const std::string& dest);
}

#endif
