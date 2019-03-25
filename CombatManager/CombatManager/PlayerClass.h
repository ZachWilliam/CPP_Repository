#include <iostream>
#pragma once

using namespace std;

class PlayerClass
{
public:
	PlayerClass();
	PlayerClass(string, int);
	PlayerClass(string, int, int);
	string name;
	string Desc1 = "desc1", Desc2 = "desc2", Desc3 = "desc3", AbilityDesc = "Ability:";
	int STR_BASE, DEX_BASE, CON_BASE, AGI_BASE, INT_BASE, PIE_BASE, LUK_BASE;
	int STR_G, DEX_G, CON_G, AGI_G, INT_G, PIE_G, LUK_G;
	bool Simple, Martial, Ranged, Magic, Staff;
	enum BaseType {NonClass = 0, 
		Knight, 
		Wizard, 
		Archer, 
		Lancer, 
		Brawler, 
		Fighter, 
		Rogue, 
		Mage, 
		Clergy};
	BaseType Prerequisite = NonClass;
	BaseType Current = NonClass;
};
PlayerClass::PlayerClass()
{
	name = "";
	Current = NonClass;
}
PlayerClass::PlayerClass(string n, int p)
{
	name = n;
	Prerequisite = BaseType(p);
}
PlayerClass::PlayerClass(string n, int p, int c)
{
	name = n;
	Prerequisite = BaseType(p);
	Current = BaseType(c);
}