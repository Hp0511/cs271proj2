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

