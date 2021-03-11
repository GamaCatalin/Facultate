#include "RepositoryMemory.h"

bool RepositoryMemory::add_element(TElem element)
{
	Validator validate;
	if (!validate.validateGoodElement(element)) {
		throw ExceptionValidationError("Invalid element!\n");
	}

	for (auto& tempElement : this->elements) {
		if (tempElement.getName() == element.getName())
			throw ExceptionAddAlreadyExisting("Element already exists!\n");
	}

	this->elements.push_back(element);
	return true;
}

bool RepositoryMemory::remove_element(std::string name)
{
	int elementCount = 0;
	for (auto& tempElement : this->elements) {
		if (tempElement.getName() == name) {
			this->elements.erase(this->elements.begin()+elementCount);
			return true;
		}
		elementCount++;
	}
	throw ExceptionDeleteDoesNotExist("Element does not exist!\n");
}

bool RepositoryMemory::update_element(TElem element)
{
	Validator validate;
	if (!validate.validateGoodElement(element)) {
		throw ExceptionValidationError("Invalid element!\n");
	}

	int elementCount = 0;

	for (auto& tempElement : this->elements) {
		if (tempElement.getName() == element.getName()) {
			this->elements[elementCount] = element;
			return true;
		}
		elementCount++;
	}
	throw ExceptionDeleteDoesNotExist("Element does not exist!\n");
}

std::vector<TElem> RepositoryMemory::get_elements()
{
	return this->elements;
}

int RepositoryMemory::lenght()
{
	return this->elements.size();
}

bool RepositoryMemory::setFileLocation(std::string fileLocation)
{
	return false;
}

TElem RepositoryMemory::getElementByIndex(int index)
{
	if (index > this->lenght())
		throw ExceptionIndexTooLarge("Index too large!\n");
	return this->elements[index];
}

TElem RepositoryMemory::getElementByName(std::string name)
{
	for (auto& element : this->elements) {
		if (element.getName() == name) {
			return element;
		}
	}
	throw ExceptionElementNotFound("Element not found!\n");
}

bool RepositoryMemory::elementExists(std::string name)
{
	for (auto& element : this->elements) {
		if (element.getName() == name) {
			return true;
		}
	}
	return false;
}
