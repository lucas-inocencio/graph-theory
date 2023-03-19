/**
 * @file AdjacencyList.hpp
 * @brief Declaration of the AdjacencyListclass, which represents an adjacency list for a graph.
 */

#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include <fstream>
#include <string>

#include "../LinkedList/LinkedList.hpp"

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
    int size;
    LinkedList *array;

    AdjacencyList(std::string);
};

/**
 * @brief Constructs an adjacency list from a file.
 * @param file_name The name of the file containing the graph data.
 */
AdjacencyList::AdjacencyList(std::string file_name)
{

    int vertex, adjacent_vertex;
    std::ifstream infile(file_name);

    infile >> size;
    array = new LinkedList[size]();

    while (infile >> vertex >> adjacent_vertex)
    {
        array[vertex - 1].insert(adjacent_vertex);
    }

    infile.close();
}

#endif