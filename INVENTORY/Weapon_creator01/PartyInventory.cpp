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

int PartyInventory::GetID()
{
	
	int ID = Backpack::m_Weapon.ID;
	return ID;
}
void PartyInventory::SwapEquipedWeapon()
{
	int x;
	int y;
	int z;

	Weapon tempWeapon;
	tempWeapon.SetWeapon(x, y, z);

	Backpack PlayerOne(int, int, bool, int, int, int, int, int, int, int);
	PlayerOne.m_Weapon = INV_WEAPON[0];
	//Backpack::m_Weapon;
}

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