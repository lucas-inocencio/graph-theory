#include <queue>
#include "AdjacencyList.hpp"

unsigned highest_power2(unsigned x) {

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x ^ (x >> 1);
}

class Graph {

    public:
        int number_vertex;
        int *parent;
        bool *reverse_edge, *visited;
        AdjacencyList *representation, *residual;
        LinkedList *path;

        Graph();
        void builder_adjacency_list(std::string, std::string);
        void breadth_first_search(int, int);
        void find_path(int);

        int find_bottleneck(int, int);
        int find_max_flow(int, int);
        AdjacencyList* find_netflow(int, int, std::string);
};

Graph::Graph() {

    representation = nullptr;
    number_vertex = 0;
}

void Graph::builder_adjacency_list(std::string file_name, std::string type) { // O(V+E)

    representation = new AdjacencyList(file_name, type);
    number_vertex = representation->number_vertex;
    path = new LinkedList();
    residual = new AdjacencyList(file_name, "residual");
    parent = new int[number_vertex]{};
    reverse_edge = new bool[number_vertex]{};
    visited = new bool[number_vertex]{};
}

void Graph::breadth_first_search(int root, int delta) { // O(V+E)

    int next_vertex;
    std::queue<int> discovered;
    NodeLinkedList *adjacent_vertex;

    for (int i = 0; i < number_vertex; i++) {
        parent[i] = -1;
        visited[i] = false;
        reverse_edge[i] = false;
    }

    discovered.push(root);
    visited[root-1] = true;
    parent[root-1] = 0;

    while (discovered.empty() == false) {

        next_vertex = discovered.front();
        discovered.pop();
        adjacent_vertex = residual->linked_list_array[next_vertex-1].head;

        for (int i = 0; i < residual->linked_list_array[next_vertex-1].size; i++) {
            
            if ((visited[adjacent_vertex->id-1] == false) && (adjacent_vertex->capacity > delta)) {
                visited[adjacent_vertex->id-1] = true;
                discovered.push(adjacent_vertex->id);
                parent[adjacent_vertex->id-1] = next_vertex;
                if (adjacent_vertex->isReverse == true) {
                    reverse_edge[adjacent_vertex->id-1] = true;
                }
            }

            adjacent_vertex = adjacent_vertex->next;
        }
    }

}

void Graph::find_path(int target) {

    path->remove_all();
    int temp = target;
    
    if (parent[target-1] == -1) {
        "pass";
    } else {
        path->insert(temp, 0);
        while (parent[temp-1] != 0) {
            temp = parent[temp-1];
            path->insert(temp, 0);            
        }
    }
}

int Graph::find_bottleneck(int source, int target) {

    if (path->size == 0) {
        return 0;
    } else {

        int bottleneck = 1000000000;
        NodeLinkedList *walk_path, *walk_residual;

        walk_path = path->head;
        int next_vertex;
        int adjacent_vertex = walk_path->id;
        
        for (int i = 1; i < path->size; i++) {

            next_vertex = adjacent_vertex;
            walk_path = walk_path->next;
            adjacent_vertex = walk_path->id;

            if (reverse_edge[adjacent_vertex-1] == true) {

                walk_residual = residual->linked_list_array[adjacent_vertex-1].head;
                while (walk_residual->id != next_vertex) {
                    walk_residual = walk_residual->next;
                }

            } else {

                walk_residual = residual->linked_list_array[next_vertex-1].head;
                while (walk_residual->id != adjacent_vertex) {
                    walk_residual = walk_residual->next;
                }
            }
            
            if (walk_residual->capacity < bottleneck) {
                bottleneck = walk_residual->capacity;
            }
        }

        
        return bottleneck;
    }
}

