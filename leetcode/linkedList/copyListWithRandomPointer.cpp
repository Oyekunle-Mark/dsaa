//
// Created by Oyekunle Oloyede on 23/10/2020.
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class CopyListWithRandomPointer {
private:
    class Node {
    public:
        int val;
        Node *next;
        Node *random;

        explicit Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

public:
    Node *copyRandomList(Node *head) {

    }
};
