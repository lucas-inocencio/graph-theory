#include "LinkedListNode.hpp"

/**
 * @brief Constructor for LinkedListNode class.
 * @param value The value to be held by the node.
 * @param next The pointer to the next node in the linked list.
 */
LinkedListNode::LinkedListNode(int value, LinkedListNode *next)
{
    this->value = value;
    this->next = next;
}

LinkedListNode::LinkedListNode(int value)
{
    this->value = value;
    this->next = nullptr;
}