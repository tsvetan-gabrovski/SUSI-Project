#include "Operations.h"
#include "SubjFactory.h"

void Operations::changeCourse(Student& student)
{
	Subjects* sub = SubjFactory::make(student.getCourseName());
	std::list<std::string> subjects = student.accept(sub);

	if (student.getGrades().size() < subjects.size())
	{
		std::cout << "Not allowed to change the course: More than two exams with mark2\n";
		return;
	}

	size_t counter = 0;
	for (const double& mark : student.getGrades())
	{
		if (mark < 3.0)
			++counter;
		if (counter > 2)
		{
			std::cout << "Not allowed to change the course: More than two exams with mark 2\n";
			return;
		}
	}

	advance(student);
}

void Operations::changeGroup(Student& student)
{
	std::cout << "Enter new group number: ";
	size_t group;
	std::cin >> group;
	student.setCourseGroup(group);
}


void Operations::change(Student& student)
{
	std::cout << "Choose option: ";
	std::cout << "To change the course press '1'\nTo change the group press '2'\n";
	std::size_t input;
	std::cin >> input;
	
	while (!std::cin && input < 3)
	{
		std::cout << "Wrong choise, please enter again: ";
		std::cin >> input;
	}

	std::cin.get();

	if (input == 1)
	{
		changeCourse(student);
		return;
	}

	changeGroup(student);
}

void Operations::enroll(Student& student)
{
	std::string name, fn, courseName, group;
	
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	
	std::cout << "Enter course name: ";
	std::getline(std::cin, courseName);

	std::cout << "Enter faculty number: ";
	std::getline(std::cin, fn);

	std::cout << "Enter group: ";
	std::getline(std::cin, group);

	std::regex groupPattern("[0-9]");
	if (!std::regex_match(group, groupPattern))
		throw std::invalid_argument("group");


	try {
		student.setName(name);
		student.setCourseName(courseName);
		student.setFacultyNumber(fn);
		student.setCourseGroup(std::stoi(group));
	}
	catch (...)
	{
		throw std::invalid_argument("Error occured during 'enroll' method\n");
	}
	
}

void Operations::advance(Student& student)
{
	size_t course = student.getCourseNumber();
	
	if (course < 4)
		student.setCourseNumber(++course);
}

void Operations::graduate(Student& student)
{
	if (student.getCourseNumber() != 4)
	{
		std::cout << "\nNot allowed to graduate!\n";
		return;
	}
	for (const double& mark : student.getGrades())
	{
		if (mark < 3.0)
		{
			std::cout << "Unable to graduate\n";
			return;
		}
	}

	student.setStatus("graduated");
}

void Operations::interrupt(Student& student)
{
	student.setStatus("inactive");
}

void Operations::resume(Student& student)
{
	student.setStatus("active");
}

void Operations::print(Student& student)
{

	std::list<std::string> subjects;

	Subjects* sub = SubjFactory::make(student.getCourseName());
	subjects = student.accept(sub);
	
	if (subjects.size() != student.getGrades().size())
		throw "size difference in subjects and grades\n";

	std::cout << student.getName() << "\n" << student.getCourseName() << " " << student.getFacultyNumber() << " "
		<< student.getCourseNumber() << " " << student.getCourseGroup() << " " << student.getStatus() << "\n";

	std::list<std::string>::iterator it = subjects.begin();
	for (const double& grade : student.getGrades())
	{
		std::cout << *it << " " << grade << "\n";
		it++;
	}
}

void Operations::addGrades(Student& student)
{
	student.setGrades();
}
