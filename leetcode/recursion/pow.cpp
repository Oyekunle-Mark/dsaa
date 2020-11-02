//
// Created by Oyekunle Oloyede on 02/11/2020.
//

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        bool isPositivePower = n > 0;

        x = isPositivePower ? x : 1 / x;
        auto result = 1.00000;

        while (n != 0) {
            result *= x;
            n = isPositivePower ? n - 1 : n + 1;
        }

        return result;
    }
};
