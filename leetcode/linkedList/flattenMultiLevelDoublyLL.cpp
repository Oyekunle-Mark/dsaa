//
// Created by Oyekunle Oloyede on 23/10/2020.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    class Node {
    public:
        int val;
        Node *prev;
        Node *next;
        Node *child;
    };

public:
    Node *flatten(Node *head) {
        if (head == nullptr) return head;

        auto currentNode = head;

        while (currentNode) {
            auto nextNode = currentNode->next;

            if (currentNode->child) {
                currentNode->next = currentNode->child;
                currentNode->child->prev = currentNode;
                auto newChildTail = mergeChildren(currentNode->child);
                currentNode->child = nullptr;

                if (nextNode == nullptr) {
                    newChildTail->next = nextNode;
                    break;
                }

                newChildTail->next = nextNode;
                nextNode->prev = newChildTail;

                currentNode = nextNode;
                continue;
            }

            if (nextNode == nullptr) {
                currentNode->next = nextNode;
                break;
            }

            currentNode->next = nextNode;
            nextNode->prev = currentNode;
            currentNode = nextNode;
        }

        return head;
    }

    Node *mergeChildren(Node *currentHead) {
        while (currentHead) {
            auto nextNode = currentHead->next;

            if (currentHead->child) {
                currentHead->next = currentHead->child;
                currentHead->child->prev = currentHead;
                auto newChildTail = mergeChildren(currentHead->child);
                currentHead->child = nullptr;

                if (nextNode == nullptr)
                    return newChildTail;

                newChildTail->next = nextNode;
                nextNode->prev = newChildTail;

                currentHead = nextNode;
                continue;
            }

            if (nextNode == nullptr)
                break;

            currentHead->next = nextNode;
            nextNode->prev = currentHead;
            currentHead = nextNode;
        }

        return currentHead;
    }
};
