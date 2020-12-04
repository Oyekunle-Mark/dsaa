//
// Created by Oyekunle Oloyede on 04/12/2020.
//
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> previousCharacters{};
        int max = 0;
        int current = 0;

        for (auto c : s) {
            if (previousCharacters.count(c)) {
                previousCharacters.clear();
                current = 0;
            }

            previousCharacters.insert(c);
            if (++current > max)
                max = current;
        }

        return max;
    }
};
