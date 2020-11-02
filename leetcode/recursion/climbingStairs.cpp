//
// Created by Oyekunle Oloyede on 02/11/2020.
//
#include <unordered_map>

class Solution {
public:
    int climbStairs(int n) {
        std::unordered_map<int, int> cache{};

        return findStairsCombo(n, cache);
    }

    int findStairsCombo(int n, std::unordered_map<int, int> &cache) {
        auto itr = cache.find(n);

        if (itr != cache.end())
            return itr->second;

        int result = 0;

        if (n < 3)
            return n;
        else
            result = findStairsCombo(n - 1, cache) + findStairsCombo(n - 2, cache);

        cache.insert({n, result});
        return result;
    }
};
