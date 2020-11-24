//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#include "MaxHeap.h"

void MaxHeap::swap(size_t index1, size_t index2) {
    auto temp = items.at(index1);
    items.at(index1) = items.at(index2);
    items.at(index2) = temp;
}

void MaxHeap::bubbleUp() {
    int index = items.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;

        if (items.at(index) > items.at(parentIndex)) {
            swap(index, parentIndex);
            index = parentIndex;
        } else
            break;
    }
}

void MaxHeap::insert(int item) {
    items.push_back(item);

    if (items.size() > 1)
        bubbleUp();
}

void MaxHeap::bubbleDown() {
    int parentIndex = 0;

    while (parentIndex < items.size()) {
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;
        int indexToSwap = -1;

        if (leftChildIndex < items.size() && items.at(leftChildIndex) > items.at(parentIndex))
            indexToSwap = leftChildIndex;

        if (rightChildIndex < items.size()) {
            if ((items.at(rightChildIndex) > items.at(parentIndex) && indexToSwap == -1) ||
                (items.at(rightChildIndex) > items.at(leftChildIndex) && indexToSwap != -1))
                indexToSwap = rightChildIndex;
        }

        if (indexToSwap == -1)
            break;

        swap(parentIndex, indexToSwap);
        parentIndex = indexToSwap;
    }
}

int MaxHeap::remove() {
    swap(0, items.size() - 1);
    auto ret = items.back();
    items.pop_back();

    if (items.size() > 1)
        bubbleDown();

    return ret;
}
