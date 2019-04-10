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
	Backpack(string serialString);

	string Serialized();

	Purse m_Purse = Purse();
	Weapon m_Weapon = Weapon();
	Armor m_Armor = Armor();
	Potion m_Potion = Potion();
	void Status();
	void EquipedWeapon();
	void EquipedArmor();
};

class PartyInventory
{
public:
	PartyInventory(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref);
	PartyInventory(string serialString);

	string Serialized();

	vector<Weapon> INV_WEAPON;
	vector<Armor> INV_ARMOR;

	Weapon EQUIPED_WEAPON1;
	Armor EQUIPED_ARMOR1;

	Weapon EQUIPED_WEAPON2;
	Armor EQUIPED_ARMOR2;

	Weapon EQUIPED_WEAPON3;
	Armor EQUIPED_ARMOR3;

	void AddWeaponsRandom();
	void AddArmorRandom();

	string AddWeapon(int, int, int);
	string AddArmor(int, int, int);

	void AddSuperWeapon(int);
	void AddSuperArmor(int);

	void SwapEquipedWeapon(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref);
	void SwapEquipedArmor(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref);

	void DisplayPartyInventory();
	void DisplayPartyWeapons();
	void DisplayPartyArmor();

};


#endif