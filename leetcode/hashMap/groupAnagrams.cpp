//
// Created by Oyekunle Oloyede on 04/12/2020.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups{};

        for (const auto &str : strs) {
            auto groupNumber = findGroup(str);

            if (groups.count(groupNumber))
                groups.at(groupNumber).push_back(str);
            else
                groups.insert({groupNumber, {str}});
        }

        std::vector<std::vector<std::string>> groupedAnagrams{};

        for (auto pair : groups)
            groupedAnagrams.push_back(pair.second);

        return groupedAnagrams;
    }

    std::string findGroup(std::string str) {
//        int sum = 0;
//
//        for (auto c : str)
//            sum += c;
//
//        return sum;
        std::sort(str.begin(), str.end());
        return str;
    }
};
