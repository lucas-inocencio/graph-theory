/**
 * @file AdjacencyMatrix.hpp
 * @brief Declaration of the AdjacencyMatrix class, which represents an adjacency matrix for a graph.
 */
#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include <fstream>
#include <string>

/**
 * @brief Represents an adjacency matrix for a graph.
 */
class AdjacencyMatrix
{

public:
    int size;
    bool **array;

    AdjacencyMatrix(std::string);
};

/**
 * @brief Constructs an adjacency matrix from a file with the specified name.
 * Reads the size of the matrix from the first line of the file, then allocates memory for the 2D boolean array
 * and reads the matrix data from the file.
 * @param file_name The name of the file containing the adjacency matrix data.
 */
AdjacencyMatrix::AdjacencyMatrix(std::string file_name)
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
}

#endif