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
        size++;
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
        size++;
    }
    else
    {
        LinkedListNode *node = new LinkedListNode(value);
        node->next = head;
        head = node;
        size++;
    }
}

/**
 * @brief Prints the elements of the list.
 */
void LinkedList::print()
{
    LinkedListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}