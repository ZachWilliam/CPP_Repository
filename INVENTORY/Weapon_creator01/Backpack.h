#pragma once
#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Weapon.h"
#include "Armor.h"
#include "Items.h"

using namespace std;


class Backpack
{
public:
	Backpack(int, int, bool, int, int, int, int, int, int, int);
	Purse m_Purse = Purse();
	Weapon m_Weapon = Weapon();
	Armor m_Armor = Armor();
	Potion m_Potion = Potion();
	void Status();
};

class PartyInventory
{
public:
	PartyInventory(Backpack &BPref);
	vector<Weapon> INV_WEAPON;
	vector<Armor> INV_ARMOR;
	Weapon EQUIPED_WEAPON;
	Armor EQUIPED_ARMOR;

	void SetWeaponsRandom();
	void SetArmorRandom();

	void AddWeapon(int, int, int);
	void AddArmor(int, int, int);

	void SwapEquipedWeapon(Backpack &BPref);
	void SwapEquipedArmor(Backpack &BPref);

	void DisplayPartyInventory();
	void DisplayPartyWeapons();
	void DisplayPartyArmor();
};


#endif