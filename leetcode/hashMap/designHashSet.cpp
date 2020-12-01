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
            : buckets{std::make_unique<std::array<std::list<int>, size>>()} {}

    /** Hash function to return bucket index for a key */
    std::size_t hash(std::size_t key) {
        auto h = std::hash<std::size_t>{}(key);
        return h % size;
    }

    /** Adds a key into the set if it does not exist already */
    void add(int key) {
        const auto index = hash(key);

        auto itr = std::find(buckets->at(index).begin(), buckets->at(index).end(), key);

        if (itr == buckets->at(index).end())
            buckets->at(index).insert(buckets->at(index).begin(), key);
    }

    /** Removes a key from the set if it's present. Does nothing otherwise */
    void remove(int key) {
        const auto index = hash(key);

        auto itr = std::find(buckets->at(index).begin(), buckets->at(index).end(), key);

        if (itr != buckets->at(index).end())
            buckets->at(index).erase(itr);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        const auto index = hash(key);

        auto itr = std::find(buckets->at(index).begin(), buckets->at(index).end(), key);

        if (itr != buckets->at(index).end())
            return true;

        return false;
    }

private:
    static constexpr std::size_t size = 10000;  // choose max number of operations as ideal bucket size
    std::unique_ptr<std::array<std::list<int>, size>> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
