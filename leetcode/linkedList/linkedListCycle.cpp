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
    bool hasCycle(ListNode *head) {

    }
};
