//
// Created by Oyekunle Oloyede on 31/10/2020.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return false;

        return findPathSum(root, sum);
    }

    bool findPathSum(TreeNode *root, int target, int currentSum = 0) {
        if (root == nullptr)
            return currentSum == target;

        return findPathSum(root->left, target, currentSum + root->val) ||
               findPathSum(root->right, target, currentSum + root->val);
    }
};
