//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#include "MaxHeap.h"

void MaxHeap::swap(size_t index1, size_t index2) {
    auto temp = items.at(index1);
    items.at(index1) = items.at(index2);
    items.at(index2) = temp;
}
