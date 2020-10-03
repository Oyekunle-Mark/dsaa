//
// Created by Oyekunle Oloyede on 03/10/2020.
//

#include "Vector.h"

template<typename Object>
Vector<Object>::Vector(std::size_t size)
        : mSize{size}, mCapacity{size + SPARE_CAPACITY} {
    objects = new Object[mCapacity];
}