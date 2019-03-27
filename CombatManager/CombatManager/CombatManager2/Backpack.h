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
	Backpack(int gold = 0, int buildingMaterials = 0, bool questItem = false,
		int setWeaponType = 0, int setWeaponName = 1, int setDamType = 10,
		int setArmorType = 0, int setArmorName = 1, int setResType = 10,
		int potion = 12);
	Purse m_Purse = Purse();
	Weapon m_Weapon = Weapon();
	Armor m_Armor = Armor();
	Potion m_Potion = Potion();
	void Status();
};


#endif