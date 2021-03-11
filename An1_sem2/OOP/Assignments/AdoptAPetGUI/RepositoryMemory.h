#pragma once
#include "Repository.h"

class RepositoryMemory:public Repository
{
private:
	std::vector<TElem> elements;
public:
	bool add_element(TElem element);
	bool remove_element(std::string name);
	bool update_element(TElem element);

	std::vector<TElem> get_elements();

	int lenght();

	bool setFileLocation(std::string fileLocation);

	TElem getElementByIndex(int index);
	TElem getElementByName(std::string name);
	bool elementExists(std::string name);
};