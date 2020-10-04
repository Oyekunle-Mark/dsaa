//
// Created by Oyekunle Oloyede on 04/10/2020.
//

#ifndef DSAA_BINARYSEARCHTREE_H
#define DSAA_BINARYSEARCHTREE_H

#include <algorithm>

template<typename Comparable>
class BinarySearchTree {
public:
    BinarySearchTree();

    BinarySearchTree(const BinarySearchTree &rhs);

    BinarySearchTree(BinarySearchTree &&rhs);

    ~BinarySearchTree();

    const Comparable &findMin() const;

    const Comparable &findMax() const;

    bool contains(const Comparable &item) const;

    bool isEmpty() const;

    void makeEmpty();

    void insert(const Comparable &item);

    void insert(Comparable &&item);

    void remove(const Comparable &x);

    BinarySearchTree &operator=(const BinarySearchTree &rhs);

    BinarySearchTree &operator=(BinarySearchTree &&rhs);

private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &element, BinaryNode *l, BinaryNode *r)
                : element{element}, left{l}, right{r} {}

        BinaryNode(Comparable &&element, BinaryNode *l, BinaryNode *r)
                : element{std::move(element)}, left{l}, right{r} {}
    };

    BinaryNode *root;

    void insert(const Comparable &item, BinaryNode *&t);

    void insert(Comparable &&item, BinaryNode *&t);

    void remove(const Comparable &x, BinaryNode *&t);

    BinaryNode *findMin(BinaryNode *t) const;

    BinaryNode *findMax(BinaryNode *t) const;

    bool contains(const Comparable &item, BinaryNode *t) const;

    void makeEmpty(BinaryNode *&t);

    BinaryNode *clone(BinaryNode *t) const;
};


#endif //DSAA_BINARYSEARCHTREE_H
