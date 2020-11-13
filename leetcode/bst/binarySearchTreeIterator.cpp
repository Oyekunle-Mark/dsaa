//
// Created by Oyekunle Oloyede on 13/11/2020.
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
class BSTIterator {
private:
    std::vector<int> nodeValues{};
    size_t currentIndex{};

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    explicit BSTIterator(TreeNode *root) {
        buildValues(root);
    }

    /** @return the next smallest number */
    int next() {
        return nodeValues.at(currentIndex++);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return currentIndex < nodeValues.size();
    }

    /**
     * Build nodes values using inorder traversal
     */
    void buildValues(TreeNode *root) {
        if (root == nullptr)
            return;

        if (root->left)
            buildValues(root->left);

        nodeValues.push_back(root->val);

        if (root->right)
            buildValues(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
