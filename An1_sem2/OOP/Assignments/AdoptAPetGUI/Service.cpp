#include "Service.h"

Service::Service(Repository* repository ,MyListController* myListController,UndoController* undoController)
{
	this->myListController = myListController;
	this->petShop = repository;
	this->undoController = undoController;
	this->myListMode = this->getMyListMode(this->myListController->getFilePath());
	//this->populateList();
}

bool Service::addElement(TElem element)
{
	if (this->petShop->add_element(element)) {
		if (this->undoController->duringUndo == false) {
			this->undoController->save("add", element,element);
		}
		return true;
	}
}

bool Service::updateElement(TElem element)
{
	TElem elementBeforeUpdate;

	if (this->petShop->elementExists(element.getName())) {
		elementBeforeUpdate = this->petShop->getElementByName(element.getName());
	}

	if (this->petShop->update_element(element)) {
		if (this->undoController->duringUndo == false) {
			this->undoController->save("update", elementBeforeUpdate,element);
		}
		return true;
	}
}

bool Service::removeElement(std::string name)
{
	TElem element;

	if (this->petShop->elementExists(name)) {
		element = this->petShop->getElementByName(name);
	}
	if (this->petShop->remove_element(name)) {
		if (this->undoController->duringUndo == false) {
			this->undoController->save("delete", element,element);
		}
		return true;
	}
}

void Service::undo()
{
	Action action;

	action=this->undoController->undo();

	if (action.actionName == "add") {
		this->undoController->duringUndo = true;
		this->removeElement(action.undoValue.getName());
		this->undoController->duringUndo = false;
	}
	if (action.actionName == "update") {
		this->undoController->duringUndo = true;
		this->updateElement(action.undoValue);
		this->undoController->duringUndo = false;
	}
	if (action.actionName == "delete") {
		this->undoController->duringUndo = true;
		this->addElement(action.undoValue);
		this->undoController->duringUndo = false;
	}
}

void Service::redo()
{
	Action action;

	action = this->undoController->redo();

	if (action.actionName == "add") {
		this->undoController->duringUndo = true;
		this->addElement(action.redoValue);
		this->undoController->duringUndo = false;
	}
	if (action.actionName == "update") {
		this->undoController->duringUndo = true;
		this->updateElement(action.redoValue);
		this->undoController->duringUndo = false;
	}
	if (action.actionName == "delete") {
		this->undoController->duringUndo = true;
		this->removeElement(action.redoValue.getName());
		this->undoController->duringUndo = false;
	}
}

int Service::lenght()
{
	return this->petShop->lenght();
}

std::vector<TElem> Service::getAll()
{
	std::vector<TElem> vector;
	vector = this->petShop->get_elements();
	return vector;
}

std::vector<TElem> Service::getAdoptionList()
{
	return this->myListController->getElements();
}

std::vector<TElem> Service::getAdoptionVector()
{
	return this->myListController->getVector();
}

TElem Service::getElementByID(std::string name)
{
	return this->petShop->getElementByName(name);
}

std::string Service::getRunMode()
{
	return this->runMode;
}

bool Service::setRunMode(std::string runMode)
{
	this->runMode = runMode;
	return true;
}

bool Service::saveDog(std::string name)
{
	//std::cout << name << std::endl;
	std::vector<TElem> elements = this->getAll();
	for (auto& current : elements) {
		if (current.getName() == name)
		return (this->myListController->saveElement(current));
	}
	return false;
}

TElem Service::nextDog()
{
	TElem tempElement;
	std::vector<TElem> tempArray=this->petShop->get_elements();

	if (this->userCurrentDogIndex == this->petShop->lenght()-1) {
		tempElement = tempArray.at(this->userCurrentDogIndex);
		this->userCurrentDogIndex = 0;
	}
	else {
		tempElement = tempArray.at(this->userCurrentDogIndex);
		this->userCurrentDogIndex++;
	}
	return tempElement;
}

bool Service::changeFileLocation(std::string fileLocation)
{
	this->petShop->setFileLocation(fileLocation);
	return true;
}

bool Service::changeMyListLocation(std::string mylistLocation)
{
	std::string fileMode = this->getMyListMode(mylistLocation);

	if (fileMode == "html") {
		this->myListController = new HTMLMyListController();
	}
	if (fileMode == "csv") {
		this->myListController = new CSVMyListController();
	}
	if (fileMode == "txt") {
		this->myListController = new TXTMyListController();
	}
	if (fileMode == "") {
		this->myListController = new MemoryMyListController();
	}

	this->myListMode = fileMode;
	this->myListController->setFileName(mylistLocation);
	return true;
}

void Service::populateList()
{
	TElem element1{ "Name1","Breed1",BirthDate{1,1,2001},100,"Photo1" };
	TElem element2{ "Name2","Breed2",BirthDate{2,2,2002},200,"Photo2" };
	TElem element3{ "Name3","Breed3",BirthDate{3,3,2003},300,"Photo3" };
	TElem element4{ "Name4","Breed4",BirthDate{4,4,2004},400,"Photo4" };
	TElem element5{ "Name5","Breed5",BirthDate{5,5,2005},500,"Photo5" };
	TElem element6{ "Name6","Breed6",BirthDate{6,6,2006},600,"Photo6" };
	TElem element7{ "Name7","Breed7",BirthDate{7,7,2007},700,"Photo7" };

	this->addElement(element1);
	this->addElement(element2);
	this->addElement(element3);
	this->addElement(element4);
	this->addElement(element5);
	this->addElement(element6);
	this->addElement(element7);
}

std::string Service::getMyListMode(std::string mylistLocation)
{
	std::string mode="";
	if (mylistLocation == "") {
		mode = "";
	}
	else if (mylistLocation.at(mylistLocation.size() - 4) == '.') {
		if (mylistLocation.at(mylistLocation.size() - 3) == 'c') {
			mode = "csv";
		}
		if (mylistLocation.at(mylistLocation.size() - 3) == 't') {
			mode = "txt";
		}
	}
	else {
		if (mylistLocation.at(mylistLocation.size() - 5) == '.') {
			if (mylistLocation.at(mylistLocation.size() - 4) == 'h') {
				mode = "html";
			}
		}
		else {

		}
	}

	return mode;
}

std::string Service::getCurrentMyListMode()
{
	return this->myListMode;
}
