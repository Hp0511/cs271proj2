# Target to build and run the test executable
mytests: mytests.o BSTNode.o
	g++ -o mytests mytests.o BSTNode.o
	./mytests

# Compile mytests.cpp into an object file
mytests.o: mytests.cpp BSTNode.hpp
	g++ -c mytests.cpp -o mytests.o

# Target to build sorting object files (only compile sorting algorithms)
BSTNode.o: BSTNode.cpp BSTNode.hpp
	g++ -c BSTNode.cpp -o BSTNode.o

# Cleaning all object files and executable
clean:
	rm -f *.o mytests
