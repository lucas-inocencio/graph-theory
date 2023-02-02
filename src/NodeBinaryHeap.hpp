class NodeBinaryHeap {

    public:
        float key;
        int value;

        NodeBinaryHeap();
        NodeBinaryHeap(int, float);
};

NodeBinaryHeap::NodeBinaryHeap() { // O(1)

    this->key = 0;
    this->value = 0.0f;
}

NodeBinaryHeap::NodeBinaryHeap(int new_key, float new_value) { // O(1)

    this->key = new_key;
    this->value = new_value;
}