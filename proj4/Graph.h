#include <iostream>
#include <vector>
#include <fstream>


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
    class Graph {

        /** NOTE: COO will be it's own data structure with COO entry */
        struct CSR {
            std::vector<int> row_ptrs;
            std::vector<int> column_idx;
            std::vector<int> values;
        };

    private:
        //fields
        int num_edges;
        int num_nodes;
        std::string format;
        CSR csr;
    
    
    public:
        //constructor
        /***
            INPUT: fstream
            OUTPUT: Graph object with populated COO
         */
        Graph();   
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
        void add_edge(int src, int dest, int val);

        /**
            INPUT: src node ID, dest node ID
            OUTPUT: return nothing, but update value if > old_val
         */

        int update_edge(int src, int dest, int new_val);
        
        /**
            INPUT:
            OUTPUT: 
         */

         /***

          */
        
        void create_csr();
        
        /**
            INPUT: COO storage
            OUTPUT: Initializes CSR with values
         */
        
        //static method gets called and creates a Graph object

        //



    }; 
 };


