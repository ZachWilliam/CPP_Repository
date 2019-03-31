#include "PartyInventory.h"

PartyInventory::PartyInventory() {}

void PartyInventory::SetWeaponsRandom()
{
	AddWeapon(-1, -1, -1);
}
void PartyInventory::SetArmorRandom()
{
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
/*
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
*/
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
}