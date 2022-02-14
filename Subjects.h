#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>

class Student;

class Subjects
{
private:
	std::string name;

protected:
	virtual void createFIle() = 0;
	std::string getNameSubject();
	void setName(const std::string& name);

	bool fileExists(const std::string& filename);

	std::list<std::string> loadFirstCourse();
	std::list<std::string> loadSecondCourse();
	std::list<std::string> loadThirdCourse();
	std::list<std::string> loadFourthCourse();

	std::list<std::string> processRequared(Student& student);
public:
	std::list<std::string> process(Student& student);
};

