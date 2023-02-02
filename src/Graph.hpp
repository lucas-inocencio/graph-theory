#include <queue>
#include "AdjacencyList.hpp"
#include "BinaryHeap.hpp"

class Graph {

    public:
        int number_vertex;
        int *parent;
        bool *reverse_path, *label;
        AdjacencyList *representation;
        LinkedList *residual, *path;

        Graph();
        void builder_adjacency_list(std::string, std::string);
        void breadth_first_search(int, int);
        void get_path(int);
        void uniform_cost_search_array(int, int);
        void uniform_cost_search_heap(int, int);
        void find_mst_heap(int);
        void builder_residual();
        int get_bottleneck(int, int);
        int find_max_flow(int, int);
};

Graph::Graph() {

    representation = nullptr;
    number_vertex = 0;
}

void Graph::builder_adjacency_list(std::string file_name, std::string type) { // O(V+E)

    representation = new AdjacencyList(file_name, type);
    number_vertex = representation->number_vertex;
    residual = new LinkedList[number_vertex]();
    parent = new int[number_vertex]{};
    reverse_path = new bool[number_vertex]{};
    label = new bool[number_vertex]{};
    path = new LinkedList();
}

void Graph::breadth_first_search(int root, int delta) { // O(V+E)

    int next_vertex;
    std::queue<int> discovered;
    NodeLinkedList *adjacent_vertex;

    for (int i = 0; i < number_vertex; i++) {
        parent[i] = -1;
        label[i] = false;
        reverse_path[i] = false;
    }

    discovered.push(root);
    label[root-1] = true;
    parent[root-1] = 0;

    while (discovered.empty() == false) {

        next_vertex = discovered.front();
        discovered.pop();
        adjacent_vertex = residual[next_vertex-1].head;

        for (int i = 1; i <= residual[next_vertex-1].size; i++) {
            
            if ((label[adjacent_vertex->data_int-1] == false) && (adjacent_vertex->capacity > delta)) {
                label[adjacent_vertex->data_int-1] = true;
                discovered.push(adjacent_vertex->data_int);
                parent[adjacent_vertex->data_int-1] = next_vertex;
                if (adjacent_vertex->reverse == true) {reverse_path[adjacent_vertex->data_int-1] = true;}
            }

            adjacent_vertex = adjacent_vertex->next_node;
        }
    }
}

void Graph::get_path(int target) {

    delete path;
    path = new LinkedList();
    int temp = target;
    
    if (parent[target-1] == -1) {
    } else {
        path->insert(temp, 0);
        while (parent[temp-1] != 0) {
            temp = parent[temp-1];
            path->insert(temp, 0);            
        }
    }
}

void Graph::uniform_cost_search_array(int source, int target) { // O(Ve2)
    
    float* distance = new float[number_vertex]{};
    float* discovered = new float[number_vertex]{};
    int* parent = new int[number_vertex]{};
    int next_vertex, index_min;
    NodeLinkedList* adjacent_vertex;

    for (int i = 0; i < number_vertex; i++) {
        distance[i] = 10.0e+11F;
        discovered[i] = 10.0e+11F;
    }

    distance[source-1] = 0.0f;
    discovered[source-1] = 0.0f;

    for (int explored_set_size = 0; explored_set_size < number_vertex; explored_set_size++) {

        index_min = 0;
        
        for (int i = 0; i < number_vertex; i++) {

            if (discovered[i] < discovered[index_min]) {
                index_min = i;
            }
        }

        discovered[index_min] = 10.0e+11F;
        next_vertex = index_min;
        adjacent_vertex = representation->linked_list_array[next_vertex].head;
        
        for (int i = 0; i < representation->linked_list_array[next_vertex].size; i++) {
            
            if (adjacent_vertex->data_float < 0.0f) {
                std::cout << "The library still doesn't implement shortest paths with negative weights.";
                return;
            } else if (distance[adjacent_vertex->data_int-1] > distance[next_vertex] + adjacent_vertex->data_float) {
                distance[adjacent_vertex->data_int-1] = distance[next_vertex] + adjacent_vertex->data_float;
                parent[adjacent_vertex->data_int-1] = next_vertex;
                discovered[adjacent_vertex->data_int-1] = distance[next_vertex] + adjacent_vertex->data_float;
            }

            adjacent_vertex = adjacent_vertex->next_node;
        }

        if (next_vertex == target) {
            break;
        }
    }
}

