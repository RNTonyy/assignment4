#include <boost/graph/compressed_sparse_row_graph.hpp>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace tony;


Graph::Graph(int num_nodes, int num_edges) : num_nodes(num_nodes), 
    num_edges(num_edges), 
    edges(std::vector<std::tuple<int, int, int>>()) {}


void Graph::add_edge(int src, int dst, int val){
    //if edge is in vector check if val greater, else if not in vector add edge
    int replace_at = edge_exist(edges, src, dst);

    if (replace_at != -1 && std::get<2>(edges[replace_at]) < val) {
        edges[replace_at] = std::make_tuple(src, dst, val);
    }else {
        edges.push_back(std::make_tuple(src, dst, val));
    }
    
}

int edge_exist(std::vector<std::tuple<int,int,int>> edges, int src, int dst){
    auto it = std::find_if(edges.begin(), edges.end(),
                           [src, dst](const std::tuple<int, int, int>& edge) {
                               return std::get<0>(edge) == src && std::get<1>(edge) == dst;
                           });

    // Check if the edge was found
    if (it != edges.end()) {
        return std::distance(edges.begin(), it);  // Calculate the index
    } else {
        return -1;  // Indicate that the edge does not exist
    }
}

void Graph::create_csr(){
    BoostCSR csr(boost::edges_are_unsorted_multi_pass, edges.begin(), edges.end(), num_nodes);
    
}



