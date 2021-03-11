#pragma once
#include "DynamicVector.h"
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
class SortedSetIterator;


class Node {
public:
	bool isLeftChild;
	Node* parent;
	Node* leftChild;
	Node* rightChild;
	TElem data;

	Node(TElem data=NULL_TELEM);
};



class SortedSet {
	friend class SortedSetIterator;
private:
	Node* root;

	Relation relation;

	int lenght;

public:
	//constructor
	SortedSet(Relation r);

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TComp elem) const;

	void recursiveWalk(Node* node,DynamicVector<Node*>* elems) const;

	DynamicVector<Node*> getSuccessors(Node* node) const;

	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	Node* getRoot();

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;

	//adds all elements of s into the SortedSet
	void Union(const SortedSet& s);

	// destructor
	~SortedSet();


};