void Graph::uniform_cost_search_heap(int source, int target) { // O((V+E)logV)

    float* distance = new float[number_vertex]{};
    int* parent = new int[number_vertex]{};
    BinaryHeap discovered(number_vertex);
    NodeLinkedList* adjacent_vertex;
    int next_vertex;
    
    for (int i = 0; i < number_vertex; i++) {
        distance[i] = 10.0e+11F;
    }

    distance[source-1] = 0.0f;
    discovered.insert(0.0f, source);
    
    for (int explored_set_size = 0; explored_set_size < number_vertex; explored_set_size++) {
        
        next_vertex = discovered.extract_min();
        adjacent_vertex = representation->linked_list_array[next_vertex-1].head;

        for (int i = 0; i < representation->linked_list_array[next_vertex-1].size; i++) {
            if (adjacent_vertex->data_float < 0.0f) {
                std::cout << "The library still doesn't implement shortest paths with negative weights.";
                return;
            } else if (distance[adjacent_vertex->data_int-1] > (distance[next_vertex-1] + adjacent_vertex->data_float)) {

                distance[adjacent_vertex->data_int-1] = distance[next_vertex-1] + adjacent_vertex->data_float;
                parent[adjacent_vertex->data_int-1] = next_vertex;

                if (discovered.auxiliar_pointers[adjacent_vertex->data_int-1] == nullptr) {
                    discovered.insert(distance[adjacent_vertex->data_int-1], adjacent_vertex->data_int);
                } else {
                    discovered.decrease_key((&*discovered.auxiliar_pointers[adjacent_vertex->data_int-1] - &discovered.heap_array[0]), (distance[next_vertex-1] + adjacent_vertex->data_float));
                }
            }
            
            adjacent_vertex = adjacent_vertex->next_node;
        }

        if (next_vertex == target) {
            break;
        }
    }
}

void Graph::find_mst_heap(int source) {
    

    float* distance = new float[number_vertex]{};
    int* parent = new int[number_vertex]{};
    BinaryHeap discovered(number_vertex);
    NodeLinkedList* adjacent_vertex;
    int next_vertex;

    for (int i = 0; i < number_vertex; i++) {
        distance[i] = 10.0e+11F;
        discovered.insert(10.0e+11F, i+1);
    }
    
    std::ofstream mst_file ("MST.txt");
    distance[source-1] = 0.0f;
    discovered.auxiliar_pointers[source-1]->key = 0.0f;   
    discovered.heapify_up(&*discovered.auxiliar_pointers[source-1] - &discovered.heap_array[0]);

    mst_file << number_vertex << "\n";

    for (int explored_set_size = 0; explored_set_size < number_vertex; explored_set_size++) {
        
        distance[discovered.heap_array[0].value-1] = discovered.heap_array[0].key;
        next_vertex = discovered.extract_min();
        adjacent_vertex = representation->linked_list_array[next_vertex-1].head;

        for (int i = 0; i < representation->linked_list_array[next_vertex-1].size; i++) {

            if (adjacent_vertex->data_float < 0.0f) {
                std::cout << "The library still doesn't implement shortest paths with negative weights.";
                return;
            } else if ((distance[adjacent_vertex->data_int-1] > adjacent_vertex->data_float) && (discovered.auxiliar_pointers[adjacent_vertex->data_int-1] != nullptr)) {
                distance[adjacent_vertex->data_int-1] = adjacent_vertex->data_float;
                discovered.auxiliar_pointers[adjacent_vertex->data_int-1]->key = adjacent_vertex->data_float;
                discovered.heapify_up(&*discovered.auxiliar_pointers[adjacent_vertex->data_int-1] - &discovered.heap_array[0]);
                parent[adjacent_vertex->data_int-1] = next_vertex;
            }

            adjacent_vertex = adjacent_vertex->next_node;
        }
        
        if (mst_file.is_open()) {
            mst_file << next_vertex << " " << discovered.heap_array[0].value<< " " << discovered.heap_array[0].key << "\n";
        }
    }

    float total_weight = 0.0f;

    for (int i = 0; i < number_vertex; i++) {
        total_weight += distance[i];
    }

    mst_file << total_weight;
    mst_file.close();
}

