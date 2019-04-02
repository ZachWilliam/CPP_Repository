// CombatManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include "BattleManager.h"
//#include "Combatant.h"
#include "CharacterCreator.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Combatant.h"
#include "Enemy.h"
#include "Encounter.h"

using namespace std;

void DrawCombatScreen()
{
	cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|        __________________     __________________     __________________        |" << endl;
	cout << "|       |                  |   |                  |   |                  |       |" << endl;
	cout << "|       |                  |   |                  |   |                  |       |" << endl;
	cout << "|        \\________________/     \\________________/     \\________________/        |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|        __________________     __________________     __________________        |" << endl;
	cout << "|       |                  |   |                  |   |                  |       |" << endl;
	cout << "|       |                  |   |                  |   |                  |       |" << endl;
	cout << "|        \\________________/     \\________________/     \\________________/        |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|                                                                                |" << endl;
	cout << "|------------I-----------------I-----------------I-----------------I-------------|" << endl;
	cout << "|            |                 |                 |                 |             |" << endl;
	cout << "|            |                 |                 |                 |             |" << endl;
	cout << "|------------I-----------------I-----------------I-----------------I-------------|" << endl;
	cout << "|            |                 |                 |                 |             |" << endl;
	cout << "|            |                 |                 |                 |             |" << endl;
	cout << "|------------I-----------------I-----------------I-----------------I-------------" << "|" << "------------------------------" << endl;
}

void gotoxy(int x, int y);

int main()
{
	srand(time(NULL));
	bool inBattle = true;
	Player PC = Player();
	CharacterCreator(PC);
	system("cls");
	Party TheGroup = Party(PC);
	TheGroup.GenPartyFromClass(PC);
	TheGroup.DisplayParty();
	_getch();
	system("cls");
	Enemy Foe(0);
	Foe.toString();
	_getch();
	system("cls");

	for (size_t i = 0; i < TheGroup.Container.size(); i++)
	{
		if (TheGroup.Container[i].name != "NULL_NAME")
		{
			TheGroup.Container[i].GenerateAttacks();
		}
	}
	

	Encounter FirstBattle(0,-1,0,-1,-1,-1);
	FirstBattle.GenerateEncounter(TheGroup);



	while (inBattle)
	{
		
		DrawCombatScreen();
		FirstBattle.TakeTurn();
		if (!FirstBattle.Battling)
		{
			inBattle = false;
		}
		
		system("cls");
	}
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

