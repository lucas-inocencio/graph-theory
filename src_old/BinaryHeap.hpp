#include <iostream>
#include "BinaryHeapNode.hpp"

class BinaryHeap
{

public:
    BinaryHeapNode *heap_array;
    BinaryHeapNode **auxiliar_pointers;
    int currrent_heap_size;
    int maximum_heap_size;

    BinaryHeap(int);
    void swapPointers(BinaryHeapNode *&, BinaryHeapNode *&);
    int parent(int i) { return (i - 1) / 2; }
    int left_child(int i) { return (2 * i + 1); }
    int right_child(int i) { return (2 * i + 2); }
    void heapify_up(int);
    void heapify_down(int);
    void insert(float, int);
    int extract_min();
    void decrease_key(int, float);
};

BinaryHeap::BinaryHeap(int new_maximum)
{

    currrent_heap_size = 0;
    maximum_heap_size = new_maximum;
    heap_array = new BinaryHeapNode[new_maximum]();
    auxiliar_pointers = new BinaryHeapNode *[new_maximum]();
}

void BinaryHeap::swapPointers(BinaryHeapNode *&pointer1, BinaryHeapNode *&pointer2)
{

    BinaryHeapNode *temporary = pointer1;
    pointer1 = pointer2;
    pointer2 = temporary;
}

void BinaryHeap::insert(float new_key, int new_value)
{

    if (currrent_heap_size == maximum_heap_size)
    {
        std::cout << "\n Overflow: Could not insert key\n";
        return;
    }

    int index = currrent_heap_size;

    currrent_heap_size++;
    heap_array[index].key = new_key;
    heap_array[index].value = new_value;
    auxiliar_pointers[new_value - 1] = &heap_array[index];
    heapify_up(index);
}

void BinaryHeap::heapify_up(int index)
{

    while ((index != 0) && (heap_array[index].key < heap_array[parent(index)].key))
    {
        std::swap(heap_array[index], heap_array[parent(index)]);
        swapPointers(auxiliar_pointers[heap_array[index].value - 1], auxiliar_pointers[heap_array[parent(index)].value - 1]);
        index = parent(index);
    }
}

void BinaryHeap::heapify_down(int index)
{

    bool done = false;
    int new_root = 0;

    while (!done)
    {

        new_root = index;

        if ((left_child(index) < currrent_heap_size) && (heap_array[left_child(index)].key < heap_array[index].key))
        {
            new_root = left_child(index);
        }
        if ((right_child(index) < currrent_heap_size) && (heap_array[right_child(index)].key < heap_array[new_root].key))
        {
            new_root = right_child(index);
        }
        if (new_root == index)
        {
            done = true;
        }
        else
        {
            std::swap(heap_array[new_root], heap_array[index]);
            swapPointers(auxiliar_pointers[heap_array[new_root].value - 1], auxiliar_pointers[heap_array[index].value - 1]);
            index = new_root;
        }
    }
}

int BinaryHeap::extract_min()
{

    if (currrent_heap_size <= 0)
    {
        return -1;
    }
    else
    {
        currrent_heap_size--;
        int root = heap_array[0].value;
        std::swap(heap_array[0], heap_array[currrent_heap_size]);
        swapPointers(auxiliar_pointers[root - 1], auxiliar_pointers[heap_array[currrent_heap_size].value - 1]);
        auxiliar_pointers[root - 1] = nullptr;
        heap_array[currrent_heap_size].key = 0.0f;
        heap_array[currrent_heap_size].value = 0;

        heapify_down(0);

        return root;
    }
}

void BinaryHeap::decrease_key(int position, float new_key)
{

    heap_array[position].key = new_key;
    heapify_up(position);
}