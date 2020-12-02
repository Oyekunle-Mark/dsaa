//
// Created by Oyekunle Oloyede on 02/12/2020.
//
#include <set>

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> sums{};

        while (true) {
            n = findDigitSquareSum(n);

            if (n == 1)
                return true;
            else if (sums.find(n) == sums.end())
                sums.insert(n);
            else
                break;
        }

        return false;
    }

    int findDigitSquareSum(int num) {
        int sum = 0;

        while (num > 0) {
            int last = num % 10;
            sum += (last * last);
            num /= 10;
        }

        return sum;
    }
};
