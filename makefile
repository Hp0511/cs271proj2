# Target to build and run the test executable
mytests: mytests.o BSTNode.o BST.o
	g++ -o mytests mytests.o BSTNode.o BST.o
	./mytests

mytests.o: mytests.cpp BSTNode.hpp BST.hpp customexceptions.hpp
	g++ -c mytests.cpp -o mytests.o

BSTNode.o: BSTNode.cpp BSTNode.hpp
	g++ -c BSTNode.cpp -o BSTNode.o

BST.o: BST.cpp BST.hpp BSTNode.hpp customexceptions.hpp
	g++ -c BST.cpp -o BST.o

RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp
	g++ -c RBTreeNode.cpp -o RBTreeNode.o

RBTree.o: RBTree.cpp RBTree.hpp RBtreeNode.hpp customexceptions.hpp
	g++ -c RBTree.cpp -o RBTree.o

# Cleaning all object files and executable
clean:
	rm -f *.o mytests
