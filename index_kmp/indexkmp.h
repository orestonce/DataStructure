#ifndef _INDEXKMP_H_
#define _INDEXKMP_H_

#include <string>
#include <vector>

namespace restonce{
	namespace kmp{
		typedef std::string::size_type size_type;
		typedef std::vector<size_type> next_type;
		constexpr size_type npos = std::string::npos ;
		/*
		 * get the model string index in main string from begin position
		 *  if main string dosen't contain model string,
		 *  	return npos
		 * */

		size_type index(std::string const& mainString, std::string const& modelString, size_type beginPosition=0);
		/*
		 * get the next array of model string
		 * */
		next_type getNext(std::string const& modelString);
	}
}

#endif // _INDEXKMP_H_
