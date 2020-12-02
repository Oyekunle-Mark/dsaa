//
// Created by Oyekunle Oloyede on 02/12/2020.
//
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> store{};

        for (auto item : nums) {
            if (store.count(item))
                return true;

            store.insert(item);
        }

        return false;
    }
};
