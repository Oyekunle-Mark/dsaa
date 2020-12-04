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

        for (int slowPointer = 0; slowPointer < s.size(); ++slowPointer) {
            int current = 0;

            for (int fastPointer = slowPointer; fastPointer < s.size(); ++fastPointer) {
                if (previousCharacters.count(s.at(fastPointer))) {
                    previousCharacters.clear();
                    break;
                }

                previousCharacters.insert(s.at(fastPointer));
                if (++current > max)
                    max = current;

                if (fastPointer == s.size() - 1) // if at end, then end operation
                    return max;
            }
        }

        return max;
    }
};
