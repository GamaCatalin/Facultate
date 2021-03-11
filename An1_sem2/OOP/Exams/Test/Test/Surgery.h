#pragma once
#include <string>
class Surgery
{
private:
	int numberOfPatients;
public:
	Surgery(int nrPatients = 0);

	bool isEfficient(int numberOfDoctors);
	std::string toString();
};

