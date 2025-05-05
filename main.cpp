#include <iostream>
#include <string>

//  #include "./include/AdjacencyList.hpp"
#include "./include/GraphSearcher.hpp"

int main()
{
    std::string file_name = "./data/example.txt";
    std::string type = "undirected_unweighted";
    AdjacencyList *graph = new AdjacencyList();
    GraphSearcher *graph_searcher = new GraphSearcher();
    graph->read_from_file(file_name, type);

    std::cout << "Graph 1 has " << graph->get_num_vertices() << " vertices and " << graph->get_num_edges() << " edges.\n";
    std::cout << "The min degree of graph 1 is " << graph->min_degree() << ".\n";
    std::cout << "The max degree of graph 1 is " << graph->max_degree() << ".\n";
    std::cout << "The average degree of graph 1 is " << graph->mean_degree() << ".\n";
    std::cout << "The median degree of graph 1 is " << graph->median_degree() << ".\n";
    // print the adjacency list
    std::cout << "The adjacency list of graph 1 is:\n";
    graph->print();
    //bfs
    int *parent = graph_searcher->breadth_first_search(graph, 1);

    std::cout << "The parent array of graph 1 is:\n";
    for (int i = 0; i < graph->get_num_vertices(); i++)
    {
        std::cout << parent[i] << " ";
    }
    std::cout << "\n";


    return 0;
}