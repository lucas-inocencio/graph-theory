#include <iostream>

#include "./src/linked-list/LinkedListNode.hpp"

using namespace std;

int main()
{
    LinkedListNode *node1 = new LinkedListNode(1);
    LinkedListNode *node2 = new LinkedListNode(2, node1);
    LinkedListNode *node3 = new LinkedListNode(3, node2);

    cout << node3->value << endl;
    cout << node3->next->value << endl;
    cout << node3->next->next->value << endl;

    return 0;
}