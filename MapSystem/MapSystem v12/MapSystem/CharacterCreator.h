#include "PlayerClass.h"
#include "ClassManager.h"
#include "Player.h"
#include "PartyManager.h"
#include "MapMain.h"
#include <iostream>
#include <conio.h>

#include <Windows.h>
#include "Format.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#pragma once

using namespace std;

void gotoxy(int x, int y);

void GoToXY(int y, int x);


void CharacterPromotion(Player &self)
{
	ClassManager Man = ClassManager();
	vector<PlayerClass> Selection;
	bool Promotion = true;
	int choice = 0;
	int counter = 0;
	int NextMove;
	string space = ".";
	for (int i = 0; i < int(Man.AllClasses.size()); i++)
	{
		if (Man.AllClasses[i].Prerequisite == self.Job.Current)
		{
			Selection.push_back(Man.AllClasses[i]);
		}
	}
	DrawGUI();
	while (Promotion)
	{
		if (Selection.size() == 2)
		{
			gotoxy(72, 1);
			cout << "You have been promoted";
			counter = 0;
			for (size_t i = 0; i < 27; i++)
			{
				if (Selection[1].name == Man.AllClasses[i].name)
				{
					gotoxy(72, 2 + counter);
					if (choice == 1)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[1].name;
						for (size_t i = 0; i < 25; i++)
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
						for (size_t i = 0; i < 27; i++)
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
					gotoxy(72, 2 + counter);
					if (choice == 0)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[0].name;
						for (size_t i = 0; i < 25; i++)
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
						for (size_t i = 0; i < 27; i++)
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

			gotoxy(0, 30);
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			gotoxy(0, 30);
			
			cout << Selection[choice].name;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].name.size())
				{
					cout << ".";
				}
			}
			cout << endl;
			cout << Selection[choice].Desc1;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].Desc1.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << Selection[choice].Desc2;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].Desc2.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << Selection[choice].Desc3;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].Desc3.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << Selection[choice].AbilityDesc;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].AbilityDesc.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << ".............................." << "Press [Z] to Continue" << ".............................." << endl;

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
	PartyManager Par = PartyManager();
	vector<PlayerClass> Selection;
	for (int i = 0; i < 9; i++)
	{
		Selection.push_back(Man.AllClasses[i]);
	}
	bool Building = true;
	bool StatedIn = false;
	int choice = 0;
	
	int PointBuy = 14;
	int NextMove;
	vector<int> PointBought = { 0,0,0,0,0,0,0 };
	char space = '.';
	DrawGUI();

	while (Building)
	{
		if (self.name == "")
		{

			string temp = "";
			cout << "What is your character's name : ";
			cin >> temp;
			self.name = temp;
			self.Combatant::name = temp;
			//_getch();
		}
		else if (self.Job.Current == self.Job.NonClass)
		{
			gotoxy(72, 1);
			cout << " Choose your Class!" << endl;
			for (size_t i = 0; i < 27; i++)
			{
				gotoxy(72, 2 + i);
				if (i < Selection.size())
				{
					if (choice == i)
					{
						SetColorAndBackground(15, 0);
						cout << " > " << Selection[i].name;
						for (size_t e = 0; e < 25; e++)
						{
							if (e > Selection[i].name.size())
							{
								cout << space;
							}
						}
						cout << endl;
						SetColorAndBackground(0, 15);
					}
					else
					{
						cout << " " << Selection[i].name;
						for (size_t e = 0; e < 27; e++)
						{
							if (e > Selection[i].name.size())
							{
								cout << space;
							}
						}
						cout << endl;
					}
				}
			}
			gotoxy(0, 30);
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			gotoxy(0, 30);
			cout << Selection[choice].name;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].name.size())
				{
					cout << ".";
				}
			}
			cout << endl;
			cout << Selection[choice].Desc1;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].Desc1.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << Selection[choice].Desc2;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].Desc2.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << Selection[choice].Desc3;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].Desc3.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << Selection[choice].AbilityDesc;
			for (size_t i = 0; i < 82; i++)
			{
				if (i > Selection[choice].AbilityDesc.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << ".............................." << "Press [Z] to Continue" << ".............................." << endl;
			
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
				self.CurrentStats.STRENGTH = Man.AllClasses[choice].STR_BASE;
				self.CurrentStats.DEXTERITY = Man.AllClasses[choice].DEX_BASE;
				self.CurrentStats.CONSTITUTION = Man.AllClasses[choice].CON_BASE;
				self.CurrentStats.AGILITY = Man.AllClasses[choice].AGI_BASE;
				self.CurrentStats.INTELLIGENCE = Man.AllClasses[choice].INT_BASE;
				self.CurrentStats.WISDOM = Man.AllClasses[choice].WIS_BASE;
				self.CurrentStats.LUCK = Man.AllClasses[choice].LUK_BASE;
				self.PlayerInventory.m_Weapon = Man.AllClasses[choice].StarterWeapon;
				system("cls");
				choice = 0;
				DrawGUI();
			}
			else
			{
				NextMove = 0;
				continue;
			}
			
		}
		else if (!StatedIn)
		{

			//82
			//  ___   ___   ___   ___   ___   ___   ___ 
			// | ^ | | ^ | | ^ | | ^ | | ^ | | ^ | | ^ |
			// |STR| |DEX| |CON| |AGI| |INT| |WIS| |LUK|
			// | 0 | | 0 | | 0 | | 0 | | 0 | | 0 | | 0 |
			// | v | | v | | v | | v | | v | | v | | v |
			//  | |   | |   | |   | |   | |   | |   | |
			//   |     |     |     |     |     |     |
			gotoxy(15, 3);
			cout << " ___   ___   ___   ___   ___   ___   ___ ";
			gotoxy(15, 4);
			cout << "| ^ | | ^ | | ^ | | ^ | | ^ | | ^ | | ^ |";
			gotoxy(15, 5);
			cout << "|";

			if (choice == 0)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "STR";
			SetColorAndBackground(0, 15);
			cout << "| |";
			if (choice == 1)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "DEX";
			SetColorAndBackground(0, 15);
			cout << "| |";
			if (choice == 2)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "CON";
			SetColorAndBackground(0, 15);
			cout << "| |";
			if (choice == 3)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "AGI";
			SetColorAndBackground(0, 15);
			cout << "| |";
			if (choice == 4)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "INT";
			SetColorAndBackground(0, 15);
			cout << "| |";
			if (choice == 5)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "WIS";
			SetColorAndBackground(0, 15);
			cout << "| |";
			if (choice == 6)
			{
				SetColorAndBackground(9, 15);
			}
			cout << "LUK";
			SetColorAndBackground(0, 15);
			cout << "|";
			gotoxy(15, 6);

			cout << "|";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.STRENGTH + PointBought[0];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "| |";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.DEXTERITY + PointBought[1];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "| |";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.CONSTITUTION + PointBought[2];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "| |";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.AGILITY + PointBought[3];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "| |";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.INTELLIGENCE + PointBought[4];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "| |";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.WISDOM + PointBought[5];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "| |";
			SetColorAndBackground(15, 0);
			cout << " ";
			cout << self.CurrentStats.LUCK + PointBought[6];
			cout << " ";
			SetColorAndBackground(0, 15);
			cout << "|";

			gotoxy(15, 7);

			cout << "| v | | v | | v | | v | | v | | v | | v |";

			gotoxy(15, 8);

			cout << " | |   | |   | |   | |   | |   | |   | |";

			gotoxy(15, 9);

			cout << "  |     |     |     |     |     |     |";

			vector<string> StatNames = {"Strength", "Dexterity","Constitution", "Agility", "Intelligence", "Wisdom", "Luck"};
			vector<string> StatDesc1 = {"Determines the strength of physical attacks.",
										"Determines the power of Dex based weapons and influences Accuracy.",
										"Determines your HP and Defense stats.",
										"Determines your turn order in battle and influences your Evasion.",
										"Determines the strength of your magical attacks",
										"Determines your magical resistance and healing power.",
										"Influences your Accuracy, Evasion, and Critical Hit chance."};
			

			gotoxy(0, 30);
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			gotoxy(0, 30);
			cout << StatNames[choice];
			for (size_t i = 0; i < 82; i++)
			{
				if (i > StatNames[choice].size())
				{
					cout << ".";
				}
			}
			cout << endl;
			cout << StatDesc1[choice];
			for (size_t i = 0; i < 82; i++)
			{
				if (i > StatDesc1[choice].size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << "                                                                                             " << endl;
			cout << "[Points Remaining]: " << PointBuy;
			for (size_t i = 0; i < 40; i++)
			{
				if (i > Selection[choice].Desc2.size())
				{
					cout << " ";
				}
			}
			cout << endl;
			cout << "                                                                                             " << endl;
			cout << ".............................." << "Press [Z] to Continue" << ".............................." << endl;

			NextMove = _getch();

			if (NextMove == KEY_LEFT)
			{
				choice--;
				if (choice < 0)
				{
					choice = 6;
				}

				continue;
			}
			else if (NextMove == KEY_RIGHT)
			{
				choice++;

				if (choice > 6)
				{
					choice = 0;
				}

				continue;

			}
			else if (NextMove == KEY_UP)
			{
				if (PointBuy > 0 && PointBought[choice] < 6)
				{
					PointBuy--;
					PointBought[choice]++;
				}
				continue;
			}
			else if (NextMove == KEY_DOWN)
			{
				if (PointBought[choice] > 0)
				{
					PointBuy ++;
					PointBought[choice]--;
				}
				continue;

			}
			else if (NextMove == 122)
			{
				if (PointBuy == 0)
				{
					self.CurrentStats.STRENGTH += PointBought[0];
					self.CurrentStats.DEXTERITY += PointBought[1];
					self.CurrentStats.CONSTITUTION += PointBought[2];
					self.CurrentStats.AGILITY += PointBought[3];
					self.CurrentStats.INTELLIGENCE += PointBought[4];
					self.CurrentStats.WISDOM += PointBought[5];
					self.CurrentStats.LUCK += PointBought[6];
					self.Max_HP = 8 + self.CurrentStats.CONSTITUTION;
					self.CurrentHP = self.Max_HP;
					self.MaxHP = self.Max_HP;
					self.BattleStats = self.CurrentStats.BattleStats(self.Job.RStat);
					self.RStat = self.Job.RStat;
					system("cls");
					StatedIn = true;
				}
			}
			else
			{
				NextMove = 0;
				continue;
			}

		}
		else 
		{
			//CharacterPromotion(self);
			Building = false;
		}
		
	}
}

