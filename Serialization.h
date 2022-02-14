#pragma once
#include "Student.h"
#include "Operations.h"
#include <fstream>


class Serialization
{
	static void saveMarks(Student& student, const std::list<double>& grades);
	static void saveHelp(const Student& student, const std::string& filename);


	static void open(Student& student, const std::string& filename);
	static void save(const Student& student);
	static void saveAS(const Student& student);
	static void exit();
	static void close();
public:
	static void process(Student& student);
};