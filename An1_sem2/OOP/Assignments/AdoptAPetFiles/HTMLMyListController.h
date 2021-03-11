#pragma once
#include "MyListController.h"
#include <Windows.h>
class HTMLMyListController : public MyListController
{
private:
	std::string fileName;
public:

	bool saveElement(TElem element);

	std::vector<TElem> getElements();

	bool setFileName(std::string fileName);

	void writeHTML(std::vector<TElem> elements);

	std::vector<TElem> readHTML();

	BirthDate strToDate(std::string date);
};

