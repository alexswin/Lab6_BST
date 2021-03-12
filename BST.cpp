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

bool BST::add(int data) {
	return add(data, root);
}

bool BST::remove(int data) {
	return remove(data, root);
}

void BST::clear() {
	clear(root);
}

void BST::clear(Node* &subRoot) {
	if (subRoot == NULL) {return;}
	clear(subRoot->left);
	clear(subRoot->right);
	delete subRoot;
}

bool BST::add(int data, Node* &subRoot) {
	if (subRoot == NULL) {
		subRoot = new Node(data);
		return true;
	}
	else if (data < subRoot->data) {
		return add(data, subRoot->left);
	}
	else if (data > subRoot->data) {
		return add(data, subRoot->right);
	}
	else {	//data == subRoot->data
		return false;
	}
}

bool BST::remove(int data, Node* &subRoot) {
	if (subRoot == NULL) {
		return false;
	}

	else if (data < subRoot->data) {
		return remove(data, subRoot->left);
	}

	else if (data > subRoot->data) {
		return remove(data, subRoot->right);
	}

	else {	//data==subRoot->data (subRoot is the node to remove)
		if (subRoot->left == NULL) {
			Node* oldNode = subRoot;
			subRoot = subRoot->right;
			delete oldNode;
		}

		else if (subRoot->right == NULL) {
			Node* oldNode = subRoot;
			subRoot = subRoot->left;
			delete oldNode;
		}

		else {
			//Find the rightmost local root to the left of subRoot that does not have a right child
			Node* replacementNode = subRoot->left;
			while (replacementNode->right != NULL) {
				replacementNode = replacementNode->right;
			}
			//Put its value into subRoot, then remove it (from subRoot's left subtree)
			subRoot->data = replacementNode->data;
			remove(data, subRoot->left);
		}

		return true;
	}
}

#endif