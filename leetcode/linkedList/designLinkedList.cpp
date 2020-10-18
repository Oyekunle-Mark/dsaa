//
// Created by Oyekunle Oloyede on 18/10/2020.
//
#include <cstddef>
#include <iostream>

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList()
            : head{nullptr}, tail{nullptr}, size{} {}

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;

        auto currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr) {
            if (currentIndex == index)
                break;

            currentNode = currentNode->next;
            ++currentIndex;
        }

        return currentNode->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto newNode = new LinkedListNode(val, head);
        head = newNode;

        if (!size)
            tail = newNode;

        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto newNode = new LinkedListNode(val);

        if (!size) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size)
            return;

        if (index == size) {
            addAtTail(val);
            return;
        }

//        if (index == 1) {
//            addAtHead(val);
//            return;
//        }

        auto currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr) {
            if (++currentIndex == index) {
                auto newNode = new LinkedListNode(val, currentNode->next);
                currentNode->next = newNode;
                ++size;
                return;
            }

            currentNode = currentNode->next;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (size == 0 || index >= size)
            return;

        if (index == 0) {
            head = head->next;
            --size;
            return;
        }

        auto currentNode = head;
        int currentIndex = 0;
        auto prev = head;

        while (currentNode != nullptr) {
            if (currentIndex == index) {
                if (index == size - 1)
                    currentNode->next = nullptr;
                else
                    currentNode->next = currentNode->next->next;
//                prev->next = currentNode->next;
                --size;

                return;
            }

            prev = head;
            currentNode = currentNode->next;
            ++currentIndex;
        }
    }

    void print() const {
        auto currentNode = head;

        while (currentNode != nullptr) {
            std::cout << currentNode->value << ' ';

            currentNode = currentNode->next;
        }

        std::cout << std::endl;
    }

private:
    struct LinkedListNode {
        int value;
        LinkedListNode *next;

        LinkedListNode(int value, LinkedListNode *next = nullptr)
                : value{value}, next{next} {}
    };

    LinkedListNode *head;
    LinkedListNode *tail;
    std::size_t size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
