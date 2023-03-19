#include <fstream>
#include <iostream>
#include <string>

#include "LinkedList.hpp"

class AdjacencyList
{

public:
    int number_vertex;
    LinkedList *linked_list_array;

    AdjacencyList(std::string, std::string);
    void directed_weight(std::string);
    void builder_residual(std::string);
};

AdjacencyList::AdjacencyList(std::string file_name, std::string type)
{

    if (type == "uu")
    {
        // undirected_unweight(file_name);
    }
    else if (type == "uw")
    {
        // undirected_weight(file_name);
    }
    else if (type == "du")
    {
        // directed_unweight(file_name);
    }
    else if (type == "dw")
    {
        directed_weight(file_name);
    }
    else if (type == "residual")
    {
        builder_residual(file_name);
    }
}

void AdjacencyList::directed_weight(std::string file_name)
{

    int vertex, adjancent_vertex, edge_capacity;
    std::ifstream infile(file_name);

    infile >> number_vertex;
    linked_list_array = new LinkedList[number_vertex](); // O(V)

    while (infile >> vertex >> adjancent_vertex >> edge_capacity)
    {
        linked_list_array[vertex - 1].insert(adjancent_vertex, edge_capacity);
    }

    infile.close();
}

void AdjacencyList::builder_residual(std::string file_name)
{

    int next_vertex, adjancent_vertex, edge_capacity;
    std::ifstream infile(file_name);

    infile >> number_vertex;
    linked_list_array = new LinkedList[number_vertex](); // O(V)

    while (infile >> next_vertex >> adjancent_vertex >> edge_capacity)
    {
        linked_list_array[next_vertex - 1].insert(adjancent_vertex, edge_capacity, false);
        linked_list_array[adjancent_vertex - 1].insert(next_vertex, 0, true);
    }

    infile.close();
}
