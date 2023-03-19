#include <chrono>
#include "Graph.hpp"

int main()
{

    Graph graph;
    clock_t start, end;
    double cpu_time_used;

    graph.builder_adjacency_list("grafo_rf_8.txt", "dw");

    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "Tempo gasto: " << cpu_time_used << '\n';

    return 0;
}