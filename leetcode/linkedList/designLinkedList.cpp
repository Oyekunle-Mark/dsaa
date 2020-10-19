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
        if (index >= size) // if index exceeds list length
            return -1;

        auto currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr) {
            if (currentIndex == index) // break at index
                break;

            currentNode = currentNode->next;
            ++currentIndex;
        }

        return currentNode->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto newNode = new LinkedListNode(val, head); // create new node with current head as next
        head = newNode; // point head at new node

        if (!size) // if this the only node they both head and tail should point at the same node
            tail = newNode;

        ++size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto newNode = new LinkedListNode(val);

        if (!size) { // if this the only node they both head and tail should point at the same node
            head = newNode;
            tail = newNode;
        } else { // otherwise, point current tail's next to new node and point tail to new node
            tail->next = newNode;
            tail = newNode;
        }

        ++size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) // index is greater than length
            return;

        if (index == size) { // index is equal to length
            addAtTail(val);
            return;
        }

        if (index == 0) { // index zero inserts at head
            addAtHead(val);
            return;
        }

        auto currentNode = head;
        int currentIndex = 0;

        while (currentNode != nullptr) {
            if (++currentIndex == index) { // is the next index the target index
                auto newNode = new LinkedListNode(val,
                                                  currentNode->next); // create new node with present index node as next
                currentNode->next = newNode; // point previous index node's next to new node
                ++size;
                return;
            }

            currentNode = currentNode->next;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (size == 0 || index >= size) // is list empty or index overflows
            return;

        if (index == 0) { // delete at head
            head = head->next;
            --size;
            return;
        }

        auto currentNode = head;
        int currentIndex = 0;
        auto prev = head;

        while (currentNode != nullptr) {
            if (currentIndex == index) { // is target index
                if (index == size - 1) // if is tail set tail to prev
                    tail = prev;

                prev->next = currentNode->next; // set previous next to current next deleting current node
                --size;

                return;
            }

            prev = currentNode; // prev tract previous node
            currentNode = currentNode->next; // move current pointer to next node
            ++currentIndex;
        }
    }

    /** Prints all the node in the linked list */
    void print() const {
        auto currentNode = head;

        while (currentNode != nullptr) {
            std::cout << currentNode->value << ' ';
            currentNode = currentNode->next;
        }

        std::cout << std::endl;
    }

private:
    /**
     * Struct representing a linked list node
     */
    struct LinkedListNode {
        int value;
        LinkedListNode *next;

        explicit LinkedListNode(int value, LinkedListNode *next = nullptr)
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
