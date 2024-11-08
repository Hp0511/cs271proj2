#include <iostream>
#include <exception>
#pragma once

using namespace std;

//==============================================================
// Empty Tree Exception
// Author: Huy Phan
// Description: An error which is called when the tree is empty
//==============================================================
class EmptyTreeException : public exception {
public:
    const char* what() const noexcept override {
        return "Operation failed: The tree is empty.";
    }
};

//==============================================================
// Value not in tree
// Author: Huy Phan
// Description: An error which is called when the search cannot 
// find the value
//==============================================================
class ValueNotInTreeException : public exception {
public:
    const char* what() const noexcept override {
        return "Operation failed: The specified value is not in the tree.";
    }
};
