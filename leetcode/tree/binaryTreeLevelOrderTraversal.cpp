//
// Created by Oyekunle Oloyede on 27/10/2020.
//
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> levelOrder{};
        auto treeHeight = findTreeHeight(root);

        for (int level = 1; level <= treeHeight; ++level) {
            std::vector<int> nodeVisitedAtThisLevel{};
            visitTreeNodeAtLevel(root, level, nodeVisitedAtThisLevel);
            levelOrder.push_back(nodeVisitedAtThisLevel);
        }

        return levelOrder;
    }

    int findTreeHeight(TreeNode *root, int currentLevel = 0) {
        if (root == nullptr)
            return currentLevel;

        int heightOfLeftSubtree = findTreeHeight(root->left, currentLevel + 1);
        int heightOfRightSubtree = findTreeHeight(root->right, currentLevel + 1);

        return max(heightOfLeftSubtree, heightOfRightSubtree);
    }

    int max(int first, int second) {
        return first > second ? first : second;
    }

    void visitTreeNodeAtLevel(TreeNode *root, int level, std::vector<int> &nodesVisited) {
        if (root == nullptr)
            return;

        if (level == 1)
            nodesVisited.push_back(root->val);
        else {
            visitTreeNodeAtLevel(root->left, level - 1, nodesVisited);
            visitTreeNodeAtLevel(root->right, level - 1, nodesVisited);
        }
    }
};
