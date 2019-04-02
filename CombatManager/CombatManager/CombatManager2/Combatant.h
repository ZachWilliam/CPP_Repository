#include <iostream>
#include <string>
#include "Stats.h"
#include "Attack.h"
#include "AttackManager.h"
#include "Backpack.h"

using namespace std;

#pragma once

class Combatant
{
public:
	Combatant();
	void SetHP(int);
	void StartCombat(int);
	void EndCombat();
	string name;
	enum Status {OK, POI, PAR, VEX, CUR, SLP, UNC};
	enum Stat_Change {UP = 1, NON = 0, DOWN = -1};
	Status status = OK;
	Stat_Change OFFENSE = NON;
	Stat_Change DEFENSE = NON;
	Stat_Change MOBILITY = NON;
	Stats CurrentStats = Stats();
	vector<int> BattleStats = {0,0,0,0,0,0,0,0};
	vector<float> Resistances = { 1,1,1,1,1,1,1,1,1,1,1 };
	int initiative;
	int CurrentHP = 0;
	int CurrentMana = 0;
	bool PlayerControl = false;
	vector<Attack> CurrentMoves = vector<Attack>(4);
	Backpack PlayerInventory = Backpack(0, 0, false, 0, 0, 0, 0, 0, 0, 0);

	bool operator==(const Combatant &che) { return name == che.name; };
};
Combatant::Combatant()
{
	name = "";
	initiative = 0;
}
void Combatant::StartCombat(int in)
{
	initiative = in;
}
void Combatant::EndCombat()
{
	initiative = 0;
}
void Combatant::SetHP(int MAX_HP)
{
	CurrentHP = MAX_HP;
}