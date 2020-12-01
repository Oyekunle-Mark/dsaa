//
// Created by Oyekunle Oloyede on 01/12/2020.
//
#include <array>
#include <list>
#include <algorithm>
#include <memory>

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap()
            : buckets{std::make_unique<std::array<std::list<int>, bucketSize>>()} {}

    /** value will always be non-negative. */
    void put(int key, int value) {

    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {

    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {

    }

private:
    static constexpr std::size_t bucketSize = 10000;
    std::unique_ptr<std::array<std::list<int>, bucketSize>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
