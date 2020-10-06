//
// Created by Oyekunle Oloyede on 06/10/2020.
//
#include <vector>
#include <set>

class CheckIfNAndItsDoubleExist {
public:
    static bool checkIfExist(std::vector<int> &arr) {
        std::set<int> items{};

        for (auto item: arr) {
            // perform check if item exists already
            auto contains = items.find(item);

            if (contains != items.end()) {
                // if it does check if it is zero
                if (*contains == 0)
                    return true; // true because zero * 2 is zero
            }

            items.insert(item);
        }

        for (auto item: arr) {
            auto contains = items.find(item * 2);

            // check if item is found excluding zeros
            // the checks done in the first loop handles zeros
            if (contains != items.end() && *contains != 0) {
                return true;
            }
        }

        return false;
    }
};
