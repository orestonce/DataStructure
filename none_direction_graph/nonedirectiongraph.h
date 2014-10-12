#ifndef _NONEDIRECTIONGRAPH_H_
#define _NONEDIRECTIONGRAPH_H_
#include <set>
#include <vector>
#include "graph.h"
namespace restonce{
	class NoneDirectionGraph: public Graph{
	public :
		NoneDirectionGraph(size_t pointNumbder_);
		// return the points of this graph
		virtual size_t pointNumbder() const  ;
		virtual bool sizeOk(size_t testSize) const  ;
		/*
		 * the follow 3 function
		 * 	you must suport true == sizeOk( first ) && true == sizeOk(second)
		 * */
		virtual void setLink(const LinkType& )  ;
		virtual bool getLink(const LinkType& )const ;
		virtual void unLink(const LinkType&  ) 	;
		virtual void depthFirstSearch() const 	;
		virtual void breadthFirstSearch() const ;
	private:
		std::vector< std::set<size_t> > data;
	};
}

#endif // _NONEDIRECTIONGRAPH_H_

