#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "ClassManager.h"
#include "Stats.h"
#include <time.h>
#include <Windows.h>

using namespace std;

class PartyManager
{
public:
	PartyManager();
	void GenerateParty();
	Player GetPartyMember(int);
	vector<Player> AllPresets = vector<Player>(30);
	ClassManager Man = ClassManager();
};
PartyManager::PartyManager()
{
	GenerateParty();
}
Player PartyManager::GetPartyMember(int PC)
{
	int choice = rand() % 100 + 1;
	if (PC < 8)
	{
		if (choice < 60)
		{
			return AllPresets[3 * PC];
		}
		else if (choice < 90)
		{
			return AllPresets[3 * PC + 1];
		}
		else
		{
			return AllPresets[3 * PC + 2];
		}
	}
	else
	{
		if (choice < 40)
		{
			return AllPresets[24];
		}
		else if (choice < 65)
		{
			return AllPresets[25];
		}
		else if (choice < 80)
		{
			return AllPresets[26];
		}
		else if (choice < 90)
		{
			return AllPresets[27];
		}
		else if (choice < 95)
		{
			return AllPresets[28];
		}
		else
		{
			return AllPresets[29];
		}
	}
}
void PartyManager::GenerateParty()
{
	AllPresets[0] = Player("Arthur");
	AllPresets[0].Job = Man.AllClasses[0];
	AllPresets[0].CurrentStats = Stats(7,1,7,3,1,4,4);
	AllPresets[0].PlayerInventory.m_Weapon.SetWeapon(2,2,10);
	AllPresets[1] = Player("Ameera");
	AllPresets[1].Job = Man.AllClasses[0];
	AllPresets[1].CurrentStats = Stats(3, 4, 4, 5, 1, 3, 6);
	AllPresets[1].PlayerInventory.m_Weapon.SetWeapon(14, 3, 10);
	AllPresets[2] = Player("Roy");
	AllPresets[2].Job = Man.AllClasses[0];
	AllPresets[2].CurrentStats = Stats(9, 1, 3, 5, 1, 3, 5);
	AllPresets[2].PlayerInventory.m_Weapon.SetWeapon(1, 1, 1);
	AllPresets[3] = Player("Hilda");
	AllPresets[3].Job = Man.AllClasses[1];
	AllPresets[3].CurrentStats = Stats(1, 1, 2, 3, 7, 7, 6);
	AllPresets[3].PlayerInventory.m_Weapon.SetWeapon(9, 2, 2);
	AllPresets[4] = Player("Tim");
	AllPresets[4].Job = Man.AllClasses[1];
	AllPresets[4].CurrentStats = Stats(1, 1, 3, 3, 8, 9, 2);
	AllPresets[4].PlayerInventory.m_Weapon.SetWeapon(11, 3, 1);
	AllPresets[5] = Player("Saga");
	AllPresets[5].Job = Man.AllClasses[1];
	AllPresets[5].CurrentStats = Stats(1, 1, 1, 3, 9, 4, 8);
	AllPresets[5].PlayerInventory.m_Weapon.SetWeapon(9, 3, 0);
	AllPresets[6] = Player("Robin");
	AllPresets[6].Job = Man.AllClasses[2];
	AllPresets[6].CurrentStats = Stats(1, 7, 3, 5, 2, 4, 5);
	AllPresets[6].PlayerInventory.m_Weapon.SetWeapon(15, 2, 10);
	AllPresets[7] = Player("Norne");
	AllPresets[7].Job = Man.AllClasses[2];
	AllPresets[7].CurrentStats = Stats(1, 6, 4, 7, 1, 2, 6);
	AllPresets[7].PlayerInventory.m_Weapon.SetWeapon(15, 1, 5);
	AllPresets[8] = Player("Kaizo");
	AllPresets[8].Job = Man.AllClasses[2];
	AllPresets[8].CurrentStats = Stats(1, 9, 1, 7, 1, 2, 6);
	AllPresets[8].PlayerInventory.m_Weapon.SetWeapon(13, 3, 5);
	AllPresets[9] = Player("Lance");
	AllPresets[9].Job = Man.AllClasses[3];
	AllPresets[9].CurrentStats = Stats(6, 1, 6, 5, 1, 3, 5);
	AllPresets[9].PlayerInventory.m_Weapon.SetWeapon(7, 2, 10);
	AllPresets[10] = Player("Camilia");
	AllPresets[10].Job = Man.AllClasses[3];
	AllPresets[10].CurrentStats = Stats(4, 6, 3, 6, 1, 1, 6);
	AllPresets[10].PlayerInventory.m_Weapon.SetWeapon(2, 3, 6);
	AllPresets[11] = Player("Kapitan");
	AllPresets[11].Job = Man.AllClasses[3];
	AllPresets[11].CurrentStats = Stats(7, 1, 9, 2, 1, 5, 2);
	AllPresets[11].PlayerInventory.m_Weapon.SetWeapon(8, 2, 3);
	AllPresets[12] = Player("Grace");
	AllPresets[12].Job = Man.AllClasses[4];
	AllPresets[12].CurrentStats = Stats(5, 1, 6, 3, 1, 7, 4);
	AllPresets[12].PlayerInventory.m_Weapon.SetWeapon(3, 2, 10);
	AllPresets[13] = Player("Hodor");
	AllPresets[13].Job = Man.AllClasses[4];
	AllPresets[13].CurrentStats = Stats(9, 1, 7, 3, 1, 1, 5);
	AllPresets[13].PlayerInventory.m_Weapon.SetWeapon(6, 4, 10);
	AllPresets[14] = Player("Cybelle");
	AllPresets[14].Job = Man.AllClasses[4];
	AllPresets[14].CurrentStats = Stats(8, 1, 2, 6, 1, 1, 8);
	AllPresets[14].PlayerInventory.m_Weapon.SetWeapon(4, 2, 7);
	AllPresets[15] = Player("Bruce");
	AllPresets[15].Job = Man.AllClasses[5];
	AllPresets[15].CurrentStats = Stats(7, 2, 2, 3, 3, 5, 5);
	AllPresets[15].PlayerInventory.m_Weapon.SetWeapon(0, 3, 10);
	AllPresets[16] = Player("Jack");
	AllPresets[16].Job = Man.AllClasses[5];
	AllPresets[16].CurrentStats = Stats(5, 2, 2, 5, 3, 5, 5);
	AllPresets[16].PlayerInventory.m_Weapon.SetWeapon(0, 3, 10);
	AllPresets[17] = Player("Morgan");
	AllPresets[17].Job = Man.AllClasses[5];
	AllPresets[17].CurrentStats = Stats(9, 2, 2, 7, 1, 2, 4);
	AllPresets[17].PlayerInventory.m_Weapon.SetWeapon(0, 4, 10);
	AllPresets[18] = Player("Kohga");
	AllPresets[18].Job = Man.AllClasses[6];
	AllPresets[18].CurrentStats = Stats(1, 6, 1, 8, 2, 2, 7);
	AllPresets[18].PlayerInventory.m_Weapon.SetWeapon(13, 3, 10);
	AllPresets[19] = Player("Vienna");
	AllPresets[19].Job = Man.AllClasses[6];
	AllPresets[19].CurrentStats = Stats(1, 3, 5, 6, 2, 3, 7);
	AllPresets[19].PlayerInventory.m_Weapon.SetWeapon(14, 2, 10);
	AllPresets[20] = Player("Eva");
	AllPresets[20].Job = Man.AllClasses[6];
	AllPresets[20].CurrentStats = Stats(1, 7, 1, 6, 6, 1, 5);
	AllPresets[20].PlayerInventory.m_Weapon.SetWeapon(14, 2, 5);
	AllPresets[21] = Player("Argyros");
	AllPresets[21].Job = Man.AllClasses[7];
	AllPresets[21].CurrentStats = Stats(1, 2, 5, 3, 8, 5, 3);
	AllPresets[21].PlayerInventory.m_Weapon.SetWeapon(10, 2, 1);
	AllPresets[22] = Player("Shulski");
	AllPresets[22].Job = Man.AllClasses[7];
	AllPresets[22].CurrentStats = Stats(1, 2, 3, 8, 8, 3, 2);
	AllPresets[22].PlayerInventory.m_Weapon.SetWeapon(10, 2, 4);
	AllPresets[23] = Player("Natalie");
	AllPresets[23].Job = Man.AllClasses[7];
	AllPresets[23].CurrentStats = Stats(1, 5, 1, 9, 6, 1, 4);
	AllPresets[23].PlayerInventory.m_Weapon.SetWeapon(11, 3, 7);
	AllPresets[24] = Player("Reginald");
	AllPresets[24].Job = Man.AllClasses[8];
	AllPresets[24].CurrentStats = Stats(2, 2, 5, 3, 5, 5, 5);
	AllPresets[24].PlayerInventory.m_Weapon.SetWeapon(12, 2, 9);
	AllPresets[25] = Player("Claire");
	AllPresets[25].Job = Man.AllClasses[8];
	AllPresets[25].CurrentStats = Stats(1, 1, 6, 2, 5, 6, 6);
	AllPresets[25].PlayerInventory.m_Weapon.SetWeapon(12, 1, 9);
	AllPresets[26] = Player("Selkie");
	AllPresets[26].Job = Man.AllClasses[8];
	AllPresets[26].CurrentStats = Stats(1, 1, 7, 3, 2, 7, 6);
	AllPresets[26].PlayerInventory.m_Weapon.SetWeapon(12, 3, 3);
	AllPresets[27] = Player("Thalia");
	AllPresets[27].Job = Man.AllClasses[8];
	AllPresets[27].CurrentStats = Stats(1, 1, 7, 2, 5, 6, 5);
	AllPresets[27].PlayerInventory.m_Weapon.SetWeapon(12, 3, 5);
	AllPresets[28] = Player("Mia");
	AllPresets[28].Job = Man.AllClasses[8];
	AllPresets[28].CurrentStats = Stats(1, 1, 3, 6, 6, 4, 6);
	AllPresets[28].PlayerInventory.m_Weapon.SetWeapon(12, 2, 7);
	AllPresets[29] = Player("Zennith");
	AllPresets[29].Job = Man.AllClasses[8];
	AllPresets[29].CurrentStats = Stats(1, 1, 9, 1, 2, 9, 4);
	AllPresets[29].PlayerInventory.m_Weapon.SetWeapon(12, 2, 6);
	
}