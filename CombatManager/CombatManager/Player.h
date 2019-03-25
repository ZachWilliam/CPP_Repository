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
	//Stats BaseStats = Stats();
	Stats CurrentStats = Stats();
	PlayerClass Job = PlayerClass();
	Backpack PlayerInventory = Backpack();
};
Player::Player()
{
	name = "";
	GeneratePlayer();
}
Player::Player(string call)
{
	name = call;
	GeneratePlayer();
}
void Player::GeneratePlayer()
{

}