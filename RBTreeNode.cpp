#include "RBTreeNode.hpp"
#include <iostream>

using namespace std;

// Find the minimum node in the subtree rooted at this node
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMin() {
    RBTreeNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Find the maximum node in the subtree rooted at this node
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMax() {
    RBTreeNode<T>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// Print preorder traversal of the subtree rooted at this node
template <typename T>
void RBTreeNode<T>::printPreOrderTraversal() const {
    cout << data << " "; // Visit the root node
    if (left != nullptr) {
        left->printPreOrderTraversal(); // Traverse left subtree
    }
    if (right != nullptr) {
        right->printPreOrderTraversal(); // Traverse right subtree
    }
}

// Print inorder traversal of the subtree rooted at this node
template <typename T>
void RBTreeNode<T>::printInOrderTraversal() const {
    if (left != nullptr) {
        left->printInOrderTraversal(); // Traverse left subtree
    }
    cout << data << " "; // Visit the root node
    if (right != nullptr) {
        right->printInOrderTraversal(); // Traverse right subtree
    }
}

// Print postorder traversal of the subtree rooted at this node
template <typename T>
void RBTreeNode<T>::printPostOrderTraversal() const {
    if (left != nullptr) {
        left->printPostOrderTraversal(); // Traverse left subtree
    }
    if (right != nullptr) {
        right->printPostOrderTraversal(); // Traverse right subtree
    }
    cout << data << " "; // Visit the root node
}
