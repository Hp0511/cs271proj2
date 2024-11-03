#include <iostream>
using namespace std;

#ifndef RBTREE_OPERATIONS_HPP
#define RBTREE_OPERATIONS_HPP

template<typename T>
class RBTreeNode {
public:
    T data; 
    RBTreeNode<T>* left;
    RBTreeNode<T>* right;
    bool color; // true for Red, false for Black

    RBTreeNode<T>* treeMin();
    RBTreeNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;
};

#endif