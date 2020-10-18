//
// Created by Oyekunle Oloyede on 08/10/2020.
//
#include <vector>

class MoveZeroes {
public:
    static void moveZeroes(std::vector<int> &nums) {
        const int numLength{static_cast<int>(nums.size())};
        int index{};

        for (int i{}; i < numLength; ++i) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                ++index;
            }
        }

        for (int i{index}; i < numLength; ++i) {
            nums[index] = 0;
            ++index;
        }
    }
};
