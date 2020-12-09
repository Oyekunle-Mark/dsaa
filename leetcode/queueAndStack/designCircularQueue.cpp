//
// Created by Oyekunle Oloyede on 09/12/2020.
//
#include <array>

class MyCircularQueue {
public:
    MyCircularQueue(int k)
            : queue{std::array<int, k>{}}, head{-1}, tail{-1} {}

    bool enQueue(int value) {
        if (isFull())
            return false;

        if (isEmpty()) {
            head = tail = 0;
            queue.at(tail) = value;
            return true;
        }

        queue.at(++tail) = value;
        return true;
    }

    bool deQueue() {

    }

    int Front() {

    }

    int Rear() {

    }

    bool isEmpty() {
        return head == -1 && tail == -1;
    }

    bool isFull() {

    }

private:
    std::array<int, 0> queue;
    int head;
    int tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
