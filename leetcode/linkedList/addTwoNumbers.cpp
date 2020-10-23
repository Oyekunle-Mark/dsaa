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
        // get the values of the two head nodes
        int l1Value = l1->val;
        int l2Value = l2->val;
        // create a new node with the remainder of adding both head node values
        auto *head = new ListNode((l1Value + l2Value) % 10);

        // advance pointers
        l1 = l1->next;
        l2 = l2->next;
        auto currentNode = head; // point current node to the head
        int carry = (l1Value + l2Value) / 10; // set carry to the quotient of integer division

        // loop while there is a valid node or carry
        while (l1 || l2 || carry) {
            // reset values to zero
            l1Value = 0;
            l2Value = 0;

            // if list 1 still has a node
            if (l1) {
                // extract the value and advance the pointer
                l1Value = l1->val;
                l1 = l1->next;
            }

            // if list 2 still has a node
            if (l2) {
                // extract the value and advance the pointer
                l2Value = l2->val;
                l2 = l2->next;
            }

            // create new node with the remainder of the sum of the node values and the carry value
            auto newNode = new ListNode((l1Value + l2Value + carry) % 10);
            // add new node to the chain
            currentNode->next = newNode;
            // point currentNode node to the last node
            currentNode = newNode;
            // set carry to the integer division of the sum of node values and carry by 10
            carry = (l1Value + l2Value + carry) / 10;
        }

        return head; // return new list head
    }
};
