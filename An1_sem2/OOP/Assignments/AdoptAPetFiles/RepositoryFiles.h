#pragma once
#include <string>
#include "Pet.h"
#include "Exception.h"
#include "Validator.h"
#include <iostream>
#include <fstream>

typedef Pet TElem;

class RepositoryFiles
{
private:
	std::string fileLocation="";
	int size=0;
public:
	bool add_element(TElem element);
	bool remove_element(std::string elementName);
	bool update_element(TElem element);

	std::vector<TElem> get_elements();

	int lenght();

	bool setFileLocation(std::string fileLocation);

	TElem getElementByIndex(int index);
	TElem getElementByName(std::string name);
};

