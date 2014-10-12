#include "suitpair.h"
#include <string>
#include <stack>
#include <algorithm>

class HalfPair{
public :
	typedef std::string::size_type size_type;	// define a new index type to loation charactor
	HalfPair(const std::string& half) : inner_string(half) {}	// constructor
	bool contains(char ch) const { 	// return whether ch in inner_string
		return std::find(inner_string.begin(), inner_string.end(), ch) != inner_string.end(); 
	}
	char operator[] (size_type i) const { 	// read the charactor of inner_string , index by i
		return inner_string[i]; 	// if ( i>= inner_string.size() || i < 0)  behavier undefined 
	}
	size_type location(char ch) const { 	// find the first position of ch , if inner_string not contains ch , return inner_string.size()
		return std::find(inner_string.begin(), inner_string.end(), ch) - inner_string.begin(); 
	}
private :
	std::string inner_string;
};

/*
 * suit_pair , if suit ok , return true 
 * 	or return false
 * */	
bool restonce::suit_pair(const std::string& expr) {
	HalfPair front("{[(");	// front charactors
	HalfPair back("}])");	// back charactors
	bool suit(true);	// default suit

	std::stack<char> stack;	// store front charactors

	for (auto ch : expr) {
		if (front.contains(ch)) {
			stack.push(ch);
		} else if ( back.contains(ch) ) {
			if (stack.empty() || stack.top() != front[ back.location(ch) ] ) {
				suit = false;
				break;
			}
			stack.pop();
		}
	}
	
	if (suit == true) {	// if didn't break, judge by stack
		suit = stack.empty();
	}

	return suit;
}
