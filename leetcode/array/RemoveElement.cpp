//
// Created by Oyekunle Oloyede on 05/10/2020.
//
#include <vector>

class RemoveElement {
public:
    static int removeElement(std::vector<int> &nums, int val) {
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == val) {
                iter = nums.erase(iter);
                --iter;
            }
        }

        return nums.size();
    }
};
