#ifndef BST_H
#define BST_H

#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {
	public:
		BST();
		~BST();

		//Please note that the class that implements this interface must be made
		//of objects which implement the NodeInterface

		/*
		* Returns the root node for this tree
		*
		* @return the root node for this tree.
		*/
		Node* getRootNode() const;

		/*
		* Attempts to add the given int to the BST tree
		*
		* @return true if added
		* @return false if unsuccessful (i.e. the int is already in tree)
		*/
		bool add(int data);

		/*
		* Attempts to remove the given int from the BST tree
		*
		* @return true if successfully removed
		* @return false if remove is unsuccessful(i.e. the int is not in the tree)
		*/
		bool remove(int data);

		/*
		* Removes all nodes from the tree, resulting in an empty tree.
		*/
		void clear();

	protected:
		Node* root;
	
	private:
		/*
		* Removes all nodes from the (sub)tree with root subRoot, resulting in an empty subtree.
		*/
		void clear(Node* &subRoot);

		/*
		* Attempts to add given data to subtree with root subRoot
		*/
		bool add(int data, Node* &subRoot);

		/*
		* Attempts to remove given data from subtree with root subRoot
		*/
		bool remove(int data, Node* &subRoot);
};

#endif