#include <fstream>
#include <string>
#include "LinkedList.hpp"

class AdjacencyList {

    public:
        int number_vertex;
        LinkedList* linked_list_array;

        AdjacencyList(std::string, std::string);
        //undirected_unweight(std::string);
        void undirected_weight(std::string);
        //directed_unweight(std::string);
        void directed_weight(std::string);
};

AdjacencyList::AdjacencyList(std::string file_name, std::string type) { // O(V+E)

    if (type == "uu") {
        //undirected_unweight(file_name);
    } else if (type == "uw") {
        undirected_weight(file_name);
    } else if (type == "du") {
        //directed_unweight(file_name);
    } else if (type == "dw") {
        directed_weight(file_name);
    }
}

void AdjacencyList::undirected_weight(std::string file_name) { // O(V+E)

    int vertex, adjancent_vertex;
    float edge_weight;
    std::ifstream infile(file_name);
    
    infile >> number_vertex;
    linked_list_array = new LinkedList[number_vertex](); // O(V)

    while (infile >> vertex >> adjancent_vertex >> edge_weight) { // O(E)
        linked_list_array[vertex-1].insert(adjancent_vertex, edge_weight);
        linked_list_array[adjancent_vertex-1].insert(vertex, edge_weight);
    }
    
    infile.close();
}

void AdjacencyList::directed_weight(std::string file_name) {

    int vertex, adjancent_vertex, edge_capacity;
    std::ifstream infile(file_name);
    
    infile >> number_vertex;
    linked_list_array = new LinkedList[number_vertex](); // O(V)

    while(infile >> vertex >> adjancent_vertex >> edge_capacity) { // O(E)
        linked_list_array[vertex-1].insert(adjancent_vertex, edge_capacity);
    }
    
    infile.close();
}