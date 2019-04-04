#pragma once
#ifndef PARTYINVENTORY_H
#define PARTYINVENTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Backpack.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class PartyInventory
{
public:
	PartyInventory();

	vector<Weapon> INV_WEAPON;

	vector<Armor> INV_ARMOR;

	void SetWeaponsRandom();
	void SetArmorRandom();

	void AddWeapon(int, int, int);
	void AddArmor(int, int, int);

	int GetID();
	void SwapEquipedWeapon();

	//void SwapEquipedArmor();

	//void DropWeapon(int);

	void DisplayPartyInventory();
};



#endif
