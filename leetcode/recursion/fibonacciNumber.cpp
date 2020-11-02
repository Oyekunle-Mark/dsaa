//
// Created by Oyekunle Oloyede on 02/11/2020.
//
#include <unordered_map>

class Solution {
public:
    int fib(int N) {
        std::unordered_map<int, int> cache{};

        return findFib(N, cache);
    }

    int findFib(int n, std::unordered_map<int, int> &cache) {
        auto itr = cache.find(n);

        if (itr != cache.end())
            return itr->second;

        int result{};

        if (n < 2)
            return n;
        else
            result = findFib(n - 1, cache) + findFib(n - 2, cache);

        cache.insert({n, result});
        return result;
    }
};
