#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

BST::BST() : root(NULL) {};

BST::~BST() {
	clear();
}

Node* BST::getRootNode() const {
	return root;
}

bool BST::add(int data);

bool BST::remove(int data);

void BST::clear() {
	clear(root);
}

void BST::clear(Node* subRoot) {
	if (subRoot == NULL) {return;}
	clear(subRoot->left);
	clear(subRoot->right);
	delete subRoot;
}

#endif