//
// Created by Oyekunle Oloyede on 13/11/2020.
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
        if (root == nullptr) // base case of nullptr
            return nullptr;

        if (root->val == val) // return root if target node
            return root;

        if (val < root->val) // if val is less than current node's val, continue to the left sub tree
            return searchBST(root->left, val);

        return searchBST(root->right, val); // otherwise, continue search in right sub tree
    }
};
