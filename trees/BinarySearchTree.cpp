//
// Created by Oyekunle Oloyede on 04/10/2020.
//

#include "BinarySearchTree.h"

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &item) const {
    return contains(item, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &item) {
    return insert(item, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &item) {
    return remote(item, root);
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &item, BinaryNode *t) const {
    if (t == nullptr)
        return false;
    else if (item < t->element)
        return contains(item, t->left);
    else if (t->element < item)
        return contains(item, t->right);
    else
        return true;
}

template<typename Comparable>
using BinaryNodeType = typename BinarySearchTree<Comparable>::BinaryNode;

template<typename Comparable>
BinaryNodeType<Comparable> *BinarySearchTree<Comparable>::findMin(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template<typename Comparable>
BinaryNodeType<Comparable> *BinarySearchTree<Comparable>::findMax(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->right == nullptr)
        return t;
    return findMin(t->right);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &item, BinaryNode *&t) {
    if (t == nullptr)
        t = new BinaryNode(item, nullptr, nullptr);
    else if (item < t->element)
        insert(item, t->left);
    else if (t->element < item)
        insert(item, t->right);
    else; // Not handling duplicates
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable &&item, BinaryNode *&t) {
    if (t == nullptr)
        t = new BinaryNode(std::move(item), nullptr, nullptr);
    else if (item < t->element)
        insert(std::move(item), t->left);
    else if (t->element < item)
        insert(std::move(item), t->right);
    else; // Not handling duplicates
}
