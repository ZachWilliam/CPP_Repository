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
	Stats BattleStats;
	int initiative;
	int CurrentHP;
};
Combatant::Combatant()
{
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