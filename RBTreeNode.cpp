#include "RBTreeNode.hpp"
#include <iostream>

using namespace std;

// Default Constructor
template <typename T>
RBTreeNode<T>::RBTreeNode(void){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = true; // new inserted nodes must be red
    data = T();
}

// Copy Constructor
// copies node and it's subtree. This does NOT make the selected node essentially a root.
template <typename T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T> &copiedNode){
    data = copiedNode.data;
    parent = nullptr;
    color = copiedNode.color;
    // Deep copy of the left subtree recursively
    if (copiedNode.left != nullptr) {
        left = new RBTreeNode<T>(*copiedNode.left);
        left->parent = this;
    } else {
        left = nullptr;
    }
    // Deep copy of the right child recursively
    if (copiedNode.right != nullptr) {
        right = new RBTreeNode<T>(*copiedNode.right);
        right->parent = this;
    } else {
        right = nullptr;
    }
}

// Destructor
// kills the naughty node. Took up too much memory so it must perish
template <typename T>
RBTreeNode<T>::~RBTreeNode(void){
}

//operator =
template <typename T>
RBTreeNode<T>& RBTreeNode<T>::operator=(const RBTreeNode<T> &copiedNode){
    if (this == &copiedNode) {
        return *this;
    }   
    delete left;
    delete right;
    data = copiedNode.data;
    color = copiedNode.color;
    // Deep copy of the left subtree recursively
    if (copiedNode.left != nullptr) {
        left = new RBTreeNode<T>(*copiedNode.left);
        left->parent = this;
    } else {
        left = nullptr;
    }
    // Deep copy of the right child recursively
    if (copiedNode.right != nullptr) {
        right = new RBTreeNode<T>(*copiedNode.right);
        right->parent = this;
    } else {
        right = nullptr;
    }
    return *this;
}

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
