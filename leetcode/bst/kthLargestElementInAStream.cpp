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

public:
    KthLargest(int k, std::vector<int> &nums) {

    }

    int add(int val) {

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
