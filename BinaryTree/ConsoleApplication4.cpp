#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree* binaryTree = new BinaryTree();
    binaryTree->add(0, 7);
    binaryTree->add(7, 2);
    binaryTree->add(7, 4);
    binaryTree->add(2, 32);
    binaryTree->add(2, 15);
    binaryTree->add(15, 23);
    binaryTree->add(4, 21);

    binaryTree->remove(2);
    
    std::cout << "Hello World!\n";
}
