//
// Created by Oyekunle Oloyede on 04/12/2020.
//
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<int, std::vector<std::string>> groups{};
    }

    int findGroup(const std::string &str) {
        int sum = 0;

        for (auto c : str)
            sum += c;

        return sum;
    }
};
