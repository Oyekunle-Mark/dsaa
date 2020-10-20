//
// Created by Oyekunle Oloyede on 20/10/2020.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class LinkedListCycle {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static bool hasCycle(ListNode *head) {
        auto slowPointer = head;
        auto fastPointer = head;

        while (slowPointer && fastPointer && fastPointer->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;

            if (slowPointer == fastPointer)
                return true;
        }

        return false;
    }
};
