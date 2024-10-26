#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <boost/graph/compressed_sparse_row_graph.hpp>
#include <boost/property_map/property_map.hpp>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

//.h define the class we want

/**
    NEEDS:
        1) constructor, gets passed in meta data
        2) destructor, frees any dyamically allocated 
        3) a static method   that handles created a COO
        4) another static method  that creates CSR


    QUESTION:
        - do we have IO file reading DIMAC and creating edges? 
        
        - Should we pass in FileBuffer to constructor and have constructor create the COO? 
            This seems the simpliest manner but it might be kinda wonky encapsualtion wise
 */

 /***
    TODO:  make gets and sets for meta data and edge weights

    TODO: make sudo code for creating COO

    TODO: make pseudo-code for COO -> CSR (thinking about duplicate parallel edges)

    
  */
namespace tony {
    /**
     * NOTE: because PageRank will be modifying a vector outside of our graph 
     *  by the time we are computing it, we will NOT need to modify the CSR.
     */
    
    // struct NodeLabel {
    //     int label;
    // };

    /**
     * NOTE: BoostCSR is Read-Only
     */
    
    //variable BoostCSR will be an alias for this long complicated template
    using BoostCSR = boost::compressed_sparse_row_graph<
        boost::directedS, // graph will be directed 
        boost::no_property, //
        boost::property<boost::edge_weight_t, int>>;
    
    using AdjacencyList = boost::adjacency_list<
        boost::vecS, //vertices will be stored in a vector
        boost::vecS, //edges will be stored in a vector
        boost::directedS, // directed edges
        boost::no_property, // vertex labels, which will be none in our case
        boost::property<boost::edge_weight_t,int>>; // edge weights
    
    using Vertex = boost::graph_traits<AdjacencyList>::vertex_descriptor;
    using Edge = boost::graph_traits<AdjacencyList>::edge_descriptor;



    class Graph {
        
    private:
        //fields
        int num_edges;
        int num_nodes;
        BoostCSR csr;
        AdjacencyList lst;
    
    
    public:
        //constructor
        /***
            INPUT: fstream
            OUTPUT: Graph object with populated COO
         */
        Graph(int num_nodes, int num_edges);   
        /*
            Plan for how to create COO

            - iterate through the fstream, line by line
            - process the line with special conditions for the meta data ('p') and edge ('a')

        */

        //destructor
        ~Graph();
        
        /**
            INPUT: src node ID, dest node ID
            OUTPUT: return nothing, but replace value in COO with VAL

            NOTE: for now let the label be -1
         */
        void add_edge(int src, int dest, int val);


        /**
         * QUESTION: Do we NEED this update_label? Because we want to only populate 
         *  the adjacency list 
         */

        /**
         * INPUT: src node (row ptr), and a new label
         * OUTPUT: label gets updated, old label is returned
         */
        // int update_label(int src, int label);
        
        /**
         * INPUT: user gives nothing, should use the graph object's adjacency list
         * OUTPUT: returns nothing, creates a read-only CSR
         */
        
        void finalize();

    }; 
 };

#endif
