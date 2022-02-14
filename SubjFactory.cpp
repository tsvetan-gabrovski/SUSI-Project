#include "SubjFactory.h"

Subjects* SubjFactory::make(const std::string type)
{
	std::regex informationSystemsPattern("[Ii]nformation\\s[Ss]ystems");
	std::regex softwareEngineeringPattern("[Ss]oftware\\s[Ee]ngineering");
	std::regex computerSciencePattern("[Cc]omputer\\s[Ss]cience");
	std::regex informaticPattern("[Ii]nformatic");

	if (std::regex_match(type, informationSystemsPattern))
		return new InformationSystemsSubj();
	else if (std::regex_match(type, softwareEngineeringPattern))
		return new SoftwareEngineeringSubj();
	else if (std::regex_match(type, computerSciencePattern))
		return new ComputerScienceSubj();
	else if (std::regex_match(type, informaticPattern))
		return new InformaticSubj();
	else
		throw std::invalid_argument("Unknown subject exeption\n");

}