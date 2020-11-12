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
    std::vector<std::vector<int>> levelOrder(Node *root) {
        std::vector<std::vector<int>> levelOrderNodes{};
        auto maxHeightOfTree = findNAryTreeHeight(root);

        for (int level = 1; level <= maxHeightOfTree; ++level) {
            std::vector<int> levelNodes{};
            addNodesAtLevel(root, levelNodes, level);
            levelOrderNodes.push_back(levelNodes);
        }

        return levelOrderNodes;
    }

    int findNAryTreeHeight(Node *root, int level = 0) {
        if (root == nullptr)
            return level;

        if (root->children.empty())
            return level + 1;

        std::vector<int> subTreeLevels{};

        for (auto node : root->children)
            subTreeLevels.push_back(findNAryTreeHeight(node, level + 1));

        int max = 0;

        for (int i : subTreeLevels) {
            if (i > max)
                max = i;
        }

        return max;
    }

    void addNodesAtLevel(Node *root, std::vector<int> &nodes, int targetLevel, int currentLevel = 1) {
        if (root == nullptr)
            return;

        if (targetLevel == currentLevel) {
            nodes.push_back(root->val);
            return;
        }

        for (auto node : root->children)
            addNodesAtLevel(node, nodes, targetLevel, currentLevel + 1);
    }
};
