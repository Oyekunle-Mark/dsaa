//
// Created by Oyekunle Oloyede on 05/11/2020.
//
#include <string>

class Solution {
public:
    int kthGrammar(int N, int K) {
        return buildGrammarAndFindKthSymbol(N - 1, K, std::to_string(0));
    }

    int buildGrammarAndFindKthSymbol(int n, int k, const std::string &grammar) {
        if (n == 0)
            return grammar.at(k - 1) - 48;

        std::string newGrammar{};

        for (char c : grammar) {
            if (c == '0')
                newGrammar += "01";
            else
                newGrammar += "10";
        }

        return buildGrammarAndFindKthSymbol(n - 1, k, newGrammar);
    }
};
