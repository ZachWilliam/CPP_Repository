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

class Weapon
{
public:
	Weapon(string prefix_name = "", string weapon_type = "", int damageMIN = 0, int damageMAX = 100, bool magic = false);
	void Status();
	int Attack();
	string GetName();
	string GetType();
private:
	string m_Prefix_Name;
	string m_Weapon_Type;
	int m_DamageMIN;
	int m_DamageMAX;
	bool m_Magic;

	static const int NUM_PREFIX_NAMES = 5;
	static const string PREFIX_NAMES[NUM_PREFIX_NAMES];

	static const int NUM_WEAPON_TYPES = 5;
	static const string WEAPON_TYPES[NUM_WEAPON_TYPES];
};
Weapon::Weapon(string prefix_name, string weapon_type, int damageMIN, int damageMAX, bool magic) :
	m_Prefix_Name(prefix_name), m_Weapon_Type(weapon_type), m_DamageMIN(damageMIN), m_DamageMAX(damageMAX), m_Magic(magic) {}

string Weapon::GetName()
{
	int namePick = (rand() % NUM_PREFIX_NAMES);
	m_Prefix_Name = PREFIX_NAMES[namePick];
	return m_Prefix_Name;
}
const string Weapon::PREFIX_NAMES[NUM_PREFIX_NAMES] = { "basic",
"flaming",
"cold",
"toxic",
"shocking" };

string Weapon::GetType()
{
	int typePick = (rand() % NUM_WEAPON_TYPES);
	m_Weapon_Type = WEAPON_TYPES[typePick];
	return m_Weapon_Type;
}
const string Weapon::WEAPON_TYPES[NUM_WEAPON_TYPES] = { "sword",
"axe",
"mace",
"spear",
"bow" };

void Weapon::Status()
{
	cout << m_Prefix_Name << " , " << m_Weapon_Type << " , " << Attack() << " , " << m_Magic << ".\n";
}
int Weapon::Attack()
{
	int attackValue = (rand() % ((m_DamageMAX + 1) - m_DamageMIN)) + m_DamageMIN;
	return attackValue;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Weapon weapon1;
	Weapon weapon2("example", "", 5, 20, true);
	Weapon weapon3("", "", 25, 75, true);

	weapon1.GetName();
	weapon1.GetType();
	cout << "weapon1: ";
	weapon1.Status();
	cout << endl;

	cout << "weapon2: ";
	weapon2.Status();
	cout << endl;

	cout << "weapon2 after type assign: ";
	weapon2.GetType();
	weapon2.Status();
	cout << endl;

	cout << "weapon3: ";
	weapon3.Status();
	cout << endl;

	cout << "weapon3 after name and type assign: ";
	weapon3.GetName();
	weapon3.GetType();
	weapon3.Status();
	cout << endl;



	_getch();
	return 0;
}