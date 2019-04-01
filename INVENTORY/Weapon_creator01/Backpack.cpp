#include "Backpack.h"

Backpack::Backpack(int gold = 0, int buildingMaterials = 0, bool questItem = false,//purse
	int setWeaponType = 0, int setWeaponName = 1, int setDamType = 10,//weapon
	int setArmorType = 0, int setArmorName = 1, int setResType = 10,//armor
	int potion = 12)//potion
{
	m_Purse.SetPurse(gold, buildingMaterials, questItem);
	m_Weapon.SetWeapon(setWeaponType, setWeaponName, setDamType);
	m_Armor.SetArmor(setArmorType, setArmorName, setResType);
	m_Potion.SetPotion(potion);
}
void Backpack::Status()
{
	cout << "Character Backpack:\n\n";
	cout << "Purse:\n" << m_Purse.GetGold() << " gold, " << m_Purse.GetBuildingMaterials() << " building materials, and " << m_Purse.QuestToString();
	cout << endl;
	cout << endl;
	cout << "Weapon:\n";
	m_Weapon.Status();
	cout << endl;
	cout << "Buy for $" << m_Weapon.GetBuyValue();
	cout << ", Sell for $" << m_Weapon.GetSellValue();
	cout << endl;
	cout << endl;
	cout << "Armor:\n";
	m_Armor.Status();
	cout << endl;
	cout << "Buy for $" << m_Armor.GetBuyValue();
	cout << ", Sell for $" << m_Armor.GetSellValue();
	cout << endl;
	cout << endl;
	cout << "Potion:\n";
	cout << m_Potion.DisplayName();
	cout << endl;
	if ((m_Potion.GetBuyValue() != 0) || (m_Potion.GetSellValue() != 0))
	{
		cout << "Buy for $" << m_Potion.GetBuyValue();
		cout << ", Sell for $" << m_Potion.GetSellValue();
		cout << endl;
	}
	else
	{
		cout << endl;
	}
}

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
	cout << endl;
}

/*
int PartyInventory::GetID()
{

	int ID = Backpack::m_Weapon.ID;
	return ID;
}

void PartyInventory::SwapEquipedWeapon(int choice)
{
	Backpack Weapon() = EQUIPED_WEAPON;
	INV_WEAPON.push_back(EQUIPED_WEAPON);
	Backpack Weapon() = INV_WEAPON(choice);
	//Weapon m_Weapon = PartyInventory::INV_WEAPON[choice];
}
*/