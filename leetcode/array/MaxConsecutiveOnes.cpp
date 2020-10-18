//
// Created by Oyekunle Oloyede on 04/10/2020.
//
#include <vector>

class MaxConsecutiveOnes {
public:
    static int findMaxConsecutiveOnes(std::vector<int> &nums) {
        int maxCount = 0;
        int currentMax = 0;

        for (auto item : nums) {
            if (item) {
                ++currentMax;
                maxCount = currentMax > maxCount ? currentMax : maxCount;
            } else
                currentMax = 0;
        }

        return maxCount;
    }
};
