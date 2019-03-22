#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <functional>
using namespace std;

class WeaponType
{
public:
	WeaponType(string, int, int, int, int);
	WeaponType();
	string ToString();
	string m_Name;
	int m_DamageMIN;
	int m_DamageMAX;
	enum stat { Str = 0, Dex = 1, Int = 2, Wis = 3 };
	stat m_StatUsed;
	enum wield { simple = 0, martial = 1, ranged = 2, magic = 3, staff = 4 };
	wield m_Wielded;
};
WeaponType::WeaponType(string weapon_type, int damageMIN, int damageMAX, int statUsed, int wielded)
{
	m_Name = weapon_type;
	m_DamageMIN = damageMIN;
	m_DamageMAX = damageMAX;
	m_StatUsed = stat(statUsed);
	m_Wielded = wield(wielded);
}
WeaponType::WeaponType() {}

string WeaponType::ToString()
{
	return m_Name;
}


class DamageType
{
public:
	DamageType(int, int);
	enum HitType { no_hit = 0, pierce = 1, slash = 2, bludgeon = 3 };
	HitType m_Technique;
	vector<string> Element = { "entrophy", "fire", "ice", "water", "thunder", "wind", "earth", "darkness", "light", "healing" };
	int m_Enhancement;
	string ToString(bool);
};
DamageType::DamageType(int hit = 0, int ele = 0)
{
	m_Technique = HitType(hit);
	m_Enhancement = ele;
}
string DamageType::ToString(bool magic)
{
	string temp = "";
	if (magic == true)
	{
		temp = " of " + Element[m_Enhancement];
	}
	return temp;
}


class Weapon
{
public:
	Weapon(WeaponType weapon_type, int prefix_name);
	void Status();
	int Attack();
	string GetName(int Choice);
	void GetType(vector<WeaponType> &WEAPON_TYPES);
	void SetDamageType(int EleChoice);
	void DisplayName();
	int SpellSlot = 1;
private:
	string m_Prefix_Name;
	WeaponType m_Weapon_Type;
	int m_DamageMIN;
	int m_DamageMAX;
	bool m_Magic = false;
	DamageType m_DamageType;

	static const int NUM_PREFIX_NAMES = 6;
	static const string PREFIX_NAMES[NUM_PREFIX_NAMES];
};

Weapon::Weapon(WeaponType weapon_type = WeaponType(" ", 0, 1, 0, 0), int prefix_name = -1)
{
	m_Weapon_Type = weapon_type; 
	m_DamageMIN = weapon_type.m_DamageMIN;
	m_DamageMAX = weapon_type.m_DamageMAX;
	GetName(prefix_name);
}
	

const string Weapon::PREFIX_NAMES[NUM_PREFIX_NAMES] = { "legendarily bad", "bad", "basic", "good", "great", "legendary" };

void Weapon::SetDamageType(int EleChoice = -1)
{
	int temp;
	if (m_Weapon_Type.m_Name == "wand" || m_Weapon_Type.m_Name == "staff" || m_Weapon_Type.m_Name == "tome" || m_Weapon_Type.m_Name == "scroll")
	{
		temp = 0;
		if (m_Weapon_Type.m_Name == "staff")
		{
			SpellSlot = 0;
		}
		else
		{
			SpellSlot = (rand() % 3) + 1;
		}
	}
	if (m_Weapon_Type.m_Name == "rapier" || m_Weapon_Type.m_Name == "lance" || m_Weapon_Type.m_Name == "daggers" || m_Weapon_Type.m_Name == "bow")
	{
		temp = 1;
	}
	if (m_Weapon_Type.m_Name == "sword" || m_Weapon_Type.m_Name == "glaive" || m_Weapon_Type.m_Name == "axe" || m_Weapon_Type.m_Name == "shuriken")
	{
		temp = 2;
	}
	if (m_Weapon_Type.m_Name == "fists" || m_Weapon_Type.m_Name == "warhammer" || m_Weapon_Type.m_Name == "mace" || m_Weapon_Type.m_Name == "club")
	{
		temp = 3;
	}


	int eleChance;
	if (EleChoice == -1)
	{
		eleChance = (rand() % 101);
	}
	else
	{
		eleChance = EleChoice;
	}
	int temp2;
	if (temp != 0 || m_Weapon_Type.m_Name == "staff")
	{
		if (eleChance < 60)
		{
			temp2 = 0;
			if (m_Weapon_Type.m_Name == "staff")
			{
				temp2 = 9;
			}
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
	m_DamageType = DamageType(temp, temp2);
	if (temp2 != 0 || temp == 0)
	{
		m_Magic = true;
		if (temp != 0)
		{
			m_DamageMIN += 1;
			m_DamageMAX += 2;
		}
	}
	else
	{
		m_Magic = false;
	}
}


string Weapon::GetName(int Choice = -1)
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
	}
	else if (namePick < 15)//bad
	{
		m_Prefix_Name = PREFIX_NAMES[1];
		m_DamageMIN = _Max_value(m_DamageMIN - 1, 0);
		m_DamageMAX -= 1;
	}
	else if (namePick < 55)//basic no bonus
	{
		m_Prefix_Name = PREFIX_NAMES[2];
	}
	else if (namePick < 80)//good
	{
		m_Prefix_Name = PREFIX_NAMES[3];
		m_DamageMIN += 1;
		m_DamageMAX += 1;
	}
	else if (namePick < 95)//great
	{
		m_Prefix_Name = PREFIX_NAMES[4];
		m_DamageMIN += 2;
		m_DamageMAX += 3;
	}
	else//legendary
	{
		m_Prefix_Name = PREFIX_NAMES[5];
		m_DamageMIN += 3;
		m_DamageMAX += 5;
	}
	return m_Prefix_Name;
}


