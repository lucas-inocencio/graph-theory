#pragma once

#include "LinkedListNode.hpp"

/**
 * @class LinkedList
 * @brief A singly linked list data structure.
 * @details The LinkedList class provides a simple implementation of a singly
 * linked list with constant-time insertion at the head of the list.
 */
class LinkedList
{
public:
    int size;
    LinkedListNode *head;

    LinkedList();
    void insert(int);
};

/**
 * @brief Constructor for a Empty LinkedList.
 */
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
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