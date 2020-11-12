//
// Created by Oyekunle Oloyede on 12/11/2020.
//
#include <vector>
#include <algorithm>

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
    std::vector<std::vector<int>> levelOrder(Node *root) {

    }

    int findNAryTreeHeight(Node *root, int level = 0) {
        if (root == nullptr)
            return level;

        std::vector<int> subTreeLevels{};

        for (auto node: root->children)
            subTreeLevels.push_back(findNAryTreeHeight(node, level + 1));

        return *std::max_element(subTreeLevels.begin(), subTreeLevels.end());
    }
};
