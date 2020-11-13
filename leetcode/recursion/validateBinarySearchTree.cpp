//
// Created by Oyekunle Oloyede on 08/11/2020.
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
    /*
     * Efficient solution using O(1) space.
    TreeNode *prevNode = nullptr;

    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;

        if (!isValidBST(root->left))
            return false;

        if (prevNode && root->val <= prevNode->val)
            return false;

        prevNode = root;

        return isValidBST(root->right);
    }
    */

    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;

        std::vector<int> nodes{};
        performInorder(root, nodes);

        return std::is_sorted(nodes.begin(), nodes.end());
    }

    void performInorder(TreeNode *root, std::vector<int> &nodes) {

    }
};
