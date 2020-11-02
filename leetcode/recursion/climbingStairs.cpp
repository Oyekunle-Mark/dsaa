//
// Created by Oyekunle Oloyede on 02/11/2020.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        else
            return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
