#include "WeaponShop.h"

WeaponShop::WeaponShop()
{
	Weapon STORE_WEAPON1;
	STORE_WEAPON1.SetWeapon(3, 3, 10);//axe
	STORE_WEAPON_LIST.push_back(STORE_WEAPON1);

	Weapon STORE_WEAPON2;
	STORE_WEAPON2.SetWeapon(15, 3, 10);//bow
	STORE_WEAPON_LIST.push_back(STORE_WEAPON2);

	Weapon STORE_WEAPON3;
	STORE_WEAPON3.SetWeapon(7, 3, 10);//lance
	STORE_WEAPON_LIST.push_back(STORE_WEAPON3);

	Weapon STORE_WEAPON4;
	STORE_WEAPON4.SetWeapon(4, 3, 10);//warhammer
	STORE_WEAPON_LIST.push_back(STORE_WEAPON4);

	Weapon STORE_WEAPON5;
	STORE_WEAPON5.SetWeapon(13, 3, 10);//shuriken
	STORE_WEAPON_LIST.push_back(STORE_WEAPON5);

	Weapon STORE_WEAPON6;
	STORE_WEAPON6.SetWeapon(6, 3, 10);//club
	STORE_WEAPON_LIST.push_back(STORE_WEAPON6);

	Weapon STORE_WEAPON7;
	STORE_WEAPON7.SetWeapon(8, 3, 10);//glaive
	STORE_WEAPON_LIST.push_back(STORE_WEAPON7);

	Weapon STORE_WEAPON8;
	STORE_WEAPON8.SetWeapon(2, 3, 3);//rapier of water
	STORE_WEAPON_LIST.push_back(STORE_WEAPON8);

	Weapon STORE_WEAPON9;
	STORE_WEAPON9.SetWeapon(1, 3, 2);//sword of ice
	STORE_WEAPON_LIST.push_back(STORE_WEAPON9);

	Weapon STORE_WEAPON10;
	STORE_WEAPON10.SetWeapon(11, 3, 1);//scroll of fire
	STORE_WEAPON_LIST.push_back(STORE_WEAPON10);
}

void WeaponShop::Greeting()
{
	int choice = 0;
	string wordChoice;

	cout << "Welcome to the shop.\n";
	cout << "What brings you in today?\n";
	cout << "1.     BUY\n";
	cout << "2.     SELL\n";
	cout << "3.     EXIT\n";
	cout << "Choice: ";
	cin >> wordChoice;
	choice = wordChoice[0] - 48;

	while (choice <= 0 || choice > 3)
	{
		cout << "Choice: ";
		cin >> wordChoice;
		choice = wordChoice[0] - 48;
	};
	switch (choice)
	{
	case 1:
		Buy();
		break;
	case 2:
		Sell();
		break;
	case 3:
		//call back to map - exit
		break;
	}
}

void WeaponShop::Buy(PartyInventory &PIref)
{
	cout << "\nWeapons:\n";
	for (int i = 0; i < STORE_WEAPON_LIST.size(); ++i)
	{
		STORE_WEAPON_LIST[i].DisplayName();
		cout << endl;
	}
}

void WeaponShop::Sell(PartyInventory &PIref)
{
	PIref.DisplayPartyWeapons();
}