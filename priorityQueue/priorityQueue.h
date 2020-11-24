//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#ifndef DSAA_PRIORITYQUEUE_H
#define DSAA_PRIORITYQUEUE_H

#include <cstdio>
#include <utility>
#include <vector>
#include <string>

/**
 * A priority queue class.
 * Uses a min heap
 */
class PriorityQueue {
private:
    struct QueueNode {
        int priority;
        std::string data;

        explicit QueueNode(int priority, std::string data)
                : priority{priority}, data{std::move(data)} {}

        bool operator<(const QueueNode &rhs) const {
            return this->priority < rhs.priority;
        }

        bool operator>(const QueueNode &rhs) const {
            return this->priority > rhs.priority;
        }
    };

    std::vector<QueueNode> items;


public:
    PriorityQueue() : items{std::vector<QueueNode>{}} {}

    void swap(int index1, int index2);

    void bubbleUp();

    void insert(int priority, const std::string &data);

    void bubbleDown();

    std::pair<int, std::string> remove();

    void emptyHeap();
};


#endif //DSAA_PRIORITYQUEUE_H
