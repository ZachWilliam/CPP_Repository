#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Combatant.h"
#include "Stats.h"
#include <time.h>
#pragma once
using namespace std;

class Enemy : public Combatant
{
public:
	Enemy(int ID);
	void GenerateEnemy(int ID);
	void toString();
	void SpawnAtLevel(int);
	int EnemyID;
	string Species;
	Stats BaseStats;
	Stats StatGrows;
	int Level;
	int MAX_HP;

};
Enemy::Enemy(int ID) : Combatant()
{
	GenerateEnemy(ID);
	this->SetHP(MAX_HP);
}

void Enemy::GenerateEnemy(int ID)
{
	EnemyID = ID;
	Species = "Slime";
	BaseStats = Stats(1, 1, 1, 1, 1, 1, 1);
	StatGrows = Stats(50, 50, 50, 50, 50, 50, 50);
	Level = 3;
	SpawnAtLevel(Level);
	MAX_HP = 0;
}
void Enemy::SpawnAtLevel(int level)
{
	BattleStats = BaseStats;
	srand(static_cast<unsigned int>(time(0)));
	int Determine;
	for (size_t i = 0; i < level - 1; i++)
	{
		Determine = (rand() % 100);
		if (StatGrows.STRENGTH > 100)
		{
			BattleStats.STRENGTH++;
			if (Determine < StatGrows.STRENGTH - 100)
			{
				BattleStats.STRENGTH++;
			}
		}
		else
		{
			if (Determine < StatGrows.STRENGTH)
			{
				BattleStats.STRENGTH++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.DEXTERITY > 100)
		{
			BattleStats.DEXTERITY++;
			if (Determine < StatGrows.DEXTERITY - 100)
			{
				BattleStats.DEXTERITY++;
			}
		}
		else
		{
			if (Determine < StatGrows.DEXTERITY)
			{
				BattleStats.DEXTERITY++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.CONSTITUTION > 100)
		{
			BattleStats.CONSTITUTION++;
			if (Determine < StatGrows.CONSTITUTION - 100)
			{
				BattleStats.CONSTITUTION++;
			}
		}
		else
		{
			if (Determine < StatGrows.CONSTITUTION)
			{
				BattleStats.CONSTITUTION++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.AGILITY > 100)
		{
			BattleStats.AGILITY++;
			if (Determine < StatGrows.AGILITY - 100)
			{
				BattleStats.AGILITY++;
			}
		}
		else
		{
			if (Determine < StatGrows.AGILITY)
			{
				BattleStats.AGILITY++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.INTELLIGENCE > 100)
		{
			BattleStats.INTELLIGENCE++;
			if (Determine < StatGrows.INTELLIGENCE - 100)
			{
				BattleStats.INTELLIGENCE++;
			}
		}
		else
		{
			if (Determine < StatGrows.INTELLIGENCE)
			{
				BattleStats.INTELLIGENCE++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.WISDOM > 100)
		{
			BattleStats.WISDOM++;
			if (Determine < StatGrows.WISDOM - 100)
			{
				BattleStats.WISDOM++;
			}
		}
		else
		{
			if (Determine < StatGrows.WISDOM)
			{
				BattleStats.WISDOM++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.LUCK > 100)
		{
			BattleStats.LUCK++;
			if (Determine < StatGrows.LUCK - 100)
			{
				BattleStats.LUCK++;
			}
		}
		else
		{
			if (Determine < StatGrows.LUCK)
			{
				BattleStats.LUCK++;
			}
		}
	}
}
void Enemy::toString()
{
	cout << "Enemy: " << Species << " | Level: " << Level << " | HP: " << CurrentHP << "/" << MAX_HP << endl;
	cout << "STR: " << BattleStats.STRENGTH << " | DEX: " << BattleStats.DEXTERITY << " | CON: " << BattleStats.CONSTITUTION;
	cout << " AGI: " << BattleStats.AGILITY << " | INT: " << BattleStats.INTELLIGENCE << " | WIS: " << BattleStats.WISDOM;
	cout << " LUK: " << BattleStats.LUCK;
}