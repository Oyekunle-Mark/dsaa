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

class LinkedListCycleII {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    static ListNode *detectCycle(ListNode *head) {
        auto currentNode = head;
        std::unordered_set<ListNode *> nodeStore{};
        nodeStore.insert(head);

        while (currentNode) {
            currentNode = currentNode->next;

            if (nodeStore.count(currentNode))
                return currentNode;

            nodeStore.insert(currentNode);
        }

        return nullptr;
    }
};
