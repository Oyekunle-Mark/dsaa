//
// Created by Oyekunle Oloyede on 05/11/2020.
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
class Solution {
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

        ListNode *head{};

        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        mergeLists(l1, l2, head);

        return head;
    }

    void mergeLists(ListNode *l1, ListNode *l2, ListNode *mergedNode) {
        if (l1 || l2) {
            if ((l1 && l2) && l1->val < l2->val) {
                mergedNode->next = l1;
                return mergeLists(l1->next, l2, mergedNode->next);
            }

            if ((l1 && l2) && l2->val <= l1->val) {
                mergedNode->next = l2;
                return mergeLists(l1, l2->next, mergedNode->next);
            }

            if (l1) {
                mergedNode->next = l1;
                return mergeLists(l1->next, l2, mergedNode->next);
            }

            if (l2) {
                mergedNode->next = l2;
                return mergeLists(l1, l2->next, mergedNode->next);
            }
        }
    }
};
