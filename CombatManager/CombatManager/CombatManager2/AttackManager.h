#pragma once
#include <iostream>
#include "Attack.h"
#include "Weapon.h"

using namespace std;

class AttackManager
{
public:
	AttackManager();
	void GenerateAttacks();
	vector<Attack> GenerateMovesFromWeapon(Weapon);
	vector<Attack> PhysMoves;
	vector<vector<Attack>> SpellBook;
};
AttackManager::AttackManager()
{
	GenerateAttacks();
}
vector<Attack> AttackManager::GenerateMovesFromWeapon(Weapon self)
{
	vector<Attack> RetVal = vector<Attack>(4);

	if (self.m_Weapon_Type.m_Name == "lance" || self.m_Weapon_Type.m_Name == "rapier")
	{
		RetVal[0] = PhysMoves[0];
	}
	else if (self.m_Weapon_Type.m_Name == "sword" || self.m_Weapon_Type.m_Name == "glaive" || self.m_Weapon_Type.m_Name == "axe")
	{
		RetVal[0] = PhysMoves[1];
	}
	else if (self.m_Weapon_Type.m_Name == "warhammer" || self.m_Weapon_Type.m_Name == "club" || self.m_Weapon_Type.m_Name == "fists" || self.m_Weapon_Type.m_Name == "mace" || self.m_Weapon_Type.m_Name == "staff")
	{
		RetVal[0] = PhysMoves[2];
	}
	else if (self.m_Weapon_Type.m_Name == "daggers")
	{
		RetVal[0] = PhysMoves[3];
	}
	else if (self.m_Weapon_Type.m_Name == "bow")
	{
		RetVal[0] = PhysMoves[4];
	}
	else if (self.m_Weapon_Type.m_Name == "shuriken")
	{
		RetVal[0] = PhysMoves[5];
	}
	if (self.m_Weapon_Type.m_Name == "wand")
	{
		if (self.m_Prefix_Name == "bad" || self.m_Prefix_Name == "basic" || self.m_Prefix_Name == "legendarily bad")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][0];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][1];
			}
		}
		if (self.m_Prefix_Name == "good")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][1];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][2];
			}
		}
		if (self.m_Prefix_Name == "great")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][3];
			}
		}
		if (self.m_Prefix_Name == "legendary" || self.m_Prefix_Name == "Super Fantastic")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][4];
			}
		}
	}
	else if (self.m_Weapon_Type.m_Name == "scroll")
	{
		if (self.m_Prefix_Name == "bad" || self.m_Prefix_Name == "basic" || self.m_Prefix_Name == "legendarily bad" || self.m_Prefix_Name == "good")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][0];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][1];
			}
		}
		if (self.m_Prefix_Name == "great")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][1];
			if (self.SpellSlot > 1)
			{
				if (self.m_DamageType.m_Enhancement == 0)
				{
					RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
				}
				else
				{
					RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][6];
				}
				
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][2];
			}
		}
		if (self.m_Prefix_Name == "legendary" || self.m_Prefix_Name == "Super Fantastic")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
			if (self.SpellSlot > 1)
			{
				if (self.m_DamageType.m_Enhancement == 0)
				{
					RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
				}
				else
				{
					RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][6];
				}

			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][3];
			}
		}
	}
	else if (self.m_Weapon_Type.m_Name == "tome")
	{
		if (self.m_Prefix_Name == "bad" || self.m_Prefix_Name == "basic" || self.m_Prefix_Name == "legendarily bad")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][0];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][1];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][2];
			}
		}
		if (self.m_Prefix_Name == "good" || self.m_Prefix_Name == "great")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][1];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][3];
			}
		}
		if (self.m_Prefix_Name == "legendary" || self.m_Prefix_Name == "Super Fantastic")
		{
			RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
			if (self.SpellSlot > 1)
			{
				RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][3];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][4];
			}
		}
	}
	if (self.m_Weapon_Type.m_Name == "staff" && self.m_DamageType.m_Enhancement != 9)
	{
		if (self.m_Prefix_Name != "legendary" && self.m_Prefix_Name != "Super Fantastic")
		{
			RetVal[1] = PhysMoves[6];
			if (self.SpellSlot > 1)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[3] = SpellBook[self.m_DamageType.m_Enhancement][6];
			}
		}
		else
		{
			RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][6];
			if (self.SpellSlot > 1)
			{
				RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][5];
			}
			if (self.SpellSlot > 2)
			{
				RetVal[3] = SpellBook[self.m_DamageType.m_Enhancement][7];
			}
		}
	}
	else if (self.m_Weapon_Type.m_Name == "staff")
	{
		RetVal[1] = PhysMoves[6];
		if (self.SpellSlot > 1)
		{
			RetVal[2] = PhysMoves[7];
		}
		if (self.SpellSlot > 2)
		{
			RetVal[3] = PhysMoves[8];
		}
	}
	return RetVal;
}
void AttackManager::GenerateAttacks()
{
	
	PhysMoves.push_back(Attack("Skewer", 100, 0));
	PhysMoves.push_back(Attack("Strike", 100, 0));
	PhysMoves.push_back(Attack("Bash", 100, 0));
	PhysMoves.push_back(Attack("Multiattack", 50, 1));
	PhysMoves.push_back(Attack("Shoot", 100, 2));
	PhysMoves.push_back(Attack("Multistrike", 50, 0));
	PhysMoves.push_back(Attack("Heal", 100, 7));
	PhysMoves.push_back(Attack("Cure Ailment", 100, 7));
	PhysMoves.push_back(Attack("Heal More", 100, 7));
	SpellBook.push_back({Attack("Break", 100, 2),
						 Attack("Spacial Rift", 100, 2),
						 Attack("Rupture", 100, 2),
						 Attack("Collapse", 100, 2),
						 Attack("Panta Rei", 100, 2),
						 Attack("Debilitate", 100, 2) });
	SpellBook.push_back({Attack("Fireball", 100, 2),
						 Attack("Firewall", 100, 2),
						 Attack("Hellfire", 100, 2),
						 Attack("Lava Plume", 100, 2),
						 Attack("Ashenheit", 100, 2),
						 Attack("Aggro", 100, 2),
						 Attack("Hearthfire", 100, 2),
						 Attack("Blazing Soul", 100, 2)});
	SpellBook.push_back({ Attack("Ice Shard", 100, 2),
						 Attack("Blizzard", 100, 2),
						 Attack("Cryosphere", 100, 2),
						 Attack("Glaciate", 100, 2),
						 Attack("Aurora", 100, 2),
						 Attack("Winterveil", 100, 2),
						 Attack("Cool Breeze", 100, 2),
						 Attack("Ice Palace", 100, 2) });
	SpellBook.push_back({ Attack("Bubble", 100, 2),
						 Attack("Riptide", 100, 2),
						 Attack("Geyser", 100, 2),
						 Attack("Water Cannon", 100, 2),
						 Attack("Bloodburst", 100, 2),
						 Attack("Oegis", 100, 2),
						 Attack("Fountain", 100, 2),
						 Attack("Wishing Well", 100, 2) });
	SpellBook.push_back({ Attack("Shock", 100, 2),
						 Attack("Plasma Burst", 100, 2),
						 Attack("Thunderbolt", 100, 2),
						 Attack("Discharge", 100, 2),
						 Attack("Thunderhead", 100, 2),
						 Attack("Excite", 100, 2),
						 Attack("Charge", 100, 2),
						 Attack("Supersedence", 100, 2) });
	SpellBook.push_back({ Attack("Gust", 100, 2),
						 Attack("Vorpal Wind", 100, 2),
						 Attack("Tornado", 100, 2),
						 Attack("Hurricane", 100, 2),
						 Attack("Miasmaime", 100, 2),
						 Attack("Stormguard", 100, 2),
						 Attack("Storm Song", 100, 2),
						 Attack("Lunar Rondo", 100, 2) });
	SpellBook.push_back({ Attack("Venom Sting", 100, 2),
						 Attack("Vine Grip", 100, 2),
						 Attack("Virus Wave", 100, 2),
						 Attack("Earthquake", 100, 2),
						 Attack("Blightstorm", 100, 2),
						 Attack("Poison Cloud", 100, 2),
						 Attack("Healing Sap", 100, 2),
						 Attack("Resonance", 100, 2) });
	SpellBook.push_back({ Attack("Life Drain", 100, 2),
						 Attack("Decay Wave", 100, 2),
						 Attack("Nosferatu", 100, 2),
						 Attack("Netherrend", 100, 2),
						 Attack("Hel Vertigo", 100, 2),
						 Attack("Hex Vex", 100, 2),
						 Attack("Nethergate", 100, 2),
						 Attack("Sacred Poetry", 100, 2) });
	SpellBook.push_back({ Attack("Purge", 100, 2),
						 Attack("Radiance", 100, 2),
						 Attack("Smite", 100, 2),
						 Attack("God's Hand", 100, 2),
						 Attack("Edenbeam", 100, 2),
						 Attack("Purify", 100, 2),
						 Attack("Revive", 100, 2),
						 Attack("Heavensend", 100, 2) });
}