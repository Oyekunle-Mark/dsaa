//
// Created by Oyekunle Oloyede on 02/11/2020.
//

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        bool isPositivePower = n > 0;

        auto newN = isPositivePower ? n - 1 : n + 1;
        return isPositivePower ? x * myPow(x, newN) : 1 / x * myPow(x, newN);
    }
};
