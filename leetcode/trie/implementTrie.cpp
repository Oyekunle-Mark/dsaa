//
// Created by Oyekunle Oloyede on 17/11/2020.
//
#include <string>
#include <unordered_map>

class Trie {
private:
    struct TrieNode {
        std::unordered_map<char, TrieNode *> children{};
        bool isWord;

        explicit TrieNode(bool isWord)
                : isWord(isWord) {}
    };

    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(false);
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        auto currentNode = root;

        for (auto c : word) {
            if (currentNode->children.find(c) ==
                currentNode->children.end()) // if character is not in current node's children
                currentNode->children.insert({c, new TrieNode(false)});

            currentNode = currentNode->children.at(c); // switch to the children of current character
        }

        currentNode->isWord = true; // change the flag of last character in word to show it is a valid word
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto currentNode = root;

        for (auto c : word) {
            if (currentNode->children.find(c) ==
                currentNode->children.end()) // if current character cant be found in current node's children
                return false; // trie does not contain word

            currentNode = currentNode->children.at(c);
        }

        return currentNode->isWord; // if the last last trie node representing word is flagged as a word
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        auto currentNode = root;

        for (auto c : prefix) {
            if (currentNode->children.find(c) == currentNode->children.end())
                return false;

            currentNode = currentNode->children.at(c);
        }

        return true; // a trie node path is found to match prefix
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
