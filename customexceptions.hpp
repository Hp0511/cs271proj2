#include <iostream>
#include <exception>
#pragma once

using namespace std;

// Exception for when attempting an operation on an empty tree
class EmptyTreeException : public exception {
public:
    const char* what() const noexcept override {
        return "Operation failed: The tree is empty.";
    }
};

// Exception for when a specific value is not found in the tree
class ValueNotInTreeException : public exception {
public:
    const char* what() const noexcept override {
        return "Operation failed: The specified value is not in the tree.";
    }
};
