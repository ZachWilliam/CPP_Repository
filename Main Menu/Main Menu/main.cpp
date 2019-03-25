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



	cout << "1.Continue" << endl;
	cout << "2.New Game" << endl;
	cout << "3.Credits" << endl;
	cout << "4.Quit" << endl;
	cin >> menuChoice;



	switch (menuChoice)
	{
	case 1:
		system("cls");
		cout << "you continue your journey" << endl;
		//load save 
		break;

	case 2:
		system("cls");
		cout << "you start new journey" << endl;
		//start from begining
		//erase save file
		break;

	case 3:
		system("cls");
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
		cout << "1.Back" << endl;

		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			system("cls");
			Menu();
			break;
		}
		break;

	case 4:
		system("cls");
		cout << "thank you for playing" << endl;
		exit;
		//exit game



	}

}


void questA()
{
	bool questActive = false;
	int questItem = 0;
}



void Credits() {
	Setup();

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
}




void Bank()
{
	Setup();
	int bankChoice = 0;

	cout << R"(
 _______                               
(_______)                    _         
 _   ___  ____ _____ _____ _| |_       
| | (_  |/ ___) ___ (____ (_   _)      
| |___) | |   | ____/ ___ | | |_       
 \_____/|_|   |_____)_____|  \__)      
                                       
 _     _             _                 
(_)   | |           | |                
 _____| | ____ _____| |  _ _____ ____  
|  _   _)/ ___|____ | |_/ ) ___ |  _ \ 
| |  \ \| |   / ___ |  _ (| ____| | | |
|_|   \_)_|   \_____|_| \_)_____)_| |_|
                                       
 ______              _                 
(____  \            | |                
 ____)  )_____ ____ | |  _             
|  __  ((____ |  _ \| |_/ )            
| |__)  ) ___ | | | |  _ (             
|______/\_____|_| |_|_| \_)            
                                       
)" << endl;
	cout << endl;
	cout << endl;
	cout << "Welcome to the GKB what would you like to do today?" << endl;
	cout << endl;
	cout << "1.Deposit Item" << endl
		<< "2.Withdawl Item" << endl
		<< "3.Exit" << endl;
	cin >> bankChoice;

	switch (bankChoice)
	{
	case 1:
		system("cls");
		cout << "which item would you like to deposit" << endl;
		cout << endl;
		//display inventory here
		//playerInventory()
		cout << "9.Previous Menu" << endl;

		cin >> bankChoice;
		switch (bankChoice)
		{
		case 9:
			system("cls");
			Bank();
		}

	case 2:
		system("cls");
		cout << "which item would you like to withdrawl" << endl;
		cout << endl;
		// display items in bank
		cout << "9.Previous Menu" << endl;

		cin >> bankChoice;
		switch (bankChoice)
		{
		case 9:
			system("cls")
				;			Bank();
		}

	case 3:
		system("cls");
		cout << "thank you for choosing GKB come again!" << endl;
		exit;
		//return to map


	}




}

void Inn()
{
	Setup();
	int innChoice = 0;
	cout << R"(
 ______                               _             
(_____ \              _              | |            
 _____) )_____  ___ _| |_    _____   | |____  ____  
|  __  /| ___ |/___|_   _)  (_____)  | |  _ \|  _ \ 
| |  \ \| ____|___ | | |_            | | | | | | | |
|_|   |_|_____|___/   \__)           |_|_| |_|_| |_|
                                                    
)" << endl;
	cout << endl;
	cout << endl;
	cout << "Welcome to our towns Inn" << endl
		<< "what would you like to do?" << endl;
	cout << endl;
	cout << "1.Spend the night" << endl // x amount of gold per night
		<< "2.Exit" << endl;

	cin >> innChoice;

	switch (innChoice)
	{
	case 1:
		system("cls");
		cout << "right this way to your room" << endl;
		//heal hp x amount per night 
		//delay
		cout << "Hope you come again" << endl;
		//return to map
		break;



	case 2:
		system("cls");
		cout << "thanks for stopping by" << endl;
		exit;
	}
}

