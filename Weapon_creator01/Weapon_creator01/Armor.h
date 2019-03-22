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
	ElementType(int, int);
	enum WhoIsFor { light = 0, medium = 1, heavy = 2, special = 3 };
	WhoIsFor m_WhoIsFor;
	vector<string> Element = { "entrophy", "fire", "ice", "water", "thunder", "wind", "earth", "darkness", "light", "healing" };
	int m_Enhancement;
	string ToString(bool);
};
ElementType::ElementType(int isfor = 0, int ele = 0)
{
	m_WhoIsFor = WhoIsFor(isfor);
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
	if (m_Armor_Type.m_Name == "silk" || m_Armor_Type.m_Name == "cotton" || m_Armor_Type.m_Name == "polyester" || m_Armor_Type.m_Name == "leather")
	{
		temp = 0;
	}
	else if (m_Armor_Type.m_Name == "studded" || m_Armor_Type.m_Name == "chainmail" || m_Armor_Type.m_Name == "ringmail" || m_Armor_Type.m_Name == "plate")
	{
		temp = 1;
	}
	else if (m_Armor_Type.m_Name == "titanium" || m_Armor_Type.m_Name == "steel" || m_Armor_Type.m_Name == "silver" || m_Armor_Type.m_Name == "onix")
	{
		temp = 2;
	}
	else if (m_Armor_Type.m_Name == "ruby" || m_Armor_Type.m_Name == "emerald" || m_Armor_Type.m_Name == "amethyst" || m_Armor_Type.m_Name == "diamond")
	{
		temp = 3;
	}

	int eleChance;
	if (EleChoice <= -1 || EleChoice > 10)
	{
		eleChance = (rand() % 101);
		int temp2;
		if (temp != 3)
		{
			if (eleChance < 60)
			{
				temp2 = 0;
			}
			else if (eleChance < 66)
			{
				temp2 = 1;
			}
			else if (eleChance < 72)
			{
				temp2 = 2;
			}
			else if (eleChance < 78)
			{
				temp2 = 3;
			}
			else if (eleChance < 84)
			{
				temp2 = 4;
			}
			else if (eleChance < 90)
			{
				temp2 = 5;
			}
			else if (eleChance < 96)
			{
				temp2 = 6;
			}
			else if (eleChance < 98)
			{
				temp2 = 7;
			}
			else
			{
				temp2 = 8;
			}
		}
		else
		{
			if (eleChance < 2)
			{
				temp2 = 0;
			}
			else if (eleChance < 15)
			{
				temp2 = 1;
			}
			else if (eleChance < 28)
			{
				temp2 = 2;
			}
			else if (eleChance < 41)
			{
				temp2 = 3;
			}
			else if (eleChance < 54)
			{
				temp2 = 4;
			}
			else if (eleChance < 67)
			{
				temp2 = 5;
			}
			else if (eleChance < 80)
			{
				temp2 = 6;
			}
			else if (eleChance < 90)
			{
				temp2 = 7;
			}
			else
			{
				temp2 = 8;
			}
		}

		m_ElementType = ElementType(temp, temp2);
		if (temp2 != 0)
		{
			m_Magic = true;
			m_MagicResist += 5;
			m_Avoidance += 10;
		}
		else
		{
			m_Magic = false;
		}
	}
	else
	{
		switch (EleChoice)
		{
		case 0://entrophy
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 1://fire
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 2://ice
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 3://water
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 4://thunder
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 5://wind
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 6://earth
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 7://darkness
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 8://light
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 9://healing
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 10://no magic
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			m_Magic = false;
		}
	}
}

string Armor::GetName(int Choice = -1)
{
	int namePick;
	if (Choice <= -1 || Choice > 5)
	{
		namePick = (rand() % 101);
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
	}
	else
	{
		switch (Choice)
		{
		case 0://default
			m_Prefix_Name = PREFIX_NAMES[0];
			m_DamageResist = _Max_value(m_DamageResist - 5, 0);
			m_MagicResist = _Max_value(m_MagicResist - 5, 0);
			m_Avoidance -= 5;
			namePick = Choice;
			break;
		case 1://badd
			m_Prefix_Name = PREFIX_NAMES[1];
			m_DamageResist = _Max_value(m_DamageResist - 3, 0);
			m_MagicResist = _Max_value(m_MagicResist - 3, 0);
			m_Avoidance -= 3;
			namePick = Choice;
			break;
		case 2://basic
			m_Prefix_Name = PREFIX_NAMES[2];
			namePick = Choice;
			break;
		case 3://good
			m_Prefix_Name = PREFIX_NAMES[3];
			m_DamageResist += 5;
			m_MagicResist += 5;
			m_Avoidance += 3;
			namePick = Choice;
			break;
		case 4://great
			m_Prefix_Name = PREFIX_NAMES[4];
			m_DamageResist += 7;
			m_MagicResist += 7;
			m_Avoidance += 5;
			namePick = Choice;
			break;
		case 5://legendary
			m_Prefix_Name = PREFIX_NAMES[5];
			m_DamageResist += 10;
			m_MagicResist += 10;
			m_Avoidance += 7;
			namePick = Choice;
			break;
		}
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
	sellValue = (m_DamageResist + m_MagicResist + (m_Avoidance /2)) / 1.5;
	if (sellValue < 1)
	{
		sellValue = 1;
	}
	return sellValue;
}
int Armor::GetBuyValue()
{
	int buyValue;
	buyValue = (m_DamageResist + m_MagicResist + (m_Avoidance / 2)) * 3;
	return buyValue;
}