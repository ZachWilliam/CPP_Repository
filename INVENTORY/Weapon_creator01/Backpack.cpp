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

PartyInventory::PartyInventory(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref)
{
	EQUIPED_WEAPON1 = BP1ref.m_Weapon;
	INV_WEAPON.push_back(EQUIPED_WEAPON1);
	EQUIPED_ARMOR1 = BP1ref.m_Armor;
	INV_ARMOR.push_back(EQUIPED_ARMOR1);

	EQUIPED_WEAPON2 = BP2ref.m_Weapon;
	INV_WEAPON.push_back(EQUIPED_WEAPON2);
	EQUIPED_ARMOR2 = BP2ref.m_Armor;
	INV_ARMOR.push_back(EQUIPED_ARMOR2);

	EQUIPED_WEAPON3 = BP3ref.m_Weapon;
	INV_WEAPON.push_back(EQUIPED_WEAPON3);
	EQUIPED_ARMOR3 = BP3ref.m_Armor;
	INV_ARMOR.push_back(EQUIPED_ARMOR3);
}

void PartyInventory::AddWeaponsRandom()
{
	AddWeapon(-1, -1, -1);
}
void PartyInventory::AddArmorRandom()
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
void PartyInventory::AddSuperWeapon(int x)
{
	Weapon tempWeapon;
	tempWeapon.SetSuperWeapon(x);
	INV_WEAPON.push_back(tempWeapon);
}
void PartyInventory::AddSuperArmor(int x)
{
	Armor tempArmor;
	tempArmor.SetSuperArmor(x);
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

void PartyInventory::DisplayPartyWeapons()
{
	cout << "\nWeapons:\n";
	for (int i = 0; i < INV_WEAPON.size(); ++i)
	{
		INV_WEAPON[i].DisplayName();
		cout << endl;
	}
	cout << endl;
}

void PartyInventory::DisplayPartyArmor()
{
	cout << "\nArmor:\n";
	for (int i = 0; i < INV_ARMOR.size(); ++i)
	{
		INV_ARMOR[i].DisplayName();
		cout << endl;
	}
	cout << endl;
}

void PartyInventory::SwapEquipedWeapon(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref)
{
	int playerSelection;
	int choice;
	cout << "Select character: ";
	cin >> playerSelection;
	if (playerSelection <= 0 || playerSelection > 3)
	{
		cout << "Select character: ";
		cin >> playerSelection;
	}
	else
	{
		switch (playerSelection)
		{
		case 1:
			DisplayPartyWeapons();
			cout << "Select Weapon: ";
			cin >> choice;
			BP1ref.m_Weapon = INV_WEAPON[choice];
			INV_WEAPON.insert(INV_WEAPON.end(), INV_WEAPON[choice]);
			INV_WEAPON.pop_back();
			EQUIPED_WEAPON1 = BP1ref.m_Weapon;
			break;
		case 2:
			DisplayPartyWeapons();
			cout << "Select Weapon: ";
			cin >> choice;
			BP2ref.m_Weapon = INV_WEAPON[choice];
			INV_WEAPON.insert(INV_WEAPON.end(), INV_WEAPON[choice]);
			INV_WEAPON.pop_back();
			EQUIPED_WEAPON2 = BP2ref.m_Weapon;
			break;
		case 3:
			DisplayPartyWeapons();
			cout << "Select Weapon: ";
			cin >> choice;
			BP3ref.m_Weapon = INV_WEAPON[choice];
			INV_WEAPON.insert(INV_WEAPON.end(), INV_WEAPON[choice]);
			INV_WEAPON.pop_back();
			EQUIPED_WEAPON3 = BP3ref.m_Weapon;
			break;
		}
	}
}

void PartyInventory::SwapEquipedArmor(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref)
{
	int playerSelection;
	int choice;
	cout << "Select character: ";
	cin >> playerSelection;
	if (playerSelection <= 0 || playerSelection > 3)
	{
		cout << "Select character: ";
		cin >> playerSelection;
	}
	else
	{
		switch (playerSelection)
		{
		case 1:
			DisplayPartyArmor();
			cout << "Select Armor: ";
			cin >> choice;
			BP1ref.m_Armor = INV_ARMOR[choice];
			INV_ARMOR.insert(INV_ARMOR.end(), INV_ARMOR[choice]);
			INV_ARMOR.pop_back();
			EQUIPED_ARMOR1 = BP1ref.m_Armor;
			break;
		case 2:
			DisplayPartyArmor();
			cout << "Select Armor: ";
			cin >> choice;
			BP2ref.m_Armor = INV_ARMOR[choice];
			INV_ARMOR.insert(INV_ARMOR.end(), INV_ARMOR[choice]);
			INV_ARMOR.pop_back();
			EQUIPED_ARMOR2 = BP2ref.m_Armor;
			break;
		case 3:
			DisplayPartyArmor();
			cout << "Select Armor: ";
			cin >> choice;
			BP3ref.m_Armor = INV_ARMOR[choice];
			INV_ARMOR.insert(INV_ARMOR.end(), INV_ARMOR[choice]);
			INV_ARMOR.pop_back();
			EQUIPED_ARMOR3 = BP3ref.m_Armor;
			break;
		}
	}
}
