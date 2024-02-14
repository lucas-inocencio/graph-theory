#pragma once

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

/**
 * @class AdjacencyMatrix
 * @brief A graph represented as an adjacency matrix.
 */
class AdjacencyMatrix
{
public:
    int num_vertices, num_edges;
    std::vector<std::vector<bool>> adjacency_matrix;

    AdjacencyMatrix();
    ~AdjacencyMatrix() = default;
    void read_from_file(std::string);
    int get_num_vertices();
    int get_num_edges();
    int min_degree();
    double mean_degree();
    int median_degree();
    int max_degree();
};