void armourShop()
{
	Setup();
	int armourChoice = 0;
	cout << R"(
 _______                               
(_______)                              
 _______  ____ ____   ___  _   _  ____ 
|  ___  |/ ___)    \ / _ \| | | |/ ___)
| |   | | |   | | | | |_| | |_| | |    
|_|   |_|_|   |_|_|_|\___/|____/|_|    
                                       
  ______ _                             
 / _____) |                            
( (____ | |__   ___  ____              
 \____ \|  _ \ / _ \|  _ \             
 _____) ) | | | |_| | |_| |            
(______/|_| |_|\___/|  __/             
                    |_|                
)" << endl;
	cout << endl;
	cout << endl;
	cout << "Welcome to my shop traveller, how can I help you?" << endl;
	cout << "1.Buy" << endl
		<< "2.Sell" << endl
		<< "3.Exit" << endl;

	cin >> armourChoice;
	switch (armourChoice)
	{
	case 1:
		system("cls");

		cout << R"(
 _______                               
(_______)                              
 _______  ____ ____   ___  _   _  ____ 
|  ___  |/ ___)    \ / _ \| | | |/ ___)
| |   | | |   | | | | |_| | |_| | |    
|_|   |_|_|   |_|_|_|\___/|____/|_|    
                                       
  ______ _                             
 / _____) |                            
( (____ | |__   ___  ____              
 \____ \|  _ \ / _ \|  _ \             
 _____) ) | | | |_| | |_| |            
(______/|_| |_|\___/|  __/             
                    |_|                
)" << endl;
		cout << endl;
		cout << endl;
		cout << "What would you like to buy?" << endl;
		cout << endl;
		cout << endl;
		cout << "SHOP INVENTORY" << endl;
		cout << "9.Previous Menu" << endl;
		cout << endl;
		cout << endl;

		cin >> armourChoice;

		switch (armourChoice)
		{

		case 9:

			system("cls");
			armourShop();
			break;
		}
		break;

	case 2:

		system("cls");
		cout << R"(
 _______                               
(_______)                              
 _______  ____ ____   ___  _   _  ____ 
|  ___  |/ ___)    \ / _ \| | | |/ ___)
| |   | | |   | | | | |_| | |_| | |    
|_|   |_|_|   |_|_|_|\___/|____/|_|    
                                       
  ______ _                             
 / _____) |                            
( (____ | |__   ___  ____              
 \____ \|  _ \ / _ \|  _ \             
 _____) ) | | | |_| | |_| |            
(______/|_| |_|\___/|  __/             
                    |_|                
)" << endl;
		cout << endl;
		cout << endl;
		cout << "INVENTORY" << endl;
		cout << "9.Previous Menu" << endl;

		cin >> armourChoice;
		switch (armourChoice)
		{

		case 9:
			system("cls");

			armourShop();
			break;
		}
		break;

	case 3:
		system("cls");
		cout << "Thank you for stopping by!" << endl;
		//return to map
		break;
	}

}

void warriorShop()
{
	Setup();
	int warriorChoice = 0;

	cout << R"(
 _  _  _                  _             
(_)(_)(_)                (_)            
 _  _  _ _____  ____ ____ _  ___   ____ 
| || || (____ |/ ___) ___) |/ _ \ / ___)
| || || / ___ | |  | |   | | |_| | |    
 \_____/\_____|_|  |_|   |_|\___/|_|    
                                        
  ______ _                              
 / _____) |                             
( (____ | |__   ___  ____               
 \____ \|  _ \ / _ \|  _ \              
 _____) ) | | | |_| | |_| |             
(______/|_| |_|\___/|  __/              
                    |_|                 
)" << endl;
	cout << "Welcome traveller how can I help you today?" << endl;
	cout << endl;
	cout << endl;
	cout << "1.buy" << endl
		<< "2.Sell" << endl
		<< "3.Exit" << endl;

	cin >> warriorChoice;
	switch (warriorChoice)
	{

	case 1:
		system("cls");

		cout << R"(
 _  _  _                  _             
(_)(_)(_)                (_)            
 _  _  _ _____  ____ ____ _  ___   ____ 
| || || (____ |/ ___) ___) |/ _ \ / ___)
| || || / ___ | |  | |   | | |_| | |    
 \_____/\_____|_|  |_|   |_|\___/|_|    
                                        
  ______ _                              
 / _____) |                             
