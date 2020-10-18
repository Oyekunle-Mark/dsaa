//
// Created by Oyekunle Oloyede on 18/10/2020.
//

#ifndef DSAA_HASHTABLE_H
#define DSAA_HASHTABLE_H

#include <vector>
#include <list>

template<typename HashedObj>
class HashTable {
public:
    explicit HashTable(int size = 10);

    bool contains(const HashedObj &item) const;

    void makeEmpty();

    bool insert(const HashedObj &item);

    bool insert(HashedObj &&item);

    bool remove(const HashedObj &item);

private:
    std::vector<std::list<HashedObj>> theLists;
    std::size_t currentSize;

    void rehash();

    size_t myHash(const HashedObj &item) const;
};


#endif //DSAA_HASHTABLE_H
