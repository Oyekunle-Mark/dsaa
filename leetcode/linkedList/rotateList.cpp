//
// Created by Oyekunle Oloyede on 23/10/2020.
//
#include <map>

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || !k) return head;

        auto currentNode = head;

        while (currentNode)
            currentNode = currentNode->next;

        currentNode->next = head;
        currentNode = head;

        for (int i{}; i < k; ++i)
            currentNode = currentNode->next;

        head = currentNode->next;
        currentNode->next = nullptr;

        return head;
    }
};
