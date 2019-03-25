#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "PlayerClass.h"
#include "ClassManager.h"
#include "Player.h"
#include "SetColorAndBackground.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#pragma once

using namespace std;



void CharacterPromotion(Player &self)
{
	ClassManager Man = ClassManager();
	vector<PlayerClass> Selection;
	bool Promotion = true;
	int choice = 0;
	int NextMove;
	for (int i = 0; i < int(Man.AllClasses.size()); i++)
	{
		if (Man.AllClasses[i].Prerequisite == self.Job.Current)
		{
			Selection.push_back(Man.AllClasses[i]);
		}
	}
	while (Promotion)
	{
		system("cls");
		if (Selection.size() == 2)
		{
			cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;
			cout << "|                                                                                |" << " Choose your Class!" << endl;
			for (size_t i = 0; i < 27; i++)
			{
				if (i < Selection.size())
				{
					cout << "|                                                                                |";
					if (choice == i)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[i].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[0].name.size())
							{
								cout << string(" ");
							}
						}
						cout << endl;
						SetColorAndBackground(0, 15);
					}
					else
					{
						cout << " " << Selection[i].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[0].name.size())
							{
								cout << string(" ");
							}
						}
						cout << endl;
					}
				}
				else {
					cout << "|                                                                                |" << endl;
				}
			}

			cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;

			cout << Selection[choice].name << endl;
			cout << Selection[choice].Desc1 << endl;
			cout << Selection[choice].Desc2 << endl;
			cout << Selection[choice].Desc3 << endl;
			cout << Selection[choice].AbilityDesc << endl;
			cout << "                            " << "Press [Z] to Continue" << "                            " << endl;

			NextMove = _getch();

			if (NextMove == KEY_UP)
			{
				choice--;
				if (choice < 0)
				{
					choice = 1;
				}

				continue;
			}
			else if (NextMove == KEY_DOWN)
			{
				choice++;

				if (choice > 1)
				{
					choice = 0;
				}

				continue;

			}
			else if (NextMove == 122)
			{
				self.Job = Selection[choice];
				cout << self.Job.name;
				Sleep(1000);
				break;
			}
			else
			{
				NextMove = 0;
				continue;
			}
		}
	}
}
void CharacterCreator(Player &self)
{
	ClassManager Man = ClassManager();
	vector<PlayerClass> Selection;
	for (int i = 0; i < 9; i++)
	{
		Selection.push_back(Man.AllClasses[i]);
	}
	bool Building = true;
	int choice = 0;
	int NextMove;
	while (Building)
	{
		system("cls");
		if (self.name == "")
		{
			{cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;
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
			cout << "|                                                                                |" << endl;
			cout << "|                                                                                |" << endl;
			cout << "|                                                                                |" << endl;
			cout << "|                                                                                |" << endl;
			cout << "|                                                                                |" << endl;
			cout << "|                                                                                |" << endl;
			cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;}
			string temp = "";
			cout << "What is your character's name : ";
			cin >> temp;
			self.name = temp;
			_getch();
		}
		else if (self.Job.Current == self.Job.NonClass)
		{
			{cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;
			cout << "|                                                                                |" << " Choose your Class!" << endl;
			for (size_t i = 0; i < 27; i++)
			{
				if (i < Selection.size())
				{
					cout << "|                                                                                |";
					if (choice == i)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[i].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[0].name.size())
							{
								cout << string(" ");
							}
						}
						cout << endl;
						SetColorAndBackground(0, 15);
					}
					else
					{
						cout << " " << Selection[i].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[0].name.size())
							{
								cout << string(" ");
							}
						}
						cout << endl;
					}
				}
				else {
					cout << "|                                                                                |" << endl;
				}
			}

			cout << "|--------------------------------------------------------------------------------" << "|" << "------------------------------" << endl;}


			cout << Man.AllClasses[choice].name << endl;
			cout << Man.AllClasses[choice].Desc1 << endl;
			cout << Man.AllClasses[choice].Desc2 << endl;
			cout << Man.AllClasses[choice].Desc3 << endl;
			cout << Man.AllClasses[choice].AbilityDesc << endl;
			cout << "                            " << "Press [Z] to Continue" << "                            " << endl;
			
			NextMove = _getch();
			
			if (NextMove == KEY_UP)
			{
				choice--;
				if (choice < 0) 
				{
					choice = 8;
				}	

				continue;
			}
			else if (NextMove == KEY_DOWN)
			{
				choice++;
				
				if (choice > 8)
				{
					choice = 0;
				}

				continue;
				
			}
			else if (NextMove == 122)
			{
				self.Job = Man.AllClasses[choice];
				cout << self.Job.name;
				Sleep(1000);
			}
			else
			{
				NextMove = 0;
				continue;
			}
			
		}
		else 
		{
			Building = false;
		}
		
	}
	CharacterPromotion(self);
}
