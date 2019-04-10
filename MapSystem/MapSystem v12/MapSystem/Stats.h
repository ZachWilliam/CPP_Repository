#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Stats
{
public:
	Stats(int str = 0, int dex = 0, int con = 0, int agi = 0, int in = 0, int wis = 0, int luk = 0)
	{
		STRENGTH = str;
		DEXTERITY = dex;
		CONSTITUTION = con;
		AGILITY = agi;
		INTELLIGENCE = in;
		WISDOM = wis;
		LUCK = luk;
	}
	inline Stats(string serialString);

	inline string Serialized();

	vector<int> BattleStats(int Relevant)
	{
		vector<int> RetVal(10);
		if (Relevant == STR)
		{
			RetVal[ATTACK] = STRENGTH;
		}
		else if (Relevant == DEX)
		{
			RetVal[ATTACK] = DEXTERITY;
		}
		else
		{
			RetVal[ATTACK] = STRENGTH;
		}

		RetVal[DEFENSE] = CONSTITUTION;

		if (Relevant == INT)
		{
			RetVal[MAGIC] = INTELLIGENCE;
		}
		else if (Relevant == WIS)
		{
			RetVal[MAGIC] = WISDOM;
		}
		else
		{
			RetVal[MAGIC] = INTELLIGENCE;
		}

		RetVal[RESISTANCE] = WISDOM;

		RetVal[SPEED] = AGILITY;

		RetVal[HIT] = (DEXTERITY / 2 + LUCK / 2);

		RetVal[AVOID] = (SPEED / 2 + LUCK / 2);

		RetVal[CRIT] = LUCK;

		return RetVal;

	}
	int ValueFromStatIn(int statin)
	{
		if (statin == 0)
		{
			return STRENGTH;
		}
		if (statin == 1)
		{
			return DEXTERITY;
		}
		if (statin == 2)
		{
			return INTELLIGENCE;
		}
		if (statin == 3)
		{
			return WISDOM;
		}
	}
	int STRENGTH, DEXTERITY, CONSTITUTION, AGILITY, INTELLIGENCE, WISDOM, LUCK;
	enum BattleStats { ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT };
	enum StatIn { STR = 0, DEX = 1, INT = 2, WIS = 3 };
};

Stats::Stats(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string Stats::Serialized()
{
	string serialString = "";

	serialString += "STRENGTH:" + to_string(STRENGTH) + ",";
	serialString += "DEXTERITY:" + to_string(DEXTERITY) + ",";
	serialString += "CONSTITUTION:" + to_string(CONSTITUTION) + ",";
	serialString += "AGILITY:" + to_string(AGILITY) + ",";
	serialString += "INTELLIGENCE:" + to_string(INTELLIGENCE) + ",";
	serialString += "WISDOM:" + to_string(WISDOM) + ",";
	serialString += "LUCK:" + to_string(LUCK) + ",";

	return serialString;
}