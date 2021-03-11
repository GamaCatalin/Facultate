#pragma once
#include "SortedSet.h"
#include "DynamicVector.h"
#include <iostream>

//DO NOT CHANGE THIS PART


class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
	int currentPosition;
	DynamicVector<Node*> nodes;
	Node* currentNode;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};

