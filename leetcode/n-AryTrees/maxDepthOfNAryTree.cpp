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
    int maxDepth(Node *root, int depth = 0) {
        if (root == nullptr) // when root is a null pointer
            return depth;

        if (root->children.empty()) // if root is a leaf node
            return depth + 1; // increment depth to count current level and return

        std::vector<int> subTreeDepths{};

        for (auto node : root->children) // for all child nodes
            subTreeDepths.push_back(maxDepth(node, depth +
                                                   1)); // increment depth to count current level and call recursively find sub tree depth

        return *std::max_element(subTreeDepths.begin(), subTreeDepths.end()); // return the max depth of sub trees
    }
};
