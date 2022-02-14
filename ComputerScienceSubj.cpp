#include "ComputerScienceSubj.h"

ComputerScienceSubj::ComputerScienceSubj()
{
	this->setName("ComputerScience.txt");
}

void ComputerScienceSubj::createFIle()
{
	std::ofstream out(this->getNameSubject());
	out << "Course1\n" << "Algebra,Discret Structures,Differential and Integral calculus1,Introduction to programming," <<
		"Geometry,Differential and Integral calculus 2,Object-oriented programming,Languages and computability,\n";
	out << "Course2\n" << "Computer English,Computer architectures,Data structures,Fundamentals of computer graphics,Functional programming," <<
		"Algebra2,Design and analysis of alhorithms,Computer networks,Operatins research,Operating systems,\n";
	out << "Course3\n" << "Logical programming,Network programming,System programming,Numerical analysis," <<
		"Database,Probability and statistics,Parallel processing systems,Software technologies,\n";
	out << "Course4\n" << "Web Technologies,Artificial intelligence,Software architectures";

	out.close();
}