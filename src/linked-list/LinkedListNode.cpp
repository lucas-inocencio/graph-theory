#include "LinkedListNode.hpp"

/*
 * @brief Constructor for LinkedListNode class with one parameter, in case of initializing the node with no next node.
 * @param value The value to be held by the node.
 */
LinkedListNode::LinkedListNode(int value)
{
    this->value = value;
    this->next = nullptr;
}

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