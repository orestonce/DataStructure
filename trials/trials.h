#ifndef _TRIALS_H_
#define _TRIALS_H_

#include <vector>
#include <stdexcept>

namespace restonce{
	using size_t= std::size_t;

	class Trials{
	public :
		// lineRowCount_ should be 4, 8
		// or throw logic_error
		Trials(size_t lineRowCount_) throw (std::logic_error);
		void trial() { trial(0); }
	private:
		// begin the trials of l line 
		void trial(size_t l);
		// print trial status 
		void outputTrial() const;
		// put a trial to l line, r row
		void putTrial(size_t l, size_t r);
		// judge the trial( l line r row) is leagle
		bool leagle(size_t l, size_t r) const;
		// drop trial from l line, r row
		void dropTrial(size_t l, size_t r);
	private:	
		// get value 
		bool at(size_t l, size_t r) const;
		// has trials
		bool hasTrials(size_t l, size_t r) const ;
	private:
		std::vector<bool> trials;
		size_t lineRowCount;
	};
}

#endif // _TRIALS_H_
