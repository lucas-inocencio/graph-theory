class BinaryHeapNode
{

public:
    float key;
    int value;

    BinaryHeapNode();
    BinaryHeapNode(int, float);
};

BinaryHeapNode::BinaryHeapNode()
{

    this->key = 0;
    this->value = 0.0f;
}

BinaryHeapNode::BinaryHeapNode(int new_key, float new_value)
{

    this->key = new_key;
    this->value = new_value;
}