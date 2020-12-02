//
// Created by Oyekunle Oloyede on 02/12/2020.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        std::unordered_map<int, int> store{};

        for (auto number : nums) {
            if (!store.count(number))
                store.insert({number, 1});
            else
                store.at(number) += 1;
        }

        typedef std::unordered_map<int, int>::value_type map_pair_t;

        auto itr = std::find_if(store.begin(), store.end(),
                                [](const map_pair_t &item) { return item.second == 1; });

        return itr->first;
    }
};
