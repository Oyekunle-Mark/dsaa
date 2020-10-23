//
// Created by Oyekunle Oloyede on 22/10/2020.
//
#include <string>

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
class AddTwoNumbers {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int l1Value = l1->val;
        int l2Value = l2->val;
        l1 = l1->next;
        l2 = l2->next;
        auto *head = new ListNode((l1Value + l2Value) % 10);
        auto currentNode = head;
        int carry = (l1Value + l2Value) / 10;

        while (l1 || l2 || carry) {
            l1Value = 0;
            l2Value = 0;

            if (l1) {
                l1Value = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                l2Value = l2->val;
                l2 = l2->next;
            }

            auto newNode = new ListNode((l1Value + l2Value + carry) % 10);
            currentNode->next = newNode;
            currentNode = newNode;
            carry = (l1Value + l2Value + carry) / 10;
        }

        return head;
    }
};
