#include "RBTree.hpp"
#include <iostream>

using namespace std;

// Constructor
template <typename T>
RBTree<T>::RBTree() : root(nullptr) {}

// Destructor (use a recursive function to delete nodes)
template <typename T>
RBTree<T>::~RBTree() {

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

// treeMin - find minimun value of tree
// Andrew Nguyen
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMin() const {
    if root == nullptr {
        return nullptr;
    }
    return root->treeMin()
}   

// treeMax- find maximun value of tree
// Andrew
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMax() const {
    if root == nullptr {
        return nullptr;
    }
    return root->treeMax()
}

// Search - return the pointer of the value being searched
// Andrew
template <typename T>
RBTreeNode<T>* RBTree<T>::search(T value) const {
    Node* node = root;
    while (node != nullptr) {
        if (node->value == value) {
            return node;
        } if (node->data <= value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return nullptr;
}