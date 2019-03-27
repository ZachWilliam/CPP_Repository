#include <iostream>
#include "Stats.h"
#include "Combatant.h"
#include "PlayerClass.h"
#include "Backpack.h"
#pragma once

using namespace std;

class Player : public Combatant
{
public:
	Player();
	Player(string call);
	void GeneratePlayer();
	string name;
	int Level;
	Stats CurrentStats = Stats();
	PlayerClass Job = PlayerClass();
	Backpack PlayerInventory = Backpack(0,0,false,0,0,0,0,0,0,0);
	int Max_HP = 0;
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