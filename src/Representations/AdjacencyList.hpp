/**
 * @file AdjacencyList.hpp
 * @brief Declaration of the AdjacencyListclass, which represents an adjacency list for a graph.
 */
#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include <bits/stdc++.h>
#include <fstream>
#include <string>

#include "../linked-list/LinkedList.hpp"

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
    LinkedList *array;

    AdjacencyList(std::string);
    int get_num_vertices();
    int get_num_edges();
    int min_degree();
    int mean_degree();
    int median_degree();
    int max_degree();
};

/**
 * @brief Constructs an adjacency list from a file.
 * @param file_name The name of the file containing the graph data.
 */
AdjacencyList::AdjacencyList(std::string file_name)
{

    int vertex, adjacent_vertex;
    std::ifstream infile(file_name);

    infile >> num_vertices;
    array = new LinkedList[num_vertices]();

    while (infile >> vertex >> adjacent_vertex)
    {
        array[vertex - 1].insert(adjacent_vertex);
        array[adjacent_vertex - 1].insert(vertex);
        this->num_edges += 1;
    }

    infile.close();
}

/**
 * Gets the number of vertices in the graph represented by the adjacency list.
 *
 * @return The number of vertices in the graph.
 */
int AdjacencyList::get_num_vertices()
{
    return this->num_vertices;
}

/**
 * Gets the number of edges in the graph represented by the adjacency list.
 *
 * @return The number of edges in the graph.
 */
int AdjacencyList::get_num_edges()
{
    return this->num_edges;
}

/**
 * Calculates the min degree of the graph represented by the adjacency list.
 *
 * @return The min degree of the graph.
 */
int AdjacencyList::min_degree()
{
    int min = this->array[0].size;

    for (int i = 0; i < num_vertices; i++)
    {
        if (min > this->array[i].size)
        {
            min = this->array[i].size;
        }
    }

    return min;
}

/**
 * Calculates the max degree of the graph represented by the adjacency list.
 *
 * @return The max degree of the graph.
 */
int AdjacencyList::max_degree()
{
    int max = this->array[0].size;

    for (int i = 0; i < num_vertices; i++)
    {
        if (max < this->array[i].size)
        {
            max = this->array[i].size;
        }
    }

    return max;
}

/**
 * Calculates the mean degree of the graph represented by the adjacency list.
 *
 * @return The mean degree of the graph.
 */
int AdjacencyList::mean_degree()
{
    int mean = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        mean += this->array->size;
    }

    mean /= num_vertices

        return mean;
}

/**
 * Calculates the median degree of the graph represented by the adjacency list.
 *
 * @return The median degree of the graph.
 */
int AdjacencyList::median_degree()
{
    int *temp_array = new int[num_vertices]();
    int median_index = num_vertices / 2;

    for (int i = 0; i < num_vertices; i++)
    {
        temp_array[i] = this->array[i].size();
    }

    std::sort(temp_array, temp_array + num_vertices);

    if (num_vertices % 2 == 0)
    {
        return (temp_array[median_index - 1] + temp_array[median_index]) / 2;
    }
    else
    {
        return temp_array[median_index];
    }

    delete[] temp_array;
}

#endif