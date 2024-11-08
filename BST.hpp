//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/3/2024
// Description: this file contains declarations for the BST class methods.
//==============================================================
#include <iostream>
#include "BSTNode.hpp"
using namespace std;

#ifndef BST_HPP
#define BST_HPP

template<typename T>
class BST {
public:
    BST<T>    ( void );
    BST<T>    ( const BST<T> &bst );
    ~BST<T>   ( void );
    void deleteSubTree(BSTNode<T>* node);
    BST<T>& operator=(const BST<T>& bst);

    void        transplant(BSTNode<T>* oldNode, BSTNode<T>* newNode);
    bool        isEmpty() const;
    long        size() const;
    BSTNode<T>* insert(T value);
    void        remove(T value);
    BSTNode<T>* search(T value) const;
    BSTNode<T>* treeMin() const;
    BSTNode<T>* treeMax() const;
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;

private:
    BSTNode<T> *root;
    long nodeCount;
};
#endif