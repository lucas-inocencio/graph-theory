#include "../../include/IncidenceMatrix.hpp"

/*
 * @class IncidenceMatrix
 * @brief A graph represented as an incidence matrix.
 * @details
 * The incidence matrix is a 2D array where rows represent vertices and columns represent edges.
 */
IncidenceMatrix::IncidenceMatrix()
{
    num_vertices = 0;
    num_edges = 0;
    incidence_matrix = std::vector<std::vector<int>>();
}

/**
 *
 */
void IncidenceMatrix::read_from_file(std::string file_name, std::string type)
{
    if (type == "undirected_unweighted")
    {
        read_undirected_unweighted(file_name);
    }
    else
    {
        std::cout << "Error: Unsupported graph type." << std::endl;
        exit(1);
    }
}

/*
 *
 */
void IncidenceMatrix::read_undirected_unweighted(std::string file_name)
{
    std::ifstream file(file_name);

    file >> num_vertices >> num_edges;
    incidence_matrix.resize(num_vertices, std::vector<int>(num_edges, 0));
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        file >> u >> v;
        incidence_matrix[u - 1][i] = 1;
        incidence_matrix[v - 1][i] = 1;
    }
}

/**
 * @return The number of vertices in the graph.
 */
int IncidenceMatrix::get_num_vertices()
{
    return num_vertices;
}

/**
 * @return The number of edges in the graph.
 */
int IncidenceMatrix::get_num_edges()
{
    return num_edges;
}

/**
 * Calculates the min degree of the graph represented by the incidence matrix.
 * @return The min degree of the graph.
 */
int IncidenceMatrix::min_degree()
{
    int min = num_edges;

    for (int i = 0; i < num_vertices; i++)
    {
        int degree = 0;
        for (int j = 0; j < num_edges; j++)
        {
            degree += incidence_matrix[i][j];
        }
        if (degree < min)
        {
            min = degree;
        }
    }

    return min;
}

/**
 * Calculates the max degree of the graph represented by the incidence matrix.
 * @return The max degree of the graph.
 */
int IncidenceMatrix::max_degree()
{
    int max = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        int degree = 0;
        for (int j = 0; j < num_edges; j++)
        {
            degree += incidence_matrix[i][j];
        }
        if (degree > max)
        {
            max = degree;
        }
    }

    return max;
}

/**
 * Calculates the mean degree of the graph represented by the incidence matrix.
 * @return The mean degree of the graph.
 */
double IncidenceMatrix::mean_degree()
{
    double mean = 0.0;

    for (int i = 0; i < num_vertices; i++)
    {
        int degree = 0;
        for (int j = 0; j < num_edges; j++)
        {
            degree += incidence_matrix[i][j];
        }
        mean += degree;
    }

    mean /= num_vertices;

    return mean;
}

/**
 * Calculates the median degree of the graph represented by the incidence matrix.
 * @return The median degree of the graph.
 */
int IncidenceMatrix::median_degree()
{
    std::vector<int> degrees(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        int degree = 0;
        for (int j = 0; j < num_edges; j++)
        {
            degree += incidence_matrix[i][j];
        }
        degrees[i] = degree;
    }

    std::sort(degrees.begin(), degrees.end());

    if (num_vertices % 2 == 0)
    {
        return (degrees[num_vertices / 2 - 1] + degrees[num_vertices / 2]) / 2;
    }
    else
    {
        return degrees[num_vertices / 2];
    }
}

/**
 * Prints the incidence matrix to the console.
 */
void IncidenceMatrix::print()
{
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_edges; j++)
        {
            std::cout << incidence_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}