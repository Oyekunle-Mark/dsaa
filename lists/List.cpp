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

template<typename Object>
Object &List<Object>::front() {
    return *begin();
}

template<typename Object>
const Object &List<Object>::front() const {
    return *begin();
}

template<typename Object>
Object &List<Object>::back() {
    return *--end();
}

template<typename Object>
const Object &List<Object>::back() const {
    return *--end();
}

template<typename Object>
void List<Object>::push_front(const Object &item) {
    insert(begin(), item);
}

template<typename Object>
void List<Object>::push_front(Object &&item) {
    insert(begin(), std::move(item));
}

template<typename Object>
void List<Object>::push_back(const Object &item) {
    insert(end(), item);
}

template<typename Object>
void List<Object>::push_back(Object &&item) {
    insert(end(), item);
}

template<typename Object>
void List<Object>::pop_front() {
    erase(begin());
}

template<typename Object>
void List<Object>::pop_back() {
    erase(--end());
}

template<typename Object>
typename List<Object>::iterator List<Object>::insert(iterator iter, const Object &item) {
    Node *p = iter.current;
    mSize++;
    return {p->prev = p->prev->next = new Node{item, p->prev, p}};
}

template<typename Object>
typename List<Object>::iterator List<Object>::insert(iterator iter, Object &&item) {
    Node *p = iter.current;
    mSize++;
    return {p->prev = p->prev->next = new Node{std::move(item), p->prev, p}};
}

template<typename Object>
typename List<Object>::iterator List<Object>::erase(iterator iter) {
    Node *p = iter.current;
    iterator ret{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;

    return ret;
}

template<typename Object>
typename List<Object>::iterator List<Object>::erase(iterator from, iterator to) {
    for (iterator iter = from; iter != to;)
        iter = erase(iter);
}
