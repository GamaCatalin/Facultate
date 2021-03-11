#pragma once
#include "Repository.h"
#include "RepositoryFiles.h"
#include "RepositoryMemory.h"
#include "MyListController.h"
#include "CSVMyListController.h"
#include "HTMLMyListController.h"
#include "MemoryMyListController.h";
#include "TXTMyListController.h";
#include "Validator.h"
#include "UndoController.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#ifndef SERVICE_H
#define SERVICE_H

class Service {
private:
	MyListController* myListController;
	UndoController* undoController;

	Repository* petShop;

	std::string runMode = "";
	std::string myListMode = "";
	
public:
	Service(Repository* repository = new RepositoryFiles{}, MyListController* myListController = new MemoryMyListController{}, UndoController* undoController = new UndoController{});
	int userCurrentDogIndex=0;
	bool addElement(TElem element);
	bool updateElement(TElem element);
	bool removeElement(std::string name);

	void undo();
	void redo();

	int lenght();

	std::vector<TElem> getAll();
	std::vector<TElem> getAdoptionList();
	std::vector<TElem> getAdoptionVector();
	TElem getElementByID(std::string name);

	std::string getRunMode();
	bool setRunMode(std::string runMode);

	bool saveDog(std::string name);

	TElem nextDog();

	bool changeFileLocation(std::string fileLocation);
	bool changeMyListLocation(std::string mylistLocation);

	void populateList();

	std::string getMyListMode(std::string mylistLocation);
	std::string getCurrentMyListMode();
};




#endif