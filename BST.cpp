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
	//cout << "In clear." << endl;
	if (subRoot == NULL) {
		//cout << "subRoot is NULL. Returning..." << endl;
		return;
	}
	//else {cout << "subRoot is " << subRoot->data << ". Clearing left and right children..." << endl;}
	clear(subRoot->left);
	clear(subRoot->right);
	//cout << "Deleting node " << subRoot->data << endl;
	delete subRoot;
	subRoot = NULL;
	//cout << "Returning..." << endl;
}

bool BST::add(int data, Node* &subRoot) {
	//cout << "In add. Attempting to add " << data << endl;
	if (subRoot == NULL) {
		//cout << "Empty subtree. Adding " << data << "..." << endl;
		subRoot = new Node(data);
		//cout << "Added new node with " << subRoot->data << ". Returning..." << endl;
		return true;
	}
	else if (data < subRoot->data) {
		//cout << data << " < " << subRoot->data << ", trying left tree..." << endl;
		return add(data, subRoot->left);
	}
	else if (data > subRoot->data) {
		//cout << data << " > " << subRoot->data << ", trying right tree..." << endl;
		return add(data, subRoot->right);
	}
	else {	//data == subRoot->data
		//cout << data << " = " << subRoot->data << ", returing false..." << endl;
		return false;
	}
}

bool BST::remove(int data, Node* &subRoot) {
	//cout << "In remove. Attempting to remove " << data << " from subtree with root ";
	//if (subRoot == NULL) {cout << "NULL..." << endl;}
	//else {cout << subRoot->data << "..." << endl;}

	if (subRoot == NULL) {
		//cout << "Empty tree. Returning false..." << endl;
		return false;
	}

	else if (data < subRoot->data) {
		//cout << data << " < " << subRoot->data << ", trying left tree..." << endl;
		return remove(data, subRoot->left);
	}

	else if (data > subRoot->data) {
		//cout << data << " > " << subRoot->data << ", trying right tree..." << endl;
		return remove(data, subRoot->right);
	}

	else {	//data==subRoot->data (subRoot is the node to remove)
		//cout << data << " = " << subRoot->data << ", removing..." << endl;
		if (subRoot->left == NULL) {
			//cout << "Left subtree is empty. Replacing " << subRoot->data << " with ";
			Node* oldNode = subRoot;
			subRoot = subRoot->right;
			//if (subRoot == NULL) {cout << "NULL";}
			//else {cout << subRoot->data;}
			//cout << " and deleting " << oldNode->data << "." << endl;
			delete oldNode;
		}

		else if (subRoot->right == NULL) {
			//cout << "Right subtree is empty. Replacing " << subRoot->data << " with ";
			Node* oldNode = subRoot;
			subRoot = subRoot->left;
			//if (subRoot == NULL) {cout << "NULL";}
			//else {cout << subRoot->data;}
			//cout << " and deleting " << oldNode->data << "." << endl;
			delete oldNode;
		}

		else {
			//Find the rightmost local root to the left of subRoot that does not have a right child
			//cout << "Neither subtree is empty." << endl;
			Node* replacementNode = subRoot->left;
			while (replacementNode->right != NULL) {
				replacementNode = replacementNode->right;
			}
			//cout << "Replacement node is " << replacementNode->data << endl;
			//Put its value into subRoot, then remove it (from subRoot's left subtree)
			subRoot->data = replacementNode->data;
			//cout << "subRoot is now " << subRoot->data << endl;
			//cout << "Removing duplicate value from left subtree." << endl;
			remove(subRoot->data, subRoot->left);
		}
	//cout << "Returning true..." << endl;
	return true;
	}
}

#endif