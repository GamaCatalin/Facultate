#pragma once
#include <string>
#include "Repository.h"



class RepositoryFiles: public Repository
{
private:
	std::string fileLocation="D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetGUI\\elements.txt";
	int size=0;
public:
	RepositoryFiles(std::string fileLocation = "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetGUI\\elements.txt");
	bool add_element(TElem element);
	bool remove_element(std::string elementName);
	bool update_element(TElem element);

	std::vector<TElem> get_elements();

	int lenght();

	bool setFileLocation(std::string fileLocation);

	TElem getElementByIndex(int index);
	TElem getElementByName(std::string name);
	bool elementExists(std::string name);
};

