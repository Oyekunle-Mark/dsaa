//
// Created by Oyekunle Oloyede on 01/11/2020.
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

        explicit ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *swapPairs(ListNode *head) {
        // base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // swap head and next node
        auto nextNode = head->next;
        head->next = head->next->next;
        nextNode->next = head;
        head = nextNode;

        // call swapPairs recursively with head->next->next
        auto nextSwappedHead = swapPairs(head->next->next);

        // chain the head of the next swapped to the current list
        head->next->next = nextSwappedHead;

        return head;
    }
};
