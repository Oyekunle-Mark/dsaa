//
// Created by Oyekunle Oloyede on 04/10/2020.
//
#include <vector>
#include <algorithm>

class SquaresOfSortedArray {
public:
    static std::vector<int> sortedSquares(std::vector<int> &A) {
        std::vector<int> squares(0);

        for (auto item: A)
            squares.push_back(item * item);

        std::sort(squares.begin(), squares.end());

        return squares;
    }
};
