//
// Created by Oyekunle Oloyede on 21/10/2020.
//
#include <iostream>

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList()
            : head{nullptr}, tail{nullptr}, length{} {}

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) const {
        if (length == 0 || index >= length) return -1;

        auto currentNode = head;
        int currentIndex{};

        while (currentNode) {
            if (currentIndex == index)
                break;

            currentNode = currentNode->next;
            ++currentIndex;
        }

        return currentNode->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!length) {
            auto newNode = new DoublyListNode(val);
            head = newNode;
            tail = newNode;
        } else {
            auto newNode = new DoublyListNode(val, nullptr, head);
            head->prev = newNode;
            head = newNode;
        }

        ++length;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!length) {
            auto newNode = new DoublyListNode(val);
            head = newNode;
            tail = newNode;
        } else {
            auto newNode = new DoublyListNode(val, tail);
            tail->next = newNode;
            tail = newNode;
        }

        ++length;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length) return;

        if (index == length) {
            addAtTail(val);
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        auto currentNode = head;
        int currentIndex{};

        while (currentNode) {
            if (++currentIndex == index) {
                auto newNode = new DoublyListNode(val, currentNode, currentNode->next);
                currentNode->next->prev = newNode;
                currentNode->next = newNode;
                ++length;
                return;
            }

            currentNode = currentNode->next;
        }
    }

    void deleteAtHead() {
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        --length;
    }

    void deleteAtTail() {
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        --length;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (!length || index >= length) return;

        if (index == 0) {
            deleteAtHead();
            return;
        }

        if (index == length - 1) {
            deleteAtTail();
            return;
        }

        auto currentNode = head;
        int currentIndex{};

        while (currentNode) {
            if (currentIndex == index) {
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
                --length;

                return;
            }

            currentNode = currentNode->next;
            ++currentIndex;
        }
    }

    /** Prints all the node in the linked list */
    void print() const {
        auto currentNode = head;

        std::cout << "NULL<->";

        while (currentNode) {
            std::cout << currentNode->value << "<->";
            currentNode = currentNode->next;
        }

        std::cout << "NULL" << std::endl;
    }

    /** Prints all the node in the linked list backward */
    void printReverse() const {
        auto currentNode = tail;

        std::cout << "NULL<->";

        while (currentNode) {
            std::cout << currentNode->value << "<->";
            currentNode = currentNode->prev;
        }

        std::cout << "NULL" << std::endl;
    }

private:
    /**
     * Struct representing a linked list node
     */
    struct DoublyListNode {
        int value;
        DoublyListNode *prev;
        DoublyListNode *next;

        explicit DoublyListNode(int value, DoublyListNode *prev = nullptr, DoublyListNode *next = nullptr)
                : value{value}, prev{prev}, next{next} {}
    };

    DoublyListNode *head;
    DoublyListNode *tail;
    std::size_t length;
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
