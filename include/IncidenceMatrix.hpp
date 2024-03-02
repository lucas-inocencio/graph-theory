#pragma once

#include <string>

class IncidenceMatrix
{
public:
    int **matrix;
    IncidenceMatrix(/* args */);
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