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
        if (root->left == nullptr && root->right == nullptr)
            return currentSum == target;

        auto leftSubTreePathSumEquals = false;
        auto rightSubTreePathSumEquals = false;

        if (root->left)
            leftSubTreePathSumEquals = findPathSum(root->left, target, currentSum + root->left->val);

        if (root->right)
            rightSubTreePathSumEquals = findPathSum(root->right, target, currentSum + root->right->val);

        return leftSubTreePathSumEquals || rightSubTreePathSumEquals;
    }
};
