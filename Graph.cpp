#include "Graph.h"
#include <boost/graph/graph_traits.hpp>

tony::Graph::Graph(int num_nodes, int num_edges) : 
    num_edges(num_edges), num_nodes(num_nodes), csr(BoostCSR(num_nodes)) {};

tony::Graph::~Graph(){};

void tony::Graph::add_edge(int src, int dest, int val) {
    //check if there already exists a parallel edge
    Vertex u = boost::vertex(src, csr);
    Vertex v = boost::vertex(dest, csr);

    boost::add_edges(u,v,csr);

    // if parallel image exists, put either the same value or the newly updated value depending on which one is larger



    
    




    //if parallel edge, either remove 

    // O.W keep
}