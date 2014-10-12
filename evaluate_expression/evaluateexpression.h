#ifndef _EVALUATEEXPRESSION_H_
#define _EVALUATEEXPRESSION_H_

#include <string>
#include <stdexcept>

namespace restonce{
	/*
	 * caculate the expression value , like 
	 * 	1+23*(34-5)#
	 * 		the expression should end with '#'
	 * */
	double evaluateExpression(const std::string& expr) throw( std::logic_error) ;
}

#endif
