#pragma once
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
ArmorType::ArmorType(string armor_type, int damageResist, int magicResist, int avoidance, int statUsed, int wieghted)
{
	m_Name = armor_type;
	m_DamageResist = damageResist;
	m_StatUsed = stat(statUsed);
	m_Wieghted = wieght(wieghted);
	m_MagicResist = magicResist;
	m_Avoidance = avoidance;
}
ArmorType::ArmorType() {}

string ArmorType::ToString()
{
	return m_Name;
}


class ElementType
{
public:
	ElementType(int);
	//enum WhoIsFor { novice = 0, intermediate = 1, advanced = 2, elite = 3 };
	//WhoIsFor m_WhoIsFor;
	vector<string> Element = { "entrophy", "fire", "ice", "water", "thunder", "wind", "earth", "darkness", "light", "healing" };
	int m_Enhancement;
	string ToString(bool);
};
ElementType::ElementType(int ele = 0)
{
	//m_WhoIsFor = WhoIsFor(isfor);
	m_Enhancement = ele;
}
string ElementType::ToString(bool magic)
{
	string temp = " armor";
	if (magic == true)
	{
		temp = " armor of " + Element[m_Enhancement];
	}
	return temp;
}


class Armor
{
public:
	Armor(int ArmorChoice, int prefix_name);
	void Status();
	string GetName(int Choice);
	void GetType(int Choice);
	void SetResitanceType(int EleChoice);
	void DisplayName();
	//int SpellSlot = 1;
	int GetSellValue();
	int GetBuyValue();
	vector<ArmorType> ARMOR_TYPES = {   ArmorType("silk", 5, 0, 0, 0, 0), 
										ArmorType("cotton", 5, 0, 0, 1, 0),
										ArmorType("polyester", 5, 0, 0, 2, 0),
										ArmorType("leather", 5, 0, 0, 3, 0),
										ArmorType("studded", 10, 5, 0, 3, 1),
										ArmorType("chainmail", 10, 5, 0, 2, 1),
										ArmorType("ringmail", 10, 5, 0, 1, 1),
										ArmorType("plate", 10, 5, 0, 0, 1),
										ArmorType("silver", 15, 10, -5, 0, 2),
										ArmorType("gold", 15, 10, -5, 1, 2),
										ArmorType("platinum", 15, 10, -5, 2, 2),
										ArmorType("onix", 15, 10, -5, 3, 2),
										ArmorType("ruby", 20, 15, 5, 0, 3),
										ArmorType("emerald", 20, 15, 5, 1, 3),
										ArmorType("amethyst", 20, 15, 5, 2, 3),
										ArmorType("diamond", 20, 15, 5, 3, 3)	};
	//clothing name, damRes, magicRes, avoidance, statUsed(Str = 0, Dex = 1, Int = 2, Wis = 3), weight (light = 0, medium = 1, heavy = 2, special = 3)
//private:
	string m_Prefix_Name;
	ArmorType m_Armor_Type;
	int m_DamageResist;
	int m_MagicResist;
	int m_Avoidance;
	bool m_Magic = false;
	ElementType m_ElementType;

	static const int NUM_PREFIX_NAMES = 6;
	static const string PREFIX_NAMES[NUM_PREFIX_NAMES];
};

Armor::Armor(int ArmorChoice = 0, int prefix_name = -1)
{
	m_Armor_Type = ARMOR_TYPES[ArmorChoice];
	m_DamageResist = ARMOR_TYPES[ArmorChoice].m_DamageResist;
	m_MagicResist = ARMOR_TYPES[ArmorChoice].m_MagicResist;
	m_Avoidance = ARMOR_TYPES[ArmorChoice].m_Avoidance;
	GetName(prefix_name);
}

const string Armor::PREFIX_NAMES[NUM_PREFIX_NAMES] = { "legendarily bad", "bad", "basic", "good", "great", "legendary" };

