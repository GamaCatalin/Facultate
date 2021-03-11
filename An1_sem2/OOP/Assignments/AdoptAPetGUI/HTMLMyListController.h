#pragma once
#include "MyListController.h"
#include <Windows.h>
class HTMLMyListController : public MyListController
{
private:
	
public:
	std::string fileName= "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetGUI\\myList.html";

	HTMLMyListController(std::string filePath= "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetGUI\\myList.html");

	bool saveElement(TElem element);

	std::vector<TElem> getElements();

	bool setFileName(std::string fileName);

	void writeHTML(std::vector<TElem> elements);

	std::vector<TElem> readHTML();

	BirthDate strToDate(std::string date);

	std::string getFilePath();

	std::vector<TElem> getVector();
};

