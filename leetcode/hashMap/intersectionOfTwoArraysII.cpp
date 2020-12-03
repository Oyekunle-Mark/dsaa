//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::unordered_map<int, int> nums2Count{}; // store count of the numbers in nums2

        for (auto num : nums2) {
            if (nums2Count.count(num))  // if number has been encountered previously, increment count
                nums2Count.at(num) += 1;
            else
                nums2Count.insert({num, 1});    // if new number, set count to 1
        }

        std::vector<int> intersection{};    // will hold the intersection of nums1 and nums2

        for (auto number : nums1) {
            if (nums2Count.count(number) &&
                nums2Count.at(number) > 0) {    // if number exist in nums2 and it still has a positive count
                intersection.push_back(number);     // add to intersection
                nums2Count.at(number) -= 1;     // decrement the count
            }
        }

        return intersection;
    }
};
