//
// Created by Oyekunle Oloyede on 09/10/2020.
//
#include <vector>
#include <algorithm>

class HeightChecker {
public:
    static int heightChecker(std::vector<int> &heights) {
        auto copy{heights};
        std::sort(copy.begin(), copy.end());
        int count{};

        for (int i{}; i < copy.size(); ++i) {
            if (copy[i] != heights[i])
                ++count;
        }

        return count;
    }
};
