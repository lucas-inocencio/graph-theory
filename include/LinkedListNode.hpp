#pragma once

/**
 * @brief A class representing a node in a singly linked list.
 */
class LinkedListNode
{
public:
    int value;
    LinkedListNode *next;

    LinkedListNode(int, LinkedListNode * = nullptr);
    ~LinkedListNode() = default;
};