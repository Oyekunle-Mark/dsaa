//
// Created by Oyekunle Oloyede on 02/12/2020.
//
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> intersect{};

        std::set_intersection(nums1.begin(), nums1.end(),
                              nums2.begin(), nums2.end(),
                              std::back_inserter(intersect));

        std::set<int> unique_intersect(intersect.begin(), intersect.end());
        return std::vector<int>(unique_intersect.begin(), unique_intersect.end());
    }
};
