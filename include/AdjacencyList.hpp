// AdjacencyList.hpp

#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "LinkedList.hpp"

/**
 * @class AdjacencyList
 * @brief A graph represented as an adjacency list.
 * @details The AdjacencyList class represents a graph as an adjacency list,
 * which is a data structure that stores a list of adjacent vertices for each
 * vertex in the graph.
 */
class AdjacencyList
{
public:
    int num_vertices, num_edges;
    std::vector<LinkedList> adjacency_list;

    AdjacencyList();
    void read_from_file(std::string, std::string);
    void read_undirected_unweighted(std::string);
    ~AdjacencyList() = default;
    int get_num_vertices();
    int get_num_edges();
    int min_degree();
    int mean_degree();
    int median_degree();
    int max_degree();
    void print();
};