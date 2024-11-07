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
using namespace std;


//==============================================================
// Default Constructor
// Author: Huy Phan
// Description: Initializes a new instance of the BSTNode class,
//              setting the node's value to the default value of type T.
//              All pointer members (parent, left, and right) are set 
//              to nullptr.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
    BSTNode<T>::BSTNode( void )
{
    value = T();
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}


//==============================================================
// Copy Constructor
// Author: Huy Phan
// Description: Initializes a new instance of the BSTNode class as a 
//              deep copy of a given BSTNode. 
// Parameters:
//    bstNode - A constant reference to the BSTNode instance to be copied.
// Return Value: None
//==============================================================
template <typename T>
    BSTNode<T>::BSTNode( const BSTNode<T> &bstNode )
{
    value = bstNode.value;
    parent = nullptr;
    //Deep copy of the left subtree
    if (bstNode.left != nullptr) {
        left = new BSTNode<T>(*bstNode.left);
        left -> parent = this;
    } else {
        left = nullptr;
    }

    // Deep copy of the right subtree
    if (bstNode.right != nullptr) {
        right = new BSTNode<T>(*bstNode.right);
        right -> parent = this;
    } else {
        right = nullptr;
    }
}


//========================================================
// Destructor
// Author: Huy Phan
// Description: delete BST Node object, and all elements in nodes to
//              ensure memory leakage does not happen
// Parameters: None
// Return Value: None
//========================================================
template <typename T>
    BSTNode<T>::~BSTNode( void )
{
}


//==============================================================
// Assignment Operator
// Author: Huy Phan
// Description: Overloads the assignment operator to ensure deep copying 
//              of a BSTNode. 
// Parameters:
//    bstNode - A constant reference to the BSTNode instance to assign from.
// Return Value:
//    A reference to this instance of BSTNode after assignment.
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
        left -> parent = this;
    } else {
        left = nullptr;
    }

    // Deep copy of the right subtree
    if (bstNode.right != nullptr) {
        right = new BSTNode<T>(*bstNode.right);
        right -> parent = this;
    } else {
        right = nullptr;
    }
    return *this;
}


//==============================================================
// Function: treeMin
// Author: Huy Phan
// Description: This function finds and returns the node with the 
//              smallest value in the subtree rooted at this node. 
// Parameters: None
// Return Value:
//    A pointer to the BSTNode containing the minimum value in the subtree.
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
// Function: treeMin
// Author: Huy Phan
// Description: This function finds and returns the node with the 
//              biggest value in the subtree rooted at this node. 
// Parameters: None
// Return Value:
//    A pointer to the BSTNode containing the maximum value in the subtree.
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
// Function: printPreOrderTraversal
// Author: Huy Phan
// Description: This function prints the values of the nodes in the subtree 
//              rooted at this node using pre-order traversal. 
// Parameters: None
// Return Value: None
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
// Function: printInOrderTraversal
// Author: Huy Phan
// Description: This function prints the values of the nodes in the subtree 
//              rooted at this node using in-order traversal. 
// Parameters: None
// Return Value: None
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
// Function: printPostOrderTraversal
// Author: Huy Phan
// Description: This function prints the values of the nodes in the subtree 
//              rooted at this node using post-order traversal. 
// Parameters: None
// Return Value: None
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