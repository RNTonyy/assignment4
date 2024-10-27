#include <iostream>
#include <vector>
#include <fstream>
#include <boost/graph/compressed_sparse_row_graph.hpp>
#include <boost/graph/properties.hpp>
#include <tuple>

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



    using BoostCSR = boost::compressed_sparse_row_graph<boost::directedS, 
    boost::property<boost::edge_weight_t, int>>;


    class Graph {

        /** NOTE: COO will be it's own data structure with COO entry */
        

    private:
        //fields
        int num_edges;
        int num_nodes;
        std::string format;
        BoostCSR csr;
        std::vector<std::tuple<int, int, int>> edges;
        
    
    
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

        //methods
    
        
        /**
            INPUT: src node ID, dest node ID
            OUTPUT: return nothing, but replace value in COO with VAL
         */
        void add_edge(int src, int dst, int val);

        /**
            INPUT: src node ID, dest node ID
            OUTPUT: return nothing, but update value if > old_val
         */

        
        void create_csr();
        
        /**
            INPUT: COO storage
            OUTPUT: Initializes CSR with values
         */
        
        //static method gets called and creates a Graph object

        //

        int get_num_nodes();


        int get_out_degree(int v);
        bool isLinked(int u, int v);





    }; 
 };


