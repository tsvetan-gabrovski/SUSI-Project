#include "Subjects.h"
#include "Student.h"


std::string Subjects::getNameSubject()
{
	return this->name;
}


void Subjects::setName(const std::string& name)
{
	this->name = name;
}

bool Subjects::fileExists(const std::string& filename)
{
	std::ifstream in;
	in.open(filename);
	return in.is_open();
}

std::list<std::string> Subjects::loadFirstCourse()
{
	std::list<std::string> firstCourse;
	if (!fileExists(this->getNameSubject()))
		createFIle();

	std::ifstream in;
	in.open(this->getNameSubject());
	if (!in.is_open())
	{
		std::cout << "Too bad buddy\n";
		return firstCourse;
	}

	std::string reader;
	std::getline(in, reader, '\n');
	char next = in.peek();
	while (next != '\n')
	{
		std::getline(in, reader, ',');
		firstCourse.push_back(reader);
		next = in.peek();
	}

	in.close();
	return firstCourse;

}

std::list<std::string> Subjects::loadSecondCourse()
{
	std::list<std::string> secondCourse = loadFirstCourse();
	std::string reader;

	std::ifstream in;
	in.open(this->getNameSubject());

	if (!in.is_open())
	{
		std::cout << "Too bad buddy\n";
		return secondCourse;
	}

	while (reader != "Course2")
	{
		std::getline(in, reader, '\n');
	}

	char next = in.peek();
	while (next != '\n')
	{
		std::getline(in, reader, ',');
		secondCourse.push_back(reader);
		next = in.peek();
	}

	in.close();
	return secondCourse;
}

std::list<std::string> Subjects::loadThirdCourse()
{

	std::list<std::string> thirdCourse = loadSecondCourse();
	std::string reader;

	std::ifstream in;
	in.open(this->getNameSubject());

	if (!in.is_open())
	{
		std::cout << "Too bad buddy\n";
		return thirdCourse;
	}

	while (reader != "Course3")
	{
		std::getline(in, reader, '\n');
	}

	char next = in.peek();
	while (next != '\n')
	{
		std::getline(in, reader, ',');
		thirdCourse.push_back(reader);
		next = in.peek();
	}

	in.close();
	return thirdCourse;
}

std::list<std::string> Subjects::loadFourthCourse()
{

	std::list<std::string> fourthCourse = loadThirdCourse();
	std::string reader;

	std::ifstream in;
	in.open(this->getNameSubject());

	if (!in.is_open())
	{
		std::cout << "Too bad buddy\n";
		return fourthCourse;
	}

	while (reader != "Course4")
	{
		std::getline(in, reader, '\n');
	}

	while (!in.eof())
	{
		std::getline(in, reader, ',');
		fourthCourse.push_back(reader);
	}

	in.close();
	return fourthCourse;
}

std::list<std::string> Subjects::processRequared(Student& student)
{
	std::list<std::string> subjects;
	try {
		if (student.getCourseNumber() == 1)
			subjects = this->loadFirstCourse();
		else if (student.getCourseNumber() == 2)
			subjects = this->loadSecondCourse();
		else if (student.getCourseNumber() == 3)
			subjects = this->loadThirdCourse();
		else if (student.getCourseNumber() == 4)
			subjects = this->loadFourthCourse();
		else
			throw "No rigth course of the student\n";
	}
	catch (...)
	{
		std::cerr << "Wrong student course-> '" << student.getCourseNumber() << "'\n";
		return subjects;
	}

	return subjects;
}


std::list<std::string> Subjects::process(Student& student)
{
	return this->processRequared(student);
}