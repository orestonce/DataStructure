#include "haffumantree.h"

restonce::index_type restonce::utility::getMinWeightRoot(const std::vector<HTNode>& tree) {
	index_type minWeightIndex= restonce::nidx;
	
	for(std::size_t i=0; i< tree.size(); ++i) {
		if (tree[i].isRoot() ){
			minWeightIndex = i;
			break;
		}
	}

	for(std::size_t i=minWeightIndex; i< tree.size(); ++i) {
		if (tree[i].isRoot() && tree[i].getWeight() < tree[minWeightIndex].getWeight()) {
			minWeightIndex = i;
		}
	}
	return minWeightIndex;
}
	
bool restonce::utility::treeCountIs( const std::vector<HTNode>& tree, std::size_t i) {
	std::size_t treeCount(0);

	for(auto& n: tree) {
		if ( n.isRoot() ){
			++treeCount;
			if (treeCount > i) {
				break;
			}
		}
	}
	return treeCount == i;
}

using namespace restonce;
using namespace restonce::utility;

std::vector<HaffumanCodeType> restonce::utility::buildHaffumanCodeData(const std::vector<HTNode>& tree) {
	return buildHaffumanCodeData( std::vector<HTNode>(tree) );
}
std::vector<HaffumanCodeType> restonce::utility::buildHaffumanCodeData(std::vector<HTNode>&& tree) {
	
	std::size_t oldTreeSize = tree.size();
	std::vector<HaffumanCodeType> data;

	while ( utility::treeCountIs(tree, 1) == false ) {
		std::pair<index_type,index_type> minWeights ;
			
		minWeights.first = utility::getMinWeightRoot(tree);
		tree[ minWeights.first].setIsNotRoot();
		tree[ minWeights.first].isLeftChild = true;
		tree[ minWeights.first].parent = tree.size();
		
		minWeights.second = utility::getMinWeightRoot(tree);
		tree[ minWeights.second].setIsNotRoot();
		tree[ minWeights.second].isLeftChild = false;
		tree[ minWeights.second].parent = tree.size();
		
		tree.push_back( utility::HTNode( tree[minWeights.first].weight + tree[minWeights.second].weight) );
	}
	
	for (size_t i=0; i<oldTreeSize; ++i) {
		std::vector<bool> rHaffumanCode;
		size_t currentNode = i;
		
		while ( tree[currentNode].isRoot() == false) {
			rHaffumanCode.push_back( !tree[currentNode].isLeftChild);
			currentNode = tree[currentNode].parent;
		}
		
		data.push_back( std::vector<bool>(rHaffumanCode.rbegin(), rHaffumanCode.rend()) );
	}
	return data;
}
