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
