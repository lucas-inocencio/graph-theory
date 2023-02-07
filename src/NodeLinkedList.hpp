class NodeLinkedList {

    public:
        int id, capacity, allocation_flow;
        bool isReverse;
        NodeLinkedList *next;

        NodeLinkedList();
        NodeLinkedList(int, int);
        NodeLinkedList(int, int, bool);
};

NodeLinkedList::NodeLinkedList() {

    id = 0;
    capacity = 0;
    allocation_flow = 0;
    isReverse = false;
    next = nullptr;
}

NodeLinkedList::NodeLinkedList(int new_id, int new_capacity) { // O(1)
    
    id = new_id;
    capacity = new_capacity;
    allocation_flow = 0;
    next = nullptr;
}

NodeLinkedList::NodeLinkedList(int new_id, int new_capacity, bool new_reverse) { // O(1)
    
    id = new_id;
    capacity = new_capacity;
    isReverse = new_reverse;
    next = nullptr;
}
