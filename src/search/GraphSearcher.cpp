#include "../../include/GraphSearcher.hpp"

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
        for (int i = 0; i < graph->array[next_vertex - 1].size; i++)
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

    delete[] visited;

    return parent;
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
        for (int i = 0; i < graph->array[next_vertex - 1].size; i++)
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

    delete[] visited;

    return parent;
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
    int next_vertex;
    std::priority_queue<int, std::vector<int>, std::greater<int>> discovered;
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
        for (int i = 0; i < graph->array[next_vertex - 1].size; i++)
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

    delete[] visited;

    return parent;
}