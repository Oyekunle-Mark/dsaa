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
class ReverseLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        explicit ListNode(int x) : val(x), next(nullptr) {}

        explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return head;

        return recursivelyReverseList(head, head);
    }

    ListNode *recursivelyReverseList(ListNode *head, ListNode *oldHead) {
        if (oldHead->next == nullptr)
            return head;

        auto newHead = oldHead->next;
        oldHead->next = oldHead->next->next;
        newHead->next = head;
        head = newHead;

        return recursivelyReverseList(head, oldHead);
    }
};
