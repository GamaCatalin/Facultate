#include "CSVMyListController.h"

CSVMyListController::CSVMyListController(std::string filePath)
{
	this->fileName = filePath;
}

bool CSVMyListController::saveElement(TElem element)
{
	std::fstream file;
	file.open(this->fileName);
	TElem tempElement;
	while (file >> tempElement) {
		if (tempElement.getName() == element.getName()) {
			file.close();
			return false;
		}
	}
	file.close();
	file.open(this->fileName, std::ios::app);
	file << element;
	file.close();
	return true;
}

std::vector<TElem> CSVMyListController::getElements()
{
	std::fstream file;
	file.open(this->fileName);
	TElem tempElement;
	std::vector<TElem> elements;
	while (file >> tempElement) {
		elements.push_back(tempElement);
	}
	std::string openNotepad = "notepad \"" + this->fileName+"\"";
	file.close();

	system(openNotepad.c_str());
	return elements;
}

bool CSVMyListController::setFileName(std::string fileName)
{
	this->fileName = fileName;
	return true;
}

std::string CSVMyListController::getFilePath()
{
	return this->fileName;
}

std::vector<TElem> CSVMyListController::getVector()
{
	std::fstream file;
	file.open(this->fileName);
	TElem tempElement;
	std::vector<TElem> elements;
	while (file >> tempElement) {
		elements.push_back(tempElement);
	}
	
	return elements;
}
