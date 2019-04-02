#pragma once
#include <iostream>

using namespace std;

class Attack
{
public:
	Attack();
	Attack(string, int, int);
	string name;
	int power;
	//Target: Single = 0; Double = 1; LongRange = 2; DoubleRange = 3; FrontRow = 4; Column = 5; All = 6; Single_H = 7; All_H = 8;
	int target;
	//Effect: None = 0; POWER_UP = 1; POWER_DOWN = 2; GUARD_UP = 3; GUARD_DOWN = 4; MOBILITY_UP = 5; MOBILITY_DOWN = 6; OMNI_UP = 7; OMNI_DOWN = 8; POETRY = 9;
	int effect;
};
Attack::Attack()
{
	name = "NULL_ATTACK";
	power = 0;
	target = 0;
}
Attack::Attack(string nama, int powa, int targa)
{
	name = nama;
	power = powa;
	target = targa;
}
