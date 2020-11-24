#include <iostream>
#include <memory>
#include "binaryHeap/MaxHeap.cpp"

int main() {
    std::unique_ptr<MaxHeap> heap = std::make_unique<MaxHeap>();
    heap->insert(2);
    heap->insert(45);
    heap->insert(3);
    heap->insert(11);
    heap->insert(6);
    heap->insert(8);
    heap->insert(6);

    std::cout << "Remove: " << heap->remove() << '\n';


    return 0;
}
