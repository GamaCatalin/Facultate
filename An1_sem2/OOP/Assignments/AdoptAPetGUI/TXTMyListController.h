#pragma once
#include "MyListController.h"
#include <Windows.h>
class TXTMyListController : public MyListController
{
private:
	
public:

	std::string fileName;

	bool saveElement(TElem element);

	std::vector<TElem> getElements();

	bool setFileName(std::string fileName);

	std::string getFilePath();

	std::vector<TElem> getVector();
};

