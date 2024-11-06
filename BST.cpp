//==============================================================
// Names: Huy Phan
// Class: CS 271-01
// Date:9/20/2024
//==============================================================

#include <iostream>
#include <stdlib.h>
#include "BSTNode.hpp"
#include "BST.hpp"
#include "customexceptions.hpp"
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
    nodeCount = 0;
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
    BST<T>::BST    ( const BST<T> &bst )
{
    nodeCount = bst.nodeCount;
    root = nullptr;
    
    if (bst.root != nullptr) {
        root = new BSTNode<T>();
        *root = *(bst.root);      
        nodeCount = bst.nodeCount;
    }
}

template <typename T>
void BST<T>::deleteSubTree(BSTNode<T>* node) {
    if (node == nullptr) {
        return; // Base case: If the node is null, do nothing.
    }

    // First, delete the left and right children.
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    // Then, delete the current node.
    delete node;
}

// Destructor for BST that calls the helper function.
template <typename T>
BST<T>::~BST() {
    deleteSubTree(root); // Delete all nodes starting from the root.
    root = nullptr;      // Set root to nullptr to prevent dangling pointer issues.
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
    nodeCount = 0;
    root = nullptr;
    
    if (bst.root != nullptr) {
        root = new BSTNode<T>();
        *root = *(bst.root);      
        nodeCount = bst.nodeCount;
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
    return nodeCount;
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
    return nodeCount == 0;
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

    // If the tree is empty, the new node becomes the root
    if (root == nullptr) {
        root = newNode;
        nodeCount++;
        return newNode;
    }

    // Traverse the tree to find the correct position for the new node
    BSTNode<T>* parentPtr = nullptr; // Pointer to keep track of the parent of the new node
    BSTNode<T>* currentPtr = root;

    while (currentPtr != nullptr) {
        parentPtr = currentPtr;

        if (value <= currentPtr->value) {
            // Move to the left child
            currentPtr = currentPtr->left;
        } else {
            // Move to the right child
            currentPtr = currentPtr->right;
        }
    }

    // Set the parent pointer of the new node
    newNode->parent = parentPtr;

    // Insert the new node as a left or right child of its parent
    if (value <= parentPtr->value) {
        parentPtr->left = newNode;
    } else {
        parentPtr->right = newNode;
    }

    // Increment the count of nodes
    nodeCount++;

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
    
    // Try to find the node to be deleted; catch the exception if not found
    try {
        toDel = search(value);
    } catch (const ValueNotInTreeException& e) {
        cout << e.what() << endl;
        return;
    }

    // Case 1: Node has no children (it's a leaf)
    if (toDel->left == nullptr && toDel->right == nullptr) {
        transplant(toDel, nullptr);
    } 
    // Case 2: Node has only a right child
    else if (toDel->left == nullptr) {
        transplant(toDel, toDel->right);
    } 
    // Case 3: Node has only a left child
    else if (toDel->right == nullptr) {
        transplant(toDel, toDel->left);
    }
    // Case 4: Node has two children
    else {
        BSTNode<T>* inOrdSuccess = toDel->right->treeMin();
        
        // If in-order successor is not the right child of the node to delete
        if (inOrdSuccess->parent != toDel) {
            transplant(inOrdSuccess, inOrdSuccess->right);
            inOrdSuccess->right = toDel->right;
            if (inOrdSuccess->right != nullptr) {
                inOrdSuccess->right->parent = inOrdSuccess;
            }
        }
        
        // Transplant the node to delete with the in-order successor
        transplant(toDel, inOrdSuccess);
        inOrdSuccess->left = toDel->left;
        if (inOrdSuccess->left != nullptr) {
            inOrdSuccess->left->parent = inOrdSuccess;
        }
    }
    
    // Decrease the node count
    nodeCount--;
    
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
BSTNode<T>* BST<T>::treeMin() const {
    if (root == nullptr) {
        return nullptr;
    }

    BSTNode<T>* ptr = root;

    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }

    return ptr;
}



//==============================================================
// TreeMax method
// Huy Phan
// PARAMETERS: list
// RETURN VALUE: a pointer to the inserted node 
//==============================================================
template <typename T>
BSTNode<T>* BST<T>::treeMax() const {
    if (root == nullptr) {
        return nullptr;
    }

    BSTNode<T>* ptr = root;

    while (ptr->right != nullptr) {
        ptr = ptr->right;
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