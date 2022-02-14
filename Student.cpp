#include "Student.h"
#include "SubjFactory.h"

//COURSEINFO CONSTRUCTORS
Student::CourseInfo::CourseInfo() : course(1), group(1) {}

Student::CourseInfo::CourseInfo(const std::string& name,const size_t& course,const size_t& group)
{
	this->setName(name);
	this->setCourse(course);
	this->setGroup(group);
}

//COURSEINFO SETTERS
void Student::CourseInfo::setName(const std::string& name)
{
	this->name = name;
}

void Student::CourseInfo::setCourse(const size_t& course)
{
	this->course = course;
}

void Student::CourseInfo::setGroup(const size_t& group)
{
	this->group = group;
}

//COURSEINFO GETTERS
std::string Student::CourseInfo::getName()const
{
	return this->name;
}

size_t Student::CourseInfo::getCourse()const
{
	return this->course;
}
size_t Student::CourseInfo::getGroup()const
{
	return this->group;
}

std::ostream& operator<<(std::ostream& out, const Student::CourseInfo& courseInfo)
{
	out << "course info: " << courseInfo.getName() << " " <<
		courseInfo.getCourse() << " " << courseInfo.getGroup();
	return out;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.getName() << "\n" << student.courseInfo << "\n";
	out << student.getStatus() << " " << student.getFacultyNumber() << "\n";

	out << "Marks:\n";
	std::list<double> grades = student.getGrades();
	for (const double& grade : grades)
	{
		out << grade << " ";
	}
	return out;
}

Student::Student()
{
	this->courseInfo.setCourse(1);
	this->courseInfo.setGroup(1);
	this->status = active;
}

//STUDENT SETTERS
void Student::setName(const std::string& name)
{
	std::regex namePattern("([A-Z][a-z]+\\s)+([A-Z][a-z]+)");
	try {
		if (!std::regex_match(name, namePattern))
			throw std::invalid_argument(name);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "regerx error cought: " << e.what() << " at function 'setName' of class Student\n";
		return;
	}

	this->name = name;
}

void Student::setStatus(const std::string& status)
{
	std::regex statusPattern("[Aa]ctive|[Ii]nactive|[Gg]raduated");
	try {
		if (!std::regex_match(status, statusPattern))
			throw std::invalid_argument(status);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "regerx error cought: " << e.what() << " at function 'setStatus' of class Student\n";
		return;
	}

	if (status == "Active" || status == "active")
		this->status = active;
	else if (status == "Inactive" || status == "inactive")
		this->status = inactive;
	else
		this->status = graduated;

}

void Student::setCourseName(const std::string& name)
{
	std::regex courseNamePattern("[Ii]nformation\\s[Ss]ystems|[Ss]oftware\\s[Ee]ngineering|[Cc]omputer\\s[Ss]cience|[Ii]nformatic");
	try {
		if (!std::regex_match(name, courseNamePattern))
			throw std::invalid_argument(name);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "invalid argument error cought: " << e.what() << " at function 'setStatus' of class Student\n";
		return;
	}


	this->courseInfo.setName(name);
}

void Student::setCourseNumber(const size_t& course)
{
	try {
		if (course > 5 || course < 0)
			throw std::invalid_argument("course number");
	}
	catch (const std::invalid_argument& ex)
	{
		std::cerr << "Invalid argument error cought: " << ex.what() << " at function 'setCourseNumber'\n";
		return;
	}

	this->courseInfo.setCourse(course);
}

void Student::setCourseGroup(const size_t& group)
{
	try {
		if (group > 5 || group < 0)
			throw std::invalid_argument("group");
	}
	catch (const std::invalid_argument& ex)
	{
		std::cerr << "Invalid argument cought: " << ex.what() << " at function 'setCourseGroup'\n";
		return;
	}

	this->courseInfo.setGroup(group);
}

void Student::setFacultyNumber(const std::string& fn)
{
	std::regex fnPattern("[0-9]{5}");
	try {
		if (!std::regex_match(fn, fnPattern))
			throw std::invalid_argument(fn);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid argument cought: " << e.what() << "at function 'setFacultyNumber'\n\n";
		return;
	}

	this->facultyNumber = fn;
}

void Student::setGrades()
{
	std::list<std::string> subjects;

	Subjects* sub = SubjFactory::make(getCourseName());
	subjects = accept(sub);

	if (this->grades.size() == subjects.size())
	{
		std::cout << "\nAll grades already added\n";
		return;
	}

	std::string grade;
	std::cout << "Enter marks:\n";
	std::regex gradesPattern("[2-6](\\.[0-9][0-9]?)?");

	size_t currSize = 0;
	for (std::string& subj : subjects)
	{
		if (currSize != this->grades.size())
		{
			currSize++;
			continue;
		}

		std::cout << subj << ": ";
		std::getline(std::cin, grade);
		while ( !std::regex_match(grade, gradesPattern) )
		{
			std::cout << "\nWrong grade, enter again\n";
			std::cout << subj << ": ";
			std::getline(std::cin, grade);
		}

		grades.push_back(std::stod(grade));
		currSize++;
	}

	delete sub;
}

void Student::setGrades(const std::list<double>& grades)
{
	this->grades = grades;
}


//STUDENT GETTERS

std::string Student::getName()const
{
	return this->name;
}

std::string Student::getStatus()const
{
	if (status == 0)
		return "active";
	else if (status == 1)
		return "inactive";

	return "graduated";
}

std::string Student::getCourseName()const
{
	return this->courseInfo.getName();
}

std::string Student::getFacultyNumber()const
{
	return this->facultyNumber;
}

size_t Student::getCourseNumber()const
{
	return this->courseInfo.getCourse();
}

size_t Student::getCourseGroup()const
{
	return this->courseInfo.getGroup();
}

std::list<std::string> Student::accept(Subjects* subject)
{
	return subject->process(*this);
}


std::list<double> Student::getGrades()const
{
	return this->grades;
}