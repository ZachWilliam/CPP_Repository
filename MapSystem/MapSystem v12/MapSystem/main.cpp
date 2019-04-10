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


void DrawTitle(bool p_animate = false);
void DrawMenu(int p_menuLocation);
void Credits();

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
	system("cls");

	srand(static_cast<unsigned int>(time(0)));//Seed
	Setup();//Set up window and cursor

	//Create and load beast and dialogue databases
	Database beast;
	Database dialogue;
	beast.LoadMonsters();
	dialogue.LoadText();
	
	enum menuState { CONTINUE, NEW_GAME, CREDITS, QUIT };
	const int MENU_SIZE = 4;
	int menuLocation = 0;
	bool isQuitting = false;


	DrawTitle(true);

	while (!isQuitting) {
		DrawTitle();
		DrawMenu(menuLocation);
		switch (_getch()) {
			case 72: {//UP
				if (menuLocation == 0) menuLocation = MENU_SIZE - 1;
				else menuLocation--;
				break;
			}
			case 80: {//DOWN
				if (menuLocation == MENU_SIZE - 1) menuLocation = 0;
				else menuLocation++;
				break;
			}
			case 'z': {
				switch (menuLocation) {
					case CONTINUE: { //Continue
						menuLocation = CONTINUE;
						break;
					}
					case NEW_GAME: { // New Gane
						menuLocation = CONTINUE;
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

						SetColorAndBackground();

						//Create and start game loop
						GManager.gameState = GManager.PLAY;
						MapMain mapMain(dialogue, beast, TheGroup, Inventory);
						mapMain.Setup(1, 0, 0);
						mapMain.main();

						system("cls");

						//Play either game over or the game ending
						EndGame endGame(dialogue);
						break;
					}
					case CREDITS: { // Credits
						Credits();
						menuLocation = CONTINUE;
						break;
					}
					case QUIT: { // Quit
						isQuitting = true;
						break;
					}
				}
			}
		}
	}

	return 0;
}

void DrawTitle(bool p_animate) {
	int animateSpeed = 1;
	if (!p_animate) animateSpeed = 0;
	SetColorAndBackground(BLACK, LIGHTCYAN);

	GoToXY(0, 0);
	string title = R"(
                  ____     ________   ________     ____       ____    __   ___       
                 (    )   (___  ___) (___  ___)   (    )     / ___)  () ) / __)      
                 / /\ \       ) )        ) )      / /\ \    / /      ( (_/ /         
                ( (__) )     ( (        ( (      ( (__) )  ( (       ()   (          
                 )    (       ) )        ) )      )    (   ( (       () /\ \         
                /  /\  \     ( (        ( (      /  /\  \   \ \___   ( (  \ \        
               /__(  )__\    /__\       /__\    /__(  )__\   \____)  ()_)  \_\       
                                                                                     
                                    ____        __      _                            
                                   / __ \      /  \    / )                           
                                  / /  \ \    / /\ \  / /                            
                                 ( ()  () )   ) ) ) ) ) )                            
                                 ( ()  () )  ( ( ( ( ( (                             
                                  \ \__/ /   / /  \ \/ /                             
                                   \____/   (_/    \__/                              
                                                                                     
        __   ___   ______       ____       ____    __   ___    _____      __      _  
       () ) / __) (   __ \     (    )     / ___)  () ) / __)  / ___/     /  \    / ) 
       ( (_/ /     ) (__) )    / /\ \    / /      ( (_/ /    ( (__      / /\ \  / /  
       ()   (     (    __/    ( (__) )  ( (       ()   (      ) __)     ) ) ) ) ) )  
       () /\ \     ) \ \  _    )    (   ( (       () /\ \    ( (       ( ( ( ( ( (   
       ( (  \ \   ( ( \ \_))  /  /\  \   \ \___   ( (  \ \    \ \___   / /  \ \/ /   
       ()_)  \_\   )_) \__/  /__(  )__\   \____)  ()_)  \_\    \____\ (_/    \__/    
                                                                                  
                       <~~~~~Press "Z" On One Of The Following~~~~~>
	)";

	for (int i = 0; i < title.size(); i++)
	{
		cout << title[i];
		Sleep(animateSpeed);
	}
}

void Credits() {
	system("cls");
	SetColorAndBackground(BLACK, LIGHTCYAN);

	//Use center word here
	cout << endl << "Created By VGDD Class of 2019" << endl;
	cout << endl;
	cout << R"(
                                      +-+-+-+-+-+
                                      |S|c|o|t|t|
                                      +-+-+-+-+-+
)" << endl
<< R"(
                                       +-+-+-+-+
                                       |Z|a|c|h|
                                       +-+-+-+-+
)" << endl
<< R"(
                                  +-+-+-+-+-+-+-+-+-+
                                  |S|e|b|a|s|t|i|a|n|
                                  +-+-+-+-+-+-+-+-+-+
)" << endl
<< R"(
                                     +-+-+-+-+-+-+
                                     |C|u|r|t|i|s|
                                     +-+-+-+-+-+-+
)" << endl
<< R"(
                                       +-+-+-+-+
                                       |N|i|c|k|
                                       +-+-+-+-+
)" << endl
<< R"(
                                      +-+-+-+-+-+
                                      |A|a|r|o|n|
                                      +-+-+-+-+-+
)" << endl;

	//Use Centerword here
	cout << "Press any key to continue..." << endl;
	_getch();
	system("cls");

}

void DrawMenu(int p_menuLocation) {
	const int MENU_SIZE = 4;
	const string MENU[MENU_SIZE] = { "Continue", "New Game", "Credits", "Quit" };

	GoToXY(28, 0);
	for (int i = 0; i < MENU_SIZE; i++)
	{
		if (i == p_menuLocation) SetColorAndBackground(BLACK, LIGHTCYAN);
		else SetColorAndBackground(BLACK, CYAN);
		//Use Center Word here
		cout << MENU[i] << endl;
	}
}