#include <iostream>
#include "Player.h"
#pragma once

using namespace std;

class Party
{
public:
	Party(Player);
	void AddToParty(Player, int);
	void RemoveFromParty(int);
	vector<Player> Container;
	bool isBank;

};
Party::Party(Player MC = Player("NULL_NAME"))
{

	Container.push_back(Player("NULL_NAME"));
	Container.push_back(Player(MC));
	Container.push_back(Player("NULL_NAME"));
	Container.push_back(Player("NULL_NAME"));
	Container.push_back(Player("NULL_NAME"));
	Container.push_back(Player("NULL_NAME"));
}
void Party::AddToParty(Player PM, int Pos)
{
	if (Container[Pos].name == "NULL_NAME")
	{
		Container[Pos] = PM;
	}
	else
	{
		RemoveFromParty(Pos);
		Container[Pos] = PM;
	}
}
void Party::RemoveFromParty(int Pos)
{
	Container[Pos] = Player("NULL_NAME");
}