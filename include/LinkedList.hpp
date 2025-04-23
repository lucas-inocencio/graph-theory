#pragma once

#include <iostream>

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
    ~LinkedList();
    void insert(int);
    void print();
};