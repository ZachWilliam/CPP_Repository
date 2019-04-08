#pragma comment(lib, "winmm.lib")
#include <iostream>
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work
#include <Windows.h>
#include <vector>
#include <conio.h>
#include "QuestManager.h"
#include "Format.h"
#include "MapMain.h"
#include "CharacterCreator.h"
#include "EndGame.h"

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



int main() 
{
	SetColorAndBackground();//Default to black/white
	srand(static_cast<unsigned int>(time(0)));//Seed
	Setup();//Set up window and cursor

	//Create and load beast and dialogue databases
	Database beast;
	Database dialogue;
	beast.LoadMonsters();
	dialogue.LoadText();

	//New GAME
	//Create character
	bool inBattle = false;
	Player PC = Player();
	CharacterCreator(PC);
	system("cls");
	//Set up party and inventory
	Party TheGroup = Party(PC);
	TheGroup.GenPartyFromClass(PC);
	TheGroup.DisplayParty();
	PartyInventory Inventory(TheGroup.Container[1].PlayerInventory, TheGroup.Container[3].PlayerInventory, TheGroup.Container[5].PlayerInventory);
	//Show party overview
	Inventory.DisplayPartyInventory();
	_getch();
	system("cls");

	//Generate Attacks
	for (size_t i = 0; i < TheGroup.Container.size(); i++)
	{
		if (TheGroup.Container[i].name != "NULL_NAME")
		{
			TheGroup.Container[i].GenerateAttacks();
		}
	}
	//NEW GAME

	   	 

	//Game Loop


	//Create and start game loop
	GManager.gameState = GManager.PLAY;
	MapMain mapMain(dialogue, beast, TheGroup, Inventory);
	mapMain.Setup(6, 0, 0);
	mapMain.main();

	system("cls");

	//Game Loop

	//Play either game over or the game ending
	EndGame endGame(dialogue);
	

	return 0;
}