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
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> nodeValues{};

        if (root == nullptr)
            return nodeValues;

        computePostOrderPath(root, nodeValues);

        return nodeValues;
    }

    void computePostOrderPath(TreeNode *root, std::vector<int> &nodeValues) {
        if (root->left)
            computePostOrderPath(root->left, nodeValues);

        if (root->right)
            computePostOrderPath(root->right, nodeValues);

        nodeValues.push_back(root->val);
    }
};
