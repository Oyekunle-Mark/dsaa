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
            newHead->random = nodeMap.at(currentNode->random); // se
        if (currentNode->next)
            newHead->next = nodeMap.at(currentNode->next);
        currentNode = currentNode->next;
        auto currentNew = newHead->next;

        while (currentNode) {
            if (currentNode->random)
                currentNew->random = nodeMap.at(currentNode->random);
            if (currentNode->next)
                currentNew->next = nodeMap.at(currentNode->next);
            currentNode = currentNode->next;
            currentNew = currentNew->next;
        }

        return newHead;
    }
};
