//
// Created by Oyekunle Oloyede on 23/10/2020.
//
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
        if (head == nullptr) return head;

        auto currentNode = head;

        while (currentNode) {
            auto nextNode = currentNode->next;

            auto newNode = new Node(currentNode->val);
            newNode->next = nextNode;
            currentNode->next = newNode;
            currentNode = nextNode;
        }

        auto prevNode = head;
        auto nextNode = head->next;
        head = nextNode;

        while (prevNode) {
            if (prevNode->random)
                nextNode->random = prevNode->random->next;

            auto prevPrev = prevNode;
            prevNode = prevNode->next->next;
            prevPrev->next = prevNode;

            if (prevNode == nullptr)
                break;

            auto prevNext = nextNode;
//            nextNode->next = nextNode->next->next;
            nextNode = nextNode->next->next;
            prevNext->next = nextNode;
        }

        return head;
    }
};
