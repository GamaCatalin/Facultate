#pragma once
#include "HospitalDepartment.h"
#include <vector>

class Controller
{
private:
	std::vector<HospitalDepartment> hospitals;
	std::string filename;
	std::string boolToString(bool value);
public:
	void addDepartament(std::string name,std::string type,int doctors, int patients,int babies,double grade);

	std::vector<std::string> getAllDepartments();
	std::vector<std::string> getAllEfficientDepartments();
 
	void changeFileName(std::string file);
	bool writeToFile();
};

