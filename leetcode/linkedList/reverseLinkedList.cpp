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
 *
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
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
    static ListNode *reverseList(ListNode *head) {
        if (!head) return head; // if the list is empty

        auto tail = head; // set the head to tail to begin with

        while (tail->next) { // while there is a node after tail
            auto newHead = tail->next; // set newHead to the next node after tail
            tail->next = tail->next->next; // remove the newHead and point tail to the node after newHead
            newHead->next = head; // point newHead's next to the old head i.e, add newHead at the head of the linked list
            head = newHead; // update the head pointer variable to point at newHead
        }

        return head;
    }
};
