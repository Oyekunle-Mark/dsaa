//
// Created by Oyekunle Oloyede on 16/11/2020.
//
#include <vector>

class KthLargest {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    };

    TreeNode *root;
    int index;

public:
    KthLargest(int k, std::vector<int> &nums) {
        root = nullptr;
        index = k;

        for (int number : nums)
            root = insert(root, number);
    }

    int add(int val) {

    }

    TreeNode *insert(TreeNode *rootNode, int newVal) {
        if (root == nullptr)
            return new TreeNode(newVal);

        if (newVal < rootNode->val)
            rootNode->left = insert(rootNode->left, newVal);
        else
            rootNode->right = insert(rootNode->right, newVal);

        return rootNode;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
