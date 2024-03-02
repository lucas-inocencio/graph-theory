#pragma once

#include <fstream>
#include <queue>
#include <stack>
#include <string>

#include "AdjacencyList.hpp"

/**
 * @brief A class that implements search algorithms on an adjacency list graph.
 */
class GraphSearcher
{
public:
    int *breadth_first_search(AdjacencyList *, int);
    int *depth_first_search(AdjacencyList *, int);
    int distance(AdjacencyList *, int, int);
    int diameter(AdjacencyList *);
    void write_parent_file(int *, int, std::string);
};