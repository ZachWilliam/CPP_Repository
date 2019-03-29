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


#endif