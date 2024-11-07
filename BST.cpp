//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/5/2024
// About: This file is the implementation file of the BSTNode class. It includes
// definition for finding the minimum and maximum nodes in a subtree, 
// performing tree traversals (pre-order, in-order, and post-order),
// and managing node memory with default, copy constructors, destructors, 
// and an assignment operator.
//==============================================================

#include <iostream>
#include <stdlib.h>
#include "BSTNode.hpp"
#include "BST.hpp"
#include "customexceptions.hpp"
using namespace std;

//==============================================================
// Default Constructor
// Author: Huy Phan
// Description: Initializes a new instance of the BST class. This
// constructor sets the root pointer to nullptr,
// effectively creating an empty binary search tree. 
// It also initializes the node count to 0, indicating 
// that the tree has no nodes at creation.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
    BST<T>::BST    ( void )
{
    root = nullptr;
    nodeCount = 0;
}


//==============================================================
// Copy Constructor
// Author: Huy Phan
// Description: Constructs a new instance of the BST class as a 
//              deep copy of an existing BST object. 
// Parameters: bst - A constant reference to the 
// BST instance to be copied.
// Return Value: None
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


//==============================================================
// Function: deleteSubTree
// Author: Huy Phan
// Description: Recursively deletes all nodes in the subtree rooted 
//              at the specified node. 
// Parameters:
//    node - Pointer to the root node of the subtree to be deleted.
// Return Value: None
//==============================================================
template <typename T>
    void BST<T>::deleteSubTree(BSTNode<T>* node) {
        if (node == nullptr) {
            return; 
        }

        // First, delete the left and right children.
        deleteSubTree(node->left);
        deleteSubTree(node->right);

        // Then, delete the current node.
        delete node;
    }


//==============================================================
// Destructor
// Author: Huy Phan
// Description: Destructor for the BST class. Ensures all memory
//              allocated for nodes within the tree is properly freed.
// Return Value: None
//==============================================================
template <typename T>
    BST<T>::~BST() {
        deleteSubTree(root); // Delete all nodes starting from the root.
        root = nullptr;      // Set root to nullptr to prevent dangling pointer issues.
    }


//==============================================================
// Operator: Assignment
// Author: Huy Phan
// Description: Overloads the assignment operator to assign the content of one BST to another, 
//              ensuring a deep copy with proper memory management.
// Parameters:
//    bst - A constant reference to the BST instance to assign from.
// Return Value:
//    A reference to this instance of BST after assignment.
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
// Function: transplant
// Author: Huy Phan
// Description: Replaces one subtree with another within the tree, updating parent 
//              pointers to maintain the BST properties.
// Parameters:
//    oldNode - Pointer to the node being replaced.
//    newNode - Pointer to the node that will replace the old node.
// Return Value: None
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
// Function: size
// Author: Huy Phan
// Description: Returns the number of nodes currently in the BST.
// Parameters: None
// Return Value: The number of nodes in the tree, represented as a long integer.
//==============================================================
template <typename T>
    long BST<T>::size() const
{
    return nodeCount;
}


//==============================================================
// Function: isEmpty
// Author: Huy Phan
// Description: Checks whether the binary search tree is empty.
// Parameters: None
// Return Value: Returns true if the tree is empty (i.e., contains no nodes), false otherwise.
//==============================================================
template <typename T>
    bool BST<T>::isEmpty() const
{
    return nodeCount == 0;
}


//==============================================================
// Function: insert
// Author: Huy Phan
// Description: Inserts a new node with the given value into the binary search tree, maintaining BST properties.
// Parameters:
//    value - The value to be inserted into the tree.
// Return Value: A pointer to the newly inserted node.
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
// Function: remove
// Author: Huy Phan
// Description: Removes a node with the specified value from the binary search tree, adjusting the tree to maintain BST properties.
// Parameters:
//    value - The value of the node to be removed from the tree.
// Return Value: None
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
// Function: search
// Author: Huy Phan
// Description: Searches for and returns the node containing the specified value within the binary search tree; 
//              throws an exception if the value is not found.
// Parameters:
//    value - The value to search for in the tree.
// Return Value: A pointer to the BSTNode containing the specified value if found.
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
// Function: treeMin
// Author: Huy Phan
// Description: Returns the node with the minimum value in the binary search tree by traversing 
//              down the leftmost path from the root; returns nullptr if the tree is empty.
// Parameters: None
// Return Value: A pointer to the BSTNode with the smallest value in the tree, or nullptr if the tree is empty.
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
// Function: treeMax
// Author: Huy Phan
// Description: Returns the node with the maximum value in the binary search tree by traversing 
//              down the rightmost path from the root; returns nullptr if the tree is empty.
// Parameters: None
// Return Value: A pointer to the BSTNode with the largest value in the tree, or nullptr if the tree is empty.
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
// Function: printPreOrderTraversal
// Author: Huy Phan
// Description: Performs and prints a pre-order traversal of the binary search tree, 
//              starting from the root; throws an exception if the tree is empty.
// Parameters: None
// Return Value: None, but prints the traversal output to standard output.
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
// Function: printInOrderTraversal
// Author: Huy Phan
// Description: Performs and prints an in-order traversal of the binary search tree,
//              which effectively displays the tree's elements in ascending order;
//              throws an exception if the tree is empty.
// Parameters: None
// Return Value: None, but prints the traversal output to standard output.
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
// Function: printPostOrderTraversal
// Author: Huy Phan
// Description: Performs and prints a post-order traversal of the binary search tree,
//              which visits the left subtree, the right subtree, and then the node itself;
//              throws an exception if the tree is empty.
// Parameters: None
// Return Value: None, but prints the traversal output to standard output.
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