void Armor::SetResitanceType(int EleChoice = -1)
{
	int temp;
	/*if (m_Armor_Type.m_Name == "silk" || m_Armor_Type.m_Name == "cotton" || m_Armor_Type.m_Name == "polyester" || m_Armor_Type.m_Name == "leather")
	{
		temp = 0;
	}
	if (m_Armor_Type.m_Name == "studded" || m_Armor_Type.m_Name == "chainmail" || m_Armor_Type.m_Name == "ringmail" || m_Armor_Type.m_Name == "plate")
	{
		temp = 1;
	}
	if (m_Armor_Type.m_Name == "ruby" || m_Armor_Type.m_Name == "emerald" || m_Armor_Type.m_Name == "amethyst" || m_Armor_Type.m_Name == "diamond")
	{
		temp = 2;
	}
	if (m_Armor_Type.m_Name == "silver" || m_Armor_Type.m_Name == "gold" || m_Armor_Type.m_Name == "platinum" || m_Armor_Type.m_Name == "starlight")
	{
		temp = 3;
	}
	*/

	int eleChance;
	if (EleChoice == -1)
	{
		eleChance = (rand() % 101);
	}
	else
	{
		eleChance = EleChoice;
	}
	if (eleChance < 60)
	{
		temp = 0;
	}
	else if (eleChance < 66)
	{
		temp = 1;
	}
	else if (eleChance < 72)
	{
		temp = 2;
	}
	else if (eleChance < 78)
	{
		temp = 3;
	}
	else if (eleChance < 84)
	{
		temp = 4;
	}
	else if (eleChance < 90)
	{
		temp = 5;
	}
	else if (eleChance < 96)
	{
		temp = 6;
	}
	else if (eleChance < 98)
	{
		temp = 7;
	}
	else
	{
		temp = 8;
	}
	
	m_ElementType = ElementType(temp);
	if (temp != 0)
	{
		m_Magic = true;
		m_DamageResist += 5;
		m_MagicResist += 5;
		m_Avoidance += 5;
	}
	else
	{
		m_Magic = false;
	}
}

string Armor::GetName(int Choice = -1)
{
	int namePick;
	if (Choice == -1)
	{
		namePick = (rand() % 101);
	}
	else
	{
		namePick = Choice;
	}

	if (namePick == 0)//default
	{
		m_Prefix_Name = PREFIX_NAMES[0];
		m_DamageResist = _Max_value(m_DamageResist - 5, 0);
		m_MagicResist = _Max_value(m_MagicResist - 5, 0);
		m_Avoidance -= 5;
	}
	else if (namePick < 15)//bad
	{
		m_Prefix_Name = PREFIX_NAMES[1];
		m_DamageResist = _Max_value(m_DamageResist - 3, 0);
		m_MagicResist = _Max_value(m_MagicResist - 3, 0);
		m_Avoidance -= 3;
	}
	else if (namePick < 55)//basic no bonus
	{
		m_Prefix_Name = PREFIX_NAMES[2];
	}
	else if (namePick < 80)//good
	{
		m_Prefix_Name = PREFIX_NAMES[3];
		m_DamageResist += 5;
		m_MagicResist += 5;
		m_Avoidance += 3;
	}
	else if (namePick < 95)//great
	{
		m_Prefix_Name = PREFIX_NAMES[4];
		m_DamageResist += 7;
		m_MagicResist += 7;
		m_Avoidance += 5;
	}
	else//legendary
	{
		m_Prefix_Name = PREFIX_NAMES[5];
		m_DamageResist += 10;
		m_MagicResist += 10;
		m_Avoidance += 7;
	}
	return m_Prefix_Name;
}

void Armor::GetType(int Choice = -1)
{
	int typePick;
	if (Choice == -1)
	{
		typePick = (rand() % ARMOR_TYPES.size());
	}
	else
	{
		typePick = Choice;
	}
	m_Armor_Type = ARMOR_TYPES[typePick];
	m_DamageResist = m_Armor_Type.m_DamageResist;
	m_MagicResist = m_Armor_Type.m_MagicResist;
	m_Avoidance = m_Armor_Type.m_Avoidance;
}

void Armor::Status()
{
	cout << m_Prefix_Name << " " << m_Armor_Type.ToString() + m_ElementType.ToString(m_Magic); 
	cout << "\ndamage resist: " + to_string(m_DamageResist) + ", magic resist: " + to_string(m_MagicResist) + ", avoidance: " + to_string(m_Avoidance);
}
void Armor::DisplayName()
{
	cout << m_Prefix_Name << " " << m_Armor_Type.ToString() + m_ElementType.ToString(m_Magic);
}
int Armor::GetSellValue()
{
	int sellValue;
	sellValue = (m_DamageResist + m_MagicResist + m_Avoidance) / 2;
	if (sellValue < 1)
	{
		sellValue = 1;
	}
	return sellValue;
}
int Armor::GetBuyValue()
{
	int buyValue;
	buyValue = (m_DamageResist + m_MagicResist + m_Avoidance) * 2;
	return buyValue;
}