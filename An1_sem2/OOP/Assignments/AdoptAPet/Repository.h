#pragma once
#include "DynamicVector.h"

typedef Pet TElem;


class Repository
{
private:
	DynamicVector<TElem> dogs;

public:
	void add_element(TElem element);
	void update_element(int position, TElem element);
	void remove_element(int position);

	DynamicVector<TElem> get_elements();

	int lenght();
};

