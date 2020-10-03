//
// Created by Oyekunle Oloyede on 03/10/2020.
//

#include "List.h"

template<typename Object>
void List<Object>::init() {
    mSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template<typename Object>
List<Object>::List() {
    init();
}

template<typename Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

template<typename Object>
List<Object>::List(const List<Object> &rhs) {
    init();
    for (auto &item: rhs)
        push_back(item);
}

template<typename Object>
List<Object> &List<Object>::operator=(const List<Object> &rhs) {
    auto copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template<typename Object>
List<Object>::List(List<Object> &&rhs)
        : mSize{rhs.mSize}, head{rhs.head}, tail{rhs.tail} {
    rhs.mSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

template<typename Object>
List<Object> &List<Object>::operator=(List<Object> &&rhs) {
    std::swap(mSize, rhs.mSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return *this;
}

template<typename Object>
typename List<Object>::iterator List<Object>::begin() {
    return {head->next};
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::begin() const {
    return {head->next};
}

template<typename Object>
typename List<Object>::iterator List<Object>::end() {
    return {tail};
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::end() const {
    return {tail};
}

template<typename Object>
std::size_t List<Object>::size() const {
    return mSize;
}

template<typename Object>
bool List<Object>::empty() const {
    return size();
}

template<typename Object>
void List<Object>::clear() {
    while (!empty())
        pop_front();
}
