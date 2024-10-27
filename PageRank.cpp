/***
    PURPOSE: implement page rank algorithm for our DIMAC Graph Object
 */

#include <vector>
#include "Graph.h"

std::vector<double> calculatePageRank(Graph g){

    std::vector<double> pageRanks(N, 0.0);
    std::vector<double> newRanks(N, 0.0);
    int N = g.get_num_nodes();
    //get the row ptrs, and col indices from csr

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        for (int u = 0; u < N; u++) {
            new_rank[u] = (1.0 - DAMPING_FACTOR) / N;
            for (int v = 0; v < N; v++) {
                if (Graph::isLinked(v, u)) {
                    new_rank[u] += DAMPING_FACTOR * page_rank[v] / Graph::get_out_degree(v);
                }
            }
        }
    }
    return pageRanks;
}