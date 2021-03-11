#include "RepositoryFiles.h"

RepositoryFiles::RepositoryFiles(std::string fileLocation)
{
	this->fileLocation = fileLocation;
	/*std::fstream file;
	file.open(fileLocation,std::ofstream::out);
	file.close();*/
}

bool RepositoryFiles::add_element(TElem element)
{
	std::fstream file;

	if (this->fileLocation == "") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	Validator validate;
	if (!validate.validateGoodElement(element))
		throw ExceptionValidationError("Invalid element!\n");
	file.open(this->fileLocation);
	TElem tempElement;

	while (file >> tempElement) {
		if (tempElement.getName() == element.getName()) {
			file.close();
			throw ExceptionAddAlreadyExisting("Element already exists!\n");
		}
	}
	this->size++;
	file.close();
	file.open(this->fileLocation, std::ios::app);
	file << element;
	file.close();
	return true;
}

bool RepositoryFiles::remove_element(std::string elementName)
{
	std::fstream file;

	if (this->fileLocation == "") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	file.open(this->fileLocation);
	TElem tempElement;
	std::vector<TElem> saveVector;
	bool elementExists=false;

	while (file >> tempElement) {
		if (tempElement.getName() != elementName) 
			saveVector.push_back(tempElement);
		if (tempElement.getName() == elementName)
			elementExists = true;
	}

	if (elementExists) {
		this->size--;
		file.open(this->fileLocation, std::ofstream::out);
		file.close();
		file.open(this->fileLocation, std::ios::out);
		for (auto& currentElement : saveVector) 
			file << currentElement;
		file.close();
		return true;
	}
	throw ExceptionDeleteDoesNotExist("Element does not exist!\n");
}

bool RepositoryFiles::update_element(TElem element)
{
	std::fstream file;

	if (this->fileLocation == "") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	Validator validate;
	if (!validate.validateGoodElement(element))
		throw ExceptionValidationError("Invalid element!\n");
	file.open(this->fileLocation);
	TElem tempElement;
	std::vector<TElem> saveVector;
	bool elementExists = false;

	while (file >> tempElement) {
		if (tempElement.getName() != element.getName())
			saveVector.push_back(tempElement);
		if (tempElement.getName() == element.getName()) {
			elementExists = true;
			saveVector.push_back(element);
		}
	}

	if (elementExists) {
		file.open(this->fileLocation, std::ofstream::out);
		file.close();
		file.open(this->fileLocation, std::ios::out);
		for (auto& currentElement : saveVector)
			file << currentElement;
		file.close();
		return true;
	}
	throw ExceptionUpdateDoesNotExist("Element does not exist!\n");
}

std::vector<TElem> RepositoryFiles::get_elements()
{
	std::fstream file;
	bool hasElements=false;

	if(this->fileLocation=="") {
		throw ExceptionNoFile("Invalid file path!\n");
	}

	file.open(this->fileLocation);
	TElem tempElement;
	std::vector<TElem> saveVector;

	while (file >> tempElement) {
		hasElements = true;
		saveVector.push_back(tempElement);
	}
	if (!hasElements) {
		file.close();
		throw ExceptionNoElements("No elements!\n");
	}

	file.close();

	return saveVector;
}

int RepositoryFiles::lenght()
{
	if(this->fileLocation=="") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	std::fstream file;
	bool hasElements = false;
	int size = 0;

	file.open(this->fileLocation);
	TElem tempElement;

	while (file >> tempElement) {
		hasElements = true;
		size++;
	}
	if (!hasElements) {
		file.close();
		throw ExceptionNoElements("No elements!\n");
	}

	file.close();

	this->size = size;

	return size;
}

bool RepositoryFiles::setFileLocation(std::string fileLocation)
{
	this->fileLocation = fileLocation;
	return true;
}

TElem RepositoryFiles::getElementByIndex(int index)
{
	if(this->fileLocation=="") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	if (this->size == 0) {
		throw ExceptionNoElements("No elements!\n");
	}
	if (this->size < index ) {
		throw ExceptionIndexTooLarge("Index too large!\n");
	}
	std::fstream file;
	TElem element;
	int counter=0;

	file.open(this->fileLocation);
	TElem tempElement;

	while (file >> tempElement) {
		if (counter == index) {
			file.close();
			return tempElement;
		}
		counter++;
	}
}

TElem RepositoryFiles::getElementByName(std::string name)
{
	if(this->fileLocation=="") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	if (this->size == 0) {
		throw ExceptionNoElements("No elements!\n");
	}
	std::fstream file;
	TElem element;

	file.open(this->fileLocation);
	TElem tempElement;

	while (file >> tempElement) {
		if (tempElement.getName() == name) {
			file.close();
			return tempElement;
		}
	}
	throw ExceptionElementNotFound("Element not found!\n");
}

bool RepositoryFiles::elementExists(std::string name)
{
	if (this->fileLocation == "") {
		throw ExceptionNoFile("Invalid file path!\n");
	}
	if (this->size == 0) {
		throw ExceptionNoElements("No elements!\n");
	}
	std::fstream file;
	TElem element;

	file.open(this->fileLocation);
	TElem tempElement;

	while (file >> tempElement) {
		if (tempElement.getName() == name) {
			file.close();
			return true;
		}
	}
	return false;
}
