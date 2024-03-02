#include "../../include/LinkedList.hpp"

/**
 * @brief Constructor for a Empty LinkedList.
 */
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

/**
 * @brief Destructor for LinkedList class.
 */
LinkedList::~LinkedList()
{
    LinkedListNode *current = head;
    LinkedListNode *next;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

/**
 * @brief Inserts a new element at the head of the list.
 * @param value The value of the element to insert.
 */
void LinkedList::insert(int value)
{
    if (size == 0)
    {
        head = new LinkedListNode(value);
    }
    else
    {
        LinkedListNode *node = new LinkedListNode(value);
        node->next = head;
        head = node;
        size++;
    }
}