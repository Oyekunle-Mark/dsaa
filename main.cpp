#include <memory>
#include <string>
#include "priorityQueue/priorityQueue.cpp"

int main() {
    std::unique_ptr<PriorityQueue<std::string>> pQueue = std::make_unique<PriorityQueue<std::string>>();
    pQueue->insert(2, "Go home");
    pQueue->insert(3, "Read");
    pQueue->insert(4, "Work out");
    pQueue->insert(1, "Eat");
    pQueue->insert(1, "Sleep");
    pQueue->insert(12, "Watch some sports");
    pQueue->insert(6, "Dance bro!");
    pQueue->emptyHeap();

    return 0;
}
