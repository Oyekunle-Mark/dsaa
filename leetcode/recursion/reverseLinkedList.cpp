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
        if (head == nullptr) // if empty node return early
            return head;

        return recursivelyReverseList(head, head);
    }

    ListNode *recursivelyReverseList(ListNode *head, ListNode *oldHead) {
        // when the next node after the old head is null then the job is done
        if (oldHead->next == nullptr)
            return head;

        // move the next node after old head to the head and change the head pointer
        auto newHead = oldHead->next;
        oldHead->next = oldHead->next->next;
        newHead->next = head;
        head = newHead;

        // recursively call reverse list with head and old head;
        return recursivelyReverseList(head, oldHead);
    }
};
