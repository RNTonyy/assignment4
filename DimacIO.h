#ifndef __DIMACIO_H__
#define __DIMACIO_H__


#include <iostream>
#include <fstream>
#include "Graph.h"

/** 
    WRITE: DIMAC
    1) be given a string file path and make a file write object (fstream)
    2) Iterate through the CSR and put into DIMAC format
        FORMAT:
            HEADER: p FORMAT NODES EDGES
            EDGE: a SOURCE DESTINATION WEIGHT 

        ITERATION:
            - idx in row_ptr = row Node #, value in row_ptr[idx] = starting jdx of column array
            - column[jdx] = column Node #
            - value[jdx] = weight of edge from row to column 

            - so we have an outer loop that is the row Node #
            - inner loop that starts @ row_ptr[idx] and ends right before row_ptr[idx+1]
            - WRITEOUT: std::cout << "idx column[jdx] value[jdx]"


    WRITE: TEXT
        - How are we supposed to format the non-DIMACS
        - For finished PageRank, node labels will have rankings rather than weights now

        - std::cout << "NODE# PageRank"
 */

 /**
    READ:
    1) take a given file path in string and open the file into fstream object
    2) call constructor for Graph() passing in metadata
    3) loop through line by line and add edges to CSR
    4) return Graph

*/
tony::Graph dimac_read(std::string fp);

void dimac_write(std::string fp, tony::Graph g);

#endif


