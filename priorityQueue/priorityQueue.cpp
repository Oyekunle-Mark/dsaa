//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#include "priorityQueue.h"

void PriorityQueue::swap(int index1, int index2) {
    auto temp = items.at(index1);
    items.at(index1) = items.at(index2);
    items.at(index2) = temp;
}

void PriorityQueue::bubbleUp() {
    int index = static_cast<int>(items.size() - 1);

    while (index > 0) {
        int parentIndex = (index - 1) / 2;

        if (items.at(index) < items.at(parentIndex)) {
            swap(parentIndex, index);
            index = parentIndex;
        } else
            break;
    }
}

void PriorityQueue::insert(int priority, const std::string &data) {
    items.emplace_back(priority, data);

    if (items.size() > 1)
        bubbleUp();
}

void PriorityQueue::bubbleDown() {
    int parentIndex = 0;

    while (parentIndex < items.size()) {
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;
        int indexToSwap = -1;

        if (leftChildIndex < items.size() && items.at(parentIndex) > items.at(leftChildIndex))
            indexToSwap = leftChildIndex;

        if (rightChildIndex < items.size()) {
            if ((items.at(parentIndex) > items.at(rightChildIndex) && indexToSwap != -1) ||
                (items.at(rightChildIndex) < items.at(leftChildIndex) && indexToSwap != -1))
                indexToSwap = rightChildIndex;

        }

        if (indexToSwap == -1)
            break;

        swap(parentIndex, indexToSwap);
        parentIndex = indexToSwap;
    }
}

const std::pair<int, std::string> &PriorityQueue::remove() {
    swap(0, static_cast<int>(items.size() - 1));
    auto temp = items.back();
    items.pop_back();

    if (items.size() > 1)
        bubbleDown();

    return std::move(std::pair<int, std::string>{temp.priority, temp.data});
}

void PriorityQueue::emptyHeap() {
    for ([[maybe_unused]] const auto &_ : items) {
        auto item = remove();
        printf("Priority %d | Data %s", item.first, item.second.c_str());
        remove();
    }
}