( (____ | |__   ___  ____               
 \____ \|  _ \ / _ \|  _ \              
 _____) ) | | | |_| | |_| |             
(______/|_| |_|\___/|  __/              
                    |_|                 
)" << endl;
		cout << endl;
		cout << endl;
		cout << "SHOP INVENTORY" << endl;
		cout << "9.Previous Menu" << endl;
		cout << endl;
		cout << endl;

		cin >> warriorChoice;

		switch (warriorChoice)
		{


		case 9:
			system("cls");
			warriorShop();
			break;
		}
		break;
	case 2:
		system("cls");
		cout << R"(
 _  _  _                  _             
(_)(_)(_)                (_)            
 _  _  _ _____  ____ ____ _  ___   ____ 
| || || (____ |/ ___) ___) |/ _ \ / ___)
| || || / ___ | |  | |   | | |_| | |    
 \_____/\_____|_|  |_|   |_|\___/|_|    
                                        
  ______ _                              
 / _____) |                             
( (____ | |__   ___  ____               
 \____ \|  _ \ / _ \|  _ \              
 _____) ) | | | |_| | |_| |             
(______/|_| |_|\___/|  __/              
                    |_|                
)";
		cout << endl;
		cout << endl;

		cout << "YOUR INVENTORY" << endl;
		//display inventory
		cout << "9.Previous Menu" << endl;
		cin >> warriorChoice;

		switch (warriorChoice)
		{

		case 9:
			system("cls");
			warriorShop();
			break;
		}
		break;



	case 3:
		system("cls");
		cout << "Thanks for coming by" << endl;
		// return to over world

		break;
	}



}

