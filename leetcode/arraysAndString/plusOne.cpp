//
// Created by Oyekunle Oloyede on 05/12/2020.
//
#include <vector>
#include <list>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        bool carry = false; // represents if a carry should done
        std::list<int> incrementedDigits{}; // holds the digits during increment operation

        for (int index = digits.size() - 1; index >= 0; --index) { // reverse iteration
            if (index == digits.size() - 1) { // at last index, where addition by one take place
                if (digits.at(index) == 9) { // if digit is a 9, increment to 10, insert 0 and carry 1
                    incrementedDigits.insert(incrementedDigits.begin(), 0);
                    carry = true;
                } else { // otherwise, simply increment digit by 1 and insert into list
                    incrementedDigits.insert(incrementedDigits.begin(), digits.at(index) + 1);
                }
            } else { // at every digit but the last digit
                if (carry) { // if there was a carry
                    if (digits.at(index) == 9) { // if digit is a 9, increment to 10, insert 0 and carry 1
                        incrementedDigits.insert(incrementedDigits.begin(), 0);
                        carry = true;
                    } else { // otherwise, simply increment digit by 1 and insert into list and flip carry to false.
                        incrementedDigits.insert(incrementedDigits.begin(), digits.at(index) + 1);
                        carry = false;
                    }
                } else { // no carry, just insert
                    incrementedDigits.insert(incrementedDigits.begin(), digits.at(index));
                }

            }
        }

        if (carry) // if after operation there is a carry, then insert 1 into the list
            incrementedDigits.insert(incrementedDigits.begin(), 1);

        // create vector from list
        return std::vector<int>(incrementedDigits.begin(), incrementedDigits.end());;
    }
};
