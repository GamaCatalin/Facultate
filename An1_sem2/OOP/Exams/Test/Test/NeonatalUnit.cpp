#include "NeonatalUnit.h"

NeonatalUnit::NeonatalUnit(int nrMothers, int nrNewborns, double averageGrade)
{
	this->averageGrade = averageGrade;
	this->numberOfMothers = nrMothers;
	this->numberOfNewborns = nrNewborns;
}

bool NeonatalUnit::isEfficient()
{
	if (this->averageGrade > 8.5 && this->numberOfNewborns > this->numberOfMothers)
		return true;
	return false;
}

std::string NeonatalUnit::toString()
{
	std::string outputString;
	outputString = std::to_string(this->numberOfMothers) + "," + std::to_string(this->numberOfNewborns) + "," + std::to_string(this->averageGrade);
	return outputString;
}
