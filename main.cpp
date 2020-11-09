#include <iostream>
#include "leetcode/linkedList/doublyLinkedList.cpp"

int main() {
    MyLinkedList myLinkedList{};
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(1);
    myLinkedList.addAtIndex(3, 0);
    myLinkedList.deleteAtIndex(2);
    myLinkedList.addAtHead(6);
    myLinkedList.addAtTail(4);
    myLinkedList.print();
    std::cout << myLinkedList.get(4) << '\n';
    myLinkedList.addAtHead(4);
    myLinkedList.addAtIndex(5, 0);
    myLinkedList.addAtHead(6);
    myLinkedList.print();

    return 0;
}
