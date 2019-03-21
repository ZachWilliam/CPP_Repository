#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Weapon.h"
//#include <cctype>
//#include <algorithm>
//#include <functional>
using namespace std;



int main()
{
	srand(static_cast<unsigned int>(time(0)));
	/*vector<WeaponType> WEAPON_TYPES = { WeaponType("fists", 0, 3, 0, 0), //weapon, damMin, damMAx, statUsed, wield
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
*/
	Weapon weapon1;

	weapon1.GetType();
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

	Weapon weapon2(15);
	weapon2.SetDamageType(100);
	weapon2.Status();
	weapon2.DisplayName();
	cout << "'s attack: " << weapon2.Attack();
	cout << endl;
	cout << endl;

	/*Weapon fists(0);
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
	club.SetDamageType();
	club.Status();
	club.DisplayName();
	cout << "'s attack: " << club.Attack();*/



	_getch();
	return 0;
}