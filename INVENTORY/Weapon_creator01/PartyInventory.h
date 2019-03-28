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

	//vector<Weapon>::const_iterator iter;
	//vector<Armor>::const_iterator iter;

	//void SetWeapons();
	//void SetArmor();
	void SetWeaponsRandom();
	void SetArmorRandom();

	void AddWeapon(int, int, int);
	void AddArmor(int, int, int);

	void DropWeapon(int);
	//void DropArmor(int);


	//void SetPartyInventory();

	//void EquipWeapon(int choice = 0);
	void DisplayPartyInventory();
	//void SetPartyInventory();


	//void AddWeapon();
	//void RemoveWeapon();

	//void AddArmor();
	//void RemoveArmor();
	
};
PartyInventory::PartyInventory() {}

/*
void PartyInventory::SetWeapons()
{
	INV_WEAPON[0].SetWeapon(1, 2, 10);
	INV_WEAPON[1].SetWeapon(2, 2, 10);
	INV_WEAPON[2].SetWeapon(3, 2, 10);
	INV_WEAPON[3].SetWeapon(4, 2, 10);
	INV_WEAPON[4].SetWeapon(5, 2, 10);
	AddWeapon(1, 2, 10);
}
*/
void PartyInventory::SetWeaponsRandom()
{
	/*INV_WEAPON[0].SetRandomWeapon();
	INV_WEAPON[1].SetRandomWeapon();
	INV_WEAPON[2].SetRandomWeapon();
	INV_WEAPON[3].SetRandomWeapon();
	INV_WEAPON[4].SetRandomWeapon();*/
	AddWeapon(-1, -1, -1);
}
/*
void PartyInventory::SetArmor()
{
	INV_ARMOR[0].SetArmor(1, 2, 10);
	INV_ARMOR[1].SetArmor(2, 2, 10);
	INV_ARMOR[2].SetArmor(3, 2, 10);
	INV_ARMOR[3].SetArmor(4, 2, 10);
	INV_ARMOR[4].SetArmor(5, 2, 10);
	AddArmor(1, 2, 10);
}
*/
void PartyInventory::SetArmorRandom()
{
	/*INV_ARMOR[0].SetRandomArmor();
	INV_ARMOR[1].SetRandomArmor();
	INV_ARMOR[2].SetRandomArmor();
	INV_ARMOR[3].SetRandomArmor();
	INV_ARMOR[4].SetRandomArmor();*/
	AddArmor(-1, -1, -1);
}

void PartyInventory::AddWeapon(int x, int y, int z)
{
	Weapon tempWeapon;
	tempWeapon.SetWeapon(x, y, z);
	INV_WEAPON.push_back(tempWeapon);
}
void PartyInventory::AddArmor(int x, int y, int z)
{
	Armor tempArmor;
	tempArmor.SetArmor(x, y, z);
	INV_ARMOR.push_back(tempArmor);
}

void PartyInventory::DropWeapon(int discardChoice = 0)
{
	vector<Weapon>::iterator iter;
	Weapon weaponToDelete;
	weaponToDelete = INV_WEAPON[discardChoice];
	iter = find(INV_WEAPON.begin(), INV_WEAPON.end(), weaponToDelete);
	cout << INV_WEAPON.size();

	if (iter != INV_WEAPON.end())
	{
		INV_WEAPON.erase(iter);
	}
	else
	{
		cout << "\nThat weapon was not found.\n";
	}
}
	/*
	if (INV_WEAPON.empty() != true)
	{
		vector<Weapon>::iterator iter;
		iter = find(INV_WEAPON.begin(), INV_WEAPON.end(), INV_WEAPON[discardChoice]);
		if (iter != INV_WEAPON.end())
		{
			INV_WEAPON.erase(iter);
		}
		else
		{
			cout << "\nThat weapon was not found.\n";
		}
	}
	else
	{
		cout << "\nYou have no weapons to drop.";
	}
}*/
/*
void PartyInventory::DropArmor(int discardChoice)
{
	if (INV_ARMOR.empty() != true)
	{
		vector<Armor>::const_iterator iter;
		iter = find(INV_ARMOR.begin(), INV_ARMOR.end(), discardChoice);
		if (iter != INV_ARMOR.end())
		{
			INV_ARMOR.erase(iter);
		}
		else
		{
			cout << "\nThat item was not found.\n";
		}
	}
	else
	{
		cout << "\nYou have nothing left to drop.";
	}
}
*/
/*
void PartyInventory::SetPartyInventory()
{
	SetWeapons();
	SetArmor();
}
*/
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
	cout << "\nWeapons:\n";
	for (int i = 0; i < INV_WEAPON.size(); ++i)
	{
		INV_WEAPON[i].DisplayName();
		cout << endl;
	}
	cout << "\nArmor:\n";
	for (int i = 0; i < INV_ARMOR.size(); ++i)
	{
		INV_ARMOR[i].DisplayName();
		cout << endl;
	}
	/*
	vector<Weapon>::iterator iter;
	vector<Armor>::iterator iter2;
	cout << "\nWeapons:\n";
	for (iter = INV_WEAPON.begin(); iter != INV_WEAPON.end(); ++iter)
	{
		*INV_WEAPON[iter].DisplayName;
		cout << endl;
	}
	cout << "\nArmor:\n";
	for (iter2 = INV_ARMOR.begin(); iter2 != INV_ARMOR.end(); ++iter)
	{
		*iter;
		cout << endl;
	}
*/
}
















#endif
