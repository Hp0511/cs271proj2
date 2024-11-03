//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/3/2024
//==============================================================
#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef BST_HPP
#define BST_HPP

template<typename T>
class BSTNode {
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

public:
    void transplant(BSTNode<T>* oldNode, BSTNode<T>* newNode);
    bool isEmpty() const;
    long size() const;
    BSTNode<T>* insert(T value);
    void remove(T value);
    BSTNode<T>* search(T value) const;
    BSTNode<T>* treeMin() const;
    BSTNode<T>* treeMax() const;
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;
};
#endif