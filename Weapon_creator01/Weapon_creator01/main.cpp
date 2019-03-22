#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Weapon.h"
#include "Armor.h"
//#include <cctype>
//#include <algorithm>
//#include <functional>
using namespace std;



int main()
{
	srand(static_cast<unsigned int>(time(0)));

	/*Weapon weapon1;

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

	Weapon weapon2;
	weapon2.GetType(15);//bow
	weapon2.GetName(100);//legendary
	weapon2.SetDamageType(100);//of light
	weapon2.Status();
	weapon2.DisplayName();
	cout << "'s attack: " << weapon2.Attack();
	cout << endl;
	cout << endl;*/

	Weapon newWeapon;
	newWeapon.GetType();
	newWeapon.GetName();
	newWeapon.SetDamageType();
	cout << "weapon: \n";
	newWeapon.Status();
	cout << endl;
	cout << "sell value: " << newWeapon.GetSellValue();
	cout << ", ";
	cout << "buy value: " << newWeapon.GetBuyValue();
	cout << endl;
	cout << endl;

	Armor armor1;
	armor1.GetType();
	armor1.GetName();
	armor1.SetResitanceType();
	cout << "armor: \n";
	armor1.Status();
	cout << endl;
	cout << "sell value: " << armor1.GetSellValue();
	cout << ", ";
	cout << "buy value: " << armor1.GetBuyValue();
	cout << endl;
	cout << endl;

	Weapon fists(0);
	fists.GetType(0);
	fists.GetName(2);
	fists.SetDamageType(1);
	fists.Status();
	cout << endl;
	cout << endl;

	Armor silk(0);
	//silk.GetType(0);
	silk.GetName(0);
	silk.SetResitanceType(0);
	silk.Status();
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