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
        std::vector<int> triangleRow{}; // to hold the Pascal triangle row
        std::map<std::string, int> cache{}; // the cache for storing result of previous operations

        int columnIndex = 0; // start at first column

        while (columnIndex <= rowIndex) // loop while column is less than or equals row
            // add the result of recursive computation of current row and column index and post increment column index
            triangleRow.push_back(getPascalNumber(rowIndex, columnIndex++, cache));

        return triangleRow;
    }

    /**
     * Recursively compute the value of row-th column-th Pascal triangle number.
     * Cache result and use previous result to optimize performance
     */
    int getPascalNumber(int row, int column, std::map<std::string, int> &cache) {
        if (column == 0 || row == column) // base case
            return 1;

        // the cache key
        auto key = std::to_string(row) + '-' + std::to_string(column);

        auto itr = cache.find(key);

        if (itr != cache.end()) // if key is found in cache, return early with the value
            return itr->second;

        // otherwise recursively call find value and add to cache
        auto answer = getPascalNumber(row - 1, column - 1, cache) + getPascalNumber(row - 1, column, cache);
        cache.insert({key, answer});

        return answer;
    }
};
