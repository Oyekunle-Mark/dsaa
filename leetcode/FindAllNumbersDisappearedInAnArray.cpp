//
// Created by Oyekunle Oloyede on 09/10/2020.
//
#include <vector>
#include <set>

class FindAllNumbersDisappearedInAnArray {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
        std::set<int> range{};

        for (auto num: nums)
            range.insert(num);

        std::vector<int> result{};

        for (int i{1}; i <= nums.size(); ++i) {
            auto isFound = range.find(i);

            if (isFound == range.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};
