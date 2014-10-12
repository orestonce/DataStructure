#include "nonedirectiongraph.h"

int main(){
	
	restonce::Graph* ndg = new restonce::NoneDirectionGraph(8);

	ndg->setLink( std::make_pair(0, 1) );
	ndg->setLink( std::make_pair(1, 3) );
	ndg->setLink( std::make_pair(4, 1) );
	ndg->setLink( std::make_pair(7, 3) );
	ndg->setLink( std::make_pair(7, 4) );
	ndg->setLink( std::make_pair(2, 0) );
	ndg->setLink( std::make_pair(2, 6) );
	ndg->setLink( std::make_pair(2, 5) );
	
	ndg->depthFirstSearch();
	ndg->breadthFirstSearch();
	
	delete ndg;

	return 0;
}
