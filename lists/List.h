//
// Created by Oyekunle Oloyede on 03/10/2020.
//

#ifndef DSAA_LIST_H
#define DSAA_LIST_H

#include <cstddef>

template<typename Object>
class List {
private:
    struct Node {
        Object data;
        Node *prev;
        Node *next;

        explicit Node(const Object &newObject = Object{}, Node p = nullptr, Node n = nullptr)
                : data{newObject}, prev{p}, next{n} {}

        explicit Node(Object &&newObject, Node p = nullptr, Node n = nullptr)
                : data{newObject}, prev{p}, next{n} {}
    };

    std::size_t mSize;
    Node *head;
    Node *tail;
public:
    class const_iterator {
    };

    class iterator : public const_iterator {
    };

    List();

    List(const List &rhs);

    List &operator=(const List &rhs);

    List(List &&rhs);

    List &operator=(List &&rhs);

    ~List();

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    std::size_t size() const;

    bool empty() const;

    void clear();

    Object &front();

    const Object &front() const;

    Object &back();

    const Object &back() const;

    void push_front(const Object &item);

    void push_front(Object &&item);

    void push_back(const Object &item);

    void push_back(Object &&item);

    void pop_front();

    void pop_back();

    iterator insert(iterator iter, const Object &item);

    iterator insert(iterator iter, Object &&item);

    iterator erase(iterator iter);

    iterator erase(iterator from, iterator to);
};


#endif //DSAA_LIST_H
