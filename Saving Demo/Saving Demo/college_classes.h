#pragma once
#include <string>
#include <vector>

#include "DeserializeHelper.h"

class Student
{
public:
	Student(std::string, char, int);					// constructor from a series of defined value types
	Student(std::string, std::string, std::string);		// constructor from a series of only strings
	Student(std::string);								// constructor from a serialized string

	std::string Serialized();							// serializer of Student class for saving

private:
	std::string m_Name;
	char m_Gender;
	int m_Age;

};

Student::Student(std::string name, char gender, int age) :
	m_Name(name),
	m_Gender(gender),
	m_Age(age)
{}

Student::Student(std::string name, std::string gender, std::string age) :
	m_Name(name),
	m_Gender(gender[0]),
	m_Age(std::stoi(age))
{}

Student::Student(std::string serialString)
{
	DeserializeHelper deserHelper(serialString);

	while (deserHelper.isActive)
	{
		deserHelper.NextParse();

		switch (deserHelper.ParseCount())
		{
		case 0: m_Name = deserHelper.ParsedValue(); break;
		case 1: m_Gender = (deserHelper.ParsedValue())[0]; break;
		case 2: m_Age = std::stoi(deserHelper.ParsedValue()); break;
		}
	}
}

std::string Student::Serialized()
{
	std::string serialString = "";

	serialString += "name:" + m_Name + ",";
	serialString += "gender:"; serialString += m_Gender; serialString += ",";
	serialString += "age:" + std::to_string(m_Age) + ",";

	return serialString;
}





class ClassRoom
{
public:
	ClassRoom();
	ClassRoom(int, std::string, std::string);
	ClassRoom(std::string);											// constructor from a serialized string
	std::string Serialized();										// serializer of Student class for saving

	void AddStudent(Student student);

private:
	int m_RoomNumber;
	std::string m_MorningInstructor;
	std::string m_AfternoonInstructor;

	std::vector<Student> m_Students;

};

ClassRoom::ClassRoom()
{}
// Constructor with manualy passed values
ClassRoom::ClassRoom(int roomNum, std::string morningInstructor, std::string afternoonInstructor) :
	m_RoomNumber(roomNum),
	m_MorningInstructor(morningInstructor),
	m_AfternoonInstructor(afternoonInstructor)
{}

// Deserializer Constructor - accepts a 'one-line' serialized string filled with data
ClassRoom::ClassRoom(std::string serialString)
{
	DeserializeHelper deserHelper(serialString);

	while (deserHelper.isActive)
	{
		deserHelper.NextParse();

		switch (deserHelper.ParseCount())
		{
		case 0: m_RoomNumber = std::stoi(deserHelper.ParsedValue()); break;
		case 1: m_MorningInstructor = deserHelper.ParsedValue(); break;
		case 2: m_AfternoonInstructor = deserHelper.ParsedValue(); break;
		case 3: m_Students.push_back(Student(deserHelper.ParsedClassSString())); break;
		default: break;
		}
	}
}

// serializer
std::string ClassRoom::Serialized()
{
	std::string serialString = "";

	serialString += "room:" + std::to_string(m_RoomNumber) + ",";	// a single variable
	serialString += "morning:" + m_MorningInstructor + ",";			// a single variable
	serialString += "afternoon:" + m_AfternoonInstructor + ",";		// a single variable

	{										// a collection of a class type of Student
		serialString += "students[";

		if (m_Students.size() > 0)
		{
			for (rsize_t i = 0; i < m_Students.size(); ++i)
			{
				serialString += "{";
				serialString += m_Students[i].Serialized();		// class serialized data derived from class serializing member function
				serialString += "},";
			}
		}
		serialString += "],";
	}

	return serialString;
}

void ClassRoom::AddStudent(Student student)
{
	m_Students.push_back(student);
}





class Campus
{
public:
	Campus();
	~Campus();
	Campus(std::string, std::string, std::string, ClassRoom, int);
	Campus(std::string serialString);

	std::string Serialized();

private:
	std::string m_country;
	std::string m_province;
	std::string m_city;
	ClassRoom m_classVGDD;
	int m_classStartYear;

};

Campus::Campus()
{
}

Campus::~Campus()
{
}


Campus::Campus(std::string country, std::string prov, std::string city, ClassRoom classVGDD, int startYear) :
	m_country(country),
	m_province(prov),
	m_city(city),
	m_classVGDD(classVGDD),
	m_classStartYear(startYear)
{}

Campus::Campus(std::string serialString)
{
	DeserializeHelper deserHelper(serialString);

	while(deserHelper.isActive)
	{
		deserHelper.NextParse();

		switch (deserHelper.ParseCount())
		{
		case 0: m_country = deserHelper.ParsedValue(); break;
		case 1: m_province = deserHelper.ParsedValue(); break;
		case 2: m_city = deserHelper.ParsedValue(); break;
		case 3: m_classVGDD = ClassRoom(deserHelper.ParsedClassSString()); break;
		case 4: m_classStartYear = std::stoi(deserHelper.ParsedValue()); break;
		default: break;
		}
	}
}

std::string Campus::Serialized()
{
	std::string serialString = "";

	serialString += "country:" + m_country + ",";
	serialString += "province:" + m_province + ",";
	serialString += "city:" + m_city + ",";
	serialString += "class room{" + m_classVGDD.Serialized() + "},";
	serialString += "year:" + std::to_string(m_classStartYear) + ",";

	return serialString;
}