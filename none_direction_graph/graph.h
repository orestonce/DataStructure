#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <utility>
namespace restonce{
	/*
	 * two ways to display a none-direction-graph, 
	 * */
	using size_t= std::size_t;
	class Graph{
	public :
		using LinkType= std::pair<size_t, size_t>;
		// return the points of this graph
		virtual size_t pointNumbder() const =0 ;
		virtual bool sizeOk(size_t testSize) const =0 ;
		/*
		 * the follow 3 function
		 * 	you must suport true == sizeOk( first ) && true == sizeOk(second)
		 * */
		virtual void setLink(const LinkType& )  =0 ;
		virtual bool getLink(const LinkType& )const 	=0 ;
		virtual void unLink(const LinkType&  ) 	=0 ;
		virtual void depthFirstSearch() const 	=0 ;
		virtual void breadthFirstSearch() const = 0;
		virtual ~Graph() {}
	};
}

#endif //_GRAPH_H_
