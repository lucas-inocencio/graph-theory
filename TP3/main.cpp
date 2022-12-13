#include <chrono>
#include "Graph.hpp"

int main() {

    Graph graph;
    clock_t start, end;
    
    graph.builder_adjacency_list("grafo_rf_1.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_2.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_3.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_4.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_5.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_6.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_7.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    graph.builder_adjacency_list("grafo_rf_8.txt", "dw");
    start = clock();
    std::cout << graph.find_max_flow(1, 2) << '\n';
    end = clock();
    std::cout << "Tempo gasto: " << ((double) (end-start) / CLOCKS_PER_SEC) << '\n';
    
    return 0;
}