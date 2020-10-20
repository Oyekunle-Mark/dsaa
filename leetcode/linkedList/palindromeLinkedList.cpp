//
// Created by Oyekunle Oloyede on 20/10/2020.
//
#include <vector>

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
 * Input: 1->2
 * Output: false

 * Example 2:
 * Input: 1->2->2->1
 * Output: true
 */
class PalindromeLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        explicit ListNode(int x) : val(x), next(nullptr) {}

        explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    bool isPalindrome(ListNode *head) {
        std::vector<int> values{}; // stores node values

        auto currentNode = head;

        while (currentNode) { // copy all the node value into values
            values.push_back(currentNode->val);
            currentNode = currentNode->next;
        }

        int endIndex = static_cast<int>(values.size()); // represents the end index plus one
        int frontIndex = -1; // represents the front index minus one

        while (++frontIndex < --endIndex) // perform increment, decrement and comparison
            if (values.at(frontIndex) != values.at(endIndex))
                return false;

        return true;
    }
};
