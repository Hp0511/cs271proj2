//==============================================================
// Names: Huy Phan, 
// Class: CS 271-01
// Project: 2
// Date: 9/20/2024
// About: mytests.cpp contains the test cases for each method in BSTNode
//==============================================================

#include <iostream>
#include "BSTNode.cpp"
#include "BST.cpp"

using namespace std;

//==============================================================
// BSTNODE TEST
//==============================================================

//==============================================================
// Test the Default Constructor
//==============================================================
void bstnode_test_default_constructor() {
    BSTNode<int> root;
    cout << "Testing Default Constructor:" << endl;
    cout << "Root value: " << root.value << " (Expected: 0)" << endl;
    cout << "Left pointer: " << root.left << " (Expected: nullptr)" << endl;
    cout << "Right pointer: " << root.right << " (Expected: nullptr)" << endl;
    cout << "Parent pointer: " << root.parent << " (Expected: nullptr)" << endl;
    cout << "Default constructor test completed." << endl << endl;
}

//==============================================================
// Test Tree Building 
//==============================================================
BSTNode<int>* bstnode_build_tree() {
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
void bstnode_test_tree_min(BSTNode<int>* root) {
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
void bstnode_test_tree_max(BSTNode<int>* root) {
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
void bstnode_test_preorder_traversal(BSTNode<int>* root) {
    cout << "Testing Pre-order Traversal (Expected output: 10 5 2 7 15):" << endl;
    root->printPreOrderTraversal();
    cout << endl << "Pre-order Traversal test completed." << endl << endl;
}

//==============================================================
// Test In-order Traversal
//==============================================================
void bstnode_test_inorder_traversal(BSTNode<int>* root) {
    cout << "Testing In-order Traversal (Expected output: 2 5 7 10 15):" << endl;
    root->printInOrderTraversal();
    cout << endl << "In-order Traversal test completed." << endl << endl;
}

//==============================================================
// Test Post-order Traversal
//==============================================================
void bstnode_test_postorder_traversal(BSTNode<int>* root) {
    cout << "Testing Post-order Traversal (Expected output: 2 7 5 15 10):" << endl;
    root->printPostOrderTraversal();
    cout << endl << "Post-order Traversal test completed." << endl << endl;
}

//==============================================================
// Test Copy Constructor
//==============================================================
void bstnode_test_copy_constructor(BSTNode<int>* root) {
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
void bstnode_test_assignment_operator(BSTNode<int>* root) {
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
void bstnode_test_self_assignment(BSTNode<int>* root) {
    cout << "Testing Self-assignment (In-order Traversal after self-assignment, Expected: 2 5 7 10 15):" << endl;
    *root = *root;  // Should not cause any changes
    root->printInOrderTraversal();
    cout << endl << "Self-assignment test completed." << endl << endl;
}


//==============================================================
// BST TEST
//==============================================================


//==============================================================
// Test the Default Constructor
//==============================================================
void bst_test_default_constructor() {
    cout << "Testing Default Constructor:" << endl;
    BST<int> bst;
    cout << "Is tree empty? " << (bst.isEmpty() ? "Yes" : "No") << " (Expected: Yes)" << endl;
    cout << "Size of tree: " << bst.size() << " (Expected: 0)" << endl;
    cout << "Default constructor test completed.\n" << endl;
}

//==============================================================
// Test Insert Method
//==============================================================
void bst_test_insert() {
    cout << "Testing Insert Method:" << endl;
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    cout << "Inserted values: 10, 5, 15, 3, 7" << endl;
    cout << "Is tree empty? " << (bst.isEmpty() ? "Yes" : "No") << " (Expected: No)" << endl;
    cout << "Size of tree: " << bst.size() << " (Expected: 5)" << endl;
    cout << "Insert method test completed.\n" << endl;
}

//==============================================================
// Test Search Method
//==============================================================
void bst_test_search() {
    cout << "Testing Search Method:" << endl;
    BST<int> bst0;

    // Insert some values into the tree
    bst0.insert(10);
    bst0.insert(5);
    bst0.insert(15);

    // Test searching for a value that exists
    try {
        BSTNode<int>* result = bst0.search(5);
        cout << "Found value: " << result->value << " (Expected: 5)" << endl;
    } catch (const ValueNotInTreeException& e) {
        cout << "Search Exception Caught (Unexpected): " << e.what() << endl;
    }

    // Test searching for a value that does not exist
    try {
        bst0.search(20);  // Value 20 is not in the tree
        cout << "Error: Value 20 was found, but it should not exist in the tree." << endl;
    } catch (const ValueNotInTreeException& e) {
        cout << "Search Exception Caught: " << e.what() << " (Expected)" << endl;
    }

    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    BSTNode<int>* result = bst.search(5);
    cout << "Found value: " << result->value << " (Expected: 5)" << endl;

    cout << "Search method test completed.\n" << endl;
}

//==============================================================
// Test Remove Method
//==============================================================
void bst_test_remove() {
    cout << "Testing Remove Method:" << endl;
    BST<int> bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    cout << "Original In-order Traversal (Expected: 5 10 15 20 25 30 35):\n";
    bst.printInOrderTraversal();
    cout << endl;

    bst.remove(10);  // Node with two children
    cout << "After removing 10 (Expected In-order: 5 15 20 25 30 35):\n";
    bst.printInOrderTraversal();
    cout << endl;

    bst.remove(5);   // Leaf node
    cout << "After removing 5 (Expected In-order: 15 20 25 30 35):\n";
    bst.printInOrderTraversal();
    cout << endl;

    bst.remove(30);  // Node with one child
    cout << "After removing 30 (Expected In-order: 15 20 25 35):\n";
    bst.printInOrderTraversal();
    cout << endl;

    cout << "Remove method test completed.\n" << endl;
}

//==============================================================
// Test Traversal Methods
//==============================================================
void bst_test_traversals() {
    cout << "Testing Traversal Methods:" << endl;
    BST<int> bst0;

    // Check traversal methods for empty tree
    cout << "Testing traversals on an empty tree (Expected: Should throw exception):" << endl;
    try {
        bst0.printPreOrderTraversal();
    } catch (const EmptyTreeException& e) {
        cout << "Pre-order Traversal Exception Caught: " << e.what() << endl;
    }

    try {
        bst0.printInOrderTraversal();
    } catch (const EmptyTreeException& e) {
        cout << "In-order Traversal Exception Caught: " << e.what() << endl;
    }

    try {
        bst0.printPostOrderTraversal();
    } catch (const EmptyTreeException& e) {
        cout << "Post-order Traversal Exception Caught: " << e.what() << endl;
    }

    BST<int> bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    cout << "Pre-order Traversal (Expected: 20 10 5 15 30 25 35):\n";
    bst.printPreOrderTraversal();
    cout << endl;

    cout << "In-order Traversal (Expected: 5 10 15 20 25 30 35):\n";
    bst.printInOrderTraversal();
    cout << endl;

    cout << "Post-order Traversal (Expected: 5 15 10 25 35 30 20):\n";
    bst.printPostOrderTraversal();
    cout << endl;

    cout << "Traversal methods test completed.\n" << endl;
}

//==============================================================
// Test TreeMin and TreeMax Methods
//==============================================================
void bst_test_tree_min_max() {
    cout << "Testing TreeMin and TreeMax Methods:" << endl;
    BST<int> bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);

    // Test treeMin
    BSTNode<int>* minNode = bst.treeMin();
    if (minNode != nullptr) {
        cout << "Minimum value in tree: " << minNode->value << " (Expected: 5)" << endl;
    } else {
        cout << "Minimum value in tree: Not found (Tree is empty)" << endl;
    }

    // Test treeMax
    BSTNode<int>* maxNode = bst.treeMax();
    if (maxNode != nullptr) {
        cout << "Maximum value in tree: " << maxNode->value << " (Expected: 30)" << endl;
    } else {
        cout << "Maximum value in tree: Not found (Tree is empty)" << endl;
    }

    cout << "TreeMin and TreeMax methods test completed.\n" << endl;
}

//==============================================================
// Main function to run all tests
//==============================================================
int main() {

    cout<<"TESTING BSTNODE CLASS" <<endl<<endl;
    // Test default constructor
    bstnode_test_default_constructor();

    // Build the tree
    BSTNode<int>* root = bstnode_build_tree();

    // Test treeMin
    bstnode_test_tree_min(root);

    // Test treeMax
    bstnode_test_tree_max(root);

    // Test Pre-order Traversal
    bstnode_test_preorder_traversal(root);

    // Test In-order Traversal
    bstnode_test_inorder_traversal(root);

    // Test Post-order Traversal
    bstnode_test_postorder_traversal(root);

    // Test Copy Constructor
    bstnode_test_copy_constructor(root);

    // Test Assignment Operator
    bstnode_test_assignment_operator(root);

    // Test Self-assignment
    bstnode_test_self_assignment(root);

    cout << "All BSTNodes tests completed successfully." << endl;

    cout<<"TESTING BST CLASS" <<endl<<endl;
    bst_test_default_constructor();
    bst_test_insert();
    bst_test_search();
    bst_test_remove();
    bst_test_traversals();
    bst_test_tree_min_max();

    cout <<endl<<endl<< "All BST tests completed successfully." << endl;
    return 0;
}
