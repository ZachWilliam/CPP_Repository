#pragma once
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
	Purse m_Purse;
	Weapon m_Weapon;
	Armor m_Armor;
	Potion m_Potion;
	void Status();
};
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