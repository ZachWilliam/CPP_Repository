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
	Weapon(string name = "", string type = "", int damageMIN = 0, int damageMAX = 100, bool magic = false);
	void Status();
	int Attack();
	string GetName();
	string GetType();
private:
	string m_Name;
	string m_Type;
	int m_DamageMIN;
	int m_DamageMAX;
	bool m_Magic;

	static const int NUM_NAMES = 5;
	static const string NAMES[NUM_NAMES];

	static const int NUM_TYPES = 5;
	static const string TYPES[NUM_TYPES];
};
Weapon::Weapon(string name, string type, int damageMIN, int damageMAX, bool magic) :
	m_Name(name), m_Type(type), m_DamageMIN(damageMIN), m_DamageMAX(damageMAX), m_Magic(magic) {}

string Weapon::GetName()
{
	int namePick = (rand() % NUM_NAMES);
	m_Name = NAMES[namePick];
	return m_Name;
}
const string Weapon::NAMES[NUM_NAMES] = { "Smashy Smash",
"Storm Breaker",
"Vera",
"Meat Maker",
"Other Random Weapon Name" };

string Weapon::GetType()
{
	int typePick = (rand() % NUM_TYPES);
	m_Type = TYPES[typePick];
	return m_Type;
}
const string Weapon::TYPES[NUM_TYPES] = { "blunt",
"edged",
"piercing",
"ranged",
"other" };

void Weapon::Status()
{
	cout << m_Name << " , " << m_Type << " , " << Attack() << " , " << m_Magic << ".\n";
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
	Weapon weapon2("example", " ", 5, 20, true);
	Weapon weapon3("", "blunt", 25, 75, true);

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

	cout << "weapon3 after name assign: ";
	weapon3.GetName();
	weapon3.Status();
	cout << endl;



	_getch();
	return 0;
}