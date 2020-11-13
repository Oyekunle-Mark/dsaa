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
class BSTIterator {
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
    explicit BSTIterator(TreeNode *root) {

    }

    /** @return the next smallest number */
    int next() {

    }

    /** @return whether we have a next smallest number */
    bool hasNext() {

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
