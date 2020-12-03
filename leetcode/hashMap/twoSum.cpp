//
// Created by Oyekunle Oloyede on 03/12/2020.
//

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> numberIndexMap{};
        std::vector<int> twoSumIndices{};

        for (int index = 0; index < nums.size(); ++index) {
            if (numberIndexMap.count(target - nums.at(index))) {
                twoSumIndices.push_back(numberIndexMap.at(target - nums.at(index)));
                twoSumIndices.push_back(index);
                break;
            } else
                numberIndexMap.insert({nums.at(index), index});
        }

        return twoSumIndices;
    }
};
