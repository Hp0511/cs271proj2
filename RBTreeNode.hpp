#include <iostream>
using namespace std;

#ifndef RBTREE_OPERATIONS_HPP
#define RBTREE_OPERATIONS_HPP

template<typename T>
class RBTreeNode {
public:
    T data;                         
    RBTreeNode* parent;       
    RBTreeNode* left;              
    RBTreeNode* right;              
    bool color;                     

    // Constructor to initialize a new node
    RBTreeNode(T value, bool nodeColor = true)
        : data(value), parent(nullptr), left(nullptr), right(nullptr), color(nodeColor) {}


    RBTreeNode<T>*      treeMin();
    RBTreeNode<T>*      treeMax();
    void                printPreOrderTraversal()    const;
    void                printInOrderTraversal()     const;
    void                printPostOrderTraversal()   const;
};

#endif