//
// Created by Oyekunle Oloyede on 05/12/2020.
//
#include <vector>
#include <algorithm>

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int largestIndex = 0;

        for (int index = 0; index < nums.size(); ++index) {
            if (nums.at(index) > nums.at(largestIndex))
                largestIndex = index;
        }

        for (int index = 0; index < nums.size(); ++index) {
            if (index != largestIndex)
                if (nums.at(index) * 2 > nums.at(largestIndex))
                    return -1;
        }

        return largestIndex;
    }
};
