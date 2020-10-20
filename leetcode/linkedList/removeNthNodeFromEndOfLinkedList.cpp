//
// Created by Oyekunle Oloyede on 20/10/2020.
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
class RemoveFromEndOfLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        explicit ListNode(int x) : val(x), next(nullptr) {}

        explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    static ListNode *removeNthFromEnd(ListNode *head, int n) {
        int listLength{};
        auto currentNode = head;

        while (currentNode) {
            currentNode = currentNode->next;
            ++listLength;
        }

        int indexToDelete = listLength - n;

        if (!indexToDelete) return head->next; // delete at head

        int currentIndex = 0;
        currentNode = head;

        while (currentNode) {
            if (++currentIndex == indexToDelete) { // if next index is to be deleted
                currentNode->next = currentNode->next->next;
                return head;
            }

            currentNode = currentNode->next;
        }

        return nullptr;
    }
};
