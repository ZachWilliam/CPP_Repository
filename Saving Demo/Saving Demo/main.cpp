#include <iostream>
#include <string>
#include <vector>
#include "college_classes.h"
#include "ConvertHelper.h"

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
	//_getch();

	ClassRoom myClassTwo(serializedClassRoom);
	cout << myClassTwo.Serialized() << endl << endl;
	//_getch();

	ClassRoom classX(1, "Mr. A", "Mr. B");
	classX.AddStudent(Student("Dave", "M", "20"));
	Campus triOS_London("CA", "ON", "London", classX, 2019);
	cout << triOS_London.Serialized() << endl;
	//_getch();

	Campus triOS_Lnd(triOS_London.Serialized());
	cout << triOS_Lnd.Serialized() << endl << endl;

	bool btrue = true;
	bool bfalse = true;
	//bfalse = stoi("0");
	bfalse = stob("0");

	cout << "btrue: " << btrue << "    bfalse: " << bfalse << endl;
	string bString = "" + btos(btrue);
	bString += " " + btos(bfalse);
	cout << "bString: " << bString;

	cout << endl << endl << endl;

	enum eTypeX { aaa = 0, bbb, ccc, ddd };
	cout << "eTypeX: " << eTypeX::aaa << endl;

	//string my_eTypeStringX = to_string((int)eTypeX::ccc);
	string my_eTypeStringX = etos((int)eTypeX::ccc);
	cout << "my_eTypeStringX: " << my_eTypeStringX << endl;

	//eTypeX myEnumX = (eTypeX)3;
	eTypeX myEnumX = (eTypeX)stoi("3");
	cout << "myEnumX: " << myEnumX << endl;	

	//my_eTypeX += to_string((int)myEnumX);
	my_eTypeStringX += etos((int)myEnumX);
	cout << "my_eTypeStringX: " << my_eTypeStringX << endl;





	_getch();
	return 0;
}
