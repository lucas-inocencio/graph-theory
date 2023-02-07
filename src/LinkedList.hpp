#include "NodeLinkedList.hpp"

class LinkedList {
    
    public:
        int size;
        NodeLinkedList *head;

        LinkedList();
        void insert(int, int);
        void insert(int, int, bool);
        void remove_all();
};

LinkedList::LinkedList() { // O(1)

    head = nullptr;
    size = 0;
}

void LinkedList::insert(int new_id, int new_capacity) { // O(1)

    if (size == 0) {
        head = new NodeLinkedList(new_id, new_capacity);
    } else {
        NodeLinkedList* new_node = new NodeLinkedList(new_id, new_capacity);
        new_node->next = head;
        head= new_node;
    }
    
    size++;
}

void LinkedList::insert(int new_id, int new_capacity, bool new_reverse) { // O(1)

    if (size == 0) {
        head = new NodeLinkedList(new_id, new_capacity, new_reverse);
    } else {
        NodeLinkedList* new_node = new NodeLinkedList(new_id, new_capacity, new_reverse);
        new_node->next = head;
        head= new_node;
    }
    
    size++;
}

void LinkedList::remove_all() {

	NodeLinkedList *current = head;
	NodeLinkedList *temp = nullptr;
	
	while (current != nullptr) {
		temp = current->next;
		delete current;
		current = temp;
	}

	head = nullptr;
    size = 0;
}
