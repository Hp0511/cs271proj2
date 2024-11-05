#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include <stdexcept>

template <typename T>
class RBTree {
private:
    RBTreeNode<T>* root;

    void        transplant(RBTreeNode<T>* oldNode, RBTreeNode<T>* newNode);
    void        leftRotation(RBTreeNode<T>* centerNode); // NOT part of assignment (helper function)
    void        rightRotation(RBTreeNode<T>* centerNode); // NOT part of assignment (helper function)
    void        insertFixup(RBTreeNode<T>* node);
    void        removeFixup(RBTreeNode<T>* node);
    void        printPreOrderTraversal(RBTreeNode<T>* node)     const;
    void        printInOrderTraversal(RBTreeNode<T>* node)      const;
    void        printPostOrderTraversal(RBTreeNode<T>* node)    const;

public:
    // Constructor and destructor
    RBTree();
    ~RBTree();

    // Public methods
    bool                isEmpty()       const;
    long                size()          const;
    RBTreeNode<T>*      insert(T value);
    void remove(T value);
    RBTreeNode<T>*      search(T value) const;
    RBTreeNode<T>*      treeMin()       const;
    RBTreeNode<T>*      treeMax()       const;
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;
};

#endif
