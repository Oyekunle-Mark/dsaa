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
        if (root == nullptr) // if tree is emptu
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            // if there is one or no child
            // remove node and update accordingly
            if (root->left == nullptr) {
                auto temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                auto temp = root->left;
                delete root;
                return temp;
            }

            // if there are two children, find the inorder successor by finding the minimum node in the right subtree
            // update the node's value to it's inorder successor and recursively delete it's inorder successor
            auto temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }

    TreeNode *findMin(TreeNode *root) {
        while (root->left)
            root = root->left;

        return root;
    }
};
