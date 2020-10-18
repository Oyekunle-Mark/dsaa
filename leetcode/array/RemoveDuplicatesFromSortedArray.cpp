//
// Created by Oyekunle Oloyede on 05/10/2020.
//
#include <vector>

class RemoveDuplicatesFromSortedArray {
public:
    static int removeDuplicates(std::vector<int> &nums) {
        int previous{};

        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (iter == nums.begin()) {
                previous = *iter;
            } else {
                if (*iter == previous) {
                    iter = nums.erase(iter);
                    --iter;
                } else {
                    previous = *iter;
                }
            }
        }

        return nums.size();
    }
};
