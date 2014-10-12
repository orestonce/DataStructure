#include "lineeditor.h"
#include <string>

std::string restonce::line_editor(const std::string& input) {
	std::string real_string ;	// store the real string 
	
	for ( char ch : input ) {
		switch(ch) {
			case '#' :	
				if (real_string.empty() == false) {	// if not empty , pop
					real_string.pop_back();
				}
				break;
			case '@' :
				real_string.clear();	// clear command
				break;
			default :
				real_string.push_back(ch);	// normal charactors , store to real_string
		}
	}

	return real_string;
}
