#pragma once
#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
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
	PartyInventory();
	vector<Weapon> INV_WEAPON;
	vector<Armor> INV_ARMOR;
	Weapon EQUIPED_WEAPON;
	Armor EQUIPED_ARMOR;

	void SetWeaponsRandom();
	void SetArmorRandom();

	void AddWeapon(int, int, int);
	void AddArmor(int, int, int);

	//int GetID();
	//void SwapEquipedWeapon(int);

	//void SwapEquipedArmor();
	//void DropWeapon(int);

	void DisplayPartyInventory();
};

#endif