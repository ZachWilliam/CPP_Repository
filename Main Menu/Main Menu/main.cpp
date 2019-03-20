#include<iostream>
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work
#include <Windows.h>
#include<string>
#include<cstdlib>
#include<conio.h>

using namespace std;


void Setup()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 930, 790, TRUE);
}



void Menu()
{
	Setup();
	int menuChoice = 0;
	bool gameOver = false;

	cout << R"(
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
                                                                      
  __   ___   ______       ____      __   ___    _____      __      _  
 () ) / __) (   __ \     (    )    () ) / __)  / ___/     /  \    / ) 
 ( (_/ /     ) (__) )    / /\ \    ( (_/ /    ( (__      / /\ \  / /  
 ()   (     (    __/    ( (__) )   ()   (      ) __)     ) ) ) ) ) )  
 () /\ \     ) \ \  _    )    (    () /\ \    ( (       ( ( ( ( ( (   
 ( (  \ \   ( ( \ \_))  /  /\  \   ( (  \ \    \ \___   / /  \ \/ /   
 ()_)  \_\   )_) \__/  /__(  )__\  ()_)  \_\    \____\ (_/    \__/    
                                                                      
)" << endl;

	while (!gameOver)
	{
		cout << "1.Continue" << endl;
		cout << "2.New Game" << endl;
		cout << "3.Quit" << endl;
		cin >> menuChoice;

		if (menuChoice == 1)
		{

			system("cls");

			cout << "Continuing your journey" << endl;
			break;
		}
		if (menuChoice == 2)
		{
			system("cls");

			cout << "You begin a new adveture" << endl;
			break;
		}
		if (menuChoice == 3)
		{
			system("cls");


			cout << "Thanks for playing" << endl;
			gameOver = true;
			break;
		}
	}


}

void magicShop()
{
	Setup();
	int quest = 0;
	int magicChoice = 0;
	bool exitMenu = false;

	cout << R"(
88b           d88                           88                  
888b         d888                           ""                  
88`8b       d8'88                                               
88 `8b     d8' 88  ,adPPYYba,   ,adPPYb,d8  88   ,adPPYba,      
88  `8b   d8'  88  ""     `Y8  a8"    `Y88  88  a8"     ""      
88   `8b d8'   88  ,adPPPPP88  8b       88  88  8b              
88    `888'    88  88,    ,88  "8a,   ,d88  88  "8a,   ,aa      
88     `8'     88  `"8bbdP"Y8   `"YbbdP"Y8  88   `"Ybbd8"'      
                                aa,    ,88                      
                                 "Y8bbdP"                       
                                                                
 ad88888ba   88                                                 
d8"     "8b  88                                                 
Y8,          88                                                 
`Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,               
  `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a              
        `8b  88       88  8b       d8  88       d8              
Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"              
 "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"'               
                                       88                       
                                       88                       
)" << endl;
	
	cout << "Welcome to the Magic Shop how may I help you?" << endl;
	cout << "1.Buy" << endl
	     << "2.Sell" << endl
		 << "3.Talk" << endl
		 << "4.Exit" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cin >> magicChoice;

	system("cls");

	if (magicChoice == 1)
	{
		cout << R"(
88b           d88                           88                  
888b         d888                           ""                  
88`8b       d8'88                                               
88 `8b     d8' 88  ,adPPYYba,   ,adPPYb,d8  88   ,adPPYba,      
88  `8b   d8'  88  ""     `Y8  a8"    `Y88  88  a8"     ""      
88   `8b d8'   88  ,adPPPPP88  8b       88  88  8b              
88    `888'    88  88,    ,88  "8a,   ,d88  88  "8a,   ,aa      
88     `8'     88  `"8bbdP"Y8   `"YbbdP"Y8  88   `"Ybbd8"'      
                                aa,    ,88                      
                                 "Y8bbdP"                       
                                                                
 ad88888ba   88                                                 
d8"     "8b  88                                                 
Y8,          88                                                 
`Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,               
  `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a              
        `8b  88       88  8b       d8  88       d8              
Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"              
 "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"'               
                                       88                       
                                       88                
)" << endl;
		cout << "What are you looking to buy" << endl;
		cout << "1.item" << endl
			 << "2.item" << endl
			 << "3.item" << endl
			 << "4.item" << endl
			 << "5.Previous Menu" << endl;
		cout << "" << endl;
		cout << "" << endl;

		cin >> magicChoice;
		system("cls");

		if (magicChoice == 5)
		{
			magicShop();
		}
	}
	if (magicChoice == 2)
	{
		cout << R"(
88b           d88                           88                  
888b         d888                           ""                  
88`8b       d8'88                                               
88 `8b     d8' 88  ,adPPYYba,   ,adPPYb,d8  88   ,adPPYba,      
88  `8b   d8'  88  ""     `Y8  a8"    `Y88  88  a8"     ""      
88   `8b d8'   88  ,adPPPPP88  8b       88  88  8b              
88    `888'    88  88,    ,88  "8a,   ,d88  88  "8a,   ,aa      
88     `8'     88  `"8bbdP"Y8   `"YbbdP"Y8  88   `"Ybbd8"'      
                                aa,    ,88                      
                                 "Y8bbdP"                       
                                                                
 ad88888ba   88                                                 
d8"     "8b  88                                                 
Y8,          88                                                 
`Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,               
  `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a              
        `8b  88       88  8b       d8  88       d8              
Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"              
 "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"'               
                                       88                       
                                       88                
)" << endl;
		cout << "what would you like to sell?" << endl;
		//need to be able to print inv/sellable items here
		cout << "9.Previous Menu" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cin >> magicChoice;

		system("cls");

		if (magicChoice == 9)
		{
			magicShop();
		}
	}

	if (magicChoice == 3)
	{
		cout << "so young traveller I have a favour to ask of you," << endl
			<< "will you take this stone the village in the north" << endl
			<< "and have it examined by the specialist there" << endl
			<< "1. (yes) 2. (no)" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cin >> quest;

		system("cls");

		if (quest == 1)
		{
			cout << "here you are take the stone up north please" << endl
				<< "and return it once finished" << endl;
			//stone placed in inventory
		}
		if (quest == 2)
		{
			
			magicShop();
		}
		
	}

	if (magicChoice == 4)
	{
		cout << "Thanks for stopping by " //<< playerName
			<< endl;
		//return to over world
	}


}
int main()
{

	magicShop();

	_getch();
	return 0;


}