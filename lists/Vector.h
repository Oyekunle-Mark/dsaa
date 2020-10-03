//
// Created by Oyekunle Oloyede on 03/10/2020.
//

#ifndef DSAA_VECTOR_H
#define DSAA_VECTOR_H

#include <cstddef>

template<typename Object>
class Vector {
public:
    explicit Vector(std::size_t size = 0);

    Vector(const Vector &rhs);

    Vector &operator=(const Vector &rhs);

    Vector(Vector &&rhs);

    Vector &operator=(Vector &&rhs);

    ~Vector();

    void resize(std::size_t newSize);

    void reserve(std::size_t newCapacity);

    Object &operator[](std::size_t index);

    const Object &operator[](std::size_t index) const;

    bool empty() const;

    std::size_t size() const;

    std::size_t capacity() const;

    void push_back(const Object &item);

    void push_back(const Object &&item);

    void pop_back();

    const Object &back() const;

    using iterator = Object *;
    using const_iterator = const Object *;

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

private:
    std::size_t mSize;
    std::size_t mCapacity;
    Object *objects;
    static constexpr std::size_t SPARE_CAPACITY{16};
};


#endif //DSAA_VECTOR_H
