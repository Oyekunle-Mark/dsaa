//
// Created by Oyekunle Oloyede on 08/10/2020.
//
#include <vector>

class ReplaceElementsWithGreatestElementOnRightSide {
public:
    static std::vector<int> replaceElements(std::vector<int> &arr) {
        const auto arrLength{arr.size()};
        int maxToRight{-1};

        for (int i{static_cast<int>(arrLength - 1)}; i >= 0; --i) {
            auto prev = arr.at(i);
            arr.at(i) = maxToRight;
            maxToRight = prev > maxToRight ? prev : maxToRight;
        }

        return std::move(arr);
    }
};
