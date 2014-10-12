#include "evaluateexpression.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <ctype.h>
#include <algorithm>
/*
 *	numbser stack type, store numbers 
 * */
class NU_Stack: public std::stack<double> {
public :
	/*
	 *	read a double number from istream , 
	 *		return the istream after read
	 * */
	std::istream& readDouble(std::istream& is) {
		double number ;
		if ( is >> number ) {
			push(number);
		}
		return is;
	}
	/*
	 *	pop tow numbers , and use the char argument to caculate result, at last, push the result to self
	 *		if self's number less than 2 , throw a logic_error
	 *		if char argument unkown, throw a logic_error
	 * */
	void caculate(char op) throw ( std::logic_error) {
		if (size() < 2) {
			throw std::logic_error("Caculate number less than 2 !");
		}
		double number1 , number2;
		number2 = top(); pop();
		number1 = top(); pop();
		
		switch( op ) {
			case '+' :
				push(number1 + number2);
				break;
			case '-' :
				push(number1 - number2);
				break;
			case '*' :
				push(number1 * number2);
				break;
			case '/' :
				if ( number2 < 0.00001 && number2 > -0.00001 ) {
					throw std::logic_error("Divied by zero !");
				}
				push(number1 / number2);
				break;
			default :
				throw std::logic_error( std::string("Unknown operator '") + op + "' !" );
		}
	}
	/*
	 * End : stack rest the last number,
	 * 	return whether the numbser stack is end
	 * */
	bool assertEnd() const {
		return size() == 1;
	}
};
/*
 * operator stack 
 * */
class OP_Stack: public std::stack<char> {
public :
	/*
	 * End : stack rest the last operator and equals '#'
	 * 	return whether the operator stack is end
	 * */
	bool assertEnd() const {
		return size() == 1 && top() == '#';
	}
};


class CompareOperator{
private :
	// store the relationship of 7 operator , the line_number is the first operator index
	// 	the row_number is the second index
	static const char relationship[7][7]; 
	static const char table[7] ;	// store operators 
public  :
	// compare two operator and return the relationship of them
	static char cmp(char op1, char op2) {
		int index1 = std::find(table, table+sizeof(table)/sizeof(*table), op1) - table;
		int index2 = std::find(table, table+sizeof(table)/sizeof(*table), op2) - table;
		
		return relationship[index1][index2];
	}
};
const char CompareOperator::relationship[7][7] = {
	// op2 	   + ,  - ,  * ,  / ,  ( ,  ) ,  #
	{ '>', '>', '<', '<', '<', '>', '>'} ,	// + 	operator 1
	{ '>', '>', '<', '<', '<', '>', '>'} ,	// -
	{ '>', '>', '>', '>', '<', '>', '>'} ,	// *
	{ '>', '>', '>', '>', '<', '>', '>'} ,	// /
	{ '<', '<', '<', '<', '<', '=', '?'} ,	// (
	{ '>', '>', '>', '>', '?', '>', '>'} ,	// )
	{ '<', '<', '<', '<', '<', '?', '='}	// #
};

const char CompareOperator::table[7] = {'+', '-', '*', '/', '(', ')', '#'};

double restonce::evaluateExpression(const std::string& expr) throw( std::logic_error) {
	OP_Stack op_stack;
	NU_Stack nu_stack;
	op_stack.push('#');	// save a '#' to operator stack

	std::istringstream is(expr); // read data from is

	for (char ch=is.peek(); ch != '#' && is; ch = is.peek() ) {
		if ( isspace(ch) ) {	// permit many space
			is.get(ch) ;	// clear space
		} else if( isdigit(ch) ) {	// number , direct into number stack
			nu_stack.readDouble(is);
		} else {
			switch( CompareOperator::cmp(op_stack.top(), ch) ) {	
				case '<' :			
					op_stack.push(ch);
					is >> ch;
					break;
				case '=' :			// clear '(' and ')'
					op_stack.pop();
					is >> ch;
					break;
				case '>' :
					if ( op_stack.assertEnd() ) {
						throw std::logic_error("Operator stack empty !");
					}
					nu_stack.caculate( op_stack.top() );
					op_stack.pop();
					break;
				default  :
					throw std::logic_error("Can't compare !");
					break;
			}
		}
	}
	// caculate end with operator stack
	while ( op_stack.assertEnd() == false) {
		nu_stack.caculate( op_stack.top() );
		op_stack.pop();
	} 
	// caculate end , the number stack must be End
	if ( nu_stack.assertEnd() == false) {
		throw std::logic_error("Number stack final not empty !");
	}
	return nu_stack.top();
}
