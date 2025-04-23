#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*
 * @class IncidenceMatrix
 * @brief A graph represented as an incidence matrix.
 * @details
 * The incidence matrix is a 2D array where rows represent vertices and columns represent edges.
 *
 */
class IncidenceMatrix
{
public:
    int num_vertices, num_edges;
    std::vector<std::vector<int>> incidence_matrix;

    IncidenceMatrix();
    ~IncidenceMatrix() = default;
    void read_from_file(std::string, std::string);
    void read_undirected_unweighted(std::string);
    int get_num_vertices();
    int get_num_edges();
    int min_degree();
    double mean_degree();
    int median_degree();
    int max_degree();
    void print();
};