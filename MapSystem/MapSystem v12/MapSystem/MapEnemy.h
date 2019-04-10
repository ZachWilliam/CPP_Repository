#pragma once
#include<string>

using namespace std;

class MapEnemy
{
public:
	MapEnemy(int p_row, int p_col, bool p_isDefeated, int p_isBoss, int p_isFinalBoss);
	MapEnemy(string serialString);

	string Serialized();

	int row;
	int col;
	bool isDefeated = false;
	bool isBoss = false;
	bool isFinalBoss = false;

	//Some sort of ID

};

