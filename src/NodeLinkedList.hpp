class NodeLinkedList {

    public:
        int data_int, capacity, allocation_flow;
        bool reverse;
        float data_float;
        NodeLinkedList* next_node;

        NodeLinkedList();
        NodeLinkedList(int, float);
        NodeLinkedList(int, int);
        NodeLinkedList(int, int, bool);
};

NodeLinkedList::NodeLinkedList() {

    this->data_int = 0;
    this->capacity = 0;
    this->allocation_flow = 0;
    this->reverse = false;
    this->next_node = nullptr;
}

NodeLinkedList::NodeLinkedList(int new_data_int, float new_data_float) { // O(1)
    
    this->data_int = new_data_int;
    this->data_float = new_data_float;
    this->next_node = nullptr;
}

NodeLinkedList::NodeLinkedList(int new_data_int, int new_capacity) { // O(1)
    
    this->data_int = new_data_int;
    this->capacity = new_capacity;
    this->allocation_flow = 0;
    this->next_node = nullptr;
}

NodeLinkedList::NodeLinkedList(int new_data_int, int new_capacity, bool new_reverse) { // O(1)
    
    this->data_int = new_data_int;
    this->capacity = new_capacity;
    this->reverse = new_reverse;
    this->next_node = nullptr;
}