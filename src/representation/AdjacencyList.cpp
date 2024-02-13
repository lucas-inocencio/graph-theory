#include <AdjacencyList.hpp>

/**
 * @brief Constructs an undirected unweighted adjacency list from a file.
 * @param file_name The name of the file containing the graph data.
 */
AdjacencyList::AdjacencyList(std::string file_name)
{
    int vertex, adjacent_vertex;

    std::ifstream infile(file_name);
    infile >> num_vertices;
    adjacency_list = std::vector<LinkedList>(num_vertices);

    while (infile >> vertex >> adjacent_vertex)
    {
        adjacency_list[vertex - 1].insert(adjacent_vertex);
        adjacency_list[adjacent_vertex - 1].insert(vertex);
        num_edges++;
    }

    infile.close();
}

/**
 * Gets the number of vertices in the graph represented by the adjacency list.
 * @return The number of vertices in the graph.
 */
int AdjacencyList::get_num_vertices()
{
    return num_vertices;
}

/**
 * Gets the number of edges in the graph represented by the adjacency list.
 * @return The number of edges in the graph.
 */
int AdjacencyList::get_num_edges()
{
    return num_edges;
}

/**
 * Calculates the min degree of the graph represented by the adjacency list.
 * @return The min degree of the graph.
 */
int AdjacencyList::min_degree()
{
    int min = adjacency_list[0].size;

    for (int i = 0; i < num_vertices; i++)
    {
        if (min > adjacency_list[i].size)
        {
            min = adjacency_list[i].size;
        }
    }

    return min;
}

/**
 * Calculates the max degree of the graph represented by the adjacency list.
 * @return The max degree of the graph.
 */
int AdjacencyList::max_degree()
{
    int max = adjacency_list[0].size;

    for (int i = 0; i < num_vertices; i++)
    {
        if (max < adjacency_list[i].size)
        {
            max = adjacency_list[i].size;
        }
    }

    return max;
}

/**
 * Calculates the mean degree of the graph represented by the adjacency list.
 * @return The mean degree of the graph.
 */
int AdjacencyList::mean_degree()
{
    int mean = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        mean += adjacency_list[i].size;
    }

    mean /= num_vertices;

    return mean;
}

/**
 * Calculates the median degree of the graph represented by the adjacency list.
 * @return The median degree of the graph.
 */
int AdjacencyList::median_degree()
{
    int median_index = num_vertices / 2;
    std::vector<int> degree_list = std::vector<int>(num_vertices);

    for (int i = 0; i < num_vertices; i++)
    {
        degree_list[i] = adjacency_list[i].size;
    }

    std::sort(degree_list.begin(), degree_list.end());

    if (num_vertices % 2 == 0)
    {
        return (degree_list[median_index - 1] + degree_list[median_index]) / 2;
    }
    else
    {
        return degree_list[median_index];
    }
}

/*
 *
 *
 */
int AdjacencyList::min_degree()
{
    int min = adjacency_list[0].size();

    for (int i = 1; i < num_vertices; i++)
    {
        if (min > adjacency_list[i].size())
        {
            min = adjacency_list[i].size();
        }
    }

    return min;
}