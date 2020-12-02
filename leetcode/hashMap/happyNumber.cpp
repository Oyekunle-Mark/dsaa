//
// Created by Oyekunle Oloyede on 02/12/2020.
//

class Solution {
public:
    bool isHappy(int n) {

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
