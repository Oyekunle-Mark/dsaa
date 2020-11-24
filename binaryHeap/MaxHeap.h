//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#ifndef DSAA_MAXHEAP_H
#define DSAA_MAXHEAP_H

#include <cstdio>
#include <vector>

/**
 * The Max Heap class
 */
class MaxHeap {
public:
    MaxHeap() : items{std::vector<int>{}} {}

    void swap(size_t index1, size_t index2);

    void bubbleUp();

    void insert(int item);

    void bubbleDown();

    int remove();

    void emptyHeap();

private:
    std::vector<int> items;
};


#endif //DSAA_MAXHEAP_H
