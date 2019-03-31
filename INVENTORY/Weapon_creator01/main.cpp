#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Backpack.h"
#include "Weapon.h"
#include "Armor.h"
#include "Items.h"
#include "PartyInventory.h"

//#include <cctype>
//#include <algorithm>
//#include <functional>
using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Backpack PlayerOne(5, 5, false, 1, 2, 10, 1, 2, 10, 12);
	//Backpack PlayerTwo;
	Backpack PlayerThree(0, 10, false, 0, 3, 10, 2, 2, 10, 12);
	Backpack PlayerFour(5, 5, false, 3, 2, 10, 1, 2, 10, 12);

	PartyInventory inStorage;
	//inStorage.SetPartyInventory();
	inStorage.DisplayPartyInventory();
	cout << endl;
	cout << "Random\n";
	inStorage.SetArmorRandom();
	inStorage.SetWeaponsRandom();
	inStorage.DisplayPartyInventory();


	cout << "Player One:\n\n";
	PlayerOne.Status();
	cout << endl;
	cout << endl;

	cout << "swap inventory item to equiped.\n";
	PlayerOne.m_Weapon = inStorage.INV_WEAPON[0];
	cout << "Player One:\n\n";
	PlayerOne.Status();
	cout << endl;
	cout << endl;

	//not working below
	cout << "\nAdding three random armor and weapons to inventory.\n\n";
	inStorage.SetWeaponsRandom();
	inStorage.SetWeaponsRandom();
	inStorage.SetWeaponsRandom();

	inStorage.SetArmorRandom();
	inStorage.SetArmorRandom();
	inStorage.SetArmorRandom();
	inStorage.DisplayPartyInventory();
	//inStorage.AddWeapon(-1,-1,-1);
	//inStorage.DisplayPartyInventory();
	cout << "Player One:\n\n";
	PlayerOne.Status();
	cout << endl;
	cout << endl;

	cout << endl;

	//cout << "Changing Player One's weapon to legendary(5) warhammer(4) of darkness(7).\n";
	//PlayerOne.m_Weapon.SetWeapon(4, 5, 7);// legendary warhammer of darkness
	cout << "changing Player One's weapon to random.\n";
	PlayerOne.m_Weapon.SetRandomWeapon();
	//cout << "Changing Player One's armor to great(4) onix(11) armor of thunder(4).\n";
	//PlayerOne.m_Armor.SetArmor(11, 4, 4);// legendary warhammer of darkness
	cout << "changing Player One's armor to random.\n";
	PlayerOne.m_Armor.SetRandomArmor();
	cout << "Adding 50 gold, 100 building materials, filling potion with large magic attack.\n";
	cout << "And giving Player One the Quest Item.\n\n";
	PlayerOne.m_Purse.AddGold(50);
	PlayerOne.m_Purse.AddBuildingMaterials(100);
	PlayerOne.m_Potion.SetPotion(11);
	PlayerOne.m_Purse.SwitchQuestYesNo();
	PlayerOne.Status();
	cout << endl;
	cout << "Using potion.\n";
	PlayerOne.m_Potion.UsePotion();
	cout << "Potion:\n";
	cout << PlayerOne.m_Potion.DisplayName();
	cout << endl;
	cout << endl;

/*cout << "Player Two:\n";
	PlayerTwo.m_Weapon.Status();
	cout << endl;
	PlayerTwo.m_Armor.Status();
	cout << endl;
	PlayerTwo.m_Purse.Status();
	cout << endl;
	cout << endl;*/

	cout << "Player Three:\n";
	PlayerThree.m_Weapon.Status();
	cout << endl;
	PlayerThree.m_Armor.Status();
	cout << endl;
	PlayerThree.m_Purse.Status();
	cout << endl;
	cout << endl;

	cout << "Player Four:\n";
	PlayerFour.m_Weapon.Status();
	cout << endl;
	PlayerFour.m_Armor.Status();
	cout << endl;
	PlayerFour.m_Purse.Status();
	cout << endl;
	cout << endl;



/*
	Weapon newWeaponTEST;
	cout << "Create ex: warhammer(4), legendary(5), of wind(5)" << endl;
	newWeaponTEST.SetWeapon(4, 5, 5);
	newWeaponTEST.Status();
	cout << endl;
	cout << endl;

	cout << "Reset to base" << endl;
	newWeaponTEST.SetWeapon();
	newWeaponTEST.Status();
	cout << endl;
	cout << endl;

	cout << "Create Super Weapon" << endl;//(actual weapon ie: sword(1), axe(3))
	newWeaponTEST.SetSuperWeapon(10);//tome
	newWeaponTEST.Status();
	cout << endl;
	cout << endl;

	Armor newArmorTEST;
	cout << "Create ex: ringmail(6), good(3), of earth(6)" << endl;
	newArmorTEST.SetArmor(6, 3, 6);
	newArmorTEST.Status();
	cout << endl;
	cout << endl;

	cout << "Reset to base" << endl;
	newArmorTEST.SetArmor();
	newArmorTEST.Status();
	cout << endl;
	cout << endl;

	cout << "Create Super Armor" << endl;//(actual armor ie: polyester(2), amethyst(14))
	newArmorTEST.SetSuperArmor(12);//ruby
	newArmorTEST.Status();
	cout << endl;
	cout << endl;

	Potion newPotion;
	newPotion.Status();
	cout << endl;

	Potion newPotion2;	   
	newPotion2.Status();
	cout << endl;
	cout << newPotion2.DisplayName() << " potion" << endl;
	cout << newPotion2.GetHeal() << " healing" << endl;
	cout << newPotion2.GetDamage() << " damage" << endl;
	cout << newPotion2.GetMagicResist() << " magic resist" << endl;
	cout << newPotion2.GetMagicAttack() << " magic attack" << endl;
	cout << "sell value: " << newPotion2.GetSellValue();
	cout << ", ";
	cout << "buy value: " << newPotion2.GetBuyValue();
	cout << endl;
	cout << endl;
	
	cout << "Initializing purse with 5 gold and 5 building mats\n";
	Purse purse(5,5);
	purse.Status();
	cout << endl;
	cout << endl;


	cout << "add 5 gold and 6 building mats\n";
	purse.AddGold(5);
	purse.AddBuildingMaterials(6);
	//purse.GetGold();
	purse.Status();
	cout << endl;
	cout << endl;

	cout << "remove 2 gold, remove 4 building mats, and add quest item\n";
	purse.RemoveGold(2);
	purse.RemoveBuildingMaterials(4);
	purse.SwitchQuestYesNo();
	purse.Status();
	cout << endl;
	cout << endl;

	cout << "reseting all\n";
	purse.ResetAll();
	purse.Status();
	cout << endl;
	cout << endl;

	/*
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

	Weapon fists;
	fists.GetType(0);
	fists.GetName(2);
	fists.SetDamageType(1);
	fists.Status();
	cout << endl;
	cout << endl;

	Armor silk;
	silk.GetType(0);
	silk.GetName(2);
	silk.SetResitanceType(1);
	silk.Status();
	cout << endl;
	cout << endl;

	*/







	_getch();
	return 0;
}
