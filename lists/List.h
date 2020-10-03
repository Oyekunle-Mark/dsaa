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

    void init();

public:
    class const_iterator {
    public:
        const_iterator()
                : current{nullptr} {}

        const Object &operator*() const {
            return retrieve();
        }

        const_iterator &operator++() {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const {
            return *this != current;
        }

    protected:
        Node *current;

        Object &retrieve() const {
            return current->data;
        }

        explicit const_iterator(Node *p) : current{p} {}

        friend class List<Object>;
    };

    class iterator : public const_iterator {
    public:
        iterator() = default;

        Object &operator*() {
            return const_iterator::retrieve();
        }

        const Object &operator*() const {
            return const_iterator::operator*();
        }

        iterator &operator++() {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        explicit iterator(Node *p)
                : const_iterator{p} {}

        friend class List<Object>;
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
