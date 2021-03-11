#include <vector>
#include "RepositoryFiles.h"
#include <iostream>



#pragma once
class MyListController
{
private:
public:
	virtual std::string getFilePath() = 0;

	virtual bool saveElement(TElem element) = 0;

	virtual std::vector<TElem> getElements() = 0;;

	virtual bool setFileName(std::string fileName) = 0;

	virtual std::vector<TElem> getVector() = 0;
};