void Graph::builder_residual() {

    NodeLinkedList *adjancent_vertex;
    
    for (int next_vertex = 1; next_vertex <= number_vertex; next_vertex++) {
        
        adjancent_vertex = representation->linked_list_array[next_vertex-1].head;
        for (int i = 1; i <= representation->linked_list_array[next_vertex-1].size; i++) { // O(E)
            residual[next_vertex-1].insert(adjancent_vertex->data_int, adjancent_vertex->capacity, false);
            residual[adjancent_vertex->data_int-1].insert(next_vertex, 0, true);
            adjancent_vertex = adjancent_vertex->next_node;
        }
    }
}

int Graph::get_bottleneck(int source, int target) {

    if (parent[target-1] == -1) {
        return 0;
    } else {
        int bottleneck = 1000000000;
        NodeLinkedList *walk_path, *walk_residual;

        walk_path = path->head;
        int next_vertex = walk_path->data_int;
        walk_path = walk_path->next_node;
        int adjacent_vertex = walk_path->data_int;

        walk_residual = residual[next_vertex-1].head;
            
        while (walk_residual->data_int != adjacent_vertex) {
            walk_residual = walk_residual->next_node;
        }
        if (walk_residual->capacity < bottleneck) {
            bottleneck = walk_residual->capacity;
        }

        for (int i = 2; i < path->size; i++) {
            next_vertex = adjacent_vertex;
            walk_path = walk_path->next_node;
            adjacent_vertex = walk_path->data_int;
            walk_residual = residual[next_vertex-1].head;
            
            while (walk_residual->data_int != adjacent_vertex) {
                walk_residual = walk_residual->next_node;
            }
            if (walk_residual->capacity < bottleneck) {
                bottleneck = walk_residual->capacity;
            }
        }

        return bottleneck;
    }
}

unsigned highestPowerof2(unsigned x) {

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x ^ (x >> 1);
}

int Graph::find_max_flow(int source, int target) {

    builder_residual();
    LinkedList *x;
    NodeLinkedList *curr_path, *walk_residual_original, *walk_residual_reverse, *walk_graph_original;
    int bottleneck, next_vertex, adjacent_vertex;
    int max_flow = 0;
    int delta = 0;

    for (int i = 0; i < representation->linked_list_array[source-1].size; i++) {
        delta += walk_graph_original->capacity;
        walk_graph_original = walk_graph_original->next_node;
    }

    delta = highestPowerof2(delta);
    breadth_first_search(source, delta);

    while (true) {

        get_path(target);
        if (path->head == nullptr) {
            break;
        } else {
            curr_path = path->head;
        }

        bottleneck = get_bottleneck(source, target);
        if (bottleneck == 0) {break;}

        while (curr_path->next_node != nullptr) {
            
            next_vertex = curr_path->data_int;
            curr_path = curr_path->next_node;
            adjacent_vertex = curr_path->data_int;
            walk_residual_original = residual[next_vertex-1].head;
            walk_residual_reverse = residual[adjacent_vertex-1].head;
            walk_graph_original = representation->linked_list_array[next_vertex-1].head;

            while (walk_residual_original->data_int != adjacent_vertex) {
                walk_residual_original = walk_residual_original->next_node;
            }
            while (walk_residual_reverse->data_int != next_vertex) {
                walk_residual_reverse = walk_residual_reverse->next_node;
            }
            while (walk_graph_original->data_int != adjacent_vertex) {
                walk_graph_original = walk_graph_original->next_node;
            }

            if (reverse_path[adjacent_vertex-1] == true) {
                walk_residual_original->capacity += bottleneck;
                walk_residual_reverse->capacity -= bottleneck;
                walk_graph_original->allocation_flow -= bottleneck;
                std::cout << "reversa: " << bottleneck << "\n";
            } else if (reverse_path[adjacent_vertex-1] == false) {
                walk_residual_original->capacity -= bottleneck;
                walk_residual_reverse->capacity += bottleneck;
                walk_graph_original->allocation_flow += bottleneck;
                std::cout << "original: " << bottleneck << "\n";
            }
        }
        delta = delta/2;
        breadth_first_search(source, delta);
    }
    
    walk_graph_original = representation->linked_list_array[source-1].head;
    for (int i = 0; i < representation->linked_list_array[source-1].size; i++) {
        max_flow += walk_graph_original->allocation_flow;
        walk_graph_original = walk_graph_original->next_node;
    }

    return max_flow;
}