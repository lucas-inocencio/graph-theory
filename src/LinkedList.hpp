#include "LinkedListNode.hpp"

class LinkedList {
    
    public:
        int size;
        LinkedListNode *head;

        LinkedList();
        void insert(int, int);
        void insert(int, int, bool);
        void remove_all();
};

LinkedList::LinkedList() {

    head = nullptr;
    size = 0;
}

void LinkedList::insert(int new_id, int new_capacity) {

    if (size == 0) {
        head = new LinkedListNode(new_id, new_capacity);
    } else {
        LinkedListNode* new_node = new LinkedListNode(new_id, new_capacity);
        new_node->next = head;
        head= new_node;
    }
    
    size++;
}

void LinkedList::insert(int new_id, int new_capacity, bool new_reverse) {

    if (size == 0) {
        head = new LinkedListNode(new_id, new_capacity, new_reverse);
    } else {
        LinkedListNode* new_node = new LinkedListNode(new_id, new_capacity, new_reverse);
        new_node->next = head;
        head= new_node;
    }
    
    size++;
}

void LinkedList::remove_all() {

	LinkedListNode *current = head;
	LinkedListNode *temp = nullptr;
	
	while (current != nullptr) {
		temp = current->next;
		delete current;
		current = temp;
	}

	head = nullptr;
    size = 0;
}
