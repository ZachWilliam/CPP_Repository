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
	Player();
	Player(string call);
	void GeneratePlayer();
	void GenerateAttacks();
	string name;
	int Level;
	int RStat;
	
	PlayerClass Job = PlayerClass();
	
	int Max_HP = 0;
	
	bool operator==(const Player &che) { return name == che.name; };
};
Player::Player()
{
	name = "";
	GeneratePlayer();
}
Player::Player(string call)
{
	name = call;
	Combatant::name = name;
	GeneratePlayer();
}
void Player::GeneratePlayer()
{
	PlayerControl = true;
}
void Player::GenerateAttacks()
{
	AttackManager Man = AttackManager();
	CurrentMoves = Man.GenerateMovesFromWeapon(PlayerInventory.m_Weapon);
}
