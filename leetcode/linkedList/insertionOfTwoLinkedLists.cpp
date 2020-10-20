//
// Created by Oyekunle Oloyede on 20/10/2020.
//
#include <unordered_set>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class InsertionOfTwoLinkedLists {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;

        auto currentNodeA = headA;
        auto currentNodeB = headB;

        std::unordered_set<ListNode *> nodeStore{};
        nodeStore.insert(headA);
        nodeStore.insert(headB);

        while (currentNodeA) {
            currentNodeA = currentNodeA->next;

            if (currentNodeA == headB)
                return currentNodeA;


            nodeStore.insert(currentNodeA);
        }

        while (currentNodeB) {
            currentNodeB = currentNodeB->next;

            if (nodeStore.count(currentNodeB))
                return currentNodeB;

            nodeStore.insert(currentNodeB);
        }

        return nullptr;
    }
};
