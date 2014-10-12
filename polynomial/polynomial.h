#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <iostream>
#include <stdexcept>
#include <list>

/*
 * caculate sum of two Polynomial 
 * 	by orestonce , homepage : www.restonce.com
 * */

namespace restonce{
	class Polynomial;
	class PolyElement{	// store every Polynomial elment to this class
	public:
		friend class Polynomial;
		friend std::istream& operator>> (std::istream& in, Polynomial& p); 
		
		PolyElement(int coef_, int expn_) : coef(coef_), expn(expn_) {}
		friend std::ostream& operator<< (std::ostream& out, const PolyElement& p) {
			if (p.coef < 0) {
				out <<"(" << p.coef << ")";
			} else {
				out << p.coef ;
			}
			if (p.getExpn() == 1) {
				out << " * x ";
			} else if (p.getExpn() !=0 ) {	
				out << " * x ^ " << p.expn ;
			}
			return out;
		}
		friend std::istream& operator>> (std::istream& in, PolyElement& p) {
			std::cout << "coef : ";
				in >> p.coef;
			if (in) {
				std::cout << "expn : ";
					in >> p.expn;
			}
			if ( !in || p.expn <0 ) {
				p.clear();
				in.setstate(std::ios::badbit | std::ios::failbit);
			}
			return in;
		}
		void clear() {
			coef = -1;
			expn = -1;
		}
		bool operator< (const PolyElement& pr) const{
			return this->expn < pr.expn;
		}
		PolyElement operator+ (const PolyElement& pr) const throw( std::logic_error) {
		 	if ( this->expn != pr.expn ) {
				throw std::logic_error("Expn not equal !");
			}
			return PolyElement(this->coef+pr.coef, this->expn);
		}
		bool equalExpn(const PolyElement& pr) const {
			return this->expn == pr.expn;
		}
		int getCoef() const { return coef; }
		int getExpn() const { return expn; }
	private :
		int coef;	// coef * x
		int expn;	// x ^ expn
	};
	class Polynomial {
	public :
		Polynomial() {}
		friend std::ostream& operator<< (std::ostream& out, const Polynomial& p) {
			auto it = p.expression.begin();
			out << *it ;
			++it;
			
			while ( it != p.expression.end() ) {
				out << " + " << *it ;
				++ it;
			}
			
			return out;
		}
		friend std::istream& operator>> (std::istream& in, Polynomial& p) {
			std::list<PolyElement> tmp;
			PolyElement input(-1, -1) ;
			
			while (in >> input) {
				tmp.push_back(input);
			}
			tmp.sort();
			p.expression.clear();

			for (auto beg= tmp.begin(); beg != tmp.end(); ) {
				auto end = beg;
				int coefSum =0;

				while ( end != tmp.end() && beg->equalExpn(*end) ) {
					coefSum += end->getCoef(); 
					++end;
				}
				if (coefSum != 0) {
					p.expression.push_back(PolyElement(coefSum, beg->getExpn()) ) ;
				}
				beg = end;
			}
			in.clear();
			return in;
		}
		Polynomial operator+ (const Polynomial& prhs) const {
			Polynomial sum ;
			
			auto it1 = this->expression.begin(), end1 = this->expression.end();
			auto it2 = prhs.expression.begin(), end2 = prhs.expression.end();

			while ( it1 != end1 && it2 != end2) {
				if ( it1->equalExpn(*it2) ) {
					PolyElement p (it1->getCoef() +it2->getCoef(), it1->getExpn());
					if ( p.getCoef() != 0) {
						sum.expression.push_back( p);
					}
					++it1 ;
					++it2 ;
				} else if (it1->getExpn() < it2->getExpn() ) {
					sum.expression.push_back( *it1);
					++it1 ;
				} else {
					sum.expression.push_back( *it2);
					++it2 ;
				}
			}
			while ( it1 != end1 ) {
				sum.expression.push_back( *it1);
				++it1 ;
			}
			while ( it2 != end2 ) {
				sum.expression.push_back( *it2);
				++it2 ;
			}
			return sum;
		}
	private :
		std::list<PolyElement> expression;
	};
}

#endif	// _POLYNOMIAL_H_
