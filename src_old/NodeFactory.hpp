#include "BinaryHeapNode.hpp"
#include "LinkedListNode.hpp"

class NodeFactory
{
    createNode(type, value)
    {
        switch (type)
        {
        case 'BinaryHeap':
            return new BinaryHeapNode(value);
        case 'LinkedList':
            return new LinkedListNode(value);
        default:
            throw new Error(`Invalid node type
                            : $ { type }`);
        }
    }
}