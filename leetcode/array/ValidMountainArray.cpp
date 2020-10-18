//
// Created by Oyekunle Oloyede on 06/10/2020.
//
#include <vector>

class ValidMountainArray {
public:
    static bool validMountainArray(std::vector<int> &A) {
        // state of the ride, rising or falling
        enum class ProgressState {
            Rising,
            Falling,
        };

        const std::vector<int>::size_type arrLength{A.size()};

        // does A meet the condition to be considered a mountain array
        if (arrLength < 3 || A[0] >= A[1])
            return false;

        // start with a rising state
        ProgressState state{ProgressState::Rising};

        for (int i{2}; i < arrLength; ++i) {
            // no constant rate. Only strict increase and decrease allowed
            if (A[i - 1] == A[i])
                return false;

            if (state == ProgressState::Rising) {
                // when rising, any decrease should mark the downward slope
                if (A[i - 1] > A[i]) {
                    state = ProgressState::Falling;
                }
            } else {
                // is falling condition met
                if (A[i] > A[i - 1]) {
                    return false;
                }
            }
        }

        // must end in a falling state
        return state == ProgressState::Falling;
    }
};
