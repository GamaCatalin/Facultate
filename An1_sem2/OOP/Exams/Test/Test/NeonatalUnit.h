#pragma once
#include <string>

class NeonatalUnit
{
private:
	int numberOfMothers;
	int numberOfNewborns;
	double averageGrade;

public:
	NeonatalUnit( int nrMothers = 0, int nrNewborns = 0, double averageGrade = 0);

	bool isEfficient();
	std::string toString();
};

