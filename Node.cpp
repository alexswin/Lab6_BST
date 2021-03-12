#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(int newData, Node* newLeft, Node* newRight) 
	: data(newData), left(newLeft), right(newRight) {};

int Node::getData() const {
	return data;
}

Node* Node::getLeftChild() const {
	return left;
}

Node* Node::getRightChild() const {
	return right;
}


#endif