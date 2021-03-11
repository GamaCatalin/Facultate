#include "HospitalDepartment.h"

HospitalDepartment::HospitalDepartment(std::string name, std::string type, int nrDoctors, NeonatalUnit newbornUnit, Surgery surgeryUnit)
{
	this->hospitalName = name;
	this->hospitalType = type;
	this->numberOfDoctors = nrDoctors;
	this->neonatalUnit = newbornUnit;
	this->surgery = surgeryUnit;
}

bool HospitalDepartment::isEfficient()
{
	if (this->hospitalType == "Neonatal Unit")
		return this->neonatalUnit.isEfficient();
	if (this->hospitalType == "Surgery")
		return this->surgery.isEfficient(this->numberOfDoctors);
	return false;
}

std::string HospitalDepartment::toString()
{
	std::string outputString;
	outputString = this->hospitalName + "," + this->hospitalType + ",";
	if (this->hospitalType == "Neonatal Unit")
		outputString += this->neonatalUnit.toString();
	if (this->hospitalType == "Surgery")
		outputString += this->surgery.toString();
	return outputString;
}
