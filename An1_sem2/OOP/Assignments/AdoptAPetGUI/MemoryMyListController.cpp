#include "MemoryMyListController.h"

bool MemoryMyListController::saveElement(TElem element)
{
	for (auto &current : this->elements) {
		if (current.getName() == element.getName()) {
			return false;
		}
	}
	this->elements.push_back(element);
	return true;
}

std::vector<TElem> MemoryMyListController::getElements()
{
	return this->elements;
}

bool MemoryMyListController::setFileName(std::string fileName)
{
	this->fileName = fileName;
	return true;
}

std::string MemoryMyListController::getFilePath()
{
	return "";
}

std::vector<TElem> MemoryMyListController::getVector()
{
	return this->elements;
}
