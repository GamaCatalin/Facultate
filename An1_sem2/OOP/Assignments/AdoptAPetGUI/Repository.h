#pragma once
#include <vector>
#include "Pet.h"
#include "Exception.h"
#include "Validator.h"
#include <fstream>
#include <iostream>

typedef Pet TElem;

class Repository
{
private:


public:
	virtual bool add_element(TElem element) = 0;
	virtual bool remove_element(std::string name) = 0;
	virtual bool update_element(TElem element) = 0;

	virtual std::vector<TElem> get_elements() = 0;

	virtual int lenght() = 0;

	virtual bool setFileLocation(std::string fileLocation) = 0;

	virtual TElem getElementByIndex(int index) = 0;
	virtual TElem getElementByName(std::string name) = 0;
	virtual bool elementExists(std::string name) = 0;
};