void Weapon::GetType(vector<WeaponType> &WEAPON_TYPES)
{
	int typePick = (rand() % WEAPON_TYPES.size());
	m_Weapon_Type = WEAPON_TYPES[typePick];
	m_DamageMIN = m_Weapon_Type.m_DamageMIN;
	m_DamageMAX = m_Weapon_Type.m_DamageMAX;
}


void Weapon::Status()
{
	cout << m_Prefix_Name << " " << m_Weapon_Type.ToString() + m_DamageType.ToString(m_Magic) + " min damage: " + to_string(m_DamageMIN) + " , max damage: " + to_string(m_DamageMAX) + ".\n";
}
int Weapon::Attack()
{
	int attackValue = (rand() % ((m_DamageMAX + 1) - m_DamageMIN)) + m_DamageMIN;
	return attackValue;
}
void Weapon::DisplayName()
{
	cout << m_Prefix_Name << " " << m_Weapon_Type.ToString() + m_DamageType.ToString(m_Magic);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	vector<WeaponType> WEAPON_TYPES = { WeaponType("fists", 0, 3, 0, 0), //weapon, damMin, damMAx, statUsed, wield
										WeaponType("sword", 2, 5, 0, 0),
										WeaponType("rapier", 2, 5, 1, 0),
										WeaponType("axe", 3, 8, 0, 1),
										WeaponType("warhammer", 4, 7, 0, 1),
										WeaponType("mace", 1, 6, 0, 0),
										WeaponType("club", 0, 4, 0, 0),
										WeaponType("lance", 4, 4, 0, 1),
										WeaponType("glaive", 3, 5, 0, 1),
										WeaponType("wand", 2, 5, 2, 3),
										WeaponType("tome", 0, 7, 2, 3),
										WeaponType("scroll", 3, 4, 2, 3),
										WeaponType("staff", 2, 2, 3, 4),
										WeaponType("shuriken", 1, 2, 1, 2),
										WeaponType("daggers", 1, 2, 1, 0),
										WeaponType("bow", 2, 5, 1, 2) };

	Weapon weapon1;

	weapon1.GetType(WEAPON_TYPES);
	weapon1.GetName();
	weapon1.SetDamageType();
	cout << "weapon: ";
	weapon1.Status();
	cout << endl;

	cout << "\nYou attack for " << weapon1.Attack() << " with ";
	weapon1.DisplayName();
	cout << endl;
	weapon1.Status();
	cout << endl;

	Weapon weapon2(WEAPON_TYPES[15]);
	weapon2.SetDamageType();
	weapon2.Status();
	weapon2.DisplayName();
	cout << "'s attack: " << weapon2.Attack();
	cout << endl;
	cout << endl;

	Weapon fists(WEAPON_TYPES[0]);
	Weapon sword(WEAPON_TYPES[1]);
	Weapon rapier(WEAPON_TYPES[2]);
	Weapon axe(WEAPON_TYPES[3]);
	Weapon warhammer(WEAPON_TYPES[4]);
	Weapon mace(WEAPON_TYPES[5]);
	Weapon club(WEAPON_TYPES[6]);
	Weapon lance(WEAPON_TYPES[7]);
	Weapon glaive(WEAPON_TYPES[8]);
	Weapon wand(WEAPON_TYPES[9]);
	Weapon tome(WEAPON_TYPES[10]);
	Weapon scroll(WEAPON_TYPES[11]);
	Weapon staff(WEAPON_TYPES[12]);
	Weapon shuriken(WEAPON_TYPES[13]);
	Weapon daggers(WEAPON_TYPES[14]);
	Weapon bow(WEAPON_TYPES[15]);

	//club.SetDamageType();
	club.Status();
	cout << endl;

	club.GetName();
	club.SetDamageType(75);
	club.Status();
	club.DisplayName();
	cout << "'s attack: " << club.Attack();



	_getch();
	return 0;
}