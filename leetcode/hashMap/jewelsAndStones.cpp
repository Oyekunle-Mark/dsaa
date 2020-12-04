//
// Created by Oyekunle Oloyede on 04/12/2020.
//
#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::unordered_set<char> jewels{};

        for (auto c : J)
            jewels.insert(c);

        int count = 0;

        for (auto c : S) {
            if (jewels.count(c))
                ++count;
        }

        return count;
    }
};
