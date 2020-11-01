//
// Created by Oyekunle Oloyede on 01/11/2020.
//
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
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr) // if root is a null pointer
            return nullptr;

        if (root->val == val) // if root node value is val
            return root;

        auto leftSubTreeSearchResult = searchBST(root->left, val); // recursively search left sub tree
        auto rightSubTreeSearchResult = searchBST(root->right, val); // recursively search right sub tree

        // return a non-null pointer is one is found or null pointer otherwise
        return leftSubTreeSearchResult == nullptr ? rightSubTreeSearchResult : leftSubTreeSearchResult;
    }
};
