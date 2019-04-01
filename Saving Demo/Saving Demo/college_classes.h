#pragma once
#include <string>
#include <vector>

class Student
{
public:
	Student(std::string, char, int);
	Student(std::string, std::string, std::string);		// constructor from a serialized string
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

std::string Student::Serialized()
{
	std::string serialString = "";

	serialString += "name:" + m_Name;
	serialString += ",gender:"; serialString += m_Gender;
	serialString += ",age:" + std::to_string(m_Age);

	return serialString;
}





class ClassRoom
{
public:
	ClassRoom(int, std::string, std::string);
	//ClassRoom(std::string, std::string, std::string, std::string);	// constructor from a serialized string
	ClassRoom(std::string);											// constructor from a serialized string
	std::string Serialized();										// serializer of Student class for saving

	void AddStudent(Student student);

private:
	int m_RoomNumber;
	std::string m_MorningInstructor;
	std::string m_AfternoonInstructor;

	std::vector<Student> m_Students;

};

ClassRoom::ClassRoom(int roomNum, std::string morningInstructor, std::string afternoonInstructor) :
	m_RoomNumber(roomNum),
	m_MorningInstructor(morningInstructor),
	m_AfternoonInstructor(afternoonInstructor)
{}

//ClassRoom::ClassRoom(std::string roomNum, std::string morningInstructor, std::string afternoonInstructor, std::string students) :
//	m_RoomNumber(std::stoi(roomNum)),
//	m_MorningInstructor(morningInstructor),
//	m_AfternoonInstructor(afternoonInstructor)
//{
//	// generate from students a series of student constructors that pass into the m_students vector
//}


ClassRoom::ClassRoom(std::string serialString)
{
	size_t iterFront = 0;
	size_t iterMiddle = 0;
	size_t iterEnd = 0;
	size_t iterCollectionFront = 0;
	size_t iterCollectionEnd = 0;
	size_t iterClassFront = 0;
	size_t iterClassEnd = 0;
	bool isCollection = false;
	bool isCollectionFinalPiece = false;

	int loopCounter = 0;

	while ((iterMiddle = serialString.find(":", iterMiddle)) != std::string::npos)
	{
		// begin parsing data to find individual values between ':' and ','  ... or ':' and '\n'
		++iterMiddle;
		iterEnd = serialString.find(",", iterMiddle);
		if (iterEnd > serialString.size())
		{
			iterEnd = serialString.find("\n", iterMiddle);
		}

		// check to see if a collection of data is present (vector)
		//std::string subString = serialString.substr(iterFront, iterEnd - iterFront);
		//if ((iterCollectionFront = subString.find("[", 0)) != std::string::npos)
		//{
		//	isCollection = true;
		//	iterCollectionEnd = subString.find("]", 0);
		//}
		std::string subString = serialString.substr(iterFront, iterMiddle);
		if ((iterCollectionFront = subString.find("[", 0)) == std::string::npos)
		{
			iterCollectionFront = iterCollectionEnd;
		}
		else if (serialString[iterCollectionFront] == '[')
		{
			isCollection = true;
			size_t emptyCollection = serialString.find("[]", iterCollectionFront, iterCollectionFront + 2);//TODO - QUESTION - will +1 work instead? perhaps make 3rd paramater 'iterEnd'
			if (iterCollectionFront == emptyCollection)
			{
				isCollectionFinalPiece = true;
			}
		}

		// if there is a '[' for a collectin, there has to be a ']'
		if (isCollection /*&& !isCollectionFinalPiece*/)//TODO - QUESTION: should the second if paramater be removed
		{
			iterCollectionEnd = serialString.find("]", iterMiddle, iterEnd);
			if (serialString[iterCollectionEnd] == ']')
			{
				isCollectionFinalPiece = true;
			}
		}

		if ((iterClassFront = subString.find("{", 0)) == std::string::npos)
		{
			iterClassFront = iterClassEnd;
		}
		else if (serialString[iterClassFront] == '{')
		{
			iterClassEnd = serialString.find("}", iterClassFront);
			// NOTE - create a tempClass that takes a substring from serialString between iterClassFront and iterClassEnd and call the class constructor accepting one string
			// NOTE - QUESTION: should a class have a deserializer constructor method of its own? (if a class exists with one one string data member, there could be a conflict error)
			iterEnd = serialString.find(",", iterClassEnd);
		}


		std::string tempStr = serialString.substr(iterMiddle, iterEnd - iterMiddle);
		switch (loopCounter)
		{
		case 0: m_RoomNumber = std::stoi(tempStr); break;
		case 1: m_MorningInstructor = tempStr; break;
		case 2: m_AfternoonInstructor = tempStr; break;
		case 3: break;
		default: break;
		}





		if (isCollectionFinalPiece)
		{
			isCollectionFinalPiece = false;
			isCollection = false;
		}
		if (!isCollection)
		{
			loopCounter++;
		}

		iterFront = iterMiddle = iterCollectionFront = iterCollectionEnd = iterClassFront = iterClassEnd = iterEnd + 1;
	}
	// generate from students a series of student constructors that pass into the m_students vector
}

std::string ClassRoom::Serialized()
{
	std::string serialString = "";

	serialString += "room:" + std::to_string(m_RoomNumber);		// a single variable
	serialString += ",morning:" + m_MorningInstructor;			// a single variable
	serialString += ",afternoon:" + m_AfternoonInstructor;		// a single variable

	{															// a vector of a class type of Student
		serialString += ",student[";	// [ to open array-vector

		if (m_Students.size() > 0)
		{
			for (rsize_t i = 0; i < m_Students.size(); ++i)
			{
				if (i == 0)
					serialString += "{";			// { to open the first class in the list
				else
					serialString += ",{";			// ,{ to open a class after the first class in the list

				serialString += m_Students[i].Serialized();			// class serialized data derived from class serializing member function

				serialString += "}";				// } to close a class
			}
		}
		serialString += "]";			// ] to close array-vector

	}

	return serialString;
}

void ClassRoom::AddStudent(Student student)
{
	m_Students.push_back(student);
}






// 