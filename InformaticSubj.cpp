#include "InformaticSubj.h"

InformaticSubj::InformaticSubj()
{
	this->setName("Informatics.txt");
}

void InformaticSubj::createFIle()
{
	std::ofstream out(this->getNameSubject());
	out << "Course1\n" << "Analytical Geometry,Lineal Algebra,Differential and Integral calculus1,Introduction to programming," <<
		"Heigher Algebra,Discret Structures,Differential and Integral calculus2,Object-oriented programming,\n";
	out << "Course2\n"<< "English 1,Differential equations,Languagesand computability,Operations research,Data structures," <<
		"English 2,Design and analysis of alhorithms,Computer architectures,Logical programming,Methematical methods,\n";
	out << "Course3\n" << "Computer networks,Operating systems,Probability and statistics,Functional programming," <<
		"Database,Geometry,Artificial intelligence,Network programming,Semantics of programming languages,\n";
	out << "Course4\n" << "Computer Graphics,Software technologies,Numerical methods for differential equations";

	out.close();
}
