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

        for (int index = 0; index < haystack.size(); ++index) {
            if (haystack.at(index) == needle.at(0)) {
                auto isFound = isMatch(haystack, needle, index);

                if (isFound)
                    return index;
            }
        }

        return -1;
    }

    bool isMatch(const std::string &haystack, const std::string &needle, int haystackIndex) {
        int needleIndex = 0;

        for (; needleIndex < needle.size() && haystackIndex < haystack.size(); ++needleIndex, ++haystackIndex) {
            if (haystack.at(haystackIndex) != needle.at(needleIndex))
                return false;
        }

        return needleIndex == needle.size();
    }
};
