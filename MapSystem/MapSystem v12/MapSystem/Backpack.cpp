#include "Backpack.h"

Backpack::Backpack(int gold = 0, int buildingMaterials = 0, bool questItem = false,//purse
	int setWeaponType = 0, int setWeaponName = 1, int setDamType = 10,//weapon
	int setArmorType = 3, int setArmorName = 2, int setResType = 10,//armor
	int potion = 12)//potion
{
	m_Purse.SetPurse(gold, buildingMaterials, questItem);
	m_Weapon.SetWeapon(setWeaponType, setWeaponName, setDamType);
	m_Armor.SetArmor(setArmorType, setArmorName, setResType);
	m_Potion.SetPotion(potion);
}
void Backpack::Status()
{
	cout << "Character Backpack:\n\n";
	cout << "Purse:\n" << m_Purse.GetGold() << " gold, " << m_Purse.GetBuildingMaterials() << " building materials, and " << m_Purse.QuestToString();
	cout << endl;
	cout << endl;
	cout << "Weapon:\n";
	m_Weapon.Status();
	cout << endl;
	cout << "Buy for $" << m_Weapon.GetBuyValue();
	cout << ", Sell for $" << m_Weapon.GetSellValue();
	cout << endl;
	cout << endl;
	cout << "Armor:\n";
	m_Armor.Status();
	cout << endl;
	cout << "Buy for $" << m_Armor.GetBuyValue();
	cout << ", Sell for $" << m_Armor.GetSellValue();
	cout << endl;
	cout << endl;
	cout << "Potion:\n";
	cout << m_Potion.DisplayName();
	cout << endl;
	if ((m_Potion.GetBuyValue() != 0) || (m_Potion.GetSellValue() != 0))
	{
		cout << "Buy for $" << m_Potion.GetBuyValue();
		cout << ", Sell for $" << m_Potion.GetSellValue();
		cout << endl;
	}
	else
	{
		cout << endl;
	}
}
void Backpack::EquipedWeapon()
{
	m_Weapon.Status();
	cout << endl;
}
void Backpack::EquipedArmor()
{
	m_Armor.Status();
	cout << endl;
}

