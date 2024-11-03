#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef RBTREE_OPERATIONS_HPP
#define RBTREE_OPERATIONS_HPP

template<typename T>
class RBTreeNode {
public:

    void transplant(RBTreeNode<T>* u, RBTreeNode<T>* v);
    bool isEmpty() const;
    long size() const;
    RBTreeNode<T>* insert(T value);
    void remove(T value);
    RBTreeNode<T>* search(T value) const;
    RBTreeNode<T>* treeMin() const;
    RBTreeNode<T>* treeMax() const;
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;
};
#endif