#include "PlayerClass.h"
#include "ClassManager.h"
#include "Player.h"
#include <iostream>
#include <conio.h>

#include <Windows.h>
#include "SetColorAndBackground.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#pragma once

using namespace std;

void gotoxy(int x, int y);

void DrawScreen()
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
}

void CharacterPromotion(Player &self)
{
	ClassManager Man = ClassManager();
	vector<PlayerClass> Selection;
	bool Promotion = true;
	int choice = 0;
	int counter = 0;
	int NextMove;
	string space = " ";
	for (int i = 0; i < int(Man.AllClasses.size()); i++)
	{
		if (Man.AllClasses[i].Prerequisite == self.Job.Current)
		{
			Selection.push_back(Man.AllClasses[i]);
		}
	}
	DrawScreen();
	while (Promotion)
	{
		if (Selection.size() == 2)
		{
			gotoxy(84, 1);
			cout << "You have been promoted";
			counter = 0;
			for (size_t i = 0; i < 27; i++)
			{
				if (Selection[1].name == Man.AllClasses[i].name)
				{
					gotoxy(84, 2 + counter);
					if (choice == 1)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[1].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[1].name.size())
							{
								cout << space;
							}
						}
						SetColorAndBackground(0, 15);
					}
					else
					{
						cout << " " << Selection[1].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[1].name.size())
							{
								cout << space;
							}
						}
						cout << endl;
					}
					counter++;
				}
				else if (Selection[0].name == Man.AllClasses[i].name)
				{
					gotoxy(84, 2 + counter);
					if (choice == 0)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[0].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[0].name.size())
							{
								cout << space;
							}
						}
						SetColorAndBackground(0, 15);
					}
					else
					{
						cout << " " << Selection[0].name;
						for (size_t i = 0; i < 29; i--)
						{
							if (i > Selection[0].name.size())
							{
								cout << space;
							}
						}
						cout << endl;
					}
					counter++;
				}
			}

			gotoxy(1, 33);
			
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
				system("cls");
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
	string space = " ";
	DrawScreen();
	while (Building)
	{
		if (self.name == "")
		{

			string temp = "";
			cout << "What is your character's name : ";
			cin >> temp;
			self.name = temp;
			self.Combatant::name = temp;
			_getch();
		}
		else if (self.Job.Current == self.Job.NonClass)
		{
			gotoxy(83, 1);
			cout << " Choose your Class!" << endl;
			for (size_t i = 0; i < 27; i++)
			{
				gotoxy(83, 2 + i);
				if (i < Selection.size())
				{
					if (choice == i)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[i].name;
						for (size_t e = 0; e < 29; e--)
						{
							if (e > Selection[0].name.size())
							{
								gotoxy(83 + e, 2 + i);
								cout << space;
							}
						}
						cout << endl;
						SetColorAndBackground(0, 15);
					}
					else
					{
						cout << " " << Selection[i].name;
						for (size_t e = 0; e < 29; e--)
						{
							if (e > Selection[0].name.size())
							{
								gotoxy(83 + e, 2 + i);
								cout << space;
							}
						}
						cout << endl;
					}
				}
			}
			gotoxy(1, 33);
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
				system("cls");
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

