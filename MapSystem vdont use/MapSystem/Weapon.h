#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Items.h"
#include <ctime>

using namespace std;

class WeaponType
{
public:
	WeaponType(string, int, int, int, int);
	WeaponType();
	string ToString();
	string m_Name;
	int m_DamageMIN;
	int m_DamageMAX;
	enum stat { Str = 0, Dex = 1, Int = 2, Wis = 3 };
	stat m_StatUsed;
	enum wield { simple = 0, martial = 1, ranged = 2, magic = 3, staff = 4 };
	wield m_Wielded;
};


class DamageType
{
public:
	DamageType(int, int);
	enum HitType { no_hit = 0, pierce = 1, slash = 2, bludgeon = 3 };
	HitType m_Technique;
	vector<string> Element = { "entrophy", "fire", "ice", "water", "thunder", "wind", "earth", "darkness", "light", "healing" };
	int m_Enhancement;
	string ToString(bool);
};



class Weapon
{
public:
	int ID;
	Weapon(int WeaponChoice = 0, int prefix_name = -1);
	void Status();
	int Attack();
	string GetName(int Choice);
	void GetType(int Choice);
	void SetDamageType(int EleChoice);
	void DisplayName();
	string DisplayNameText();
	int SpellSlot = 0;
	int GetSellValue();
	int GetBuyValue();
	vector<WeaponType> WEAPON_TYPES = { WeaponType("fists", 0, 3, 0, 0), //weapon, damMin, damMAx, statUsed, wield
										WeaponType("sword", 2, 5, 0, 0),
										WeaponType("rapier", 2, 5, 1, 0),
										WeaponType("axe", 3, 8, 0, 1),
										WeaponType("warhammer", 4, 7, 0, 1),
										WeaponType("mace", 1, 6, 0, 0),
										WeaponType("club", 0, 4, 0, 0),
										WeaponType("lance", 4, 4, 0, 1),
										WeaponType("glaive", 3, 5, 0, 1),
										WeaponType("wand", 2, 5, 2, 3),
										WeaponType("tome", 0, 7, 2, 3),
										WeaponType("scroll", 3, 4, 2, 3),
										WeaponType("staff", 2, 2, 3, 4),
										WeaponType("shuriken", 1, 2, 1, 2),
										WeaponType("daggers", 1, 2, 1, 0),
										WeaponType("bow", 2, 5, 1, 2) };
//private:
	string m_Prefix_Name;
	WeaponType m_Weapon_Type;
	int m_DamageMIN;
	int m_DamageMAX;
	bool m_Magic = false;
	DamageType m_DamageType;

	void SetWeapon(int, int, int);
	void SetSuperWeapon(int);
	void SetRandomWeapon();

	static const int NUM_PREFIX_NAMES = 7;
	static const string PREFIX_NAMES[NUM_PREFIX_NAMES];
};



#endif