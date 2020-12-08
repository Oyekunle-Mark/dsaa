//
// Created by Oyekunle Oloyede on 08/12/2020.
//
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty())
            return 0;

        if (needle.size() > haystack.size())
            return -1;
    }
};
