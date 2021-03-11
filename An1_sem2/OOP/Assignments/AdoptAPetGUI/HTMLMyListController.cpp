#include "HTMLMyListController.h"

HTMLMyListController::HTMLMyListController(std::string filePath)
{
	this->fileName = filePath;
}

bool HTMLMyListController::saveElement(TElem element)
{
	//std::cout << "Save: " << element.getPrintable() << std::endl;
	std::vector<TElem> elements=this->readHTML();
	for (auto& current : elements) {
		if (current.getName() == element.getName()) {
		}
	}

	elements.push_back(element);
	this->writeHTML(elements);
	return true;
}

std::vector<TElem> HTMLMyListController::getElements()
{
	std::vector<TElem> elements = this->readHTML();
	system(this->fileName.c_str());
	return elements;
}

bool HTMLMyListController::setFileName(std::string fileName)
{
	this->fileName = fileName;
	return true;
}

void HTMLMyListController::writeHTML(std::vector<TElem> elements)
{
	std::fstream file;
	std::vector<TElem> elems = elements;
	file.open(this->fileName, std::ofstream::out);
	file.close();
	file.open(this->fileName, std::ios::out);

	file << "<!DOCTYPE html>\n<html>\n	<head>\n		<title>Pet Shop</title>\n	</head>\n	<body>\n		<table border=\"1\">\n		<tr>\n			<td>Name</td>\n			<td>Breed</td>\n			<td>Birth Date</td>\n			<td>Vaccinations Count</td>\n			<td>Photo</td>\n		</tr>\n";
	for (auto& current : elems) {
		//std::cout << "Write: " << current.getPrintable() << std::endl;
		file << "		<tr>\n			<td>" << current.getName() << "</td>\n";
		file << "			<td>" << current.getBreed() << "</td>\n";
		file << "			<td>" << current.getBirthDate().getString() << "</td>\n";
		file << "			<td>" << current.getVaccinationsCount() << "</td>\n";
		file << "			<td>" << current.getPhotograph() <<"</td>\n		</tr>\n";
	}

	file << "		</table>\n	</body>\n</html>";
}

std::vector<TElem> HTMLMyListController::readHTML()
{
	std::vector<TElem> elements;
	std::fstream file;
	std::string name = "", breed = "", date = "", vaccinations = "", photo = "", line = "", tempLine = "";
	int day,month,year,atributeCount=0;
	file.open(this->fileName);

	while (std::getline(file, line)) {
		if (line.find("</tr>") != std::string::npos)
			break;
	}
	
	while (std::getline(file, line)) {
		tempLine = line;
		if (tempLine.find("</tr>") != std::string::npos) {
			atributeCount = 0;
			name = "";
			breed = "";
			date = "";
			vaccinations = "";
			photo = "";
		}
		if (tempLine.find("<td>") != std::string::npos) {
			bool inCell = false;
			int start = 0, end = 0, size = 0;
			
			
			if (atributeCount == 4) {
				for (int i = 0; i < tempLine.size(); i++) {
					if (!inCell && tempLine[i] == '>') {
						start = i + 1;
						inCell = true;
					}
					if (inCell && tempLine[i] == '<') {
						end = i;
						break;
					}
				}
				size = end - start;
				photo = tempLine.substr(start, size);
				//std::cout << "Photo: " << photo << std::endl<<std::endl;
				atributeCount++;
				TElem element{ name,breed,this->strToDate(date),std::stoi(vaccinations),photo };
				elements.push_back(element);
			}
			if (atributeCount == 3) {
				for (int i = 0; i < tempLine.size(); i++) {
					if (!inCell && tempLine[i] == '>') {
						start = i + 1;
						inCell = true;
					}
					if (inCell && tempLine[i] == '<') {
						end = i;
						break;
					}
				}
				size = end - start;
				vaccinations = tempLine.substr(start, size);
				//std::cout << "Vac: " << vaccinations << std::endl;
				atributeCount++;
			}
			if (atributeCount == 2) {
				for (int i = 0; i < tempLine.size(); i++) {
					if (!inCell && tempLine[i] == '>') {
						start = i + 1;
						inCell = true;
					}
					if (inCell && tempLine[i] == '<') {
						end = i;
						break;
					}
				}
				size = end - start;
				date = tempLine.substr(start, size);
				//std::cout << "Date: " << date << std::endl;
				atributeCount++;
			}
			if (atributeCount == 1) {
				for (int i = 0; i < tempLine.size(); i++) {
					if (!inCell && tempLine[i] == '>') {
						start = i + 1;
						inCell = true;
					}
					if (inCell && tempLine[i] == '<') {
						end = i;
						break;
					}
				}
				size = end - start;
				breed = tempLine.substr(start, size);
				//std::cout << "Breed: " << breed << std::endl;
				atributeCount++;
			}
			if (atributeCount == 0) {
				for (int i = 0; i < tempLine.size(); i++) {
					if (!inCell && tempLine[i] == '>') {
						start = i + 1;
						inCell = true;
					}
					if (inCell && tempLine[i] == '<') {
						end = i;
						break;
					}
				}
				size = end - start;
				name = tempLine.substr(start, size);
				//std::cout << "Name: " << name << std::endl;
				atributeCount++;
			}
		}
	}

	file.close();


	return elements;
}

BirthDate HTMLMyListController::strToDate(std::string date)
{
	BirthDate finalDate;
	std::string day, month, year;
	int a = 0, b = 0,dateArgument=1,size=0;
	for (int i = 0; i < date.size(); i++) {
		if (dateArgument == 3 && i==date.size()-1) {
			b = i;
			size = b - a+1;
			year = date.substr(a, size);
			dateArgument++;
		}
		if (dateArgument == 2 && date[i] == '-') {
			b = i - 1;
			size = b - a+1;
			month = date.substr(a, size);
			a = i + 1;
			dateArgument++;
		}
		if (dateArgument == 1 && date[i] == '-') {
			b = i - 1;
			size = b - a+1;
			day = date.substr(a, size);
			a = i + 1;
			dateArgument++;
		}
	}
	finalDate.setDay(std::stoi(day));
	finalDate.setMonth(std::stoi(month));
	finalDate.setYear(std::stoi(year));

	return finalDate;
}

std::string HTMLMyListController::getFilePath()
{
	return this->fileName;
}

std::vector<TElem> HTMLMyListController::getVector()
{
	std::vector<TElem> elements = this->readHTML();

	return elements;
}
