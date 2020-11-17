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
            if (currentNode->children.find(c) == currentNode->children.end())
                currentNode->children.insert({c, new TrieNode(false)});

            currentNode = currentNode->children.at(c);
        }

        currentNode->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto currentNode = root;

        for (auto c : word) {
            if (currentNode->children.find(c) == currentNode->children.end())
                return false;

            currentNode = currentNode->children.at(c);
        }

        return currentNode->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
