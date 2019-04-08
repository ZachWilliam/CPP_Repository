#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Combatant.h"
#include "Stats.h"
#include "Monster.h"
#include <time.h>
#pragma once
using namespace std;

class Enemy : public Combatant
{
public:
	Enemy(int id) : Combatant()
	{
		GenerateEnemy(id);
	}
	Enemy(Monster me, int lvl) : Combatant()
    {
        GenerateEnemy(me, lvl);
    }

    void GenerateEnemy(int id)
    {
        // Generates an Enemy from a Monster object
        EnemyID = id;
        if (EnemyID != -1)
        {
            Species = "Slime";
            name = Species;
            stats = Stats(5, 1, 1, 1, 1, 1, 1);
            StatGrows = Stats(50, 10, 120, 10, 10, 20, 70);
            Level = 5;

            SpawnAtLevel(Level);
            MAX_HP = 8 + stats.CONSTITUTION * 2;
            SetHP(MAX_HP);
        }
        else
        {
            NullEnemy = true;
        }
    }
	void GenerateEnemy(Monster me, int lvl)
	{
		// Generates an Enemy from a Monster object
		EnemyID = me.m_ID;
		if (EnemyID != -1)
		{
			Species = me.m_Name;
			name = Species;
			stats = Stats(me.m_Str, me.m_Dex, me.m_Con, me.m_Agi, me.m_Intel, me.m_Wis, me.m_Luk);
			StatGrows = Stats(me.m_Str_G, me.m_Dex_G, me.m_Con_G, me.m_Agi_G, me.m_Intel_G, me.m_Wis_G, me.m_Luk_G);
			Resistances = {	me.m_PierceRes,
							me.m_SlashRes,
							me.m_BludgeonRes,
							me.m_FireRes,
							me.m_IceRes,
							me.m_WaterRes,
							me.m_ThunderRes,
							me.m_WindRes,
							me.m_EarthRes,
							me.m_DarkRes,
							me.m_LightRes};
			Level = lvl;
			AI = me.m_Target;

			SpawnAtLevel(Level);
			MAX_HP = stats.CONSTITUTION + Level * (stats.CONSTITUTION / 2);
			SetHP(MAX_HP);
		}
		else
		{
			NullEnemy = true;
		}
	}
    void SpawnAtLevel(int level)
    {
        //srand(static_cast<unsigned int>(time(0)));
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
        MAX_HP = 8 + Level * (stats.CONSTITUTION / 2);
        SetHP(MAX_HP);
        MaxHP = MAX_HP;
    }
	int GetXP()
	{
		int RetVal = 0;
		RetVal += stats.STRENGTH;
		RetVal += stats.DEXTERITY;
		RetVal += stats.CONSTITUTION;
		RetVal += stats.AGILITY;
		RetVal += stats.INTELLIGENCE;
		RetVal += stats.WISDOM;
		RetVal += stats.LUCK;
		RetVal *= Level;
		return RetVal;

	}
    void toString()
    {
        cout << "Enemy: " << Species << " | Level: " << Level << " | HP: " << CurrentHP << "/" << MAX_HP << endl;
        cout << "STR: " << stats.STRENGTH << " | DEX: " << stats.DEXTERITY << " | CON: " << stats.CONSTITUTION << " |";
        cout << " AGI: " << stats.AGILITY << " | INT: " << stats.INTELLIGENCE << " | WIS: " << stats.WISDOM << " |";
        cout << " LUK: " << stats.LUCK;
    }
	int EnemyID;
	string Species;
	Stats stats;
	Stats StatGrows;
	int Level;
	int MAX_HP = 0;
	enum BStats { ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT };
	bool NullEnemy = false;
	int AI = 0;
	enum Target {RANDOM = 0, WEAKEST, STRONGEST, LEADER};


};
