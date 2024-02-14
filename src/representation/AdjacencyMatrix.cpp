#include "AdjacencyMatrix.hpp"

/**
 * @brief Constructs an empty undirected unweighted adjacency matrix.
 */
AdjacencyMatrix::AdjacencyMatrix()
{
    num_vertices = 0;
    num_edges = 0;
    adjacency_matrix = std::vector<std::vector<bool>>();
}

/**
 * @brief Reads a graph from a file and stores it in the adjacency matrix.
 * @param file_name The name of the file containing the graph.
 */
void AdjacencyMatrix::read_from_file(std::string file_name)
{
    int vertex, adjacent_vertex;

    std::ifstream infile(file_name);

    infile >> num_vertices;
    adjacency_matrix = std::vector<std::vector<bool>>(num_vertices, std::vector<bool>(num_vertices, false));

    while (infile >> vertex >> adjacent_vertex)
    {
        adjacency_matrix[vertex-1][adjacent_vertex-1] = true;
        adjacency_matrix[adjacent_vertex-1][vertex-1] = true;
        num_edges++;
    }

    infile.close();
}

/**
 * Gets the number of vertices in the graph represented by the adjacency matrix.
 *
 * @return The number of vertices in the graph.
 */
int AdjacencyMatrix::get_num_vertices()
{
    return num_vertices;
}

/**
 * Gets the number of edges in the graph represented by the adjacency matrix.
 *
 * @return The number of edges in the graph.
 */
int AdjacencyMatrix::get_num_edges()
{
    return num_edges;
}

/**
 * Calculates the min degree of the graph represented by the adjacency matrix.
 *
 * @return The min degree of the graph.
 */
int AdjacencyMatrix::min_degree()
{
    int min = num_vertices;
    int temp;

    for (int i = 0; i < num_vertices; i++)
    {
        temp = 0;

        for (int j = 0; j < num_vertices; j++)
        {
            if (adjacency_matrix[i][j] == true)
            {
                temp++;
            }
        }

        if (temp < min)
        {
            min = temp;
        }
    }

    return min;
}

/**
 * Calculates the max degree of the graph represented by the adjacency matrix.
 *
 * @return The max degree of the graph.
 */
int AdjacencyMatrix::max_degree()
{
    int max = 0; 
    int temp = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        temp = 0;

        for (int j = 0; j < num_vertices; j++)
        {
            if (adjacency_matrix[i][j] == true)
            {
                temp++;
            }
        }

        if (temp > max)
        {
            max = temp;
        }
    }

    return max;
}

/**
 * Calculates the mean degree of the graph represented by the adjacency matrix.
 *
 * @return The mean degree of the graph.
 */
double AdjacencyMatrix::mean_degree()
{
    double mean = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (adjacency_matrix[i][j] == true)
            {
                mean++;
            }
        }
    }

    mean /= num_vertices;

    return mean;
}

/**
 * Calculates the median degree of the graph represented by the adjacency matrix.
 *
 * @return The median degree of the graph.
 */
int AdjacencyMatrix::median_degree()
{
    int median_index = num_vertices / 2;
    std::vector<int> degree_list = std::vector<int>(num_vertices);

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (adjacency_matrix[i][j] == true)
            {
                degree_list[i]++;
            }
        }
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