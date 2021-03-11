#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <cstddef>

SortedSet::SortedSet(Relation r) {
	this->relation = r;
	this->lenght = 0;
	this->root = NULL;
}


bool SortedSet::add(TComp elem) {
	Node* tempNode = this->root;
	Node* parent=this->root;
	bool isLeftChild = false;

	Node* addedNode=new Node();
	addedNode->data = elem;
	
	if (this->root == NULL) {
		this->root = addedNode;
		this->lenght++;
		return true;
	}

	while (tempNode != NULL) {
		if (tempNode->data == elem)
			return false;
		if (this->relation(tempNode->data, elem)) {
			if (tempNode->leftChild == NULL) {
				parent = tempNode;
				isLeftChild = true;
			}
			tempNode = tempNode->leftChild;
		}
		else {
			if (tempNode->leftChild == NULL) {
				parent = tempNode;
				isLeftChild = false;
			}
			tempNode = tempNode->rightChild;
		}
	}

	tempNode = new Node();
	tempNode->data = elem;
	tempNode->parent = parent;
	if (isLeftChild) {
		parent->leftChild = tempNode;
		tempNode->isLeftChild = true;
	}
	else {
		parent->rightChild = tempNode;
		tempNode->isLeftChild = false;
	}
	this->lenght++;
	return true;
}


bool SortedSet::remove(TComp elem) {
	Node* tempNode=this->root;
	DynamicVector<Node*> successors;
	bool foundNode = false;


	while (tempNode != NULL) {
		if (tempNode->data == elem) {
			DynamicVector<Node*> successors = this->getSuccessors(tempNode);
			foundNode = true;
			break;
		}
		if (this->relation(tempNode->data, elem)) {
			tempNode = tempNode->leftChild;
		}
		else {
			tempNode = tempNode->rightChild;
		}
	}

	if (foundNode) {
		if (tempNode->isLeftChild) {
			tempNode->parent->leftChild = NULL;
		}
		else {
			tempNode->parent->rightChild = NULL;
		}
		for (int i = 0; i < successors.lenght(); i++) {
			Node* element = successors.get_element(i);
			if (element->data != elem) {
				this->add(element->data);
			}
		}
		return true;
	}

	return false;
}


bool SortedSet::search(TComp elem) const {
	DynamicVector<Node*> elements;

	this->recursiveWalk(this->root, &elements);

	for (int i = 0; i < elements.lenght(); i++) {
		if (elements.get_element(i)->data == elem)
			return true;
	}

	return false;
}

void SortedSet::recursiveWalk(Node* node, DynamicVector<Node*>* elems) const
{
	if (node != NULL) {
		this->recursiveWalk(node->leftChild,elems);
		elems->add(node);
		this->recursiveWalk(node->rightChild,elems);
		
	}
}

DynamicVector<Node*> SortedSet::getSuccessors(Node* node) const
{
	/*DynamicVector<Node*> stack;
	
	while (node != NULL) {
		if (node->rightChild != NULL) {
			stack.add(node->rightChild);
		}
		stack.add(node);
		node = node->leftChild;
	}
	while (stack.lenght() > 0) {
		node = stack.pop_back();
		if (node->rightChild != NULL && (stack.lenght() > 0) && (node->rightChild == stack.lastElement())) {
			stack.pop_back();
			stack.add(node);
			node = node->rightChild;
		}
		else {
			node = NULL;
		}
		while (node != NULL) {
			if (node->rightChild != NULL) {
				stack.add(node->rightChild);
			}
			stack.add(node);
			node = node->leftChild;
		}
	}
	*/


	DynamicVector<Node*> elems;
	DynamicVector<Node*> reversed;
	this->recursiveWalk(node, &elems);

	for (int i = elems.lenght() - 1; i >= 0; i--) {
		reversed.add(elems.get_element(i));
	}

	return reversed;

}

int SortedSet::size() const {
	
	DynamicVector<Node*> elements;

	this->recursiveWalk(this->root, &elements);

	for (int i = 0; i < elements.lenght(); i++) {
		std::cout << elements.get_element(i)->data << " ";
	}
	std::cout << std::endl;
	return elements.lenght();
}

bool SortedSet::isEmpty() const {
	if (this->root == NULL)
		return true;
	return false;
}

Node* SortedSet::getRoot()
{
	return this->root;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}

void SortedSet::Union(const SortedSet& s)
{
	/*
	WC/BC - size_of(s)
	*/
	DynamicVector<Node*> elements=s.getSuccessors(s.root);

	for (int i = 0; i < elements.lenght(); i++) {
		Node* elem = elements.get_element(i);
		this->add(elem->data);
	}
}


SortedSet::~SortedSet() {
	
}

Node::Node(TElem data)
{
	this->isLeftChild = false;
	this->data = data;
	this->rightChild = NULL;
	this->leftChild = NULL;
	this->parent = NULL;
}
