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
            : buckets{std::make_unique<std::array<std::list<std::pair<int, int>>, bucketSize>>()} {}

    /** Hash function to return bucket index for a key */
    std::size_t hash(std::size_t key) {
        auto h = std::hash<std::size_t>{}(key);
        return h % bucketSize;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        const auto index = hash(key);

        auto itr = std::find_if(buckets->at(index).begin(), buckets->at(index).end(),
                                [key](std::pair<int, int> item) { return item.first == key; });

        if (itr == buckets->at(index).end())
            buckets->at(index).insert(buckets->at(index).begin(), std::pair<int, int>{key, value});
        else
            itr->second = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        const auto index = hash(key);

        auto itr = std::find_if(buckets->at(index).begin(), buckets->at(index).end(),
                                [key](std::pair<int, int> item) { return item.first == key; });

        if (itr != buckets->at(index).end())
            return itr->second;

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        const auto index = hash(key);

        auto itr = std::find_if(buckets->at(index).begin(), buckets->at(index).end(),
                                [key](std::pair<int, int> item) { return item.first == key; });

        if (itr != buckets->at(index).end())
            buckets->at(index).erase(itr);
    }

private:
    static constexpr std::size_t bucketSize = 10000;    // choose max number of operations as ideal bucket size
    std::unique_ptr<std::array<std::list<std::pair<int, int>>, bucketSize>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
