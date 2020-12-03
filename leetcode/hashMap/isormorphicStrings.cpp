//
// Created by Oyekunle Oloyede on 03/12/2020.
//
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> sMap{}; // tracks mapping of s characters
        std::unordered_map<char, char> tMap{}; // tracks mapping of t characters

        for (std::size_t index = 0;
             index < s.size(); ++index) { // since s and t lengths are the same, loop with s length
            if (sMap.count(s.at(index))) { // if current s character has been mapped already
                if (sMap.at(s.at(index)) != t.at(index)) // ensure it maps to the same current character in t
                    return false;
            } else {
                if (tMap.count(t.at(index))) // check if there is a previous mapping for t current character
                    if (tMap.at(t.at(index)) !=
                        s.at(index)) // ensure it maps to the current s character before performing new map
                        return false;

                sMap.insert({s.at(index), t.at(index)}); // create new s character mapping
                tMap.insert({t.at(index), s.at(index)}); // create new t character mapping
            }
        }

        return true;
    }
};
