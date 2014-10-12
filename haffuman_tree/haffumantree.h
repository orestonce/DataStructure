#ifndef _HAFFUMANTREE_H_
#define _HAFFUMANTREE_H_

#include <vector>
#include <utility>
/*
 * create by restonce@163.com
 * */
namespace restonce{
	/*
	 * define self types
	 * */
	using size_t = std::size_t;
	using index_type = std::size_t;
	using HaffumanCodeType =std::vector<bool> ;
	
	constexpr index_type nidx = -1;
	
	namespace utility{
		/*
		 * manage haffuman node 
		 * */
		class HTNode{
		public :	
			friend std::vector<HaffumanCodeType> buildHaffumanCodeData(std::vector<HTNode>&& );
			HTNode(double weight_, restonce::index_type parent_ = restonce::nidx)
				: weight(weight_), parent(parent_), isLeftChild(false) {}
			bool isRoot() const 
				{ return parent == restonce::nidx; }
			void setIsNotRoot() { parent = restonce::nidx; }
			double getWeight() const 
				{ return weight; }
		private :
			double weight;
			index_type parent;
			bool isLeftChild;
		};
		/*
		 * get minimal weight index from tree nodes
		 * 	if the tree count ==0 , return restonce::nidx
		 * */
		restonce::index_type getMinWeightRoot(const std::vector<HTNode>& tree); 
		/*
		 * return whether the tree root-count ==i
		 * */
		bool treeCountIs( const std::vector<HTNode>& tree,std::size_t i) ;
		/*
		 * return a HaffumanCode vector hfv, the code of trees[i] is hfv[i]
		 * */
		std::vector<HaffumanCodeType> buildHaffumanCodeData(const std::vector<HTNode>& trees);
		std::vector<HaffumanCodeType> buildHaffumanCodeData(std::vector<HTNode>&& trees);
	}
	class HaffumanTree{
	public :
		/*
	 	*  HaffumanTree, build from two input iterator
	 	* */
		template <class InputIterator> 
		HaffumanTree(InputIterator begin, InputIterator end) {
			std::vector<utility::HTNode> tree;
			
			for(auto it=begin; it != end; ++it) {
				tree.push_back(*it);
			}
			data = utility::buildHaffumanCodeData(tree);
		}
		HaffumanCodeType operator[](index_type i) const noexcept{
			return data[i];
		}
		HaffumanCodeType at(index_type i) const {
			return data.at(i);
		}
		size_t size() const noexcept{
			return data.size();
		}
	private:
		std::vector<HaffumanCodeType> data;
	};
}

#endif // _HAFFUMANTREE_H_
