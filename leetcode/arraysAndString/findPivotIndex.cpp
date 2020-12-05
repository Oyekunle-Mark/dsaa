//
// Created by Oyekunle Oloyede on 05/12/2020.
//
#include <algorithm>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int> &nums) {
        int sum = 0;
        std::for_each(nums.begin(), nums.end(),
                      [&sum](int num) {
                          sum += num;
                      })
    }
};
