#include <iostream>
#include "leetcode/MaxConsecutiveOnes.cpp"

int main() {
    std::vector<int> data{5, 1, 1, 0, 1, 1, 1};
    std::cout << MaxConsecutiveOnes::findMaxConsecutiveOnes(data) << std::endl;

    return 0;
}
