//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> numsIndex{}; // will store index of numbers in nums

        for (int index = 0; index < nums.size(); ++index) {
            if (numsIndex.count(nums.at(index))) { // if current number has occurred before
                if ((index - numsIndex.at(nums.at(index))) <=
                    k) // does the difference of the index of both numbers not greater than k
                    return true;
                else // otherwise simply update the index of the number to the present index
                    numsIndex.at(nums.at(index)) = index;
            } else // otherwise, add number to map
                numsIndex.insert({nums.at(index), index});
        }

        return false;
    }
};
