#include <iostream>
#include "leetcode/linkedList/designLinkedList.cpp"

int main() {
    MyLinkedList myLinkedList{};
    myLinkedList.addAtHead(1);
    myLinkedList.print();
    myLinkedList.addAtTail(3);
    myLinkedList.print();
    myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    myLinkedList.print();
    std::cout << myLinkedList.get(1) << '\n';              // return 2
    myLinkedList.deleteAtIndex(1);          // now the linked list is 1->3
    myLinkedList.print();
    std::cout << myLinkedList.get(1) << '\n';       // return 3
    myLinkedList.print();

    return 0;
}
