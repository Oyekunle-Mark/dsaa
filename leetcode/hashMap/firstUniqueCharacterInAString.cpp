//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> charCount{};

        for (auto c : s) {
            if (charCount.count(c))
                charCount.at(c) += 1;
            else
                charCount.insert({c, 1});
        }

        for (int index = 0; index < s.size(); ++index) {
            if (charCount.at(s.at(index)) == 1)
                return index;
        }

        return -1;
    }
};
