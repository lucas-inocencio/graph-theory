/**
 * @file LinkedListNode.hpp
 * @brief Definition of the LinkedListNode class.
 */

/**
 * @brief A class representing a node in a singly linked list.
 */
class LinkedListNode
{
public:
    int value;
    LinkedListNode *next;
    LinkedListNode(int value);
};
/**
 * @brief Constructor for LinkedListNode class.
 * @param value The value to be held by the node.
 */
LinkedListNode::LinkedListNode(int value)
{
    this->value = value;
}