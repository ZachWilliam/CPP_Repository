#include <iostream>
#include "Stats.h"
#include "Combatant.h"
#include "PlayerClass.h"
#include "Backpack.h"
#include "Attack.h"
#include "AttackManager.h"
#pragma once

using namespace std;

class Player : public Combatant
{
public:
    Player()
    {
        name = "";
        GeneratePlayer();
    }
    Player(string call)
    {
        name = call;
        Combatant::name = name;
        GeneratePlayer();
    }
    void GeneratePlayer()
    {
        PlayerControl = true;
    }
    void GenerateAttacks()
    {
        AttackManager Man = AttackManager();
        CurrentMoves = Man.GenerateMovesFromWeapon(PlayerInventory.m_Weapon);
    }

	string name;
	int Level;
	int RStat;
	int CurrentEXP = 0;
	
	PlayerClass Job = PlayerClass();
	
	int Max_HP = 0;
	
	bool operator==(const Player &che) { return name == che.name; };
};
