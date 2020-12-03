//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> sMap{};
        std::unordered_map<char, char> tMap{};

        for (std::size_t index = 0; index < s.size(); ++index) {
            if (sMap.count(s.at(index))) {
                if (sMap.at(s.at(index)) != t.at(index))
                    return false;
            } else {
                if (tMap.count(t.at(index)))
                    if (tMap.at(t.at(index)) != s.at(index))
                        return false;

                sMap.insert({s.at(index), t.at(index)});
                tMap.insert({t.at(index), s.at(index)});
            }
        }

        return true;
    }
};
