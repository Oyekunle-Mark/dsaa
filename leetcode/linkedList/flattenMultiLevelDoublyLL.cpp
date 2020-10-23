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

class FlattenAMultiLevelDoublyLinkedList {
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
        if (head == nullptr) return head; // empty head;

        auto currentNode = head;

        while (currentNode) { // while there is a node to process
            auto nextNode = currentNode->next; // preserve a pointer to the next node

            if (currentNode->child) { // if current node has a child list
                currentNode->next = currentNode->child; // point current node's next to the head of it's childnode
                currentNode->child->prev = currentNode; // point current node's child head prev to current node

                auto newChildTail = mergeChildren(
                        currentNode->child); // call method to merge all child list and return pointer to the tail of the merged list
                currentNode->child = nullptr; // set current node's child to null after merger

                if (nextNode == nullptr) { // if at end of list, point merged child list tail's next to NULL and break
                    newChildTail->next = nextNode;
                    break;
                }

                newChildTail->next = nextNode; // point merged child list tail's next to the next node
                nextNode->prev = newChildTail; // point next node's prev to the merged child list tail

                currentNode = nextNode; // advance current node to next
                continue; // skip to next iteration
            }

            if (nextNode == nullptr) { // if at tail, point current node's next to NULL and break
                currentNode->next = nextNode;
                break;
            }

            currentNode->next = nextNode; // point current node's next to the next node
            nextNode->prev = currentNode; // point next node's prev to the current node
            currentNode = nextNode; // advance pointer
        }

        return head; // return head
    }

    /**
     * Recursively merges all child lists of a given ListNode and returns a pointer to the tail of the merged list.
     */
    Node *mergeChildren(Node *currentHead) {
        while (currentHead) { // while there is a node to process
            auto nextNode = currentHead->next; // preserve a pointer to the next node

            if (currentHead->child) { // if current node has a child
                currentHead->next = currentHead->child; // point current node's next to the head of the child list
                currentHead->child->prev = currentHead; // point child list's head prev to current node

                auto newChildTail = mergeChildren(currentHead->child); // recursively merge child lists
                currentHead->child = nullptr; // set child to NULL after merger

                if (nextNode == nullptr) // if at end of list, return the newChildTail as merged list tail
                    return newChildTail;

                newChildTail->next = nextNode; // point merged list tail's next to the next node
                nextNode->prev = newChildTail; // point next node prev to merged list tail

                currentHead = nextNode; // advance current to next
                continue; // skip to next iteration
            }

            if (nextNode == nullptr) // if at end break;
                break;

            currentHead->next = nextNode; // set current node's next to the next node
            nextNode->prev = currentHead; // set next node's prev to the current node
            currentHead = nextNode; // advance current to next
        }

        return currentHead; // return the last processed node as tail
    }
};
