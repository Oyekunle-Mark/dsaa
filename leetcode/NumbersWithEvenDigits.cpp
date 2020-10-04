//
// Created by Oyekunle Oloyede on 04/10/2020.
//
#include <vector>

class NumbersWithEvenDigits {
public:
    static int findNumbers(std::vector<int> &nums) {
        int numOfEvenDigits = 0;

        for (auto item: nums) {
            if (findDigitLength(item) % 2 == 0)
                ++numOfEvenDigits;
        }

        return numOfEvenDigits;
    }

    static int findDigitLength(int num) {
        int length{};

        while (num > 0) {
            num /= 10;
            ++length;
        }

        return length;
    }
};
