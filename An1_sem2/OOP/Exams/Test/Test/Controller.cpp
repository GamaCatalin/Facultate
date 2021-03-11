#include "Controller.h"


std::string Controller::boolToString(bool value)
{
	if (value)
		return "true";
	return "false";
}

void Controller::addDepartament(std::string name, std::string type, int doctors, int patients, int babies, double grade)
{
	HospitalDepartment tempDepartament;
	Surgery tempSurgery;
	NeonatalUnit tempNewborn;
	if (type == "Surgery") {
		tempSurgery = Surgery{ patients };
	}
	else {
		tempNewborn = NeonatalUnit{ patients, babies,grade };
	}
	tempDepartament = HospitalDepartment{ name,type,doctors,tempNewborn,tempSurgery };
	this->hospitals.push_back(tempDepartament);
}

std::vector<std::string> Controller::getAllDepartments()
{
	std::vector<std::string> tempVector;

	for (int i = 0; i < this->hospitals.size(); i++) {
		tempVector.push_back(this->hospitals.at(i).toString());
	}
	return tempVector;
}

std::vector<std::string> Controller::getAllEfficientDepartments()
{
	std::vector<std::string> tempVector;

	for (int i = 0; i < this->hospitals.size(); i++) {
		tempVector.push_back(this->hospitals.at(i).toString()+","+this->boolToString(this->hospitals.at(i).isEfficient()));
	}
	return tempVector;
}

void Controller::changeFileName(std::string file)
{
	this->filename = file;
}

bool Controller::writeToFile()
{
	return false;
}
