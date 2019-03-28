#include <iostream>
#include <conio.h>
#include "Database.h"

int main()
{
	Database beast;
	Database scene;
	beast.LoadMonsters();
	scene.LoadText();

	//FUNCTION TESTING
	/*
	int speakerID;
	cout << "SpeakerID: ";
	cin >> speakerID;
	cout << "Speaker: " << scene.ReturnName(1) << endl;
	*/
	//beast.DisplayBeastiary();
	//scene.DisplayText();
	/*
	cout << scene.ReturnDialogue(3, 0, 1) << endl;
	cout << scene.ReturnDialogue(3, 0, 2) << endl;
	cout << scene.ReturnDialogue(6, 1, 2) << endl;
	*/

	_getch();
	return 0;
}