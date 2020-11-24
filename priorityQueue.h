//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#ifndef DSAA_PRIORITYQUEUE_H
#define DSAA_PRIORITYQUEUE_H

#include <vector>

template<typename QueueItem>
class PriorityQueue {
public:
    PriorityQueue() : items{std::vector<QueueItem>{}} {}

    void swap(int index1, int index2);

    void bubbleUp();

    void insert(const QueueItem &item);

    void bubbleDown();

    const QueueItem &remove();

private:
    std::vector<QueueItem> items;
};


#endif //DSAA_PRIORITYQUEUE_H
