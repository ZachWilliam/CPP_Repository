#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Stats
{
public:
	Stats(int, int, int, int, int, int, int);
	vector<int> BattleStats(int);
	int STRENGTH, DEXTERITY, CONSTITUTION, AGILITY, INTELLIGENCE, WISDOM, LUCK;
	enum BattleStats {ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT};
	enum StatIn {STR = 0, DEX = 1, INT = 2, WIS = 3};
};
Stats::Stats(int str = 0, int dex = 0, int con = 0, int agi = 0, int in = 0, int wis = 0, int luk = 0)
{
	STRENGTH = str;
	DEXTERITY = dex;
	CONSTITUTION = con;
	AGILITY = agi;
	INTELLIGENCE = in;
	WISDOM = wis;
	LUCK = luk;
}
vector<int> Stats::BattleStats(int Relevant)
{
	vector<int> RetVal(10);
	if (Relevant = STR) 
	{
		RetVal[ATTACK] = STRENGTH;
	}
	else if (Relevant = DEX)
	{
		RetVal[ATTACK] = DEXTERITY;
	}
	else
	{
		RetVal[ATTACK] = _Max_value(STRENGTH, DEXTERITY);
	}

	RetVal[DEFENSE] = CONSTITUTION;

	if (Relevant = INT)
	{
		RetVal[MAGIC] = INTELLIGENCE;
	}
	else if (Relevant = WIS)
	{
		RetVal[MAGIC] = WISDOM;
	}
	else
	{
		RetVal[MAGIC] = _Max_value(INTELLIGENCE, WISDOM);
	}
	
	RetVal[RESISTANCE] = WISDOM;
	
	RetVal[SPEED] = AGILITY;

	RetVal[HIT] = (DEXTERITY / 2 + LUCK / 2);

	RetVal[AVOID] = (SPEED / 2 + LUCK / 2);

	RetVal[CRIT] = LUCK;

	return RetVal;

}