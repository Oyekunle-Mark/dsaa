//
// Created by Oyekunle Oloyede on 08/11/2020.
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
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;

        if (root->left && root->left->val >= root->val)
            return false;

        if (root->right && root->right->val <= root->val)
            return false;

        auto leftTree = isValidLeft(root->left, root->val);
        auto rightTree = isValidRight(root->right, root->val);

        return leftTree && rightTree;
    }

    bool isValidLeft(TreeNode *root, int rootVal) {
        if (root == nullptr)
            return true;

        if (root->left && (root->left->val >= rootVal))
            return false;

        if (root->right && (root->right->val >= rootVal))
            return false;

        if (root->left && (root->left->val >= root->val))
            return false;

        if (root->right && (root->right->val <= root->val))
            return false;

        auto leftTree = isValidLeft(root->left, rootVal);
        auto rightTree = isValidLeft(root->right, rootVal);

        return leftTree && rightTree;
    }

    bool isValidRight(TreeNode *root, int rootVal) {
        if (root == nullptr)
            return true;

        if (root->left && (root->left->val <= rootVal))
            return false;

        if (root->right && (root->right->val <= rootVal))
            return false;

        if (root->left && (root->left->val >= root->val))
            return false;

        if (root->right && (root->right->val <= root->val))
            return false;

        auto leftTree = isValidRight(root->left, rootVal);
        auto rightTree = isValidRight(root->right, rootVal);

        return leftTree && rightTree;
    }
};
