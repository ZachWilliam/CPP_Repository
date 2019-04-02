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
