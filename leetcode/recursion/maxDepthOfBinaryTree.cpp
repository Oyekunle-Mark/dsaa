//
// Created by Oyekunle Oloyede on 02/11/2020.
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
    int maxDepth(TreeNode *root, int level = 0) {
        if (root == nullptr)
            return level;

        auto maxLeftSubTreeDepth = maxDepth(root->left, level + 1);
        auto maxRightSubTreeDepth = maxDepth(root->right, level + 1);

        return maxLeftSubTreeDepth > maxRightSubTreeDepth ? maxLeftSubTreeDepth : maxRightSubTreeDepth;
    }
};
