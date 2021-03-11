#pragma once
#include <vector>
#include "Pet.h"

typedef Pet TElem;

class Repository
{
private:
	std::vector<TElem> dogs;
	bool isValid(TElem element);
public:
	virtual bool add_element(TElem element);
	virtual bool update_element(TElem element);
	virtual bool remove_element(std::string element);

	std::vector<TElem> get_elements();

	int lenght();
};

