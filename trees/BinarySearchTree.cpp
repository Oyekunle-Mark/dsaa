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
