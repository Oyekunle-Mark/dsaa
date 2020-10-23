//
// Created by Oyekunle Oloyede on 23/10/2020.
//
#include <map>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class CopyListWithRandomPointer {
private:
    class Node {
    public:
        int val;
        Node *next;
        Node *random;

        explicit Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return head; // return for empty list

        std::map<Node *, Node *> nodeMap{}; // stores a mapping of nodes to copies
        auto currentNode = head;

        while (currentNode) {
            auto newNode = new Node(currentNode->val); // create a copy with current node's val
            nodeMap.insert({currentNode, newNode}); // insert the mapping

            currentNode = currentNode->next;
        }

        auto newHead = nodeMap.at(head); // set the copy of the head node as new node
        currentNode = head; // track current node

        if (currentNode->random) // if current node has a random pointer
            newHead->random = nodeMap.at(
                    currentNode->random); // set new head random pointer to the copy of head node random pointer

        if (currentNode->next) // if current node has a next
            newHead->next = nodeMap.at(currentNode->next); // set new head next pointer to the copy of head node next

        currentNode = currentNode->next; // advance current node to the next node
        auto currentNew = newHead->next; // advance current copy list node to the next copied node

        while (currentNode) { // while there is node in the list
            if (currentNode->random) // if current node has a random pointer
                currentNew->random = nodeMap.at(
                        currentNode->random); // set current copy list node's random pointer to the copy of the original list current node's random pointer

            if (currentNode->next) // if current node has a next
                currentNew->next = nodeMap.at(
                        currentNode->next); // set current copy list node's next to the copy of the original list current node's next pointer

            currentNode = currentNode->next; // advance current node of original list
            currentNew = currentNew->next; // advance current node of the copy list
        }

        return newHead;
    }
};
