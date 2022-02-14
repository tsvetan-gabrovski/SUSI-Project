#include <iostream>

#include "Student.h"
#include "ComputerScienceSubj.h"
#include "InformaticSubj.h"
#include "Subjects.h"
#include "SoftwareEngineeringSubj.h"
#include "InformationSystemsSubj.h"
#include "Serialization.h"
#include "Operations.h"
#include "SubjFactory.h"

int main()
{

	Student student1;
	
	try {
		student1.setName("Stoyan Iordanov Gabrovski");
		student1.setCourseName("Software Engineering");
		student1.setCourseNumber(3);
		student1.setFacultyNumber("62401");
		student1.setStatus("Active");
		student1.setCourseGroup(2);
		Operations::addGrades(student1);
	}
	catch (...)
	{
		std::cerr << "\nCatched error in student info block\n";
		return 0;
	}


	
	try {
		Operations::addGrades(student1);
	}
	catch (...)
	{
		std::cerr << "\nError during addding grades\n";
		return 0;
	}

	try {
		
		Serialization::process(student1);
	}
	catch (...)
	{
		std::cerr << "\nError ocuured during Serialization\n\n";
		return 0;
	}
	

	Operations::print(student1);
	
	
	return 0;
}