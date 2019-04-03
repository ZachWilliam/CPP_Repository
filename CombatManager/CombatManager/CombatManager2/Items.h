#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
static class Item
{
public:
	//Item();
	static int uniqueID;
};
*/
static int uniqueID;

class Purse
{
public:
	Purse(int gold = 0, int buildingMaterials = 0, bool questItem = false);

	void Status();
	void ResetAll();
	void SetPurse(int, int, bool);

	int m_Gold;
	int GetGold();
	int AddGold(int);
	int RemoveGold(int);

	int m_BuildingMaterials;
	int GetBuildingMaterials();
	int AddBuildingMaterials(int);
	int RemoveBuildingMaterials(int);

	bool m_QuestItem;
	bool GetQuestItem();
	bool SetQuestItem(bool);
	bool SwitchQuestYesNo();
	string QuestToString();
};


class Potion
{
public:
	Potion(int PotionName = -1);
	string DisplayName();
	string m_Name;
	int m_HealAmount;
	int m_DamageAmount;
	int m_MagicAttack;
	int m_MagicResist;
	vector<string> POTION_TYPES = { "small healing",
									"medium healing",
									"large healing",
									"small damaging",
									"medium damaging",
									"large damaging",
									"small magic resist",
									"medium magic resist",
									"large magic resist",
									"small magic attack",
									"medium magic attack",
									"large magic attack",
									"empty" };
	int GetHeal();
	int GetDamage();
	int GetMagicResist();
	int GetMagicAttack();
	void Status();
	void SetPotion(int);
	int UsePotion();
	int GetSellValue();
	int GetBuyValue();
};


#endif
