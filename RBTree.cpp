#include "RBTree.hpp"
#include "RBTreeNode.hpp"
#include "customexceptions.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor
template <typename T>
RBTree<T>::RBTree(){
    root = nullptr;
    nodeCount = 0;
}

// Deep copy 
template <typename T>
RBTree<T>::RBTree( const RBTree<T> &RBTree )
{
    nodeCount = RBTree.nodeCount;
    root = nullptr;
    
    if (RBTree.root != nullptr) {
        root = new RBTreeNode<T>();
        *root = *(RBTree.root);      
        nodeCount = RBTree.nodeCount;
    }
}

// Delete
template <typename T>
void RBTree<T>::deleteSubTree(RBTreeNode<T>* node) {
    if (node == nullptr) {
        return; // Base case: If the node is null, do nothing.
    }

    // First, delete the left and right children.
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    // Then, delete the current node.
    delete node;
}

// Destructor (use a recursive function to delete nodes)
template <typename T>
RBTree<T>::~RBTree() {
    deleteSubTree(root); 
}

// Assignment operator
template <typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& RBTree) {
    if (this == &RBTree){
        return *this;
    }
    deleteSubTree (root);
    nodeCount = 0;
    root = nullptr;
    
    if (RBTree.root != nullptr) {
        root = new RBTreeNode<T>();
        *root = *(RBTree.root);      
        nodeCount = RBTree.nodeCount;
    }

    return *this;
}

// Check if the tree is empty
template <typename T>
bool RBTree<T>::isEmpty() const {
    return root == nullptr;
}

// Transplant - exchange locations of 2 nodes
// Andrew
template <typename T>
void RBTree<T>::transplant(RBTreeNode<T>* oldNode, RBTreeNode<T>* newNode) {
    if (oldNode->parent == nullptr)
            root = newNode;
        else if (oldNode == oldNode->parent->left)
            oldNode->parent->left = newNode;
        else
            oldNode->parent->right = newNode;
        if (newNode != nullptr)
            newNode->parent = oldNode->parent;
}


// Left Rotation
// Tri Dang
template <typename T>
void RBTree<T>::leftRotation(RBTreeNode<T>* centerNode) {
    RBTreeNode<T>* sideNode = centerNode->right;
    centerNode->right = sideNode->left;
    if (sideNode->left != nullptr){
        sideNode->left->parent = centerNode;
    }
    sideNode->parent = centerNode->parent;
    if (centerNode->parent == nullptr){
        root = sideNode; // remember to fix this
    } else if(centerNode == centerNode->parent->left){
        centerNode->parent->left = sideNode;
    } else{
        centerNode->parent->right = sideNode;
    }
    sideNode->left = centerNode;
    centerNode->parent = sideNode;
}

// Right Rotation:
// Tri Dang
template<typename T>
void RBTree<T>::rightRotation(RBTreeNode<T>* centerNode) {
    RBTreeNode<T>* sideNode = centerNode->left;
    centerNode->left = sideNode->right;
    if (sideNode->right != nullptr){
        sideNode->right->parent = centerNode;
    }
    sideNode->parent = centerNode->parent;
    if (centerNode->parent == nullptr){
        root = sideNode; // remember to fix this
    } else if(centerNode == centerNode->parent->right){
        centerNode->parent->right = sideNode;
    } else{
        centerNode->parent->left = sideNode;
    }
    sideNode->right = centerNode;
    centerNode->parent = sideNode;
}

//==============================================================
// insert
// Author: Tri Dang
// Description: Inserts a new value into the RBTree, maintaining red-black properties.
// Parameters: T value - The value to insert.
// Return Value: RBTreeNode<T>* - Pointer to the inserted node.
//==============================================================
template<typename T>
RBTreeNode<T>* RBTree<T>::insert(T value) {
    // Create a new node with the specified value
    RBTreeNode<T>* newNode = new RBTreeNode<T>();
    newNode->data = value;
    newNode->color = true;  // New nodes are red by default

    RBTreeNode<T>* parentNode = nullptr;
    RBTreeNode<T>* comparedNode = root;

    // Traverse the tree to find the insertion point
    while (comparedNode != nullptr) {
        parentNode = comparedNode;
        if (newNode->data < comparedNode->data) {
            comparedNode = comparedNode->left;
        } else {
            comparedNode = comparedNode->right;
        }
    }

    // Set the parent of the new node and update pointers
    newNode->parent = parentNode;
    if (parentNode == nullptr) {
        root = newNode;  // Tree was empty; new node becomes root
    } else if (newNode->data < parentNode->data) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }

    // Initialize children pointers
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Fix red-black properties after insertion
    insertFixup(newNode);
    nodeCount++;  // Increment node count
    return(newNode);
}

