#include "Surgery.h"

Surgery::Surgery(int nrPatients)
{
	this->numberOfPatients = nrPatients;

}

bool Surgery::isEfficient(int numberOfDoctors)
{
	if (numberOfDoctors * 2 <= this->numberOfPatients)
		return true;
	return false;
}

std::string Surgery::toString()
{
	std::string outputString;
	outputString = std::to_string(this->numberOfPatients);
	return outputString;
}
