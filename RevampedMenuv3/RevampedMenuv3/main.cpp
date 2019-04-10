#pragma comment(lib, "winmm.lib")
#include <iostream>
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void Setup() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 845, 790, TRUE);
}

void SetColorAndBackground(int backC, int textC) {
	//Make sure color choice isnt above 15
	if (backC > 15 || textC > 15 || backC < 0 || textC < 0) {
		cout << "Invalid choice(s)" << endl;
		return;
	}

	//Convert backC to binary and back (as a byte) so 15 = 11110000, not 00001111
	int remainder = 0, newBackC = 0, multiplier = 1;
	while (backC > 0)
	{
		remainder = backC % 2;
		if (remainder % 2 != 0) newBackC += 16 * multiplier;
		multiplier *= 2;
		backC /= 2;
	}

	//Change colors
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newBackC + textC);
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

void DrawTitle(bool p_animate = false);
void DrawMenu(int p_menuLocation);
void Credits();

int main() {
	Setup();
	enum menuState {CONTINUE, NEW_GAME, CREDITS, QUIT};
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