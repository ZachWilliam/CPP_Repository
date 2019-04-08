#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>


using namespace std;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void Setup() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 845, 790, TRUE);
}

void slow_print(const string&, unsigned int);

void Menu()

{
	Setup();
	int menuChoice = 0;

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 11);
	string message = R"(
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
 
          <~~~~~Press "Z" On One Of The Following~~~~~>                                                                     
)";
	slow_print(message, 1);


	const string menu[4] = { "Continue", "New Game", "Credits", "Quit" };
	int pointer = 0;


	while (true)
	{

		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once
		SetConsoleTextAttribute(color,11);
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
 
          <~~~~~Press "Z" On One Of The Following~~~~~>                                                                     
)" << endl;

		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << menu[i] << endl;
			}
		}
		while (true)
		{

			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(0x5A) != 0)
			{

				switch (pointer)
				{
				case 0:						//Continue
				{

					system("cls");

				}break;
				case 1:						//New Game
				{
					system("cls");

					
					
					

				}break;
				case 2:				//Credits
				{
					system("cls");
					
					SetConsoleTextAttribute(color, 12);
					cout << "Created By VGDD Class of 2019" << endl;
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

					Sleep(3000);
				}break;
				case 3:
				{

					system("cls");
					cout << "thank you for playing" << endl;
					Sleep(1000);
					exit(0);
					//exit game

				}break;

				}
				break;
			}
		}
		Sleep(150);
	}

	_getch();
}

int main() {
	Setup();
	Menu();

	return 0;
}

void slow_print(const string& message, unsigned int millis_per_char)
{
	// Range loops are "for each" constructs; here: for each character in the string
	for (const char c : message)
	{
		// flush is used to make sure the buffer is emptied to the terminal immediately
		cout << c << flush;

		// Ask the thread to sleep for at least n millis.
		sleep_for(milliseconds(millis_per_char));
	}
}