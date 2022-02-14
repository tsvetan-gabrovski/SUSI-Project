#pragma once
#include "Student.h"

class Operations
{
private:
	static void changeCourse(Student& student);
	static void changeGroup(Student& student);
public:
	static void change(Student& student);
	static void enroll(Student& student);
	static void advance(Student& student);
	static void graduate(Student& student);
	static void interrupt(Student& student);
	static void resume(Student& student);
	static void print(Student& student);
	static void addGrades(Student& student);
};