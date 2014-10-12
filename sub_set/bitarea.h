#ifndef _BITAREA_H_
#define _BITAREA_H_

#include <vector>
#include <iostream>

namespace restonce{
	using size_t = std::size_t;
	// print the element of two mark as m
	// if ( count(begin, end) > m.size() ) , ub
	// else if ( < ) , will check the forward count(begin, end)
	template<class Inputiterator>
	void mirrrorOutput(Inputiterator begin, Inputiterator end, const std::vector<bool>& m, std::ostream& out = std::cout) {
		out << "[";
		for(auto f : m) {
			if ( f == true) {	// mark is true , should print
				out << *begin << " ";
			}
			++ begin;
		}
		out << "]";
	}
	// manage whether the [i] should be output
	class BitArea: public std::vector<bool>{
	public :
		BitArea(size_t length, bool value) : std::vector<bool>(length, value){}
		// if rhs.size() != size() , ub
		bool operator != (const BitArea& rhs) const;
		BitArea& operator++ () ;
		static BitArea maxValue(size_t length) ;
	};
	// output all sub-set besides [begin, end)
	//  elementsCount should be count(begin, end), or ub
	template <class Inputiterator>
	void printSubSet(Inputiterator begin, Inputiterator end, size_t elementsCount, std::ostream& out = std::cout) {
		for (BitArea ba(elementsCount, false); 
			ba != BitArea::maxValue(elementsCount);
			++ ba) {
			mirrrorOutput(begin, end, ba, out);
			out << "\n";
		}
		mirrrorOutput(begin, end, BitArea::maxValue(elementsCount), out);
	}
}

#endif	// _BITAREA_H_
