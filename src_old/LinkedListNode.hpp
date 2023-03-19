class LinkedListNode
{

public:
    int data_int, capacity, allocation_flow;
    bool reverse;
    float data_float;
    LinkedListNode *next_node;

    LinkedListNode();
    LinkedListNode(int, float);
    LinkedListNode(int, int);
    LinkedListNode(int, int, bool);
};

LinkedListNode::LinkedListNode()
{

    this->data_int = 0;
    this->capacity = 0;
    this->allocation_flow = 0;
    this->reverse = false;
    this->next_node = nullptr;
}

LinkedListNode::LinkedListNode(int new_data_int, float new_data_float)
{

    this->data_int = new_data_int;
    this->data_float = new_data_float;
    this->next_node = nullptr;
}

LinkedListNode::LinkedListNode(int new_data_int, int new_capacity)
{

    this->data_int = new_data_int;
    this->capacity = new_capacity;
    this->allocation_flow = 0;
    this->next_node = nullptr;
}

LinkedListNode::LinkedListNode(int new_data_int, int new_capacity, bool new_reverse)
{

    this->data_int = new_data_int;
    this->capacity = new_capacity;
    this->reverse = new_reverse;
    this->next_node = nullptr;
}