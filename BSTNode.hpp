//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/3/2024
//==============================================================
#include <iostream>
using namespace std;

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

template<typename T>
class BSTNode {
public:

    BSTNode<T>* treeMin();
    BSTNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
};

#endif