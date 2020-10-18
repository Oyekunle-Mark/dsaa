//
// Created by Oyekunle Oloyede on 18/10/2020.
//

#ifndef DSAA_HASH_H
#define DSAA_HASH_H

#include <string>

template<typename Key>
class hash {
public:
    std::size_t operator()(const Key &key) const;
};

template<>
class hash<std::string> {
public:
    std::size_t operator()(const std::string &key) const {
        std::size_t hashVal{};

        for (char ch: key)
            hashVal += 37 * hashVal + ch;

        return hashVal;
    }
};

#endif //DSAA_HASH_H
