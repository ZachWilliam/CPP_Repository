#include <iostream>
#include "Stats.h"
#include "Combatant.h"
#include "PlayerClass.h"
#include "Backpack.h"
#include "Attack.h"
#include "AttackManager.h"
#pragma once

using namespace std;

class Player : public Combatant
{
public:
    Player()
    {
        name = "";
        GeneratePlayer();
    }
    Player(string call)
    {
        name = call;
        Combatant::name = name;
        GeneratePlayer();
    }
    void GeneratePlayer()
    {
        PlayerControl = true;
    }
    void GenerateAttacks()
    {
        AttackManager Man = AttackManager();
        CurrentMoves = Man.GenerateMovesFromWeapon(PlayerInventory.m_Weapon);
    }

	string name;
	int Level = 1;
	int RStat;
	int CurrentEXP = 0;

	vector<int> OnTheLevel = {0,100,200,400,800,1200,1600,2400,3200,6400,12800,25600,51200,
								102400,153600,204800,307000,409600,614900,819200,
								1214300, 9999999 };
	
	PlayerClass Job = PlayerClass();
	
	int Max_HP = 0;
	
	bool operator==(const Player &che) { return name == che.name; };

	void LevelUp()
	{
		Level++;
		if (Level == 10)
		{
			
		}
		int Determine;
		Determine = (rand() % 100);
		if (Job.STR_G > 100 && CurrentStats.STRENGTH <= 30)
		{
			CurrentStats.STRENGTH++;
			if (Determine < Job.STR_G - 100)
			{
				CurrentStats.STRENGTH++;
				cout << "STR: " << CurrentStats.STRENGTH;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "STR: " << CurrentStats.STRENGTH;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.STR_G && CurrentStats.STRENGTH <= 30)
			{
				CurrentStats.STRENGTH++;
				cout << "STR: " << CurrentStats.STRENGTH;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "STR: " << CurrentStats.STRENGTH << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.DEX_G > 100 && CurrentStats.DEXTERITY <= 30)
		{
			CurrentStats.DEXTERITY++;
			if (Determine < Job.DEX_G - 100)
			{
				CurrentStats.DEXTERITY++;
				cout << "DEX: " << CurrentStats.DEXTERITY;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "DEX: " << CurrentStats.DEXTERITY;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.DEX_G && CurrentStats.DEXTERITY <= 30)
			{
				CurrentStats.DEXTERITY++;
				cout << "DEX: " << CurrentStats.DEXTERITY;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "DEX: " << CurrentStats.DEXTERITY << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.CON_G > 100 && CurrentStats.CONSTITUTION <= 30)
		{
			CurrentStats.CONSTITUTION++;
			if (Determine < Job.CON_G - 100)
			{
				CurrentStats.CONSTITUTION++;
				cout << "CON: " << CurrentStats.CONSTITUTION;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "CON: " << CurrentStats.CONSTITUTION;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.CON_G && CurrentStats.CONSTITUTION <= 30)
			{
				CurrentStats.CONSTITUTION++;
				cout << "CON: " << CurrentStats.CONSTITUTION;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "CON: " << CurrentStats.CONSTITUTION << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.AGI_G > 100 && CurrentStats.AGILITY <= 30)
		{
			CurrentStats.AGILITY++;
			if (Determine < Job.AGI_G - 100)
			{
				CurrentStats.AGILITY++;
				cout << "AGI: " << CurrentStats.AGILITY;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "AGI: " << CurrentStats.AGILITY;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.AGI_G && CurrentStats.AGILITY <= 30)
			{
				CurrentStats.AGILITY++;
				cout << "AGI: " << CurrentStats.AGILITY;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "AGI: " << CurrentStats.AGILITY << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.INT_G > 100 && CurrentStats.INTELLIGENCE <= 30)
		{
			CurrentStats.INTELLIGENCE++;
			if (Determine < Job.INT_G - 100)
			{
				CurrentStats.INTELLIGENCE++;
				cout << "INT: " << CurrentStats.INTELLIGENCE;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "INT: " << CurrentStats.INTELLIGENCE;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.INT_G && CurrentStats.INTELLIGENCE <= 30)
			{
				CurrentStats.INTELLIGENCE++;
				cout << "INT: " << CurrentStats.INTELLIGENCE;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "INT: " << CurrentStats.INTELLIGENCE << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.WIS_G > 100 && CurrentStats.WISDOM <= 30)
		{
			CurrentStats.WISDOM++;
			if (Determine < Job.WIS_G - 100)
			{
				CurrentStats.WISDOM++;
				cout << "WIS: " << CurrentStats.WISDOM;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "WIS: " << CurrentStats.WISDOM;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.WIS_G && CurrentStats.WISDOM <= 30)
			{
				CurrentStats.WISDOM++;
				cout << "WIS: " << CurrentStats.WISDOM;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "WIS: " << CurrentStats.WISDOM << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.LUK_G > 100 && CurrentStats.LUCK <= 30)
		{
			CurrentStats.LUCK++;
			if (Determine < Job.LUK_G - 100)
			{
				CurrentStats.LUCK++;
				cout << "LUK: " << CurrentStats.LUCK;
				SetColorAndBackground(0, 10);
				cout << " (+ 2)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "LUK: " << CurrentStats.LUCK;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
		}
		else
		{
			if (Determine < Job.LUK_G && CurrentStats.LUCK <= 30)
			{
				CurrentStats.LUCK++;
				cout << "LUK: " << CurrentStats.LUCK;
				SetColorAndBackground(0, 2);
				cout << " (+ 1)" << endl;
				SetColorAndBackground(0, 15);
			}
			else
			{
				cout << "LUK: " << CurrentStats.LUCK << endl;
			}
		}
		
		BattleStats = CurrentStats.BattleStats(0);
		Max_HP = 6 * Level + CurrentStats.CONSTITUTION;
		SetHP(Max_HP);
		MaxHP = Max_HP;
	}
};
