//==============================================================
// Names: Huy Phan
// Class: CS 271-01
// Date:9/20/2024
//==============================================================

#include <iostream>
#include <stdlib.h>
#include "BSTNode.hpp"
#include <stdexcept>
using namespace std;

//==============================================================
// default constructor
// Huy Phan
// Set value to 0
// Set left pointer to nullptr
// Set right pointer to nullptr
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new BST Node
//==============================================================
template <typename T>
    BSTNode<T>::BSTNode    ( void )
{
    value = T();
    left = nullptr;
    right = nullptr;
}


//==============================================================
// copy constructor
// Huy Phan
// creates a new BST Node that is a deep copy 
// of the passed-in BST Node by copying elements 
// PARAMETERS: list
// RETURN VALUE: none
//==============================================================
template <typename T>
    BSTNode<T>::BSTNode    ( const BSTNode<T> &bstNode )
{
    value = bstNode.value;
    //Deep copy of the left subtree
    if (bstNode.left != nullptr) {
        left = new BSTNode<T>(*bstNode.left);
    } else {
        left = nullptr;
    }

    // Deep copy of the right subtree
    if (bstNode.right != nullptr) {
        right = new BSTNode<T>(*bstNode.right);
    } else {
        right = nullptr;
    }
}


//========================================================
// destructor
// Huy Phan
// deletesBST Node object, and all elements in nodes to
// ensure memory leakage does not happen
// parameters: none
// return value: none
//========================================================
template <typename T>
    BSTNode<T>::~BSTNode    ( void )
{
    delete left;
    delete right;
}


//==============================================================
// assignment operator
// Huy Phan
// creates a new BST Node that is a deep copy 
// of the passed-in BST Node by copying elements 
// PARAMETERS: bstNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    BSTNode<T>& BSTNode<T>::operator=( const BSTNode<T> &bstNode )
{
    if (this == &bstNode) {
        return *this;
    }   
    delete left;
    delete right;

    value = bstNode.value;
    //Deep copy of the left subtree
    if (bstNode.left != nullptr) {
        left = new BSTNode<T>(*bstNode.left);
    } else {
        left = nullptr;
    }

    // Deep copy of the right subtree
    if (bstNode.right != nullptr) {
        right = new BSTNode<T>(*bstNode.right);
    } else {
        right = nullptr;
    }
    return *this;
}


//==============================================================
// treeMin operator
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: none
//==============================================================
template <typename T>
    BSTNode<T>* BSTNode<T>::treeMin()
{
    BSTNode<T> *ptr = this;

    while(ptr -> left != nullptr){
        ptr = ptr-> left;
    }
    return ptr;
}

//==============================================================
// treeMax operator
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: none
//==============================================================
template <typename T>
    BSTNode<T>* BSTNode<T>::treeMax()
{
    BSTNode<T>* ptr = this;
    while(ptr -> right != nullptr){
        ptr = ptr-> right;
    }
    return ptr;
}


//==============================================================
// printPreOrderTraversal
// Huy Phan
// PARAMETERS: BSTNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BSTNode<T>::printPreOrderTraversal() const
{
    cout<<value<<" ";
    if(left != nullptr){
        left -> printPreOrderTraversal();
    }
    if(right != nullptr){
        right -> printPreOrderTraversal();
    }
}


//==============================================================
// printInOrderTraversal
// Huy Phan
// PARAMETERS: BSTNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BSTNode<T>::printInOrderTraversal() const
{
    if(left != nullptr){
        left -> printInOrderTraversal();
    }
    cout<<value<<" ";
    if(right != nullptr){
        right -> printInOrderTraversal();
    }
}

//==============================================================
// printPostOrderTraversal
// Huy Phan
// PARAMETERS: BSTNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BSTNode<T>::printPostOrderTraversal() const
{
    if(left != nullptr){
        left -> printPostOrderTraversal();
    }
    if(right != nullptr){
        right -> printPostOrderTraversal();
    }
    cout<<value<<" ";    
}