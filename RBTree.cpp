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

// Insertion
// Tri Dang
template<typename T>
void RBTree<T>::insert(T value){
    // creation of a new node
    RBTreeNode<T>* newNode =  new RBtreeNode<T>();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;

    RBTreeNode<T>* comparedNode = root;
    RBTreeNode<T>* parentNode = nullptr;
    while (comparedNode != nullptr){
        parentNode = comparedNode;
        if (newNode->data < comparedNode->data){
            comparedNode = comparedNode->left;
        } else{
            comparedNode = comparedNode->right;
        }
    }
    newNode->parent = parentNode;
    if (parentNode == nullptr){
        root = newNode;
    } else if(newNode->data < parentNode->data){
        parentNode->left = newNode;
    } else{
        parentNode->right = newNode;
    }
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = true;
    insertFixup(newNode); // is it this*?
}

// Fixing tree after insertion
// Tri Dang
template<typename T>
void RBTree<T>::insertFixup(RBTreeNode<T>* newNode){
    while(newNode->parent->color == True){
        if (newNode->parent == newNode->parent->parent->left){ // Z's newNode grandparent a left child?
            RBTreeNode<T>* uncle = newNode->parent->parent->right;
            if (uncle->color == true){ // case 1
                newNode->parent->color = false;
                uncle->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            } else{
                if (newNode == newNode->parent->right){ // case 2
                    newNode = newNode->parent;
                    leftRotation(newNode->parent->parent);
                }
                // case 3
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                rightRotation(newNode->parent->parent);
            }
        } else{ // newNode's grandparent MUST be a right child
                RBTreeNode<T>* uncle = newNode->parent->parent->left;
                if (uncle->color == true){ // case 1
                    newNode->parent->color = false;
                    uncle->color = false;
                    newNode->parent->parent->color = true;
                    newNode = newNode->parent->parent;
                } else{
                    if (newNode == newNode->parent->left){ // case 2
                        newNode = newNode->parent;
                        rightRotation(newNode);
                    }
                    // case 3
                    newNode->parent->color = false;
                    newNode->parent->parent->color = true;
                    leftRotation(newNode->parent->parent);
                }
        }
    root->color = false;
    }
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
