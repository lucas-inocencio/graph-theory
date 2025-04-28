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
    int *best_first_search(AdjacencyList *, int);
    int *a_star_search(AdjacencyList *, int);
    int *dijkstra(AdjacencyList *, int);
    int *topological_sort(AdjacencyList *);
    int *bellman_ford(AdjacencyList *, int);
    int *floyd_warshall(AdjacencyList *, int);
    int *prim(AdjacencyList *, int);
    int *kruskal(AdjacencyList *, int);
    int *strongly_connected_components(AdjacencyList *);
    int *dense_or_sparse(AdjacencyList *, int);
    int *transposed_graph(AdjacencyList *);
    int *square_graph(AdjacencyList *);
    int *universal_sink(AdjacencyList *);
    int  *semiconnected(AdjacencyList *);
};