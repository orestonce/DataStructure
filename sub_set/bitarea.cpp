#include "bitarea.h"

bool restonce::BitArea::operator !=( const BitArea& rhs) const {
	for (size_t i=0; i< size(); ++i) {
		if ( (*this)[i] != rhs[i] ) {
			return true;
		}
	}
	return false;
}

restonce::BitArea& restonce::BitArea::operator++() {
	for(size_t i=0; i<size(); ++i) {
		(*this)[i] = !(*this)[i];

		if ( (*this)[i] ) {
			break;
		}
	}
	return *this;
}

restonce::BitArea restonce::BitArea::maxValue(size_t length) {
	return BitArea(length,true);
}
