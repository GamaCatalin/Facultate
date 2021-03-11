#pragma once
#include "MyListController.h"
class MemoryMyListController : public MyListController
{
private:
	std::string fileName;
	std::vector<TElem> elements;
public:

	bool saveElement(TElem element);

	std::vector<TElem> getElements();

	bool setFileName(std::string fileName);

	std::string getFilePath();

	std::vector<TElem> getVector();
};

