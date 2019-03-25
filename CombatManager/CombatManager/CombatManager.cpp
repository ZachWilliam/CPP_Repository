// CombatManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include "BattleManager.h"
//#include "Combatant.h"
#include "CharacterCreator.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Combatant.h"
#include "Enemy.h"

using namespace std;

int main()
{
	bool inBattle = true;
	Player PC = Player();
	//CharacterCreator(PC);
	Enemy Foe(0);
	Foe.toString();
}

