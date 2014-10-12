#include "convert.h"
#include <string>
#include <stdexcept>
#include <stack>

std::string convert(int origin_10, int step ) throw ( std::logic_error ){
	if (step <2 || step > 10 ) {				// convert destnation error 
		throw std::logic_error("Convert step error !");
	}
	
	std::string after_convert_str;			// store output result
	if (origin_10 < 0) {				// judge <0
		origin_10 = -origin_10;
		after_convert_str.push_back('-');
	}

	std::stack<char> after_convert_stk;		// after conversion , store every bits to here

	while (origin_10 ) {
		after_convert_stk.push('0' + origin_10%step );	// save to stack
		origin_10 /= step;			// decrease
	}
	while (after_convert_stk.empty() == false) {	// move to output string
		after_convert_str.push_back(after_convert_stk.top());
		after_convert_stk.pop();
	}
	if (after_convert_str.empty() ) {	// is zero
		after_convert_str = "0";
	}
	return after_convert_str;	
}
