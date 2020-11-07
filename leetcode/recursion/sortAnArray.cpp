//
// Created by Oyekunle Oloyede on 07/11/2020.
//
#include <vector>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        if (nums.size() <= 1)
            return nums;

        int pivot = static_cast<int>(nums.size()) / 2;
        auto left = std::vector<int>(nums.begin(), nums.begin() + pivot);
        auto right = std::vector<int>(nums.begin() + pivot, nums.end());

        return merge(sortArray(left), sortArray(right));
    }

    std::vector<int> merge(const std::vector<int> &right, const std::vector<int> &left) {
        std::vector<int> result{};
        const size_t rightSize = right.size();
        const size_t leftSize = left.size();
        size_t rightIndex = 0;
        size_t leftIndex = 0;

        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (left.at(leftIndex) < right.at(rightIndex))
                result.push_back(left.at(leftIndex++));
            else
                result.push_back(right.at(rightIndex++));
        }

        while (leftIndex < leftSize)
            result.push_back(left.at(leftIndex++));

        while (rightIndex < rightSize)
            result.push_back(right.at(rightIndex++));

        return result;
    }
};
