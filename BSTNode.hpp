//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/5/2024
// About: This file is the header file of the BSTNode class, a template for nodes
// in a Binary Search Tree (BST). It includes methods for
// finding the minimum and maximum nodes in a subtree, 
// performing tree traversals (pre-order, in-order, and post-order),
// and managing node memory with default, copy constructors, destructors, 
// and an assignment operator.
//==============================================================
#include <iostream>
using namespace std;

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

template<typename T>
class BSTNode {
public:
    BSTNode<T> (void);
    BSTNode<T> (const BSTNode<T> &bstNode);
    ~BSTNode<T> (void);
    BSTNode<T>& operator=(const BSTNode<T> &bstNode);
    BSTNode<T>* treeMin();
    BSTNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

    T value;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
};

#endif