//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> numsIndex{};

        for (int index = 0; index < nums.size(); ++index) {
            if (numsIndex.count(nums.at(index))) {
                if ((index - numsIndex.at(nums.at(index))) <= k)
                    return true;
                else
                    numsIndex.at(nums.at(index)) = index;
            } else
                numsIndex.insert({nums.at(index), index});
        }

        return false;
    }
};
