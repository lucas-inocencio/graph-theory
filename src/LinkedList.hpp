#include "NodeLinkedList.hpp"

class LinkedList {
    
    public:
        NodeLinkedList* head;
        int size;

        LinkedList();
        ~LinkedList();
        void insert(int, float);
        void insert(int, int);
        void insert(int, int, bool);
};

LinkedList::LinkedList() { // O(1)

    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {

	NodeLinkedList *currNode = head;
	NodeLinkedList *nextNode = nullptr;
	
	while (currNode != nullptr) {
		nextNode = currNode->next_node;
		delete currNode;
		currNode = nextNode;
	}
	head = nullptr;
}

void LinkedList::insert(int new_data_int, float new_data_float) { // O(1)

    if (head == nullptr) {
        head = new NodeLinkedList(new_data_int, new_data_float);
    } else {
        NodeLinkedList* new_node = new NodeLinkedList(new_data_int, new_data_float);
        new_node->next_node = head;
        this->head= new_node;
    }
    
    size++;
}

void LinkedList::insert(int new_data_int, int new_capacity) { // O(1)

    if (head == nullptr) {
        head = new NodeLinkedList(new_data_int, new_capacity);
    } else {
        NodeLinkedList* new_node = new NodeLinkedList(new_data_int, new_capacity);
        new_node->next_node = head;
        this->head= new_node;
    }
    
    size++;
}

void LinkedList::insert(int new_data_int, int new_capacity, bool new_reverse) { // O(1)

    if (head == nullptr) {
        head = new NodeLinkedList(new_data_int, new_capacity, new_reverse);
    } else {
        NodeLinkedList* new_node = new NodeLinkedList(new_data_int, new_capacity, new_reverse);
        new_node->next_node = head;
        this->head= new_node;
    }
    
    size++;
}