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

template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
    for (auto &thisList: theLists)
        thisList.clear();
}

template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &item) const {
    auto &whichList = theLists[myHash(item)];
    return std::find(std::begin(whichList), std::end(whichList), item) != std::end(whichList);
}
