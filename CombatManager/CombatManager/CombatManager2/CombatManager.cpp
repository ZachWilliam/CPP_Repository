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

void SetCursor(bool p_isVisible) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = p_isVisible; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Setup() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 845, 790, TRUE);

	SetCursor(false);
}
void DrawGUI() {

	const int BORDER = 2;
	const int SCREEN_WIDTH = 69;
	const int SCREEN_HEIGHT = 27;
	const int DIST_FROM_MID_C = SCREEN_WIDTH / 2 + SCREEN_WIDTH % 2;
	const int DIST_FROM_MID_R = SCREEN_HEIGHT / 2 + SCREEN_HEIGHT % 2;
	const int BOT_START_ROW = SCREEN_HEIGHT + BORDER;
	const int RIGHT_START_COL = SCREEN_WIDTH + BORDER;
	const int SIDE_WIDTH = 30;

	system("CLS");
	GoToXY(0, 0);
	//Draw screen border
	cout << string(SCREEN_WIDTH + BORDER, '#') << endl;
	for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		cout << "#" << string(SCREEN_WIDTH, ' ') << "#" << endl;
	cout << string(SCREEN_WIDTH + BORDER, '#') << endl;

	//Draw right border
	GoToXY(0, RIGHT_START_COL); cout << string(SIDE_WIDTH, '#') << endl;
	for (size_t i = 0; i < SCREEN_HEIGHT; i++) {
		GoToXY(i + 1, RIGHT_START_COL);
		cout << "#" << string(SIDE_WIDTH - BORDER, ' ') << "#" << endl;
	}
	GoToXY(SCREEN_HEIGHT + 1, RIGHT_START_COL); cout << string(SIDE_WIDTH, '#') << endl;
	gotoxy(0, 30);
}

void DrawCombatScreen()
{
	DrawGUI();
	gotoxy(1, 4);
	cout << "  __________________     __________________     __________________";
	gotoxy(1, 5);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 6);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 7);
	cout << "  \\________________/     \\________________/     \\________________/";
	gotoxy(1, 10);
	cout << "  __________________     __________________     __________________";
	gotoxy(1, 11);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 12);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 13);
	cout << "  \\________________/     \\________________/     \\________________/";
	gotoxy(1, 20);

	cout << "-------I-----------------I-----------------I-----------------I-------";
	gotoxy(1, 21);
	cout << "       |                 |                 |                 |        ";
	gotoxy(1, 22);
	cout << "       |                 |                 |                 |        ";
	gotoxy(1, 23);
	cout << "-------I-----------------I-----------------I-----------------I-------";
	gotoxy(1, 24);
	cout << "       |                 |                 |                 |        ";
	gotoxy(1, 25);
	cout << "       |                 |                 |                 |        ";
	gotoxy(1, 26);
	cout << "-------I-----------------I-----------------I-----------------I-------";
}

void gotoxy(int x, int y);

int main()
{
	Setup();
	srand(time(NULL));
	bool inBattle = true;
	Player PC = Player();
	CharacterCreator(PC);
	system("cls");
	Party TheGroup = Party(PC);
	TheGroup.GenPartyFromClass(PC);
	TheGroup.DisplayParty();
	cout << endl;

	PartyInventory Inventory(TheGroup.Container[1].PlayerInventory, TheGroup.Container[3].PlayerInventory, TheGroup.Container[5].PlayerInventory);

	Inventory.DisplayPartyInventory();
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
void GoToXY(int line, int column)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

