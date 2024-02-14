#include <iostream>
#include <string>

#include "./src/representation/AdjacencyMatrix.hpp"

using namespace std;

int main()
{
    string file_path = "../data/undirected-unweighted/graph_1.txt";
    AdjacencyMatrix *graph1 = new AdjacencyMatrix();
    graph1->read_from_file(file_path);

    cout << "Graph 1 has " << graph1->get_num_vertices() << " vertices and " << graph1->get_num_edges() << " edges." << endl;
    cout << "The min degree of graph 1 is " << graph1->min_degree() << "." << endl;
    cout << "The max degree of graph 1 is " << graph1->max_degree() << "." << endl;
    cout << "The average degree of graph 1 is " << graph1->mean_degree() << "." << endl;
    cout << "The median degree of graph 1 is " << graph1->median_degree() << "." << endl;

    return 0;
}