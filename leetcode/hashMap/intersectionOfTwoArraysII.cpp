//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::unordered_map<int, int> nums2Count{};
        std::vector<int> intersection{};

        for (auto num : nums2) {
            if (nums2Count.count(num))
                nums2Count.at(num) += 1;
            else
                nums2Count.insert({num, 1});
        }

        for (auto number : nums1) {
            if (nums2Count.count(number) && nums2Count.at(number) > 0) {
                intersection.push_back(number);
                nums2Count.at(number) -= 1;
            }
        }

        return intersection;
    }
};
