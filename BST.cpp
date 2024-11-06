//==============================================================
// Names: Huy Phan
// Class: CS 271-01
// Date:9/20/2024
//==============================================================

#include <iostream>
#include <stdlib.h>
#include "BST.hpp"
#include "BSTNode.cpp"
#include "customexceptions.hpp"
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
    BST<T>::BST    ( void )
{
    root = nullptr;
    size = 0;
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
    BST<T>    ( const BST<T> &bst )
{
    size = bst.size;
    root = nullptr;
    
    if (bst.root != nullptr) {
        root = new BSTNode<T>();
        *root = *(bst.root);      
        size = bst.size;
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
    BST<T>::~BST   ( void )
{
    delete root;
}


//==============================================================
// assignment operator
// Huy Phan
// PARAMETERS: bstNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    BST<T>& BST<T>::operator=( const BST<T> &bst)
{
    if (this == &bst){
        return *this;
    }
    delete root;
    size = 0;
    root = nullptr;
    
    if (bst.root != nullptr) {
        root = new BSTNode<T>();
        *root = *(bst.root);      
        size = bst.size;
    }

    return *this;
}


//==============================================================
// transplant method
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BST<T>::transplant(BSTNode<T>* oldNode, BSTNode<T>* newNode)
{
    if (oldNode->parent == nullptr) {
        root = newNode;
    }
    
    else if (oldNode == oldNode->parent->left) {
        oldNode->parent->left = newNode;
    }
    
    else {
        oldNode->parent->right = newNode;
    }
    if (newNode != nullptr) {
        newNode->parent = oldNode->parent;
    }
}


//==============================================================
// size
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: number of nodes in the tree
//==============================================================
template <typename T>
    long BST<T>::size() const
{
    return size;
}


//==============================================================
// isEmpty
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: number of nodes in the tree
//==============================================================
template <typename T>
    bool BST<T>::isEmpty() const
{
    return size == 0;
}


//==============================================================
// Insert method
// Huy Phan
// PARAMETERS: value - The value to be inserted into the BST
// RETURN VALUE: a pointer to the inserted node
//==============================================================
template <typename T>
BSTNode<T>* BST<T>::insert(T value) {
    // Create the new node
    BSTNode<T>* newNode = new BSTNode<T>();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;

    // If the tree is empty, the new node becomes the root
    if (root == nullptr) {
        root = newNode;
        return newNode;
    }

    // Traverse the tree to find the correct position for the new node
    BSTNode<T>* ptr = root;

    while (ptr != nullptr) {
        newNode->parent = ptr;  // Keep track of the parent of the insertion point

        if (value <= ptr->value) {
            // Move to the left child
            ptr = ptr->left;
        } else {
            // Move to the right child
            ptr = ptr->right;
        }
    }

    // Insert the new node as a left or right child of its parent
    if (value <= newNode->parent->value) {
        newNode->parent->left = newNode;
    } else {
        newNode->parent->right = newNode;
    }

    return newNode;
}


//==============================================================
// Remove method
// Huy Phan
// PARAMETERS: value - The value to remove from the BST
// RETURN VALUE: none
//==============================================================
template <typename T>
void BST<T>::remove(T value) {   
    BSTNode<T>* toDel = nullptr;
    try {
        toDel = search(value);
    } catch (const ValueNotInTreeException& e) {
        cout << e.what() << endl;
        return;
    }

    // Case 1: Node has no children (it's a leaf)
    if (toDel->left == nullptr && toDel->right == nullptr) {
        transplant(toDel, nullptr);
        delete toDel;
    } 
    // Case 2: Node has only a right child
    else if (toDel->left == nullptr) {
        transplant(toDel, toDel->right);
        delete toDel;
    }
    // Case 2: Node has only a left child
    else if (toDel->right == nullptr) {
        transplant(toDel, toDel->left);
        delete toDel;
    }
    // Case 3: Node has two children
    else {
        BSTNode<T>* inOrdSuccess = toDel->right->treeMin();

        if (inOrdSuccess->parent != toDel) {
            // Transplant in-order successor with its right child
            transplant(inOrdSuccess, inOrdSuccess->right);
            // The in-order successor now replaces the node to be deleted
            inOrdSuccess->right = toDel->right;
            inOrdSuccess->right->parent = inOrdSuccess;
        }
        // Transplant the node to delete with the in-order successor
        transplant(toDel, inOrdSuccess);
        inOrdSuccess->left = toDel->left;
        inOrdSuccess->left->parent = inOrdSuccess;

        delete toDel;
    }
}



//==============================================================
// Search method
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: a pointer to the inserted node 
//==============================================================
template <typename T>
    BSTNode<T>* BST<T>::search(T value) const
{
    BSTNode<T> *ptr = root;
    while (ptr != nullptr) {
        if (value < ptr->value) {
            // Move to the left child
            ptr = ptr->left;
        } 
        else if (value > ptr->value) {
            // Move to the right child
            ptr = ptr->right;
        }
        else {
            return ptr;
        }
    }
    throw ValueNotInTreeException();
}


//==============================================================
// TreeMin method
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: a pointer to the inserted node 
//==============================================================
template <typename T>
    BSTNode<T>* BST<T>::treeMin() const
{
    if(root != nullptr){
        root->treeMin();
    }
    else{
        throw EmptyTreeException();
    }
}


//==============================================================
// TreeMax method
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: a pointer to the inserted node 
//==============================================================
template <typename T>
    BSTNode<T>* BST<T>::treeMax() const
{
    if(root != nullptr){
        root -> treeMax();
    }
    else{
        throw EmptyTreeException();
    }
}


//==============================================================
// printPreOrderTraversal
// Huy Phan
// PARAMETERS: BSTNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BST<T>::printPreOrderTraversal() const
{
    if(root != nullptr){
        root -> printPreOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}


//==============================================================
// printInOrderTraversal
// Huy Phan
// PARAMETERS: BSTNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BST<T>::printInOrderTraversal() const
{
    if(root != nullptr){
        root -> printInOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}

//==============================================================
// printPostOrderTraversal
// Huy Phan
// PARAMETERS: BSTNode
// RETURN VALUE: none
//==============================================================
template <typename T>
    void BST<T>::printPostOrderTraversal() const
{
    if(root != nullptr){
        root -> printPostOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}