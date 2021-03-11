#pragma once
#include "NeonatalUnit.h"
#include "Surgery.h"


class HospitalDepartment
{
friend class NeonatalUnit;
friend class Surgery;
private:
	std::string hospitalName;
	std::string hospitalType;
	int numberOfDoctors;
	NeonatalUnit neonatalUnit;
	Surgery surgery;
public:
	HospitalDepartment(std::string name = "", std::string type = "", int nrDoctors = 0, NeonatalUnit newbornUnit = NeonatalUnit{ 0,0,0 }, Surgery surgeryUnit = Surgery{0});

	bool isEfficient();
	std::string toString();
};

