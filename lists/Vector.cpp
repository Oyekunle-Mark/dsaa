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

template<typename Object>
Object &Vector<Object>::operator[](std::size_t index) {
    return objects[index];
}

template<typename Object>
const Object &Vector<Object>::operator[](std::size_t index) const {
    return objects[index];
}

template<typename Object>
std::size_t Vector<Object>::size() const {
    return mSize;
}

template<typename Object>
bool Vector<Object>::empty() const {
    return size();
}

template<typename Object>
std::size_t Vector<Object>::capacity() const {
    return mCapacity;
}

template<typename Object>
void Vector<Object>::push_back(const Object &item) {
    if (mSize == mCapacity)
        reserve(2 * mCapacity + 1);
    objects[mSize++] = item;
}

template<typename Object>
void Vector<Object>::push_back(const Object &&item) {
    if (mSize == mCapacity)
        reserve(2 * mCapacity + 1);
    objects[mSize++] = std::move(item);
}

template<typename Object>
void Vector<Object>::pop_back() {
    mSize--;
}

template<typename Object>
const Object &Vector<Object>::back() const {
    return objects[mSize - 1];
}

template<typename Object>
typename Vector<Object>::iterator Vector<Object>::begin() {
    return &objects[0];
}

template<typename Object>
typename Vector<Object>::const_iterator Vector<Object>::begin() const {
    return &objects[0];
}

template<typename Object>
typename Vector<Object>::iterator Vector<Object>::end() {
    return &objects[size()];
}

template<typename Object>
typename Vector<Object>::const_iterator Vector<Object>::end() const {
    return &objects[size()];
}
