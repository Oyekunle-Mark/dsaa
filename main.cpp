#include <memory>
#include <string>
#include "priorityQueue/priorityQueue.cpp"

int main() {
    std::unique_ptr<PriorityQueue<std::string>> pQueue = std::make_unique<PriorityQueue<std::string>>();
    pQueue->insert(2, std::string{"Go home"});
    pQueue->insert(3, std::string{"Read"});
    pQueue->insert(4, std::string{"Work out"});
    pQueue->insert(1, std::string{"Eat"});
    pQueue->insert(1, std::string{"Sleep"});
    pQueue->insert(12, std::string{"Watch some sports"});
    pQueue->insert(6, std::string{"Dance bro!"});
    pQueue->emptyHeap();

    return 0;
}
