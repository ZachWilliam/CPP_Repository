#include <iostream>
#include <string>
#include <vector>
#include "college_classes.h"

#include <conio.h>
#include <regex>

using namespace std;

int main()
{
	ClassRoom myClassRm(11, "Paolo", "no one");
	myClassRm.AddStudent(Student("Sebastian", 'M', 38));
	myClassRm.AddStudent(Student("Bobbetta", "F", "21"));
	myClassRm.AddStudent(Student("Charlie", "?", "24"));
	string serializedClassRoom = myClassRm.Serialized();

	cout << serializedClassRoom << endl;
	_getch();

	ClassRoom myClassTwo(serializedClassRoom);
	cout << myClassTwo.Serialized() << endl << endl;
	_getch();

	ClassRoom classX(1, "Mr. A", "Mr. B");
	classX.AddStudent(Student("Dave", "M", "20"));
	Campus triOS_London("CA", "ON", "London", classX, 2019);
	cout << triOS_London.Serialized() << endl;
	_getch();

	Campus triOS_Lnd(triOS_London.Serialized());
	//cout << triOS_Lnd.Serialized() << endl << endl;

	_getch();
	return 0;
}