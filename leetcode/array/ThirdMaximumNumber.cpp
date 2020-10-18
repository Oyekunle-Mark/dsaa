//
// Created by Oyekunle Oloyede on 09/10/2020.
//
#include <vector>
#include <algorithm>

class ThirdMaximumNumber {
public:
    static int thirdMax(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int maxNum = nums[nums.size() - 1];
        int count{};

        for (int i{static_cast<int>(nums.size() - 1)}; i >= 0; --i) {
            if (nums[i] < maxNum) {
                maxNum = nums[i];

                if (++count == 2)
                    return maxNum;
            }
        }

        return nums[nums.size() - 1];
    }
};
