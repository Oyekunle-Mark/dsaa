//
// Created by Oyekunle Oloyede on 14/11/2020.
//

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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) // if empty tree return the new node of value val
            return new TreeNode(val);

        insertIntoPlace(root, val);

        return root;
    }

    /**
     * Insert the val into the correct position in the tree
     */
    void insertIntoPlace(TreeNode *root, int val) {
        if (val < root->val) {
            if (root->left == nullptr)
                root->left = new TreeNode(val);
            else
                insertIntoBST(root->left, val);
        } else {
            if (root->right == nullptr)
                root->right = new TreeNode(val);
            else
                insertIntoBST(root->right, val);
        }
    }
};
