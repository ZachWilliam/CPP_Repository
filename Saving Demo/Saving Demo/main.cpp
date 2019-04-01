#include <iostream>
#include <string>
#include <vector>
#include "college_classes.h"//m_RoomNumber = serialString.substr(iterMiddle, iterEnd - iterMiddle); 

#include <conio.h>
#include <regex>

using namespace std;

//class College
//{
//public:
//	College();
//	~College();
//	//Save();
//
//private:
//	string m_Name;
//	string campus;
//
//	Serialize();
//	
//};

int main()
{
	ClassRoom myClassRm(11, "Paolo", "no one");
	myClassRm.AddStudent(Student("Sebastian", 'M', 38));
	myClassRm.AddStudent(Student("Bobbettea", "F", "21"));
	string serializedClassRoom = myClassRm.Serialized() + "\n";
	cout << serializedClassRoom << endl;
	_getch();



	//cout << serializedClassRoom.find("name",75);




	size_t iterFront = 0;
	size_t iterEnd = 0;

	//while ((iterFront = serializedClassRoom.find(":", iterFront)) != string::npos )
	//{
	//	iterEnd = serializedClassRoom.find(",", ++iterFront);
	//	string temp = serializedClassRoom.substr(iterFront, iterEnd-iterFront);
	//	cout << temp << " ";
	//}




	//cout << endl << serializedClassRoom.size() << endl;

	{
	//size_t iterX = 0;
	//while ((iterFront = serializedClassRoom.find(":", iterFront)) != string::npos)
	//{
	//	++iterFront;
	//	iterEnd = serializedClassRoom.find(",", iterFront);
	//	if (iterEnd > serializedClassRoom.size())
	//	{
	//		iterEnd = serializedClassRoom.find("\n", iterFront);
	//	}

	//	size_t iterArrayFront = 0;
	//	string mySubString = serializedClassRoom.substr(iterX, iterEnd - iterX);
	//	//cout << mySubString.find("[", iterArrayFront);
	//	if ((iterArrayFront = mySubString.find("[", 0)) != string::npos)
	//	{
	//		cout << endl << "Array/Vector found" << endl;
	//	}

	//	string temp = serializedClassRoom.substr(iterFront, iterEnd - iterFront);
	//	cout << temp << " ";

	//	iterX = iterEnd;
	//}
	}

	ClassRoom myClassTwo(serializedClassRoom);
	cout << myClassTwo.Serialized() << endl;

	_getch();
	return 0;
}