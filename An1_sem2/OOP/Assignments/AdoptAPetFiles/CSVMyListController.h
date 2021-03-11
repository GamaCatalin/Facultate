#pragma once
#include "MyListController.h"
#include <Windows.h>
class CSVMyListController : public MyListController
{
private:
	std::string fileName;
public:

	bool saveElement(TElem element);

	std::vector<TElem> getElements();

	bool setFileName(std::string fileName);
};

