//
// Created by Oyekunle Oloyede on 22/10/2020.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class MergeSortedLists {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        auto currentL1 = l1;
        auto currentL2 = l2;
        ListNode *newHead{};
        ListNode *currentNode{};
        int currentIndex{};

        if (currentL1->val <= currentL2->val) {
            newHead = new ListNode(currentL1->val);
            currentL1 = currentL1->next;
        } else {
            newHead = new ListNode(currentL2->val);
            currentL2 = currentL2->next;
        }

        currentNode = newHead;

        while (currentL1 && currentL2) {
            if (currentL1->val <= currentL2->val) {
                auto newNode = new ListNode(currentL1->val);
                currentNode->next = newNode;
                currentNode = newNode;

                currentL1 = currentL1->next;
            } else {
                auto newNode = new ListNode(currentL2->val);
                currentNode->next = newNode;
                currentNode = newNode;

                currentL2 = currentL2->next;
            }
        }

        while (currentL1) {
            auto newNode = new ListNode(currentL1->val);
            currentNode->next = newNode;
            currentNode = newNode;

            currentL1 = currentL1->next;
        }

        while (currentL2) {
            auto newNode = new ListNode(currentL2->val);
            currentNode->next = newNode;
            currentNode = newNode;

            currentL2 = currentL2->next;
        }

        return newHead;
    }
};
