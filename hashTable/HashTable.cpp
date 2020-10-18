//
// Created by Oyekunle Oloyede on 18/10/2020.
//

#include "HashTable.h"
#include "hash.h"

template<typename HashedObj>
HashTable<HashedObj>::HashTable(int size)
        : currentSize{static_cast<std::size_t>(size)} {}

template<typename HashedObj>
std::size_t HashTable<HashedObj>::myHash(const HashedObj &item) const {
    static hash<HashedObj> hashFunction{};
    return hashFunction(item) % theLists.size();
}
