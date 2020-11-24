//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#include "priorityQueue.h"

template<typename QueueItem>
void PriorityQueue<QueueItem>::swap(int index1, int index2) {
    auto temp = items.at(index1);
    items.at(index1) = items.at(index2);
    items.at(index2) = temp;
}
