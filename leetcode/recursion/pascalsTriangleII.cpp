//
// Created by Oyekunle Oloyede on 01/11/2020.
//
#include <vector>
#include <map>
#include <string>

/**
Recurrence Relation

Let's start with the recurrence relation within the Pascal's Triangle.

First of all, we define a function f(i,j)f(i, j)f(i,j) which returns the number in the Pascal's Triangle in the i-th row and j-th column.

We then can represent the recurrence relation with the following formula:

f(i,j)=f(i−1,j−1)+f(i−1,j)



Base Case

As one can see, the leftmost and rightmost numbers of each row are the base cases in this problem, which are always equal to 1.

As a result, we can define the base case as follows:

f(i,j)=1 where j=1 or j=i
*/

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> triangleRow{};
        std::map<std::string, int> cache{};

        int columnIndex = 0;

        while (columnIndex <= rowIndex)
            triangleRow.push_back(getPascalNumber(rowIndex, columnIndex++, cache));

        return triangleRow;
    }

    int getPascalNumber(int row, int column, std::map<std::string, int> &cache) {
        if (column == 0 || row == column)
            return 1;

        auto key = std::to_string(row) + '-' + std::to_string(column);

        auto itr = cache.find(key);

        if (itr != cache.end())
            return itr->second;

        auto answer = getPascalNumber(row - 1, column - 1, cache) + getPascalNumber(row - 1, column, cache);
        cache.insert({key, answer});

        return answer;
    }
};
