#include "trials.h"
#include <iostream>

using namespace restonce;

Trials::Trials(size_t lineRowCount_) throw ( std::logic_error)
	: trials(lineRowCount_*lineRowCount_), lineRowCount(lineRowCount_) {
	if ( lineRowCount != 4 && lineRowCount != 8) {
		throw std::logic_error("Line row not support");
	}	
}


void Trials::outputTrial() const {
	for(size_t line=0; line<lineRowCount; ++line) {
		for(size_t row=0; row < lineRowCount; ++row) {
			if ( trials[line * lineRowCount + row] ) {
				std::cout << "* ";
			} else {
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Trials::putTrial(size_t l, size_t r) {
	trials[l * lineRowCount + r] = true;
}

bool Trials::leagle(size_t l, size_t r) const {
	size_t line, row;
	// judge same line
	for( row =0; row<lineRowCount; ++row){
		if ( hasTrials(l, row) && row != r) {
			return false;
		} 
	}
	// judge same row
	for(line =0; line<lineRowCount; ++line) {
		if ( hasTrials(line, r) && line != l) {
			return false;
		}
	}
	// judge \ lr
	if (l > r) {
		line = l - r;
		row = 0;
	} else {
		line = 0;
		row = r - l;
	}
	while ( row < lineRowCount && line < lineRowCount) {
		if (hasTrials(line, row) && line != l && row != r) {
			return false;
		}
		++ line;
		++ row ;
	}
	// judge / 
	line =l , row =r;

	while( line >0 && row < lineRowCount-1 ) {
		-- line;
		++ row;
	}

	while ( row >= 0  && line < lineRowCount) {
		if (hasTrials(line, row) && line != l && row != r) {
			return false;
		}
		++ line;
		-- row ;
	}
	return true;
}
void Trials::dropTrial(size_t l, size_t r) {
	trials[l * lineRowCount + r] = false;
}

bool Trials::at(size_t l, size_t r) const {
	return trials[l * lineRowCount + r];
}

bool Trials::hasTrials(size_t l, size_t r) const {
	return at(l, r)== true;
}

void Trials::trial(size_t i) {
	if ( i == lineRowCount) {
		outputTrial();
	} else {
		for ( size_t x=0; x != lineRowCount; ++x) {
			putTrial(i , x);
			if ( leagle(i, x) ) {
				trial(i+1);
			}
			dropTrial(i, x);
		}
	}
}
