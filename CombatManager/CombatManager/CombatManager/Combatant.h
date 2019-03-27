#include <iostream>
#include <string>
#include "Stats.h"

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
	enum Stat_Change {UP, NON, DOWN};
	Status status = OK;
	Stat_Change OFFENSE = NON;
	Stat_Change DEFENSE = NON;
	Stat_Change MOBILITY = NON;
	vector<int> BattleStats = {0,0,0,0,0,0,0,0};
	vector<float> Resistances = { 1,1,1,1,1,1,1,1,1,1,1 };
	int initiative;
	int CurrentHP;
	int CurrentMana;
	bool PlayerControl = false;
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