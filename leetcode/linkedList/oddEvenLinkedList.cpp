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
 * Example 1:
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL

 * Example 2:
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 */
class OddEvenLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        explicit ListNode(int x) : val(x), next(nullptr) {}

        explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *oddEvenList(ListNode *head) {
        // if list is not up to three nodes, return early
        if (!head || !head->next || !head->next->next) return head;

        auto lastOddNode = head;
        auto nextEvenNode = head->next;

        // loop while there is a next odd node to swap
        while (nextEvenNode && nextEvenNode->next) {
            // remove the next odd node, i.e, the node after the next even node
            auto removedNode = removeNextNode(nextEvenNode);
            // set next even node to the next node after the just removed node
            nextEvenNode = removedNode->next;
            // insert the node after the last odd node
            addNodeAfter(lastOddNode, removedNode);
            // set removed node as last odd node so next encountered odd nodes are inserted after
            lastOddNode = removedNode;

            // check if there is a next odd node after the removed node
            if (!removedNode->next || !removedNode->next->next) break;
        }

        return head;
    }

    ListNode *removeNextNode(ListNode *node) {
        auto nodeToRemove = node->next;
        node->next = node->next->next;

        return nodeToRemove;
    }

    void addNodeAfter(ListNode *node, ListNode *newNode) {
        newNode->next = node->next;
        node->next = newNode;
    }
};
