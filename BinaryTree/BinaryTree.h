#pragma once
#include "TreeElement.h"

class BinaryTree
{
	vector<int> getVerticesSmallerThan(int value) {
        vector<int> vertices;
        getVerticesSmallerThan(root, value, vertices);
        return vertices;
	TreeElement* root;
	TreeElement* findElement(int n);
	TreeElement* recursiveFindElement(int n);
	TreeElement* recursiveFindElement(TreeElement* r,int n);
	void recursiveRemove(int n, TreeElement* r);
public:
	BinaryTree() :root(nullptr) {};
	BinaryTree(TreeElement* r) :root(r) {};
	

	void add(int current_n,int new_n);
	void remove(int n);
private:
	void getVerticesSmallerThan(Node* node, int value, std::vector<int>& vertices) {
        if (node == nullptr) {
            return;
        }

        getVerticesSmallerThan(node->left, value, vertices);
        if (node->value < value) {
            vertices.push_back(node->value);
        }
        getVerticesSmallerThan(node->right, value, vertices);
    }	
};
