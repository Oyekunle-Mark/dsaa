//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2) {
        std::unordered_map<std::string, int> firstListIndexMap{}; // stores a map of restaurants in list1 to index

        for (int index = 0; index < list1.size(); ++index) // loop and set the index of each restaurant in list1
            firstListIndexMap.insert({list1.at(index), index});

        std::unordered_map<std::string, int> commonInterestIndicesSumMap{}; // will hold the sum of indices of restaurant present in list1 and list2
        int minimumListIndexSum = 1000 *
                                  2; // maximum list size is 1000. So highest possible index is an item at the tail end of both max list

        for (int index = 0; index < list2.size(); ++index) { // loop through list 2
            if (firstListIndexMap.count(list2.at(index))) { // if current restaurant is found in list 1
                commonInterestIndicesSumMap.insert({list2.at(index), firstListIndexMap.at(list2.at(index)) +
                                                                     index}); // retrieves its index from list 1 and add its index in list two. Save restaurant as a map to the sum of these indices.

                if (commonInterestIndicesSumMap.at(list2.at(index)) <
                    minimumListIndexSum) // if sum of indices of current common restaurant is less than the minimum
                    minimumListIndexSum = commonInterestIndicesSumMap.at(list2.at(index)); // set as new minimum
            }
        }

        std::vector<std::string> interests{};

        for (const std::pair<std::string, int> pair : commonInterestIndicesSumMap) { // for each pair
            if (pair.second == minimumListIndexSum) // if it's a minimum, append restaurant to interest
                interests.push_back(pair.first);
        }

        return interests;
    }
};
