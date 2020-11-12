//
// Created by Oyekunle Oloyede on 12/11/2020.
//

//
// Created by Oyekunle Oloyede on 12/11/2020.
//
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() = default;

    explicit Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = std::move(_children);
    }
};


class Solution {
public:
    std::vector<int> postorder(Node *root) {

    }

    void buildPostorderNodes(Node *root, std::vector<int> &nodes) {
        if (root == nullptr)
            return;

        for (auto node: root->children)
            buildPostorderNodes(node, nodes);

        nodes.push_back(root->val);
    }
};
