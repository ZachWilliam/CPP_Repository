#include <iostream>
#include "Weapon.h"
#pragma once

using namespace std;

class PlayerClass
{
public:
    PlayerClass()
    {
        name = "";
        Current = NonClass;
    }
    PlayerClass(string n, int p)
    {
        name = n;
        Prerequisite = BaseType(p);
    }
    PlayerClass(string n, int p, int c)
    {
        name = n;
        Prerequisite = BaseType(p);
        Current = BaseType(c);
    }
	string name;
	string Desc1 = "desc1", Desc2 = "desc2", Desc3 = "desc3", AbilityDesc = "Ability:";
	int STR_BASE = 0, DEX_BASE = 0, CON_BASE = 0, AGI_BASE = 0, INT_BASE = 0, WIS_BASE = 0, LUK_BASE = 0;
	int STR_G = 0, DEX_G = 0, CON_G = 0, AGI_G = 0, INT_G = 0, WIS_G = 0, LUK_G = 0;
	bool Simple, Martial, Ranged, Magic, Staff;
	int RStat; //STR = 0, DEX = 1, INT = 2, WIS = 3
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
	Weapon StarterWeapon = Weapon();
};
