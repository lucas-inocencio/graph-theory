#pragma once

/**
 * @brief A class representing a node in a singly linked list.
 */
class LinkedListNode
{
public:
    int value;
    LinkedListNode *next;

    LinkedListNode(int, LinkedListNode *);
};

/**
 * @brief Constructor for LinkedListNode class.
 * @param value The value to be held by the node.
 * @param next The pointer to the next node in the linked list.
 */
LinkedListNode::LinkedListNode(int value, LinkedListNode *next = nullptr)
{
    this->value = value;
    this->next = next;
}