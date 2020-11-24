//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#include "priorityQueue.h"

template<typename DataType>
void PriorityQueue<DataType>::swap(int index1, int index2) {
    auto temp = items.at(index1);
    items.at(index1) = items.at(index2);
    items.at(index2) = temp;
}

template<typename DataType>
void PriorityQueue<DataType>::bubbleUp() {
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
