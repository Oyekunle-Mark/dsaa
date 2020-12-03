//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2) {
        std::unordered_map<std::string, int> firstListIndexMap{};

        for (int index = 0; index < list1.size(); ++index)
            firstListIndexMap.insert({list1.at(index), index});

        std::unordered_map<std::string, int> commonInterestIndicesSumMap{};
        int minimumListIndexSum = 1000 * 2;

        for (int index = 0; index < list2.size(); ++index) {
            if (firstListIndexMap.count(list2.at(index))) {
                commonInterestIndicesSumMap.insert({list2.at(index), firstListIndexMap.at(list2.at(index)) + index});

                if (commonInterestIndicesSumMap.at(list2.at(index)) < minimumListIndexSum)
                    minimumListIndexSum = commonInterestIndicesSumMap.at(list2.at(index));
            }
        }

        std::vector<std::string> interests{};

        for (const std::pair<std::string, int> pair : commonInterestIndicesSumMap) {
            if (pair.second == minimumListIndexSum)
                interests.push_back(pair.first);
        }

        return interests;
    }
};
