//
// Created by Oyekunle Oloyede on 03/10/2020.
//

#include "Vector.h"

template<typename Object>
Vector<Object>::Vector(std::size_t size)
        : mSize{size}, mCapacity{size + SPARE_CAPACITY} {
    objects = new Object[mCapacity];
}

template<typename Object>
Vector<Object>::Vector(const Vector<Object> &rhs)
        : mSize{rhs.mSize}, mCapacity{rhs.mCapacity}, objects{nullptr} {
    objects = new Object[mCapacity];

    for (std::size_t i{}; i < mSize; ++i)
        objects[i] = rhs.objects[i];
}

template<typename Object>
Vector<Object> &Vector<Object>::operator=(const Vector<Object> &rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);

    return *this;
}

template<typename Object>
Vector<Object>::Vector(Vector<Object> &&rhs)
        : mSize{rhs.mSize}, mCapacity{mCapacity}, objects{rhs.objects} {
    rhs.objects = nullptr;
    rhs.mSize = 0;
    rhs.mCapacity = 0;
}

template<typename Object>
Vector<Object> &Vector<Object>::operator=(Vector<Object> &&rhs) {
    std::swap(mSize, rhs.mSize);
    std::swap(mCapacity, rhs.mCapacity);
    std::swap(objects, rhs.objects);

    return *this;
}

template<typename Object>
Vector<Object>::~Vector<Object>() {
    delete[] objects;
}

template<typename Object>
void Vector<Object>::resize(std::size_t newSize) {
    if (newSize > mCapacity)
        reserve(newSize * 2);
    mSize = newSize;
}

template<typename Object>
void Vector<Object>::reserve(std::size_t newCapacity) {
    if (newCapacity < mSize)
        return;

    auto *newObjects = new Object[newCapacity];

    for (std::size_t i{}; i < mSize; ++i)
        newObjects[i] = std::move(objects[i]);

    mCapacity = newCapacity;
    std::move(objects, newObjects);
    delete[] newObjects;
}
