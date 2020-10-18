//
// Created by Oyekunle Oloyede on 05/10/2020.
//
#include <vector>

class MergeSorted {
public:
    static void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        std::vector<int> mergedNums{};
        int mIndex{};
        int nIndex{};

        while (mIndex < m && nIndex < n) {
            if (nums1.at(mIndex) <= nums2.at(nIndex)) {
                mergedNums.push_back(nums1.at(mIndex));
                ++mIndex;
            } else {
                mergedNums.push_back(nums2.at(nIndex));
                ++nIndex;
            }
        }

        while (mIndex < m) {
            mergedNums.push_back(nums1.at(mIndex));
            ++mIndex;
        }

        while (nIndex < n) {
            mergedNums.push_back(nums2.at(nIndex));
            ++nIndex;
        }

        for (int i{}; i < mergedNums.size(); ++i)
            nums1[i] = mergedNums[i];
    }
};
