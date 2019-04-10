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
	Player(string call/*, char dummyValue*/)
	{
		name = call;
		Combatant::name = name;
		GeneratePlayer();
	}
	inline Player(string serialString, char dummyValue);

	inline string Serialized();

	void GeneratePlayer()
	{
		PlayerControl = true;
	}
	void GenerateAttacks()
	{
		AttackManager Man = AttackManager();
		CurrentMoves = Man.GenerateMovesFromWeapon(PlayerInventory.m_Weapon);
	}

	//string name;			// TODO - determine if this is needed or not as it is inherited from the Combatant class
	int Level = 1;
	int RStat;
	int CurrentEXP = 0;

	vector<int> OnTheLevel = { 0,100,200,400,800,1600,3200,6400,12800,25600,51200,
								102400,153600,204800,307000,409600,614900,819200,
								1214300,1638400,2457600,3276800 };

	PlayerClass Job = PlayerClass();

	int Max_HP = 0;

	bool operator==(const Player &che) { return name == che.name; };

	void LevelUp()
	{
		Level++;
		int Determine;
		Determine = (rand() % 100);
		if (Job.STR_G > 100)
		{
			CurrentStats.STRENGTH++;
			if (Determine < Job.STR_G - 100)
			{
				CurrentStats.STRENGTH++;
				cout << "STR: " << CurrentStats.STRENGTH << " + 2" << endl;
			}
			else
			{
				cout << "STR: " << CurrentStats.STRENGTH << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.STR_G)
			{
				CurrentStats.STRENGTH++;
				cout << "STR: " << CurrentStats.STRENGTH << " + 1" << endl;
			}
			else
			{
				cout << "STR: " << CurrentStats.STRENGTH << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.DEX_G > 100)
		{
			CurrentStats.DEXTERITY++;
			if (Determine < Job.DEX_G - 100)
			{
				CurrentStats.DEXTERITY++;
				cout << "DEX: " << CurrentStats.DEXTERITY << " + 2" << endl;
			}
			else
			{
				cout << "DEX: " << CurrentStats.DEXTERITY << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.DEX_G)
			{
				CurrentStats.DEXTERITY++;
				cout << "DEX: " << CurrentStats.DEXTERITY << " + 1" << endl;
			}
			else
			{
				cout << "DEX: " << CurrentStats.DEXTERITY << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.CON_G > 100)
		{
			CurrentStats.CONSTITUTION++;
			if (Determine < Job.CON_G - 100)
			{
				CurrentStats.CONSTITUTION++;
				cout << "CON: " << CurrentStats.CONSTITUTION << " + 2" << endl;
			}
			else
			{
				cout << "CON: " << CurrentStats.CONSTITUTION << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.CON_G)
			{
				CurrentStats.CONSTITUTION++;
				cout << "CON: " << CurrentStats.CONSTITUTION << " + 1" << endl;
			}
			else
			{
				cout << "CON: " << CurrentStats.CONSTITUTION << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.AGI_G > 100)
		{
			CurrentStats.AGILITY++;
			if (Determine < Job.AGI_G - 100)
			{
				CurrentStats.AGILITY++;
				cout << "AGI: " << CurrentStats.AGILITY << " + 2" << endl;
			}
			else
			{
				cout << "AGI: " << CurrentStats.AGILITY << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.AGI_G)
			{
				CurrentStats.AGILITY++;
				cout << "AGI: " << CurrentStats.AGILITY << " + 1" << endl;
			}
			else
			{
				cout << "AGI: " << CurrentStats.AGILITY << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.INT_G > 100)
		{
			CurrentStats.INTELLIGENCE++;
			if (Determine < Job.INT_G - 100)
			{
				CurrentStats.INTELLIGENCE++;
				cout << "INT: " << CurrentStats.AGILITY << " + 2" << endl;
			}
			else
			{
				cout << "INT: " << CurrentStats.AGILITY << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.INT_G)
			{
				CurrentStats.INTELLIGENCE++;
				cout << "INT: " << CurrentStats.AGILITY << " + 1" << endl;
			}
			else
			{
				cout << "INT: " << CurrentStats.AGILITY << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.WIS_G > 100)
		{
			CurrentStats.WISDOM++;
			if (Determine < Job.WIS_G - 100)
			{
				CurrentStats.WISDOM++;
				cout << "WIS: " << CurrentStats.WISDOM << " + 2" << endl;
			}
			else
			{
				cout << "WIS: " << CurrentStats.WISDOM << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.WIS_G)
			{
				CurrentStats.WISDOM++;
				cout << "WIS: " << CurrentStats.WISDOM << " + 1" << endl;
			}
			else
			{
				cout << "WIS: " << CurrentStats.WISDOM << endl;
			}
		}
		Determine = (rand() % 100);
		if (Job.LUK_G > 100)
		{
			CurrentStats.LUCK++;
			if (Determine < Job.LUK_G - 100)
			{
				CurrentStats.LUCK++;
				cout << "LUK: " << CurrentStats.LUCK << " + 2" << endl;
			}
			else
			{
				cout << "LUK: " << CurrentStats.LUCK << " + 1" << endl;
			}
		}
		else
		{
			if (Determine < Job.LUK_G)
			{
				CurrentStats.LUCK++;
				cout << "LUK: " << CurrentStats.LUCK << " + 1" << endl;
			}
			else
			{
				cout << "LUK: " << CurrentStats.LUCK << endl;
			}
		}

		BattleStats = CurrentStats.BattleStats(0);
		Max_HP = 8 + Level * (CurrentStats.CONSTITUTION / 2);
		SetHP(Max_HP);
		MaxHP = Max_HP;
	}
};

Player::Player(string serialString, char dummyValue)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string Player::Serialized()
{
	string serialString = "";

	// from "Combatant"
	serialString += "name:" + name + ",";
	serialString += "status:" + etos((int)status) + ",";
	serialString += "OFFENSE:" + etos((int)OFFENSE) + ",";
	serialString += "DEFENSE:" + etos((int)DEFENSE) + ",";
	serialString += "MOBILITY:" + etos((int)MOBILITY) + ",";
	serialString += "CurrentStats{" + CurrentStats.Serialized() + "},";
	{
		serialString += "BattleStats[";
		if (BattleStats.size() > 0)
		{
			for (size_t i = 0; i < BattleStats.size(); ++i)
			{
				serialString += "stat:" + to_string(BattleStats[i]) + ",";
			}
		}
		serialString += "],";
	}
	{
		serialString += "Resistances[";
		if (Resistances.size() > 0)
		{
			for (size_t i = 0; i < Resistances.size(); ++i)
			{
				serialString += "res:" + to_string(Resistances[i]) + ",";
			}
		}
		serialString += "],";
	}
	serialString += "init:" + to_string(initiative) + ",";
	serialString += "HP:" + to_string(CurrentHP) + ",";
	serialString += "MaxHP:" + to_string(MaxHP) + ",";
	serialString += "Mana:" + to_string(CurrentMana) + ",";
	serialString += "PlayerControl:" + btos(PlayerControl) + ",";
	{
		serialString += "CurrentMoves[";
		if (CurrentMoves.size() > 0)
		{
			for (size_t i = 0; i < CurrentMoves.size(); ++i)
			{
				serialString += "{";
				serialString += CurrentMoves[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	serialString += "PlayerInventory{" + PlayerInventory.Serialized() + "},";
	// from "Player"
	serialString += "LVL:" + to_string(Level) + ",";
	serialString += "RStat:" + to_string(RStat) + ",";
	serialString += "EXP:" + to_string(CurrentEXP) + ",";
	serialString += "Job{" + Job.Serialized() + "},";

	return serialString;
}