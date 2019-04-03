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



int main() {
	srand(static_cast<unsigned int>(time(0)));
	Setup();
	bool inBattle = false;
	Player PC = Player();
	CharacterCreator(PC);
	system("cls");
	Party TheGroup = Party(PC);
	TheGroup.GenPartyFromClass(PC);
	TheGroup.DisplayParty();

	PartyInventory Inventory(TheGroup.Container[1].PlayerInventory, TheGroup.Container[3].PlayerInventory, TheGroup.Container[5].PlayerInventory);

	Inventory.DisplayPartyInventory();
	_getch();
	system("cls");

	QuestManager::Instance().questSetup();

	Database beast;
	Database dialogue;
	beast.LoadMonsters();
	dialogue.LoadText();





	MapMain mapMain(dialogue, TheGroup);
	mapMain.Setup(3, 0, 0);
	mapMain.main();





	return 0;
}