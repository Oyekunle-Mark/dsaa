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
