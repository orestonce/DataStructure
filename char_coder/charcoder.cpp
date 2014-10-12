#include "charcoder.h"
#include <sstream>
#include <iomanip>

std::string restonce::encoder(const std::string& str) {
	std::ostringstream os;

	os << std::setw(2) << std::setfill('0') << std::hex << std::uppercase;

	for(short int ch: str) {
		os << ch;
	}
	return std::move( os.str()) ;
}

std::string restonce::decoder(const std::string& str) {
	std::istringstream is(str);
	std::string afterDecod;

	std::string temp("xx");

	while(is>>temp[0]>> temp[1]) {
		afterDecod += char( std::stoi(temp,nullptr, 16) );
	}

	return std::move(afterDecod);
}
