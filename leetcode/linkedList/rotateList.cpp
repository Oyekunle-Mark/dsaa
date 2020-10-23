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
        if (head == nullptr || head->next == nullptr) return head;

        std::map<ListNode *, ListNode *> nodeToPrevMap{};

        auto prevNode = head;
        auto currentNode = head->next;
        nodeToPrevMap.insert({head, nullptr});
        ListNode *tail{};

        while (currentNode) {
            nodeToPrevMap.insert({currentNode, prevNode});

            prevNode = currentNode;
            currentNode = currentNode->next;

            if (currentNode == nullptr)
                tail = prevNode;
        }

        while (k--) {
            tail->next = head;
            nodeToPrevMap.at(head) = tail;
            head = tail;
            auto newTail = nodeToPrevMap.at(tail);
            nodeToPrevMap.at(tail) = nullptr;
            tail = newTail;
            newTail->next = nullptr;
        }

        return head;
    }
};
