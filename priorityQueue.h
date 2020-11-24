//
// Created by Oyekunle Oloyede on 24/11/2020.
//

#ifndef DSAA_PRIORITYQUEUE_H
#define DSAA_PRIORITYQUEUE_H

#include <vector>

template<typename DataType>
class PriorityQueue {
private:
    template<typename NodeData>
    struct QueueNode {
        int priority;
        NodeData data;

        explicit QueueNode(int priority, const NodeData &data)
                : priority{priority}, data{data} {}
    };

    using Node_t = QueueNode<DataType>;

    std::vector<Node_t> items;

public:
    PriorityQueue() : items{std::vector<Node_t>{}} {}

    void swap(int index1, int index2);

    void bubbleUp();

    void insert(const Node_t &item);

    void bubbleDown();

    const Node_t &remove();
};


#endif //DSAA_PRIORITYQUEUE_H
