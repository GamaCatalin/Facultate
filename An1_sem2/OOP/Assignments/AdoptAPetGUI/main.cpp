#include "AdoptAPetGUI.h"
#include <QtWidgets/QApplication>
#include "GUI.h"
#include "AdoptAPetGUI.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	

	std::fstream file;

	file.open("configuration.txt");

	std::string line,repoType,myListType;

	file >> line;

	for (int i = 0; i < line.size(); i++) {
		if (line.at(i) == ':') {
			repoType = line.substr(i+1, line.size()-i);
			break;
		}
	}

	file >> line;

	for (int i = 0; i < line.size(); i++) {
		if (line.at(i) == ':') {
			myListType = line.substr(i+1, line.size()-i);
			break;
		}
	}

	file.close();

	MyListController* myList;
	Repository* repository;

	if (myListType == "html") {
		myList = new HTMLMyListController{};
	}
	else {
		if (myListType == "csv") {
			myList = new CSVMyListController{};
		}
		else {
			if (myListType == "memory") {
				myList = new MemoryMyListController{};
			}
			else {
				myList = new CSVMyListController{};
			}
		}
	}

		
	if (repoType == "file") {
		repository = new RepositoryFiles{};
	}
	else {
		if (repoType == "memory") {
			repository = new RepositoryMemory{};
		}
		else {
			repository = new RepositoryFiles{};
		}
	}

	
	Service service{repository,myList};


	AdoptAPetGUI gui{service};

	//GUI gui{service};
	

	gui.show();
	

	return a.exec();
}
