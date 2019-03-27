#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Party.h"
#include <Windows.h>
#include "SetColorAndBackground.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void gotoxy(int, int);

struct MyStruct
{
	int key;
	Combatant combatantValue;

	MyStruct(int k, const Combatant& s) : key(k), combatantValue(s) {}
};

struct less_than_key
{
	inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
	{
		return (struct1.key < struct2.key);
	}
};

class Encounter
{
public:
	Encounter(int, int, int, int, int, int);
	void GenerateEncounter(Party);
	void CalculateInitiative();
	void TakeTurn();
	void Attack(Player, Combatant);
	void Attack(Enemy, Combatant);
	vector<int> AllEnemies = { -1,-1,-1,-1,-1,-1 };
	Party PlayerParty;
	vector<Enemy> FrontRow = { Enemy(AllEnemies[0]), Enemy(AllEnemies[1]), Enemy(AllEnemies[2]) };
	vector<Enemy> BackRow = { Enemy(AllEnemies[3]), Enemy(AllEnemies[4]), Enemy(AllEnemies[5]) };
	vector<MyStruct> Order;
	int InitiativeOrder = 0;
	int MinLevel;
	int Level;
	int Selection = 0;
	int NextMove = 0;
	bool Battling = true;
	bool TopMenu = true;
	bool AtkMenu = false;
	bool ItmMenu = false;
	bool Flee = false;
	enum BattleStats { ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT };
};
Encounter::Encounter(int FL_E, int FC_E, int FR_E, int BL_E, int BC_E, int BR_E)
{
	AllEnemies = {FL_E,FC_E,FR_E,BL_E,BC_E,BR_E};
	FrontRow = { Enemy(AllEnemies[0]), Enemy(AllEnemies[1]), Enemy(AllEnemies[2]) };
	BackRow = { Enemy(AllEnemies[3]), Enemy(AllEnemies[4]), Enemy(AllEnemies[5]) };
}
void Encounter::GenerateEncounter(Party Players)
{
	PlayerParty = Players;
	CalculateInitiative();

}
void Encounter::CalculateInitiative()
{
	for (size_t i = 0; i < PlayerParty.Container.size(); i++)
	{
		
		if (PlayerParty.Container[i].name != "NULL_NAME")
		{
			Order.push_back(MyStruct(PlayerParty.Container[i].BattleStats[SPEED], PlayerParty.Container[i]));
		}
	}
	for (size_t i = 0; i < 3; i++)
	{

		if (!FrontRow[i].NullEnemy)
		{
			Order.push_back(MyStruct(FrontRow[i].BattleStats[SPEED], FrontRow[i]));
		}
		if (!BackRow[i].NullEnemy)
		{
			Order.push_back(MyStruct(BackRow[i].BattleStats[SPEED], BackRow[i]));
		}
	}
	sort(Order.begin(), Order.end(), less_than_key());
}
void Encounter::Attack(Player User, Combatant Target)
{
	int Damage = User.PlayerInventory.m_Weapon.Attack();
	Damage += User.CurrentStats.ValueFromStatIn(User.PlayerInventory.m_Weapon.m_Weapon_Type.m_StatUsed);
	if (User.PlayerInventory.m_Weapon.m_Weapon_Type.magic)
	{
		Damage -= Target.BattleStats[RESISTANCE];
	}
	else
	{
		Damage -= Target.BattleStats[DEFENSE];
	}
	if (User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement > 0 && User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement < 9)
	{
		if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 0)
		{
			Damage *= Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2];
		}
		else
		{
			Damage *= (Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2] / float(2));
		}
		
	}
	if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 1)
	{
		Damage *= Target.Resistances[0];
	}
	if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 2)
	{
		Damage *= Target.Resistances[1];
	}
	if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 3 || User.PlayerInventory.m_Weapon.m_Weapon_Type.staff)
	{
		Damage *= Target.Resistances[2];
	}
	Target.CurrentHP -= Damage;

}
void Encounter::Attack(Enemy User, Combatant Target)
{

}
void Encounter::TakeTurn()
{
	
	for (int i = Order.size() - 1; i >= 0; i--)
	{
		if (Order[i].combatantValue.CurrentHP <= 0 && Order[i].combatantValue.PlayerControl == false)
		{
			Order.erase(Order.begin()+i);
			if (i <= InitiativeOrder)
			{
				InitiativeOrder--;
			}
		}
	}
	Battling = false;
	for (int i = Order.size() - 1; i >= 0; i--)
	{
		if (!Order[i].combatantValue.PlayerControl)
		{
			Battling = true;
		}
	}
	if (!Battling)
	{
		return;
	}
	//if (Order[InitiativeOrder].combatantValue.name == "")
	//{
	//	return;
	//}
	if (Order[InitiativeOrder].combatantValue.PlayerControl)
	{
		Selection = 0;
		NextMove = 0;
		TopMenu = true;
		AtkMenu = false;
		ItmMenu = false;
		Flee = false;
		while (true)
		{
			gotoxy(0, 33);
			if (TopMenu)
			{
				cout << "Select your action:" << endl;
				for (size_t i = 0; i < 3; i++)
				{
					cout << "|";
					if (Selection == i)
					{
						SetColorAndBackground(15, 0);
					}
					else
					{
						SetColorAndBackground(0, 15);
					}
					if (i == 0)
					{
						cout << "           Fight          ";
					}
					if (i == 1)
					{
						cout << "           Item           ";
					}
					if (i == 2)
					{
						cout << "           Flee           ";
					}
					SetColorAndBackground(0, 15);
				}
				cout << "|" << endl;
			}
			else if (AtkMenu)
			{
				cout << "Select your attack:" << endl;
				for (size_t i = 0; i < 3; i++)
				{
					cout << "|";
					if (Selection == i)
					{
						SetColorAndBackground(15, 0);
					}
					else
					{
						SetColorAndBackground(0, 15);
					}
					if (i == 0)
					{
						cout << "          Skewer          ";
					}
					if (i == 1)
					{
						cout << "           Bash           ";
					}
					if (i == 2)
					{
						cout << "           Slash          ";
					}
					SetColorAndBackground(0, 15);
				}
				cout << "|" << endl;
			}
			else if (ItmMenu)
			{
				cout << "Used an item!";
			}
			else if (Flee)
			{
				cout << Order[InitiativeOrder].combatantValue.name << " has fled the battle!";
				Order.erase(Order.begin() + InitiativeOrder);
			}
			NextMove = _getch();

			if (NextMove == KEY_LEFT)
			{
				Selection--;
				if (Selection < 0)
				{
					Selection = 2;
				}

				continue;
			}
			else if (NextMove == KEY_RIGHT)
			{
				Selection++;

				if (Selection > 2)
				{
					Selection = 0;
				}

				continue;

			}
			else if (NextMove == 122)
			{
				if (Selection == 0 && TopMenu)
				{
					TopMenu = false;
					AtkMenu = true;
				}
				else if (Selection == 1 && TopMenu)
				{
					TopMenu = false;
					ItmMenu = true;
				}
				else if (Selection == 2 && TopMenu)
				{
					TopMenu = false;
					Flee = true;
				}
				else if (Selection == 0 && AtkMenu)
				{

					break;
				}
				else if (Selection == 1 && AtkMenu)
				{
					break;
				}
				else if (Selection == 2 && AtkMenu)
				{
					break;
				}

			}
			else if (NextMove == 120)
			{
				if (ItmMenu || AtkMenu)
				{
					ItmMenu = false;
					AtkMenu = false;
					TopMenu = true;
				}
			}
			else
			{
				NextMove = 0;
				continue;
			}

		}
		InitiativeOrder++;
		if (InitiativeOrder >= Order.size())
		{
			InitiativeOrder = 0;
		}
	}
	else
	{
		gotoxy(0, 33);
		cout << "Slime acts!";
		InitiativeOrder++;
		if (InitiativeOrder >= Order.size())
		{
			InitiativeOrder = 0;
		}
	}
}