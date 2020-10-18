//
// Created by Oyekunle Oloyede on 05/10/2020.
//
#include <vector>

class DuplicateZeros {
public:
    static void duplicateZeros(std::vector<int> &arr) {
        std::vector<int> duplicate{};

        for (auto item: arr) {
            if (item == 0) {
                duplicate.push_back(0);
                duplicate.push_back(0);
            } else
                duplicate.push_back(item);
        }

        for (int i{}; i < arr.size(); ++i) {
            arr[i] = duplicate[i];
        }
    }
};
