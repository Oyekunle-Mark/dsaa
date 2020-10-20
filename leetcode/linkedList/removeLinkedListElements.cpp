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
class RemoveLinkedListElement {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        explicit ListNode(int x) : val(x), next(nullptr) {}

        explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return head;

        while (head && head->val == val)
            head = head->next;

        auto currentNode = head;
        auto prevNode = head;

        while (currentNode) {
            if (currentNode->val == val) {
                prevNode->next = currentNode->next;
                currentNode = currentNode->next;

                continue;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        return head;
    }
};
