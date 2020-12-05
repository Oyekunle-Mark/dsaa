//
// Created by Oyekunle Oloyede on 05/12/2020.
//
#include <algorithm>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int> &nums) {
        int sum = 0;
        (void) std::for_each(nums.begin(), nums.end(),
                             [&sum](int num) {
                                 sum += num;
                             });

        int leftSum = 0;

        for (int index = 0; index < nums.size(); ++index) {
            sum -= nums.at(index);

            if (leftSum == sum)
                return index;

            leftSum += nums.at(index);
        }

        return -1;
    }
};
