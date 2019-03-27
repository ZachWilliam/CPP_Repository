#pragma once
#ifndef ARMOR_H
#define ARMOR_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class ArmorType
{
public:
	ArmorType(string, int, int, int, int, int);
	ArmorType();
	string ToString();
	string m_Name;
	int m_DamageResist;
	int m_MagicResist;
	int m_Avoidance;
	enum stat { Str = 0, Dex = 1, Int = 2, Wis = 3 };
	stat m_StatUsed;
	enum wieght { light = 0, medium = 1, heavy = 2, special = 3 };
	wieght m_Wieghted;
};



class ElementType
{
public:
	ElementType(int, int);
	enum WhoIsFor { light = 0, medium = 1, heavy = 2, special = 3 };
	WhoIsFor m_WhoIsFor;
	vector<string> Element = { "entrophy", "fire", "ice", "water", "thunder", "wind", "earth", "darkness", "light", "healing" };
	int m_Enhancement;
	string ToString(bool);
};



class Armor
{
public:
	Armor(int ArmorChoice = 0, int prefix_name = -1);
	void Status();
	string GetName(int Choice);
	void GetType(int Choice);
	void SetResistanceType(int EleChoice);
	void DisplayName();
	string DisplayNameText();
	int GetSellValue();
	int GetBuyValue();
	vector<ArmorType> ARMOR_TYPES = {   ArmorType("silk", 0, 6, 15, 3, 0), 
										ArmorType("cotton", 2, 4, 15, 2, 0),
										ArmorType("polyester", 4, 2, 15, 1, 0),
										ArmorType("leather", 6, 0, 15, 0, 0),
										ArmorType("studded", 7, 6, 0, 3, 1),
										ArmorType("chainmail", 9, 5, 0, 2, 1),
										ArmorType("ringmail", 12, 2, 0, 1, 1),
										ArmorType("plate", 14, 0, 0, 0, 1),
										ArmorType("titanium", 20, 0, -10, 0, 2),
										ArmorType("steel", 16, 4, -10, 1, 2),
										ArmorType("silver", 14, 6, -10, 2, 2),
										ArmorType("onix", 6, 14, -10, 3, 2),
										ArmorType("ruby", 10, 16, 5, 0, 3),
										ArmorType("emerald", 13, 15, 0, 1, 3),
										ArmorType("amethyst", 15, 13, 0, 2, 3),
										ArmorType("diamond", 18, 12, -5, 3, 3)	};
	//clothing name, damRes, magicRes, avoidance, statUsed(Str = 0, Dex = 1, Int = 2, Wis = 3), weight (light = 0, medium = 1, heavy = 2, special = 3)
//private:
	string m_Prefix_Name;
	ArmorType m_Armor_Type;
	int m_DamageResist;
	int m_MagicResist;
	int m_Avoidance;
	bool m_Magic = false;
	ElementType m_ElementType;

	void SetArmor(int, int, int);
	void SetSuperArmor(int);
	void SetRandomArmor();

	static const int NUM_PREFIX_NAMES = 7;
	static const string PREFIX_NAMES[NUM_PREFIX_NAMES];
};



#endif