#ifndef GRAPH_SEARCHER_HPP
#define GRAPH_SEARCHER_HPP

#include <queue>
#include <stack>

#include "./representations/AdjacencyList.hpp"

/**
 * @brief A class that implements search algorithms on an adjacency list graph.
 */
class GraphSearcher
{
public:
    int *breadth_first_search(AdjacencyList *, int);
    int *depth_first_search(AdjacencyList *, int);
};

/**
 * @brief Perform a breadth-first search on the specified graph, starting from the given root vertex.
 * @param graph Pointer to the adjacency list representing the graph.
 * @param root The id (value) of the root vertex to start the search from.
 */
int *GraphSearcher::breadth_first_search(AdjacencyList *graph, int root)
{
    int next_vertex;
    std::queue<int> discovered;
    LinkedListNode *adjacent_vertex;

    int *parent = new int[graph->num_vertices]{};
    bool *visited = new bool[graph->num_vertices]{};

    for (int i = 0; i < graph->num_vertices; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }
    discovered.push(root);
    visited[root - 1] = true;
    parent[root - 1] = 0;

    while (discovered.empty() == false)
    {
        next_vertex = discovered.front();
        discovered.pop();
        adjacent_vertex = graph->array[next_vertex - 1].head;
        for (int i = 0; i < graph->array[next_vertex - 1].num_vertices; i++)
        {
            if (visited[adjacent_vertex->value - 1] == false)
            {
                visited[adjacent_vertex->value - 1] = true;
                discovered.push(adjacent_vertex->value);
                parent[adjacent_vertex->value - 1] = next_vertex;
            }
            adjacent_vertex = adjacent_vertex->next;
        }
    }
}

/**
 * @brief Perform a depth-first search on the specified graph, starting from the given root vertex.
 * @param graph Pointer to the adjacency list representing the graph.
 * @param root The id (value) of the root vertex to start the search from.
 */
int *GraphSearcher::depth_first_search(AdjacencyList *graph, int root)
{
    int next_vertex;
    std::stack<int> discovered;
    LinkedListNode *adjacent_vertex;

    int *parent = new int[graph->num_vertices]{};
    bool *visited = new bool[graph->num_vertices]{};

    for (int i = 0; i < graph->num_vertices; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }
    discovered.push(root);
    visited[root - 1] = true;
    parent[root - 1] = 0;

    while (discovered.empty() == false)
    {
        next_vertex = discovered.top();
        discovered.pop();
        adjacent_vertex = graph->array[next_vertex - 1].head;
        for (int i = 0; i < graph->array[next_vertex - 1].num_vertices; i++)
        {
            if (visited[adjacent_vertex->value - 1] == false)
            {
                visited[adjacent_vertex->value - 1] = true;
                discovered.push(adjacent_vertex->value);
                parent[adjacent_vertex->value - 1] = next_vertex;
            }
            adjacent_vertex = adjacent_vertex->next;
        }
    }

    return parent;
}

#endif