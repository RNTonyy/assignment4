#include "DimacIO.h"

/***
    PURPOSE: Implement IO operations for DIMAC file, including reading DIMAC and creating DIMAC Graph
        and then writing to two files for ouptput

 */

tony::Graph dimac_read(std::string fp) {

    //open file
    std::fstream file(fp, std::fstream::in);

    //check if not sucessful
    if (!file.is_open()) {
        throw std::runtime_error("ERROR: output file failed to open!");
    }

    std::string line;
    std::string tok;
    std::vector<std::string> tokens;

    tony::Graph *g;

    //lets make an initial read 
    while (std::getline(file,line)) {
        std::istringstream stream(line);
        //tokenize output 
        while (std::getline(stream,tok,' ')) {
            tokens.push_back(tok);
        }
        //header
        if (tokens[0].compare("p") == 0) {
            int num_nodes = std::stoi(tokens[2]);
            int num_edges = std::stoi(tokens[3]);
            // NODES , EDGES, FORMAT
            g = new tony::Graph(num_nodes, num_edges ,tokens[1]);
        } 
        //edge
        else if (tokens[0].compare("a") == 0 && g != nullptr) {
            int src = std::stoi(tokens[1]);
            int dst = std::stoi(tokens[2]);
            int val = std::stoi(tokens[3]);
            
            g->add_edge(src,dst,val);
        } else {
            std::runtime_error("ERROR: faulty file!");
        }

        //clear tokens
        tokens.clear();
    }

    //finished, lets finalize
    g->create_csr();

    return *g;
    }

    void dimac_write(std::string fp, tony::Graph g) {
        std::fstream file(fp, std::fstream::out);

        if (!file.is_open()) {
            std::runtime_error("ERROR: write-out file failed to open!");
        }

        // need to know how to interact with the graph


        //header
        // file << "p " << num_vertices(g) << " " << num_edges(g) << std::endl;

        //outer loop will be the vertices

        //inner loop will be the edges
    }



