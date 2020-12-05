//
// Created by Oyekunle Oloyede on 05/12/2020.
//
#include <vector>
#include <list>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        bool carry = false;
        std::list<int> incrementedDigits{};

        for (int index = digits.size() - 1; index >= 0; --index) {
            if (index == digits.size() - 1) {
                if (digits.at(index) == 9) {
                    incrementedDigits.insert(incrementedDigits.begin(), 0);
                    carry = true;
                } else {
                    incrementedDigits.insert(incrementedDigits.begin(), digits.at(index) + 1);
                }
            } else {
                if (carry) {
                    if (digits.at(index) == 9) {
                        incrementedDigits.insert(incrementedDigits.begin(), 0);
                        carry = true;
                    } else {
                        incrementedDigits.insert(incrementedDigits.begin(), digits.at(index) + 1);
                        carry = false;
                    }
                } else {
                    incrementedDigits.insert(incrementedDigits.begin(), digits.at(index) + 1);
                }

            }
        }

        if (carry)
            incrementedDigits.insert(incrementedDigits.begin(), 1);
    }
};
