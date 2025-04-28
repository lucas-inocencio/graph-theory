#include "../../include/GraphSearcher.hpp"

/**
 * @brief Perform a breadth-first search on the specified graph, starting from the given root vertex.
 * @param graph Pointer to the adjacency list representing the graph.
 * @param root The id (value) of the root vertex to start the search from.
 */
int *GraphSearcher::breadth_first_search(AdjacencyList *graph, int root)
{
    // Initialize the queue and the parent array
}

/**
 * @brief Perform a depth-first search on the specified graph, starting from the given root vertex.
 * @param graph Pointer to the adjacency list representing the graph.
 * @param root The id (value) of the root vertex to start the search from.
 */
int *GraphSearcher::depth_first_search(AdjacencyList *graph, int root)
{
    // Initialize the stack and the parent array
}

void GraphSearcher::write_parent_file(int *parent, int root, std::string file_name)
{
    int vertex, level;
    int num_vertices = sizeof(parent) / sizeof(int);
    std::ofstream outfile(file_name);

    outfile << "Number of Vertices:" << num_vertices << std::endl;

    for (int i = 0; i < num_vertices; i++)
    {
        level = 0;
        vertex = i;
        while (vertex != root)
        {
            vertex = parent[vertex - 1];
            level++;
        }

        outfile << "Vertice:" << i + 1 << "Parent:" << parent[i] << "Level:" << level << std::endl;
    }

    outfile.close();
}

int GraphSearcher::distance(AdjacencyList *graph, int root, int vertex)
{
    int *parent = breadth_first_search(graph, root);
    int level = 0;
    int child = parent[vertex - 1];

    while (child != root)
    {
        child = parent[vertex - 1];
        level++;
    }

    return level;
}
/*
 * @brief Calculate the diameter of the graph represented by the adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 * @return The diameter of the graph.
 */
int GraphSearcher::diameter(AdjacencyList *graph)
{
    int max_distance = 0;
    int *parent = breadth_first_search(graph, 1);

    for (int i = 0; i < graph->num_vertices; i++)
    {
        int distance = 0;
        int child = parent[i];
        while (child != 1)
        {
            child = parent[child - 1];
            distance++;
        }
        if (distance > max_distance)
        {
            max_distance = distance;
        }
    }

    return max_distance;
}

/*
 * @brief Best First Search algorithm.
 * @ details This function implements the Best First Search algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::best_first_search(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
}

/*
 * @brief A* Search algorithm.
 * @ details This function implements the A* Search algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::a_star_search(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
}

/*
 * @brief Dijkstra's algorithm.
 * @ details This function implements Dijkstra's algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::dijkstra(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
}
/*
 * @brief Topological Sort algorithm.
 * @ details This function implements the Topological Sort algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::topological_sort(AdjacencyList *graph)
{
    // Initialize the stack and the parent array
}
/*
 * @brief Bellman-Ford algorithm.
 * @ details This function implements the Bellman-Ford algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::bellman_ford(AdjacencyList *graph, int root)
{
    // Initialize the parent array
}
/*
 * @brief Floyd-Warshall algorithm.
 * @ details This function implements the Floyd-Warshall algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::floyd_warshall(AdjacencyList *graph, int root)
{
    // Initialize the distance array
}
/*
 * @brief Prim's algorithm.
 * @ details This function implements Prim's algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::prim(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
}
/*
 * @brief Kruskal's algorithm.
 * @ details This function implements Kruskal's algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::kruskal(AdjacencyList *graph, int root)
{
    // Initialize the parent array
}
/*
 * @brief Strongly Connected Components algorithm.
 * @ details This function implements the Strongly Connected Components algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::strongly_connected_components(AdjacencyList *graph)
{
    // Initialize the stack and the parent array
}
/*
 * @brief Dense or Sparse algorithm.
 * @ details This function implements the Dense or Sparse algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::dense_or_sparse(AdjacencyList *graph, int root)
{
    // Initialize the parent array
}

/*
 *
 * @brief Transposed Graph algorithm.
 * @ details This function implements the Transposed Graph algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
*/
int *GraphSearcher::transposed_graph(AdjacencyList *graph)
{
    // Initialize the transposed graph
}

/*
 * @brief Square Graph algorithm.
 * @ details This function implements the Square Graph algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::square_graph(AdjacencyList *graph)
{
    // Initialize the square graph
}

/*
 * @brief Universal Sink algorithm.
 * @ details This function implements the Universal Sink algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::universal_sink(AdjacencyList *graph)
{
    // Initialize the universal sink
}

/*
 * @brief Semiconnected algorithm.
 * @ details This function implements the Semiconnected algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::semiconnected(AdjacencyList *graph)
{
    // Initialize the semiconnected graph
}