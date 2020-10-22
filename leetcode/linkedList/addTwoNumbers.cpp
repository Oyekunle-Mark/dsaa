//
// Created by Oyekunle Oloyede on 22/10/2020.
//
#include <string>

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
class AddTwoNumbers {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto currentL1 = l1;
        std::string l1ToString{};

        while (currentL1) {
            l1ToString = std::to_string(currentL1->val) + l1ToString;
            currentL1 = currentL1->next;
        }

        auto currentL2 = l2;
        std::string l2ToString{};

        while (currentL2) {
            l2ToString = std::to_string(currentL2->val) + l2ToString;
            currentL2 = currentL2->next;
        }

        std::string sum = std::to_string(std::stoi(l1ToString) + std::stoi(l2ToString));

        ListNode *newHead{};
        ListNode *currentNode{};

        for (int index{}; index < sum.length(); ++index) {
            if (!index) {
                newHead = new ListNode(std::stoi(std::string(1, sum.at(index))));
                currentNode = newHead;
            } else {
                auto newNode = new ListNode(std::stoi(std::string(1, sum.at(index))));
                currentNode->next = newNode;
                currentNode = newNode;
            }
        }

        return newHead;
    }
};
