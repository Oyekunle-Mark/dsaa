//
// Created by Oyekunle Oloyede on 01/12/2020.
//
#include <array>
#include <list>
#include <memory>
#include <algorithm>

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet()
            : buckets{std::make_unique<std::array<std::list<int>, size>>()} {

    }

    std::size_t hash(std::size_t key) {
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = ((key >> 16) ^ key) * 0x45d9f3b;
        key = (key >> 16) ^ key;

        return key % size;
    }

    void add(int key) {
        const auto index = hash(key);

        auto itr = std::find(buckets->at(index).begin(), buckets->at(index).end(), key);

        if (itr != buckets->at(index).end())
            buckets->at(index).insert(buckets->at(index).begin(), key);
    }

    void remove(int key) {

    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {

    }

private:
    static constexpr std::size_t size = 10000;
    std::unique_ptr<std::array<std::list<int>, size>> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
