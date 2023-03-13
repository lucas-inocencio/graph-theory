#include "NodeBinaryHeap.hpp"
#include "NodeLinkedList.hpp"

class NodeFactory
{
    createNode(type, value)
    {
        switch (type)
        {
        case 'BinaryHeap':
            return new NodeBinaryHeap(value);
        case 'LinkedList':
            return new NodeLinkedList(value);
        default:
            throw new Error(`Invalid node type
                            : $ { type }`);
        }
    }
}