void magicShop()
{
	Setup();
	int quest = 0;
	int magicChoice = 0;


	cout << R"(
 _______             _         
(_______)           (_)        
 _  _  _ _____  ____ _  ____   
| ||_|| (____ |/ _  | |/ ___)  
| |   | / ___ ( (_| | ( (___   
|_|   |_\_____|\___ |_|\____)  
              (_____|          
  ______ _                     
 / _____) |                    
( (____ | |__   ___  ____      
 \____ \|  _ \ / _ \|  _ \     
 _____) ) | | | |_| | |_| |    
(______/|_| |_|\___/|  __/     
                    |_|            
)" << endl;
	cout << endl;
	cout << endl;

	cout << "Welcome to the Magic Shop how may I help you?" << endl;
	cout << "1.Buy" << endl
		<< "2.Sell" << endl
		<< "3.Talk" << endl
		<< "4.Exit" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cin >> magicChoice;

	switch (magicChoice)
	{

	case 1:
		system("cls");

		cout << R"(
 _______             _         
(_______)           (_)        
 _  _  _ _____  ____ _  ____   
| ||_|| (____ |/ _  | |/ ___)  
| |   | / ___ ( (_| | ( (___   
|_|   |_\_____|\___ |_|\____)  
              (_____|          
  ______ _                     
 / _____) |                    
( (____ | |__   ___  ____      
 \____ \|  _ \ / _ \|  _ \     
 _____) ) | | | |_| | |_| |    
(______/|_| |_|\___/|  __/     
                    |_|        
)" << endl;
		cout << endl;
		cout << endl;
		cout << "What are you looking to buy" << endl;
		cout << endl;
		cout << endl;
		cout << "SHOP INVENTORY" << endl;
		cout << "9.Previous Menu" << endl;
		cout << "" << endl;
		cout << "" << endl;

		cin >> magicChoice;

		switch (magicChoice)
		{
		case 9:
			system("cls");
			magicShop();
			break;
		}
		break;



	case 2:
		system("cls");
		cout << R"(
 _______             _         
(_______)           (_)        
 _  _  _ _____  ____ _  ____   
| ||_|| (____ |/ _  | |/ ___)  
| |   | / ___ ( (_| | ( (___   
|_|   |_\_____|\___ |_|\____)  
              (_____|          
  ______ _                     
 / _____) |                    
( (____ | |__   ___  ____      
 \____ \|  _ \ / _ \|  _ \     
 _____) ) | | | |_| | |_| |    
(______/|_| |_|\___/|  __/     
                    |_|        
)" << endl;
		cout << endl;
		cout << endl;
		cout << "what would you like to sell?" << endl;
		//need to be able to print inv/sellable items here
		cout << endl;
		cout << endl;
		cout << "YOUR INVENTORY" << endl;
		cout << "9.Previous Menu" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cin >> magicChoice;

		switch (magicChoice)
		{
		case 9:
			system("cls");
			magicShop();
			break;
		}
		break;


	case 3:
		system("cls");

		cout << "so young traveller I have a favour to ask of you," << endl
			<< "will you take this stone the village in the north" << endl
			<< "and have it examined by the specialist there" << endl
			<< "1.(YES)------2.(NO)" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cin >> quest;


		switch (quest)
		{
		case 1:
			system("cls");
			cout << "here you are take the stone up north please" << endl
				<< "and return it once finished" << endl;
			cout << endl;
			cout << endl;
			cout << "The Stone has been placed in Inventory" << endl;
			//stone placed in inventory
			break;

		case 2:
			system("cls");
			cout << "maybe another time then" << endl;
			break;
		}

		break;










	case 4:
		system("cls");

		cout << "Thanks for stopping by " //<< playerName
			<< endl;
		//return to over world
		break;

	}



}

void generalShop()
{
	Setup();
	int generalChoice = 0;

	cout << R"(
 _______                               _  
(_______)                             | | 
 _   ___ _____ ____  _____  ____ _____| | 
| | (_  | ___ |  _ \| ___ |/ ___|____ | | 
| |___) | ____| | | | ____| |   / ___ | | 
 \_____/|_____)_| |_|_____)_|   \_____|\_)
                                          
  ______ _                                
 / _____) |                               
( (____ | |__   ___  ____                 
 \____ \|  _ \ / _ \|  _ \                
 _____) ) | | | |_| | |_| |               
(______/|_| |_|\___/|  __/                
                    |_|                   
)" << endl;
	cout << endl;
	cout << endl;
	cout << "1.Buy" << endl
		<< "2.Sell" << endl
		<< "3.Exit" << endl;

	cin >> generalChoice;
	switch (generalChoice)
	{
	case 1:
		system("cls");
		cout << R"(
 _______                               _  
(_______)                             | | 
 _   ___ _____ ____  _____  ____ _____| | 
| | (_  | ___ |  _ \| ___ |/ ___|____ | | 
| |___) | ____| | | | ____| |   / ___ | | 
 \_____/|_____)_| |_|_____)_|   \_____|\_)
                                          
  ______ _                                
 / _____) |                               
( (____ | |__   ___  ____                 
 \____ \|  _ \ / _ \|  _ \                
 _____) ) | | | |_| | |_| |               
(______/|_| |_|\___/|  __/                
                    |_|                   
)" << endl;
		cout << endl;
		cout << endl;
		cout << "SHOP INVENTORY" << endl;
		//display shop items
		cout << "9.Previous Menu" << endl;

		cin >> generalChoice;

		switch (generalChoice)
		{
		case 9:
			system("cls");
			generalShop();
			break;
		}
		break;

	case 2:
		system("cls");
		cout << R"(
 _______                               _  
(_______)                             | | 
 _   ___ _____ ____  _____  ____ _____| | 
| | (_  | ___ |  _ \| ___ |/ ___|____ | | 
| |___) | ____| | | | ____| |   / ___ | | 
 \_____/|_____)_| |_|_____)_|   \_____|\_)
                                          
  ______ _                                
 / _____) |                               
( (____ | |__   ___  ____                 
 \____ \|  _ \ / _ \|  _ \                
 _____) ) | | | |_| | |_| |               
(______/|_| |_|\___/|  __/                
                    |_|                   
)" << endl;
		cout << endl;
		cout << endl;
		cout << "YOUR INVENTORY" << endl;
		cout << "9.Previous Menu" << endl;
		cout << endl;
		cout << endl;

		cin >> generalChoice;
		switch (generalChoice)
		{
		case 9:
			system("cls");
			generalShop();
			break;
		}
		break;
		
	case 3:
		system("cls");
		cout << "Thanks for stopping by." << endl;
		break;
	}










}

int main()
{
	Menu();




	_getch();
	return 0;


}