int Graph::find_max_flow(int source, int target) {

    NodeLinkedList *curr_path, *residual_original, *residual_reverse, *graph_original, *out_capacity;
    int bottleneck, next_vertex, adjacent_vertex;
    int max_flow = 0;
    int delta = 0;

    out_capacity = representation->linked_list_array[source-1].head;
    for (int i = 0; i < representation->linked_list_array[source-1].size; i++) {
        delta += out_capacity->capacity;
        out_capacity = out_capacity->next;
    }

    delta = highest_power2(delta);
    breadth_first_search(source, delta);

    while (parent[target-1] > 0 || delta > 0) {
        
        curr_path = path->head;
        bottleneck = find_bottleneck(source, target);

        for (int i = 1; i < path->size; i++) {
            
            next_vertex = curr_path->id;
            curr_path = curr_path->next;
            adjacent_vertex = curr_path->id;
            residual_original = residual->linked_list_array[next_vertex-1].head;
            residual_reverse = residual->linked_list_array[adjacent_vertex-1].head;

            while (residual_original->id != adjacent_vertex) {
                residual_original = residual_original->next;
            }
            while (residual_reverse->id != next_vertex) {
                residual_reverse = residual_reverse->next;
            }

            residual_original->capacity -= bottleneck;
            residual_reverse->capacity += bottleneck;
        }

        delta = delta/2;
        breadth_first_search(source, delta);
        find_path(target);
    }

    out_capacity = representation->linked_list_array[source-1].head;
    residual_original = residual->linked_list_array[source-1].head;
    for (int i = 0; i < representation->linked_list_array[source-1].size; i++) {
        max_flow += out_capacity->capacity - residual_original->capacity;
        out_capacity = out_capacity->next;
        residual_original = residual_original->next;
    }

    return max_flow;
}

AdjacencyList* Graph::find_netflow(int source, int target, std::string write) {

    NodeLinkedList *curr_path, *residual_original, *residual_reverse, *graph_original, *out_capacity;
    int bottleneck, next_vertex, adjacent_vertex;
    int max_flow = 0;
    int delta = 0;

    out_capacity = representation->linked_list_array[source-1].head;
    for (int i = 0; i < representation->linked_list_array[source-1].size; i++) {
        delta += out_capacity->capacity;
        out_capacity = out_capacity->next;
    }

    delta = highest_power2(delta);
    breadth_first_search(source, delta);

    while (parent[target-1] > 0 || delta > 0) {
        
        curr_path = path->head;
        bottleneck = find_bottleneck(source, target);

        for (int i = 1; i < path->size; i++) {
            
            next_vertex = curr_path->id;
            curr_path = curr_path->next;
            adjacent_vertex = curr_path->id;
            residual_original = residual->linked_list_array[next_vertex-1].head;
            residual_reverse = residual->linked_list_array[adjacent_vertex-1].head;
            graph_original = representation->linked_list_array[next_vertex-1].head;

            while (residual_original->id != adjacent_vertex) {
                residual_original = residual_original->next;
            }
            while (residual_reverse->id != next_vertex) {
                residual_reverse = residual_reverse->next;
            }
            while (graph_original->id != adjacent_vertex) {
                graph_original = graph_original->next;
            }

            //std::cout << next_vertex << " " << adjacent_vertex << " " << bottleneck << '\n';
            if (reverse_edge[adjacent_vertex-1] == true) {
                residual_original->capacity += bottleneck;
                residual_reverse->capacity -= bottleneck;
                graph_original->allocation_flow -= bottleneck;
            } else {
                residual_original->capacity -= bottleneck;
                residual_reverse->capacity += bottleneck;
                graph_original->allocation_flow += bottleneck;
            }
        }

        delta = delta/2;
        breadth_first_search(source, delta);
        find_path(target);
    }

    if (write == "w") {

        std::ofstream outfile ("output_netflow.txt");
        outfile << number_vertex << std::endl;
        for (int i = 0; i < number_vertex; i++) {
            graph_original = representation->linked_list_array[i].head;
            residual_original = residual->linked_list_array[i].head;
            for (int j = 0; j < representation->linked_list_array[i].size; j++) {
                outfile << i+1 << " " << graph_original->id << " " << graph_original->allocation_flow << std::endl;
                graph_original = graph_original->next;
            }
        }
    }
    

    return representation;
}