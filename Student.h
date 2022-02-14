#pragma once
#include <iostream>
#include <string>
#include <list>
#include <regex>
#include <exception>

class Subjects;

class Student
{
private:
	class CourseInfo
	{
	private:
		std::string name;
		size_t course;
		size_t group;
	public:
		CourseInfo(const std::string& name,const size_t& course,const size_t& group);
		CourseInfo();

		void setName(const std::string& name);
		void setCourse(const size_t& course);
		void setGroup(const size_t& group);

		std::string getName()const;
		size_t getCourse()const;
		size_t getGroup()const;

		friend std::ostream& operator<<(std::ostream& out, const CourseInfo& courseInfo);
	};
	enum status { active, inactive, graduated };


	CourseInfo courseInfo;
	std::list<double> grades;
	status status;
	std::string name;
	std::string facultyNumber;


public:
	Student();

	void setName(const std::string& name);
	void setStatus(const std::string& status);
	void setCourseName(const std::string& name);
	void setCourseNumber(const size_t& course);
	void setCourseGroup(const size_t& group);
	void setFacultyNumber(const std::string& fn);
	void setGrades();
	void setGrades(const std::list<double>& grades);

	std::string getName()const;
	std::string getStatus()const;
	std::string getCourseName()const;
	size_t getCourseNumber()const;
	size_t getCourseGroup()const;
	std::string getFacultyNumber()const;
	std::list<double> getGrades()const;


	friend std::ostream& operator<<(std::ostream& out, const Student::CourseInfo& courseInfo);
	friend std::ostream& operator<<(std::ostream& out, const Student& student);
	
	std::list<std::string> accept(Subjects* subject);
	
	
};