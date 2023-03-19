#include <chrono>
#include <iostream>

#include "./Representations/AdjacencyList.hpp"
#include "./Representations/AdjacencyMatrix.hpp"

int main()
{
    std::chrono::high_resolution_clock::time_point start, end;
    double cpu_time_used;

    for (int i = 1; i < 6; i++)
    {
        start = std::chrono::high_resolution_clock::now();
        AdjacencyList *test_adj_list = new AdjacencyList(std::string("../txt/undirected-unweighted/graph_" + std::to_string(i) + ".txt"));
        end = std::chrono::high_resolution_clock::now();
        cpu_time_used = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
        std::cout << "Time spent to build the graph " << i << " in AdjacencyList is: " << cpu_time_used << " seconds\n";
        delete test_adj_list;
    }

    for (int i = 1; i < 6; i++)
    {
        start = std::chrono::high_resolution_clock::now();
        AdjacencyMatrix *test_adj_matrix = new AdjacencyMatrix(std::string("../txt/undirected-unweighted/graph_" + std::to_string(i) + ".txt"));
        end = std::chrono::high_resolution_clock::now();
        cpu_time_used = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
        std::cout << "Time spent to build the graph " << i << " in AdjacencyMatrix: " << cpu_time_used << " seconds\n";
        delete test_adj_matrix;
    }

    return 0;
}
