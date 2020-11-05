//
// Created by Oyekunle Oloyede on 05/11/2020.
//
#include <string>

class Solution {
public:
    int kthGrammar(int N, int K) {
        return buildGrammarAndFindKthSymbol(N - 1, K, std::to_string(1));
    }

    int buildGrammarAndFindKthSymbol(int n, int k, std::string grammar) {

    }
};
