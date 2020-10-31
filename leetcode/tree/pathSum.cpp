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
        if (root == nullptr) // return false for empty tree
            return false;

        return findPathSum(root, sum, root->val); // call findPath starting at root and using root-val as current sum
    }

    /**
     * Recursively add up the sum of the node values along the tree.
     * Compares currentSum to target and returns result of comparison.
     */
    bool findPathSum(TreeNode *root, int target, int currentSum) {
        // base case. At leaf node, compare and return result of comparison
        if (root->left == nullptr && root->right == nullptr)
            return currentSum == target;

        auto leftSubTreePathSumEquals = false;
        auto rightSubTreePathSumEquals = false;

        if (root->left) // if there is a left node, pass left node pointer and add left node value to current sum
            leftSubTreePathSumEquals = findPathSum(root->left, target, currentSum + root->left->val);

        if (root->right) // if there is a right node, pass right node pointer and add right node value to current sum
            rightSubTreePathSumEquals = findPathSum(root->right, target, currentSum + root->right->val);

        return leftSubTreePathSumEquals || rightSubTreePathSumEquals; // does sum of left or right sub-tree equal target
    }
};
