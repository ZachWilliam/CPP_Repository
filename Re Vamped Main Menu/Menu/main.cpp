#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <string>


using namespace std;






void Setup() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 845, 790, TRUE);
}

void Menu()

{
	Setup();
	int menuChoice = 0;


	

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


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
                                                                      
   ____        __      _             .'-'.                                       
  / __ \      /  \    / )        .  (  o O)       	                                       
 / /  \ \    / /\ \  / /          \_ `  _,   _                                        
( ()  () )   ) ) ) ) ) )       -.___'.) ( ,-'                                       
( ()  () )  ( ( ( ( ( (             '-.O.'-..-..                                         
 \ \__/ /   / /  \ \/ /         ./\/\/ | \_.-._                                        
  \____/   (_/    \__/                 ;                                     
                                    ._/                                     
  __   ___   ______       ____      __   ___    _____      __      _  
 () ) / __) (   __ \     (    )    () ) / __)  / ___/     /  \    / ) 
 ( (_/ /     ) (__) )    / /\ \    ( (_/ /    ( (__      / /\ \  / /  
 ()   (     (    __/    ( (__) )   ()   (      ) __)     ) ) ) ) ) )  
 () /\ \     ) \ \  _    )    (    () /\ \    ( (       ( ( ( ( ( (   
 ( (  \ \   ( ( \ \_))  /  /\  \   ( (  \ \    \ \___   / /  \ \/ /   
 ()_)  \_\   )_) \__/  /__(  )__\  ()_)  \_\    \____\ (_/    \__/    
 
          <~~~~~Press Space On One Of The Following~~~~~>                                                                     
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

			if (GetAsyncKeyState(0x57) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(0x53) != 0)
			{
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0)
			{





				switch (pointer)
				{
				case 0:
				{

					system("cls");
					
					


				}break;
				case 1:
				{
					system("cls");

					
					Sleep(1000);
					

				}break;
				case 2:
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
	Menu();





	return 0;
}