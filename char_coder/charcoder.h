#ifndef _CHARCODER_H_
#define _CHARCODER_H_

#include <string>
namespace restonce{
	// encode every char to 16-step number's string
	std::string encoder(const std::string& );
	// decode from a 16-step number's string,
	// if not hex, return front covert out 
	std::string decoder(const std::string& );
}

#endif // _CHARCODER_H_
