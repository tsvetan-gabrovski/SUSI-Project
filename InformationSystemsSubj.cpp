#include "InformationSystemsSubj.h"

InformationSystemsSubj::InformationSystemsSubj()
{
	this->setName("InformationSystems.txt");
}

void InformationSystemsSubj::createFIle()
{
	std::ofstream out(this->getNameSubject());
	out << "Course1\n" << "Algebra,Discret Structures,Differential and Integral calculus 1,Introduction to programming," <<
		"Geometry,Differential and Integral calculus2,Object-oriented programming,Fundamentals of information systems 1,Functional programming,\n";
	out << "Course2\n" << "English 1,Fundamentals of information systems 2,Computer architectures,Data structures," <<
		"English 2,Database,Computer networks,Applied OOP,Statistics,\n";
	out << "Course3\n" << "XML technologies,Database management systems,Based-knoledge systems,Specialized English,Team work," <<
		"Web technologies,Distributed It architectures,Analysis and proecting of information systems,\n";
	out << "Course4\n" << "e-bussiness,Project manegement,Findamentals of information security";

	out.close();
}
