#include "Serialization.h"
#include "Subjects.h"

void Serialization::saveMarks(Student& student, const std::list<double>& grades)
{
	std::string filename = student.getFacultyNumber() + "Marks.txt";
	std::ofstream out(filename);
	
	for (const double& grade : grades)
		out << grade << "\n";
	out.close();
}

void Serialization::saveHelp(const Student& student, const std::string& filename)
{
	std::ofstream save(filename);
	
	save << student.getName() << "," << student.getFacultyNumber() << "," << student.getCourseName() << "," << student.getStatus() << " "
		<< student.getCourseGroup() << " " << student.getCourseNumber() << " ";

	double last = 0;
	size_t count = 1;
	for (const double& grade : student.getGrades())
	{
		if (count == student.getGrades().size())
		{
			last = grade;
			break;
		}
		save << grade << " ";
		++count;
	}

	save << last;
	save.close();
}

void Serialization::open(Student& student, const std::string& filename)
{
	std::ifstream in;
	in.open(filename);
	if (!in.is_open())
		throw std::ios::failure("Unable to open file");
	

	std::string name, fn, courseName, status;
	size_t courseGroup, courseNumber;
	std::list<double> grades;

	std::getline(in, name, ',');
	std::getline(in, fn, ',');
	std::getline(in, courseName, ',');
	in >> status;
	in >> courseGroup;
	in >> courseNumber;
	
	double currGrade;
	while (!in.eof())
	{
		in >> currGrade;
		grades.push_back(currGrade);
	}

	in.close();

	
	student.setName(name);
	student.setFacultyNumber(fn);
	student.setCourseName(courseName);
	student.setStatus(status);
	student.setCourseGroup(courseGroup);
	student.setCourseNumber(courseNumber);
	student.setGrades(grades);
}

void Serialization::save(const Student& student)
{
	std::string filename = "FN" + student.getFacultyNumber();

	saveHelp(student, filename);
}

void Serialization::saveAS(const Student& student)
{
	std::string filename;
	std::cout << "\nEnter filename: ";
	std::cin >> filename;

	std::regex filenamePattern("[A-Z|a-z]+.txt");

	if (!std::regex_match(filename, filenamePattern))
		throw std::invalid_argument(filename);

	saveHelp(student, filename);
}

void Serialization::exit()
{
	std::cout << "Exiting program...\n";
}

void Serialization::close()
{
	std::cout << "Closing the program...\n";
}

void Serialization::process(Student& student)
{
	std::cout << "\n\n";
	std::cout << "ENTER COMMAND\n";
	std::cout << "To open a file press '1'\nTo save press '2'\nTo save as press '3'\nFor exit press '4'\nTo close press'5'\n";
	std::string choise;
	std::getline(std::cin, choise);

	while (choise != "1" && choise != "2" && choise != "3" && choise != "4" && choise != "5")
	{
		std::cout << "Invalid input,please enter again: ";
		std::getline(std::cin, choise);
	}

	if (choise == "1")
	{
		std::cout << "Enter name of the file\n";
		std::string filename;
		std::getline(std::cin, filename);

		try {
			open(student, filename);
		}
		catch (...) 
		{
			throw std::ios::failure("Error occured during method 'open'\n\n");
		}

	}
	else if (choise == "2")
		save(student);
	else if (choise == "3")
	{
		try {
			saveAS(student);
		}
		catch (...)
		{
			throw std::invalid_argument("Error ocuured during method 'saveAS'\n");
		}
		
	}
	else if (choise == "4")
		exit();
	else
		close();
}