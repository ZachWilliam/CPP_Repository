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
	Stats stats;
	Stats StatGrows;
	int Level;
	int MAX_HP;
	enum BStats { ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT };
	bool NullEnemy = false;


};
Enemy::Enemy(int ID) : Combatant()
{
	GenerateEnemy(ID);
	this->SetHP(MAX_HP);
}

void Enemy::GenerateEnemy(int ID)
{
	// Generates an Enemy from a Monster object
	EnemyID = ID;
	if (ID != -1)
	{
		Species = "Slime";
		stats = Stats(1, 1, 1, 1, 1, 1, 1);
		StatGrows = Stats(50, 10, 120, 10, 10, 20, 70);
		Level = 15;
		SpawnAtLevel(Level);
		MAX_HP = 0;
	}
	else
	{
		NullEnemy = true;
	}
}
void Enemy::SpawnAtLevel(int level)
{
	srand(static_cast<unsigned int>(time(0)));
	int Determine;
	for (size_t i = 0; i < level - 1; i++)
	{
		Determine = (rand() % 100);
		if (StatGrows.STRENGTH > 100)
		{
			stats.STRENGTH++;
			if (Determine < StatGrows.STRENGTH - 100)
			{
				stats.STRENGTH++;
			}
		}
		else
		{
			if (Determine < StatGrows.STRENGTH)
			{
				stats.STRENGTH++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.DEXTERITY > 100)
		{
			stats.DEXTERITY++;
			if (Determine < StatGrows.DEXTERITY - 100)
			{
				stats.DEXTERITY++;
			}
		}
		else
		{
			if (Determine < StatGrows.DEXTERITY)
			{
				stats.DEXTERITY++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.CONSTITUTION > 100)
		{
			stats.CONSTITUTION++;
			if (Determine < StatGrows.CONSTITUTION - 100)
			{
				stats.CONSTITUTION++;
			}
		}
		else
		{
			if (Determine < StatGrows.CONSTITUTION)
			{
				stats.CONSTITUTION++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.AGILITY > 100)
		{
			stats.AGILITY++;
			if (Determine < StatGrows.AGILITY - 100)
			{
				stats.AGILITY++;
			}
		}
		else
		{
			if (Determine < StatGrows.AGILITY)
			{
				stats.AGILITY++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.INTELLIGENCE > 100)
		{
			stats.INTELLIGENCE++;
			if (Determine < StatGrows.INTELLIGENCE - 100)
			{
				stats.INTELLIGENCE++;
			}
		}
		else
		{
			if (Determine < StatGrows.INTELLIGENCE)
			{
				stats.INTELLIGENCE++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.WISDOM > 100)
		{
			stats.WISDOM++;
			if (Determine < StatGrows.WISDOM - 100)
			{
				stats.WISDOM++;
			}
		}
		else
		{
			if (Determine < StatGrows.WISDOM)
			{
				stats.WISDOM++;
			}
		}
		Determine = (rand() % 100);
		if (StatGrows.LUCK > 100)
		{
			stats.LUCK++;
			if (Determine < StatGrows.LUCK - 100)
			{
				stats.LUCK++;
			}
		}
		else
		{
			if (Determine < StatGrows.LUCK)
			{
				stats.LUCK++;
			}
		}
	}
	BattleStats = stats.BattleStats(0);
}
void Enemy::toString()
{
	cout << "Enemy: " << Species << " | Level: " << Level << " | HP: " << CurrentHP << "/" << MAX_HP << endl;
	cout << "STR: " << stats.STRENGTH << " | DEX: " << stats.DEXTERITY << " | CON: " << stats.CONSTITUTION << " |";
	cout << " AGI: " << stats.AGILITY << " | INT: " << stats.INTELLIGENCE << " | WIS: " << stats.WISDOM << " |";
	cout << " LUK: " << stats.LUCK;
}