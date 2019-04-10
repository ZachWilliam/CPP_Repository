#include <iostream>
#include "Weapon.h"
#include "ConvertHelper.h"
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
	inline PlayerClass(string serialString);

	inline string Serialized();

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

PlayerClass::PlayerClass(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string PlayerClass::Serialized()
{
	string serialString = "";

	serialString += "name:" + name + ",";
	serialString += "Desc1:" + Desc1 + ",";
	serialString += "Desc2:" + Desc2 + ",";
	serialString += "Desc3:" + Desc3 + ",";
	serialString += "AbilityDesc:" + AbilityDesc + ",";
	serialString += "STR_BASE:" + to_string(STR_BASE) + ",";
	serialString += "DEX_BASE:" + to_string(DEX_BASE) + ",";
	serialString += "CON_BASE:" + to_string(CON_BASE) + ",";
	serialString += "AGI_BASE:" + to_string(AGI_BASE) + ",";
	serialString += "INT_BASE:" + to_string(INT_BASE) + ",";
	serialString += "WIS_BASE:" + to_string(WIS_BASE) + ",";
	serialString += "LUK_BASE:" + to_string(LUK_BASE) + ",";
	serialString += "STR_G:" + to_string(STR_G) + ",";
	serialString += "DEX_G:" + to_string(DEX_G) + ",";
	serialString += "CON_G:" + to_string(CON_G) + ",";
	serialString += "AGI_G:" + to_string(AGI_G) + ",";
	serialString += "INT_G:" + to_string(INT_G) + ",";
	serialString += "WIS_G:" + to_string(WIS_G) + ",";
	serialString += "LUK_G:" + to_string(LUK_G) + ",";
	serialString += "Simple:" + btos(Simple) + ",";
	serialString += "Martial:" + btos(Martial) + ",";
	serialString += "Ranged:" + btos(Ranged) + ",";
	serialString += "Magic:" + btos(Magic) + ",";
	serialString += "Staff:" + btos(Staff) + ",";
	serialString += "RStat:" + to_string(RStat) + ",";
	serialString += "Prerequisite:" + etos((int)Prerequisite) + ",";
	serialString += "Current:" + etos((int)Current) + ",";
	serialString += "StarterWeapon{" + StarterWeapon.Serialized() + "},";

	return serialString;
}