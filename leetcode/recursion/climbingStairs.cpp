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

    /**
     * Recursively find the number of ways of climbing n stairs.
     * Uses memoization with an map as the cache.
     */
    int findStairsCombo(int n, std::unordered_map<int, int> &cache) {
        // check if operation has been performed previously. If it has return result from cache.
        auto itr = cache.find(n);

        if (itr != cache.end())
            return itr->second;

        int result = 0;

        // the base cases are there are 2 ways of climbing two stairs and 1 way of climbing one stair
        if (n < 3)
            return n;
        else // recursively reduce n until it gets to the base case and add up result of sub-problems.
            result = findStairsCombo(n - 1, cache) + findStairsCombo(n - 2, cache);

        cache.insert({n, result}); // cache result
        return result;
    }
};
