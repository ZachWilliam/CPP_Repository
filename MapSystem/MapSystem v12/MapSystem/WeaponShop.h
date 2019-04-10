#pragma once
#ifndef WEAPONSHOP_H
#define WEAPONSHOP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Weapon.h"
#include "Armor.h"
#include "Items.h"
#include "Backpack.h"

using namespace std;

class WeaponShop
{
public:
	WeaponShop();
	vector<Weapon> STORE_WEAPON_LIST;
	void Greeting();
	void Buy(PartyInventory &PIref);
	void Sell(PartyInventory &PIref);
};




#endif