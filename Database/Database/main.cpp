#include <iostream>
#include <conio.h>
#include "Database.h"

int main()
{
	Database beast;
	Database scene;
	beast.LoadMonsters();
	scene.LoadText();


	beast.DisplayBeastiary();
	_getch();
	scene.DisplayText();
	_getch();
	return 0;
}