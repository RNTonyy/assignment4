#include "Graph.h"
#include <boost/graph/graph_traits.hpp>

using namespace tony;

Graph::Graph(int num_nodes, int num_edges) : 
    num_edges(num_edges), num_nodes(num_nodes), csr(BoostCSR(num_nodes)) {};

Graph::~Graph(){};

void Graph::add_edge(int src, int dest, int new_val) {
    //check if there already exists a parallel edge
    Vertex u = boost::vertex(src, lst);
    Vertex v = boost::vertex(dest, lst);

    Edge e;
    // returns both the actual edge and the state of its existence
    // std::pair is roughly similar to tulip in that it allows you to couple 
    // two unmutable pieces of data together in a pair
    std::pair<Edge, bool> edge_pair = boost::edge(u,v,lst);

    //check if edge exists
    if (edge_pair.second) {
        e = edge_pair.first;
        int cur_val = boost::get(boost::edge_weight, lst, e);
        if (new_val > cur_val) {
            boost::put(boost::edge_weight, lst, e, new_val);
        }
    } else { // edge currently DNE 
        boost::add_edge(u,v,new_val,lst);
    }
}

void Graph::finalize() {
    // Convert the adjacency list to a CSR graph
    
    

}