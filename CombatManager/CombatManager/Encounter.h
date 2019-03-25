#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"

using namespace std;

class Encounter
{
public:
	Encounter(int, int, int, int, int, int);
	vector<int> AllEnemies = { 0,0,0,0,0,0 };
	vector<Enemy> FrontRow = { Enemy(AllEnemies[0]), Enemy(AllEnemies[1]), Enemy(AllEnemies[2]) };
	vector<Enemy> BackRow = { Enemy(AllEnemies[3]), Enemy(AllEnemies[4]), Enemy(AllEnemies[5]) };
};