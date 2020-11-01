//
// Created by Oyekunle Oloyede on 01/11/2020.
//
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char> &s) {
        if (s.size())
            reverseRecursive(s, 0, s.size() - 1);
    }

    void reverseRecursive(std::vector<char> &str, size_t front, size_t end) {
        if (front < end) {
            char temp = str.at(front);
            str.at(front) = str.at(end);
            str.at(end) = temp;
            reverseRecursive(str, front + 1, end - 1);
        }
    }
};
