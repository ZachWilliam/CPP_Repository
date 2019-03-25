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
	cout << "|-------------I----------------I-----------------I-----------------I-------------|" << endl;
	cout << "|             |                |                 |                 |             |" << endl;
	cout << "|             |                |                 |                 |             |" << endl;
	cout << "|-------------I----------------I-----------------I-----------------I-------------|" << endl;
	cout << "|             |                |                 |                 |             |" << endl;
	cout << "|             |                |                 |                 |             |" << endl;
	cout << "|-------------I----------------I-----------------I-----------------I-------------" << "|" << "------------------------------" << endl;
}

void gotoxy(int x, int y);

int main()
{
	bool inBattle = true;
	Player PC = Player();
	CharacterCreator(PC);
	Party TheGroup = Party(PC);
	system("cls");
	Enemy Foe(0);
	Foe.toString();
	_getch();
	system("cls");
	Encounter FirstBattle(-1,0,-1,-1,-1,-1);
	FirstBattle.GenerateEncounter(TheGroup);

	for (size_t i = 0; i < FirstBattle.Order.size(); i++)
	{
		cout << i << ": " << FirstBattle.Order[i].combatantValue.name << endl;
	}

	while (inBattle)
	{
		DrawCombatScreen();
		FirstBattle.TakeTurn();
		
		_getch();
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