//==============================================================
// insertFixup
// Author: Tri Dang
// Description: Fixes red-black properties after insertion.
// Parameters: RBTreeNode<T>* newNode - The newly inserted node that may violate properties.
// Return Value: None
//==============================================================
template<typename T>
void RBTree<T>::insertFixup(RBTreeNode<T>* newNode) {
    while (newNode != root && newNode->parent->color == true) {
        if (newNode->parent == newNode->parent->parent->left) {  // Parent is left child of grandparent
            RBTreeNode<T>* uncle = newNode->parent->parent->right;

            // Case 1
            if (uncle != nullptr && uncle->color == true) {
                newNode->parent->color = false;
                uncle->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            } else {
                // Case 2
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotation(newNode);
                }
                // Case 3
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                rightRotation(newNode->parent->parent);
            }
        } else {  // Parent is right child of grandparent
            RBTreeNode<T>* uncle = newNode->parent->parent->left;

            // Case 1
            if (uncle != nullptr && uncle->color == true) {
                newNode->parent->color = false;
                uncle->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            } else {
                // Case 2
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotation(newNode);
                }
                // Case 3
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                leftRotation(newNode->parent->parent);
            }
        }
    }
    root->color = false;  // Ensure root is always black
}

// treeMin - find minimun value of tree
// Andrew Nguyen
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMin() const {
    if (root == nullptr) {
        return nullptr;
    }

    RBTreeNode<T>* ptr = root;

    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }

    return ptr;
}   

// treeMax- find maximun value of tree
// Andrew
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMax() const {
     if (root == nullptr) {
        return nullptr;
    }

    RBTreeNode<T>* ptr = root;

    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }

    return ptr;
}

// Search - return the pointer of the value being searched
// Andrew
template <typename T>
RBTreeNode<T>* RBTree<T>::search(T value) const {
    RBTreeNode<T>* node = root;
    while (node != nullptr) {
        if (node->data == value) {
            return node;
        } if (node->data <= value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    throw ValueNotInTreeException();
}

// Size function
// Tri dang
template <typename T>
long RBTree<T>::size() const{
    return (nodeCount);
}

template <typename T>
void RBTree<T>::remove(T value) {
    RBTreeNode<T>* z = nullptr;
    RBTreeNode<T>* y = nullptr;
    RBTreeNode<T>* x = nullptr;

    try {
        z = search(value);
    } catch (const ValueNotInTreeException& e) {
        cout << e.what() << endl;
        return;
    }

    y = z;
    bool yOriginalColor = y->color;
    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if ( z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = z->right->treeMin();
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
                if (x != nullptr)
                    x->parent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
    delete z;
    if (yOriginalColor == false) {
        removeFixup(x);
    }
    nodeCount--;
}

template <typename T>
void RBTree<T>::removeFixup(RBTreeNode<T>* node){
    while (node != root && node->color == false) {
            if (node == node->parent->left) {
                RBTreeNode<T>* sibling = node->parent->right;
                if (sibling->color == true) {
                    sibling->color = false;
                    node->parent->color = true;
                    leftRotation(node->parent);
                    sibling = node->parent->right;
                }
                if ((sibling->left == nullptr || sibling->left->color == false)
                    && (sibling->right == nullptr || sibling->right->color == false)) {
                    sibling->color = true;
                    node = node->parent;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == false) {
                        if (sibling->left != nullptr) {
                            sibling->left->color = false;
                        }
                        sibling->color = true;
                        rightRotation(sibling);
                        sibling = node->parent->right;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = false;
                    if (sibling->right != nullptr) {
                        sibling->right->color = false;
                    }
                    leftRotation(node->parent);
                    node = root;
                }
            }
            else {
                RBTreeNode<T>* sibling = node->parent->left;
                if (sibling->color == true) {
                    sibling->color = false;
                    node->parent->color = true;
                    rightRotation(node->parent);
                    sibling = node->parent->left;
                }
                if ((sibling->left == nullptr || sibling->left->color == false)
                    && (sibling->right == nullptr || sibling->right->color == false)) {
                    sibling->color = true;
                    node = node->parent;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == false) {
                        if (sibling->right != nullptr) {
                            sibling->right->color = false;
                        }
                        sibling->color = true;
                        leftRotation(sibling);
                        sibling = node->parent->left;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = false;
                    if (sibling->left != nullptr)
                        sibling->left->color = false;
                    rightRotation(node->parent);
                    node = root;
                }
            }
        }
    node->color = false;
}

template <typename T>
void RBTree<T>::printPreOrderTraversal() const
{
    if(root != nullptr){
        root -> printPreOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}

template <typename T>
void RBTree<T>::printInOrderTraversal() const
{
    if(root != nullptr){
        root -> printInOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}

template <typename T>
void RBTree<T>::printPostOrderTraversal() const
{
    if(root != nullptr){
        root -> printPostOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}