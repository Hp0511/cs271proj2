#include<iostream>
#include "customexceptions.hpp"

const char* EmptyTreeException::what() const noexcept {
    return "Operation failed: The tree is empty.";
}

const char* ValueNotInTreeException::what() const noexcept {
    return "Operation failed: The specified value is not in the tree.";
}
