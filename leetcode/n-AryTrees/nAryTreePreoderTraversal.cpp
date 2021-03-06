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
    std::vector<int> preorder(Node *root) {
        std::vector<int> nodes{};

        buildPreorderNodes(root, nodes);

        return nodes;
    }

    void buildPreorderNodes(Node *root, std::vector<int> &nodes) {
        if (root == nullptr)
            return;

        nodes.push_back(root->val);

        for (auto node: root->children)
            buildPreorderNodes(node, nodes);
    }
};
