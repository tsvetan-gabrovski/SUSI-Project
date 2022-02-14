#pragma once
#include "Subjects.h"
#include "ComputerScienceSubj.h"
#include "InformaticSubj.h"
#include "InformationSystemsSubj.h"
#include "SoftwareEngineeringSubj.h"
#include <regex>

class SubjFactory
{
public:
	static Subjects* make(const std::string type);
};

