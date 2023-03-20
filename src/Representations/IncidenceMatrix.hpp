// DON'T USE THIS CLASS

/**
 * @file IncidenceMatrix.hpp
 * @brief Declaration of the IncidenceMatrix class, which represents an incidence matrix for a graph.
 */
#ifndef INCIDENCE_MATRIX_HPP
#define INCIDENCE_MATRIX_HPP

#include <fstream>
#include <string>

/**
 * @brief Represents an incidence matrix for a graph.
 */
class IncidenceMatrix
{
public:
    int size;
    bool **array;

    IncidenceMatrix(std::string file_name);
};

IncidenceMatrix::IncidenceMatrix(std::string file_name)
{
    int vertex, adjacent_vertex;

    std::ifstream infile(file_name);
    infile >> size;

    array = new bool *[size]();
    for (int i = 0; i < size; ++i)
    {
        array[i] = new bool[size]();
    }

    while (infile >> vertex >> adjacent_vertex)
    {
        array[vertex - 1][adjacent_vertex - 1] == true;
        array[adjacent_vertex - 1][vertex - 1] == true;
    }

    infile.close();
};

#endif