#pragma once
#include "MyListController.h"
#include <Windows.h>
class CSVMyListController : public MyListController
{
private:
	
public:
	CSVMyListController(std::string filePath = "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetGUI\\myList.csv");

	std::string fileName= "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetGUI\\myList.csv";

	bool saveElement(TElem element);

	std::vector<TElem> getElements();

	bool setFileName(std::string fileName);

	std::string getFilePath();

	std::vector<TElem> getVector();
};

