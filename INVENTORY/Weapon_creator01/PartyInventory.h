#pragma once
#ifndef PARTYINVENTORY_H
#define PARTYINVENTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Backpack.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class PartyInventory
{
public:
	PartyInventory();

	vector<Weapon> INV_WEAPON = {	Weapon(1,2),
									Weapon(2,2),
									Weapon(3,2),
									Weapon(4,2),
									Weapon(5,2)  };

	vector<Armor> INV_ARMOR = { Armor(1,2), 
								Armor(2,2),
								Armor(3,2),
								Armor(4,2),
								Armor(5,2) };

	//vector<Weapon>::const_iterator iter;
	//vector<Armor>::const_iterator iter;

	void SetWeapons();
	void SetWeaponsRandom();
	void SetArmor();
	void SetArmorRandom();
	//void SetPartyInventory();

	//void EquipWeapon(int choice = 0);
	void DisplayPartyInventory();
	void SetPartyInventory();


	//void AddWeapon();
	//void RemoveWeapon();

	//void AddArmor();
	//void RemoveArmor();
	
};
PartyInventory::PartyInventory() {}


void PartyInventory::SetWeapons()
{
	INV_WEAPON[0].SetWeapon(1, 2, 10);
	INV_WEAPON[1].SetWeapon(2, 2, 10);
	INV_WEAPON[2].SetWeapon(3, 2, 10);
	INV_WEAPON[3].SetWeapon(4, 2, 10);
	INV_WEAPON[4].SetWeapon(5, 2, 10);
}

void PartyInventory::SetWeaponsRandom()
{
	INV_WEAPON[0].SetRandomWeapon();
	INV_WEAPON[1].SetRandomWeapon();
	INV_WEAPON[2].SetRandomWeapon();
	INV_WEAPON[3].SetRandomWeapon();
	INV_WEAPON[4].SetRandomWeapon();
}

void PartyInventory::SetArmor()
{
	INV_ARMOR[0].SetArmor(1, 2, 10);
	INV_ARMOR[1].SetArmor(2, 2, 10);
	INV_ARMOR[2].SetArmor(3, 2, 10);
	INV_ARMOR[3].SetArmor(4, 2, 10);
	INV_ARMOR[4].SetArmor(5, 2, 10);
}

void PartyInventory::SetArmorRandom()
{
	INV_ARMOR[0].SetRandomArmor();
	INV_ARMOR[1].SetRandomArmor();
	INV_ARMOR[2].SetRandomArmor();
	INV_ARMOR[3].SetRandomArmor();
	INV_ARMOR[4].SetRandomArmor();
}

void PartyInventory::SetPartyInventory()
{
	SetWeapons();
	SetArmor();
}

/*void PartyInventory::EquipWeapon(int choice)
{
	vector<Weapon>::const_iterator iter;

	iter = find(INV_WEAPON.begin(), INV_WEAPON.end(), INV_WEAPON[choice]);
	if (iter != INV_WEAPON.end())
	{
		int x;
		int y;
		int z;
		INV_WEAPON[choice].GetType(x);
		INV_WEAPON[choice].GetName(y);
		INV_WEAPON[choice].SetDamageType(z);
		
		Backpack PlayerOne(5, 5, false, 1, 2, 10, 1, 2, 10, 12);
		PlayerOne.m_Weapon.SetWeapon(x, y, z);

	}

}*/
void PartyInventory::DisplayPartyInventory()
{
	//vector<Weapon>::const_iterator iter;
	cout << "\nWeapons:\n";
	for (int i = 0; i < 5; ++i)
	{
		INV_WEAPON[i].DisplayName();
		cout << endl;
	}
	cout << "\nArmor:\n";
	for (int i = 0; i < 5; ++i)
	{
		INV_ARMOR[i].DisplayName();
		cout << endl;
	}

}
















#endif
