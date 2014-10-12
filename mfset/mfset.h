#ifndef _MFSET_H_
#define _MFSET_H_

#include <vector>
#include <utility>

namespace restonce{
	using size_t = std::size_t;
	using index_type = size_t;
	class MFSet: public std::vector<size_t>{
	public :
		static const index_type nidx ;
		
		// create an array to store parent-node's index
		// now , parent-node's index is all nindx
		MFSet(size_t max) : std::vector<index_type>(max, nidx) {}
		// judge whether the index is root
		// 	if i > size() , ub
		bool isRoot(index_type i) const {
			return (*this)[i] == nidx;
		}
		// find root index from child node
		// if i > size() , ub
		index_type findRoot(index_type i) const {
			index_type idx = i;

			while( !isRoot(idx) ) {
				idx = (*this)[idx];
			}
			return idx;
		}
		// merge two tree as a tree
		// if index > size() , ub
		void merge(index_type toRoot, index_type fromRoot) {
			(*this)[fromRoot] = toRoot ;
		}
		// get parse relations and merge the same relation with a tree
		void parseRelation(const std::vector< std::pair<size_t, size_t>>& relation){
			
			for( auto& r : relation) {
				int root1 = findRoot(r.first);
				int root2 = findRoot(r.second);

				if (root1 != root2) {
					merge(root1, root2);
				}
			}
		}
	};
	const index_type MFSet::nidx = -1;
}

#endif // _MFSET_H_
