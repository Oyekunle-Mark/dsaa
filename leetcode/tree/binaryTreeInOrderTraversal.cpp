//
// Created by Oyekunle Oloyede on 26/10/2020.
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
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> nodeValues{};

        if (root == nullptr)
            return nodeValues;

        computeInorderPath(root, nodeValues);

        return nodeValues;
    }

    void computeInorderPath(TreeNode *root, std::vector<int> &nodeValues) {
        if (root->left)
            computeInorderPath(root->left, nodeValues);

        nodeValues.push_back(root->val);

        if (root->right)
            computeInorderPath(root->right, nodeValues);
    }
};
