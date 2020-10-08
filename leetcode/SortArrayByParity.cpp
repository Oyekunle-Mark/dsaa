//
// Created by Oyekunle Oloyede on 08/10/2020.
//
#include <vector>

class SortArrayByParity {
public:
    static std::vector<int> sortArrayByParity(std::vector<int> &A) {
        std::vector<int> result(A.size());
        int evenIndex{};
        auto oddIndex{A.size() - 1};

        for (auto item: A) {
            if (item % 2 == 0) {
                result[evenIndex] = item;
                ++evenIndex;
            } else {
                result[oddIndex] = item;
                --oddIndex;
            }
        }

        return result;
    }
};
