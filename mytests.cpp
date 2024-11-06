//==============================================================
// Names: Huy Phan, 
// Class: CS 271-01
// Project: 2
// Date: 9/20/2024
// About: mytests.cpp contains the test cases for each method in BSTNode
//==============================================================

#include <iostream>
#include "BSTNode.cpp"

using namespace std;

//==============================================================
// Test the Default Constructor
//==============================================================
void test_default_constructor() {
    BSTNode<int> root;
    cout << "Testing Default Constructor:" << endl;
    cout << "Root value: " << root.value << " (Expected: 0)" << endl;
    cout << "Left pointer: " << root.left << " (Expected: nullptr)" << endl;
    cout << "Right pointer: " << root.right << " (Expected: nullptr)" << endl;
    cout << "Parent pointer: " << root.parent << " (Expected: nullptr)" << endl;
    cout << "Default constructor test completed." << endl << endl;
}

//==============================================================
// Test Tree Building Manually
//==============================================================
BSTNode<int>* build_tree() {
    BSTNode<int>* root = new BSTNode<int>();
    root->value = 10;

    root->left = new BSTNode<int>();
    root->left->value = 5;
    root->left->parent = root;  // Set parent of the left child

    root->right = new BSTNode<int>();
    root->right->value = 15;
    root->right->parent = root;  // Set parent of the right child

    root->left->left = new BSTNode<int>();
    root->left->left->value = 2;
    root->left->left->parent = root->left;  // Set parent of the left-left child

    root->left->right = new BSTNode<int>();
    root->left->right->value = 7;
    root->left->right->parent = root->left;  // Set parent of the left-right child

    cout << "Tree built successfully." << endl;
    return root;
}

//==============================================================
// Test TreeMin Method
//==============================================================
void test_tree_min(BSTNode<int>* root) {
    BSTNode<int>* minNode = root->treeMin();
    cout << "Testing treeMin():" << endl;
    if (minNode != nullptr) {
        cout << "Minimum value in tree: " << minNode->value << " (Expected: 2)" << endl;
    } else {
        cout << "Error: treeMin() returned nullptr." << endl;
    }
    cout << "treeMin() test completed." << endl << endl;
}

//==============================================================
// Test TreeMax Method
//==============================================================
void test_tree_max(BSTNode<int>* root) {
    BSTNode<int>* maxNode = root->treeMax();
    cout << "Testing treeMax():" << endl;
    if (maxNode != nullptr) {
        cout << "Maximum value in tree: " << maxNode->value << " (Expected: 15)" << endl;
    } else {
        cout << "Error: treeMax() returned nullptr." << endl;
    }
    cout << "treeMax() test completed." << endl << endl;
}

//==============================================================
// Test Pre-order Traversal
//==============================================================
void test_preorder_traversal(BSTNode<int>* root) {
    cout << "Testing Pre-order Traversal (Expected output: 10 5 2 7 15):" << endl;
    root->printPreOrderTraversal();
    cout << endl << "Pre-order Traversal test completed." << endl << endl;
}

//==============================================================
// Test In-order Traversal
//==============================================================
void test_inorder_traversal(BSTNode<int>* root) {
    cout << "Testing In-order Traversal (Expected output: 2 5 7 10 15):" << endl;
    root->printInOrderTraversal();
    cout << endl << "In-order Traversal test completed." << endl << endl;
}

//==============================================================
// Test Post-order Traversal
//==============================================================
void test_postorder_traversal(BSTNode<int>* root) {
    cout << "Testing Post-order Traversal (Expected output: 2 7 5 15 10):" << endl;
    root->printPostOrderTraversal();
    cout << endl << "Post-order Traversal test completed." << endl << endl;
}

//==============================================================
// Test Copy Constructor
//==============================================================
void test_copy_constructor(BSTNode<int>* root) {
    BSTNode<int> copiedRoot(*root);
    cout << "Testing Copy Constructor (In-order Traversal of copied tree, Expected: 2 5 7 10 15):" << endl;
    copiedRoot.printInOrderTraversal();
    cout << endl << "Copy constructor test completed." << endl << endl;

    // Check that parent pointers are set correctly
    if (copiedRoot.left) {
        cout << "Copied root's left child parent value: " << copiedRoot.left->parent->value << " (Expected: 10)" << endl;
    }
    if (copiedRoot.right) {
        cout << "Copied root's right child parent value: " << copiedRoot.right->parent->value << " (Expected: 10)" << endl;
    }
}

//==============================================================
// Test Assignment Operator
//==============================================================
void test_assignment_operator(BSTNode<int>* root) {
    BSTNode<int> assignedNode;
    assignedNode = *root;
    cout << "Testing Assignment Operator (In-order Traversal of assigned tree, Expected: 2 5 7 10 15):" << endl;
    assignedNode.printInOrderTraversal();
    cout << endl << "Assignment operator test completed." << endl << endl;

    // Check that parent pointers are set correctly
    if (assignedNode.left) {
        cout << "Assigned root's left child parent value: " << assignedNode.left->parent->value << " (Expected: 10)" << endl;
    }
    if (assignedNode.right) {
        cout << "Assigned root's right child parent value: " << assignedNode.right->parent->value << " (Expected: 10)" << endl;
    }
}

//==============================================================
// Test Self-assignment
//==============================================================
void test_self_assignment(BSTNode<int>* root) {
    cout << "Testing Self-assignment (In-order Traversal after self-assignment, Expected: 2 5 7 10 15):" << endl;
    *root = *root;  // Should not cause any changes
    root->printInOrderTraversal();
    cout << endl << "Self-assignment test completed." << endl << endl;
}

//==============================================================
// Main function to run all tests
//==============================================================
int main() {
    // Test default constructor
    test_default_constructor();

    // Build the tree
    BSTNode<int>* root = build_tree();

    // Test treeMin
    test_tree_min(root);

    // Test treeMax
    test_tree_max(root);

    // Test Pre-order Traversal
    test_preorder_traversal(root);

    // Test In-order Traversal
    test_inorder_traversal(root);

    // Test Post-order Traversal
    test_postorder_traversal(root);

    // Test Copy Constructor
    test_copy_constructor(root);

    // Test Assignment Operator
    test_assignment_operator(root);

    // Test Self-assignment
    test_self_assignment(root);

    cout << "All tests completed successfully." << endl;
    return 0;
}
