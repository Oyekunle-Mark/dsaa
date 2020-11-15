//
// Created by Oyekunle Oloyede on 14/11/2020.
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr)
            return nullptr;
    }

    TreeNode *findMin(TreeNode *root) {
        while (root->left)
            root = root->left;

        return root;
    }

    void findInOrderSuccessor(TreeNode *root, TreeNode *&successor, int val) {
        if (root == nullptr) {
            successor = nullptr;
            return;
        }

        if (val < root->val) {
            successor = root;
            findInOrderSuccessor(root->left, successor, val);
        } else if (val == root->val) {
            if (root->right)
                successor = findMin(root->right);
        } else
            findInOrderSuccessor(root->right, successor, val);
    }

    TreeNode *findTargetNode(TreeNode *root, int val) {
        if (root == nullptr)
            return nullptr;

        if (root->val == val)
            return root;
        else if (val < root->val)
            return findTargetNode(root->left, val);

        return findTargetNode(root->right, val);
    }
};
