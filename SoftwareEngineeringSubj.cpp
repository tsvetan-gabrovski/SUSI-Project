#include "SoftwareEngineeringSubj.h"

SoftwareEngineeringSubj::SoftwareEngineeringSubj()
{
	this->setName("SoftwareEngineering.txt");
}

void SoftwareEngineeringSubj::createFIle()
{
	std::ofstream out(this->getNameSubject());
	out << "Course1\n" << "English,Algebra,Discret Structures 1,Differential and Integral calculus1,Introduction to programming," <<
		"Geometry,Differential and Integral calculus2,Object-oriented programming,Discret Structures 1,Computer english,\n";
	out << "Course2\n" << "Computer architectures,Data structures and algorithms,Team work,Introduction to software engineering," <<
		"Database,Differential equations,Computer networks,Operating systems,Software architectures and software developing,\n";
	out << "Course3\n" << "XML technologies,Statistics,Quality manegement," <<
		"Web technologies,Software requarements analysis,Distributed software architectures,\n";
	out << "Course4\n" << "Data mining,Integration of software systems,Project management";
	out.close();
}