Backpack::Backpack(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string Backpack::Serialized()
{
	string serialString = "";

	serialString += "Purse{" + m_Purse.Serialized() + "},";
	serialString += "Weapon{" + m_Weapon.Serialized() + "},";
	serialString += "Armor{" + m_Armor.Serialized() + "},";
	serialString += "Potion{" + m_Potion.Serialized() + "},";

	return serialString;
}




PartyInventory::PartyInventory(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref)
{
	EQUIPED_WEAPON1 = BP1ref.m_Weapon;
	INV_WEAPON.push_back(EQUIPED_WEAPON1);
	EQUIPED_ARMOR1 = BP1ref.m_Armor;
	INV_ARMOR.push_back(EQUIPED_ARMOR1);

	EQUIPED_WEAPON2 = BP2ref.m_Weapon;
	INV_WEAPON.push_back(EQUIPED_WEAPON2);
	EQUIPED_ARMOR2 = BP2ref.m_Armor;
	INV_ARMOR.push_back(EQUIPED_ARMOR2);

	EQUIPED_WEAPON3 = BP3ref.m_Weapon;
	INV_WEAPON.push_back(EQUIPED_WEAPON3);
	EQUIPED_ARMOR3 = BP3ref.m_Armor;
	INV_ARMOR.push_back(EQUIPED_ARMOR3);
}

void PartyInventory::AddWeaponsRandom()
{
	AddWeapon(-1, -1, -1);
}
void PartyInventory::AddArmorRandom()
{
	AddArmor(-1, -1, -1);
}

string PartyInventory::AddWeapon(int x, int y, int z)
{
	Weapon tempWeapon;
	tempWeapon.SetWeapon(x, y, z);
	INV_WEAPON.push_back(tempWeapon);
	return tempWeapon.DisplayNameText();
}
string PartyInventory::AddArmor(int x, int y, int z)
{
	Armor tempArmor;
	tempArmor.SetArmor(x, y, z);
	INV_ARMOR.push_back(tempArmor);
	return tempArmor.DisplayNameText();
}
void PartyInventory::AddSuperWeapon(int x)
{
	Weapon tempWeapon;
	tempWeapon.SetSuperWeapon(x);
	INV_WEAPON.push_back(tempWeapon);
}
void PartyInventory::AddSuperArmor(int x)
{
	Armor tempArmor;
	tempArmor.SetSuperArmor(x);
	INV_ARMOR.push_back(tempArmor);
}

void PartyInventory::DisplayPartyInventory()
{
	cout << "\nWeapons:\n";
	for (int i = 0; i < INV_WEAPON.size(); ++i)
	{
		INV_WEAPON[i].DisplayName();
		cout << endl;
	}
	cout << "\nArmor:\n";
	for (int i = 0; i < INV_ARMOR.size(); ++i)
	{
		INV_ARMOR[i].DisplayName();
		cout << endl;
	}
	cout << endl;
}

void PartyInventory::DisplayPartyWeapons()
{
	cout << "\nWeapons:\n";
	for (int i = 0; i < INV_WEAPON.size(); ++i)
	{
		cout << i << ". ";
		INV_WEAPON[i].DisplayName();
		cout << endl;
	}
	cout << endl;
}

void PartyInventory::DisplayPartyArmor()
{
	cout << "\nArmor:\n";
	for (int i = 0; i < INV_ARMOR.size(); ++i)
	{
		cout << i << ". ";
		INV_ARMOR[i].DisplayName();
		cout << endl;
	}
	cout << endl;
}

void PartyInventory::SwapEquipedWeapon(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref)
{
	int playerSelection = 0;
	string wordPlayerSelection;
 
	int choice = 0;
	string wordChoice;

	cout << "Select character: ";
	cin >> wordPlayerSelection;
	playerSelection = wordPlayerSelection[0] - 48;

	while (playerSelection <= 0 || playerSelection > 3)
	{
		cout << "Select character: ";
		cin >> wordPlayerSelection;
		playerSelection = wordPlayerSelection[0] - 48;
	};
	switch (playerSelection)
	{
	case 1:
		if (INV_WEAPON.size() <= 3)
		{
			cout << "Nothing to swap.\n";
			break;
		}
		else
		{
			DisplayPartyWeapons();
			cout << "Select Weapon: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;
			while ((choice > INV_WEAPON.size() - 1) || choice < 0)
			{
				cout << "Invalid Selection. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			while ((EQUIPED_WEAPON1.ID == INV_WEAPON[choice].ID) || (EQUIPED_WEAPON2.ID == INV_WEAPON[choice].ID) || (EQUIPED_WEAPON3.ID == INV_WEAPON[choice].ID))
			{
				cout << "Already in use. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			BP1ref.m_Weapon = INV_WEAPON[choice];
			INV_WEAPON.insert(INV_WEAPON.end(), INV_WEAPON[choice]);
			INV_WEAPON.pop_back();
			EQUIPED_WEAPON1 = BP1ref.m_Weapon;
			break;
		}

	case 2:
		if (INV_WEAPON.size() <= 3)
		{
			cout << "Nothing to swap.\n";
			break;
		}
		else
		{
			DisplayPartyWeapons();
			cout << "Select Weapon: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;
			while ((choice > INV_WEAPON.size() - 1) || choice < 0)
			{
				cout << "Invalid Selection. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			while ((EQUIPED_WEAPON1.ID == INV_WEAPON[choice].ID) || (EQUIPED_WEAPON2.ID == INV_WEAPON[choice].ID) || (EQUIPED_WEAPON3.ID == INV_WEAPON[choice].ID))
			{
				cout << "Already in use. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			BP2ref.m_Weapon = INV_WEAPON[choice];
			INV_WEAPON.insert(INV_WEAPON.end(), INV_WEAPON[choice]);
			INV_WEAPON.pop_back();
			EQUIPED_WEAPON2 = BP2ref.m_Weapon;
			break;
		}

	case 3:
		if (INV_WEAPON.size() <= 3)
		{
			cout << "Nothing to swap.\n";
			break;
		}
		else
		{
			DisplayPartyWeapons();
			cout << "Select Weapon: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;
			while ((choice > INV_WEAPON.size() - 1) || choice < 0)
			{
				cout << "Invalid Selection. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			while ((EQUIPED_WEAPON1.ID == INV_WEAPON[choice].ID) || (EQUIPED_WEAPON2.ID == INV_WEAPON[choice].ID) || (EQUIPED_WEAPON3.ID == INV_WEAPON[choice].ID))
			{
				cout << "Already in use. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			BP3ref.m_Weapon = INV_WEAPON[choice];
			INV_WEAPON.insert(INV_WEAPON.end(), INV_WEAPON[choice]);
			INV_WEAPON.pop_back();
			EQUIPED_WEAPON3 = BP3ref.m_Weapon;
			break;
		}

	}
}

void PartyInventory::SwapEquipedArmor(Backpack &BP1ref, Backpack &BP2ref, Backpack &BP3ref)
{
	int playerSelection = 0;
	string wordPlayerSelection;

	int choice = 0;
	string wordChoice;

	cout << "Select character: ";
	cin >> wordPlayerSelection;
	playerSelection = wordPlayerSelection[0] - 48;

	while (playerSelection <= 0 || playerSelection > 3)
	{
		cout << "Select character: ";
		cin >> wordPlayerSelection;
		playerSelection = wordPlayerSelection[0] - 48;
	};
	switch (playerSelection)
	{
	case 1:
		if (INV_ARMOR.size() <= 3)
		{
			cout << "Nothing to swap.\n";
			break;
		}
		else
		{
			DisplayPartyArmor();
			cout << "Select Armor: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;
			while ((choice > INV_ARMOR.size() - 1) || choice < 0)
			{
				cout << "Invalid Selection. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			while ((EQUIPED_ARMOR1.ID == INV_ARMOR[choice].ID) || (EQUIPED_ARMOR2.ID == INV_ARMOR[choice].ID) || (EQUIPED_ARMOR3.ID == INV_ARMOR[choice].ID))
			{
				cout << "Already in use. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			BP1ref.m_Armor = INV_ARMOR[choice];
			INV_ARMOR.insert(INV_ARMOR.end(), INV_ARMOR[choice]);
			INV_ARMOR.pop_back();
			EQUIPED_ARMOR1 = BP1ref.m_Armor;
			break;
		}

	case 2:
		if (INV_ARMOR.size() <= 3)
		{
			cout << "Nothing to swap.\n";
			break;
		}
		else
		{
			DisplayPartyArmor();
			cout << "Select Armor: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;
			while ((choice > INV_ARMOR.size() - 1) || choice < 0)
			{
				cout << "Invalid Selection. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			while ((EQUIPED_ARMOR1.ID == INV_ARMOR[choice].ID) || (EQUIPED_ARMOR2.ID == INV_ARMOR[choice].ID) || (EQUIPED_ARMOR3.ID == INV_ARMOR[choice].ID))
			{
				cout << "Already in use. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			BP2ref.m_Armor = INV_ARMOR[choice];
			INV_ARMOR.insert(INV_ARMOR.end(), INV_ARMOR[choice]);
			INV_ARMOR.pop_back();
			EQUIPED_ARMOR2 = BP2ref.m_Armor;
			break;
		}

	case 3:
		if (INV_ARMOR.size() <= 3)
		{
			cout << "Nothing to swap.\n";
			break;
		}
		else
		{
			DisplayPartyArmor();
			cout << "Select Armor: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;
			while ((choice > INV_ARMOR.size() - 1) || choice < 0)
			{
				cout << "Invalid Selection. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			while ((EQUIPED_ARMOR1.ID == INV_ARMOR[choice].ID) || (EQUIPED_ARMOR2.ID == INV_ARMOR[choice].ID) || (EQUIPED_ARMOR3.ID == INV_ARMOR[choice].ID))
			{
				cout << "Already in use. Reselect: ";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			BP3ref.m_Armor = INV_ARMOR[choice];
			INV_ARMOR.insert(INV_ARMOR.end(), INV_ARMOR[choice]);
			INV_ARMOR.pop_back();
			EQUIPED_ARMOR3 = BP3ref.m_Armor;
			break;
		}

	}
}

PartyInventory::PartyInventory(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string PartyInventory::Serialized()
{
	string serialString = "";

	{
		serialString += "invWeapon[";
		if (INV_WEAPON.size() > 0)
		{
			for (size_t i = 0; i < INV_WEAPON.size(); ++i)
			{
				serialString += "{";
				serialString += INV_WEAPON[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	{
		serialString += "invArmor[";
		if (INV_ARMOR.size() > 0)
		{
			for (size_t i = 0; i < INV_ARMOR.size(); ++i)
			{
				serialString += "{";
				serialString += INV_ARMOR[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	serialString += "equipedWeapon1{" + EQUIPED_WEAPON1.Serialized() + "},";
	serialString += "equipedArmor1{" + EQUIPED_ARMOR1.Serialized() + "},";
	serialString += "equipedWeapon2{" + EQUIPED_WEAPON2.Serialized() + "},";
	serialString += "equipedArmor2{" + EQUIPED_ARMOR2.Serialized() + "},";
	serialString += "equipedWeapon3{" + EQUIPED_WEAPON3.Serialized() + "},";
	serialString += "equipedArmor3{" + EQUIPED_ARMOR3.Serialized() + "},";

	return serialString;
}