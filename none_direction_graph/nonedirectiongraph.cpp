#include "nonedirectiongraph.h"
#include <iostream>
using namespace restonce;

NoneDirectionGraph::NoneDirectionGraph(size_t pointNumbder_) : data(pointNumbder_){ }

size_t NoneDirectionGraph::pointNumbder() const {
	return data.size();
}

bool NoneDirectionGraph::sizeOk(size_t testSize) const {
	return pointNumbder() > testSize;
}
bool NoneDirectionGraph::getLink(const LinkType& link) const {
	return data[link.first].end() != data[link.first].find(link.second);
}

void NoneDirectionGraph::setLink(const LinkType& link) {
	data[link.first].insert(link.second);
	data[link.second].insert(link.first);
}

void NoneDirectionGraph::unLink(const LinkType& link) {
	if ( getLink(link) == true) {
		auto posFirst = data[link.first].find(link.second);
		data[link.first].erase(posFirst);
		auto posSecond= data[link.second].find(link.first);
		data[link.second].erase(posSecond);
	}
}

void depthFirstSearchGlobal(const std::vector<std::set<size_t>>& graphData,size_t dest, std::vector<bool>& visitFlag) {
	if ( visitFlag[dest] == true) {
		return ;
	} else {
		visitFlag[dest] = true;
		std::cout << dest << "\t";
		for (auto& i : graphData[dest]) {
			depthFirstSearchGlobal(graphData, i, visitFlag);
		}
	}
}

void NoneDirectionGraph::depthFirstSearch() const{
	if (pointNumbder() != 0) {
		std::vector<bool> visitFlag( pointNumbder() , false);
		for ( size_t i=0; i<pointNumbder(); ++i) {
			depthFirstSearchGlobal(data, i, visitFlag);
		}
		std::cout << std::endl;
	}
}

#include <deque>

void breadthFirstSearchGlobal(const std::vector<std::set<size_t>>& graphData,std::deque<size_t>& subPoints, std::vector<bool>& visitFlag) {
	while( subPoints.empty() == false){
		size_t i = subPoints.front() ;
		subPoints.pop_front();
		if (visitFlag[i] == false) {
			visitFlag[i] = true;
			std::cout << i << "\t";
			for (auto& x : graphData[i]) {
				if (visitFlag[x] == false) {
					subPoints.push_back(x);
				}
			}
		}
	}
}

void NoneDirectionGraph::breadthFirstSearch() const{
	if (pointNumbder() != 0) {
		std::deque<size_t> subPoints;
		std::vector<bool> visitFlag(pointNumbder());

		for(size_t i=0; i<pointNumbder(); ++i) {
			subPoints.push_back(i);
			breadthFirstSearchGlobal(data, subPoints, visitFlag);
		}
		std::cout << std::endl;
	}
}
