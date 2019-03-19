// RPG_Project.cpp : This file contains the 'main' function.
//

#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

void MenuManager() {}
void CombatManager() {}
void MapManager() {}

int main()
{
	bool onMap = false;
	bool inCombat = false;
	bool onMenu = false;
	bool Quit = true;

	while (true)
	{
		if (onMenu)
		{
			MenuManager();
		}
		else if (inCombat)
		{
			CombatManager();
		}
		else if (onMap)
		{
			MapManager();
		}
		else if (Quit)
		{
			cout << "Hello World!";
			break;
		}
	}
	_getch();
}