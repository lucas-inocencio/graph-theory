#include "../../include/GraphSearcher.hpp"

/*
 * @brief Constructor for the GraphSearcher class.
 */
GraphSearcher::GraphSearcher()
{
    // Constructor implementation
}

/**
 * @brief Perform a breadth-first search on the specified graph, starting from the given root vertex.
 * @param graph Pointer to the adjacency list representing the graph.
 * @param root The id (value) of the root vertex to start the search from.
 */
int *GraphSearcher::breadth_first_search(AdjacencyList *graph, int root)
{
    // let queue be a queue of vertices
    std::queue<int> queue;
    // let parent be an array of integers
    int *parent = new int[graph->num_vertices];
    // let discovered be an array of booleans
    bool *discovered = new bool[graph->num_vertices];
    LinkedListNode *linked_list_node = new LinkedListNode();
    // initialize parent and discovered arrays
    for (int i = 0; i < graph->num_vertices; i++)
    {
        parent[i] = -1;
        discovered[i] = false;
    }
    // label root as discovered
    discovered[root] = true;
    // enqueue root
    queue.push(root);
    // while queue is not empy
    while (!queue.empty())
    {
        // for all edges from v to w in G.adjacentEdges(v) do
        int vertex = queue.front();
        queue.pop();
        std::cout << "Visiting vertex: " << vertex << std::endl;
        LinkedListNode *linked_list_node = graph->adjacency_list[vertex].head;
        for (int i = 0; i < graph->adjacency_list[vertex].size; i++)
        {   
            int neighbor = linked_list_node->value;
            // if w is not labeled as explored then
            if (discovered[neighbor - 1] == false)
            {
                // label w as explored
                discovered[neighbor - 1] = true;
                //        w.parent := v
                parent[neighbor - 1] = vertex;
                //        Q.enqueue(w)
                queue.push(neighbor - 1);
            }
            // move to the next neighbor
            linked_list_node = linked_list_node->next;
        }
    }

    return parent;
}

/**
 * @brief Perform a depth-first search on the specified graph, starting from the given root vertex.
 * @param graph Pointer to the adjacency list representing the graph.
 * @param root The id (value) of the root vertex to start the search from.
 */
int *GraphSearcher::depth_first_search(AdjacencyList *graph, int root)
{
    // Initialize the stack and the parent array
    return nullptr;
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
    return nullptr;
}

/*
 * @brief A* Search algorithm.
 * @ details This function implements the A* Search algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::a_star_search(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
    return nullptr;
}

/*
 * @brief Dijkstra's algorithm.
 * @ details This function implements Dijkstra's algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::dijkstra(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
    int *parent = new int[graph->num_vertices];
    return parent;
}
/*
 * @brief Topological Sort algorithm.
 * @ details This function implements the Topological Sort algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::topological_sort(AdjacencyList *graph)
{
    // Initialize the stack and the parent array
    return nullptr;
}
/*
 * @brief Bellman-Ford algorithm.
 * @ details This function implements the Bellman-Ford algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::bellman_ford(AdjacencyList *graph, int root)
{
    // Initialize the parent array
    return nullptr;
}
/*
 * @brief Floyd-Warshall algorithm.
 * @ details This function implements the Floyd-Warshall algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::floyd_warshall(AdjacencyList *graph, int root)
{
    // Initialize the distance array
    return nullptr;
}
/*
 * @brief Prim's algorithm.
 * @ details This function implements Prim's algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::prim(AdjacencyList *graph, int root)
{
    // Initialize the priority queue and the parent array
    return nullptr;
}
/*
 * @brief Kruskal's algorithm.
 * @ details This function implements Kruskal's algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::kruskal(AdjacencyList *graph, int root)
{
    // Initialize the parent array
    return nullptr;
}
/*
 * @brief Strongly Connected Components algorithm.
 * @ details This function implements the Strongly Connected Components algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::strongly_connected_components(AdjacencyList *graph)
{
    // Initialize the stack and the parent array
    return nullptr;
}
/*
 * @brief Dense or Sparse algorithm.
 * @ details This function implements the Dense or Sparse algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::dense_or_sparse(AdjacencyList *graph, int root)
{
    // Initialize the parent array
    return nullptr;
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
    return nullptr;
}

/*
 * @brief Square Graph algorithm.
 * @ details This function implements the Square Graph algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::square_graph(AdjacencyList *graph)
{
    // Initialize the square graph
    return nullptr;
}

/*
 * @brief Universal Sink algorithm.
 * @ details This function implements the Universal Sink algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::universal_sink(AdjacencyList *graph)
{
    // Initialize the universal sink
    return nullptr;
}

/*
 * @brief Semiconnected algorithm.
 * @ details This function implements the Semiconnected algorithm on a graph represented by an adjacency list.
 * @param graph Pointer to the adjacency list representing the graph.
 */
int *GraphSearcher::semiconnected(AdjacencyList *graph)
{
    // Initialize the semiconnected graph
    return nullptr;
}