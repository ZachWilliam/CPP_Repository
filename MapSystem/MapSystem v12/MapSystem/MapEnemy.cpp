#include "MapEnemy.h"
#include"ConvertHelper.h"

MapEnemy::MapEnemy(int p_row, int p_col, bool p_isDefeated, int p_isBoss, int p_isFinalBoss) :
	row(p_row),
	col(p_col),
	isDefeated(p_isDefeated),
	isBoss(p_isBoss),
	isFinalBoss(p_isFinalBoss)
{
}

MapEnemy::MapEnemy(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string MapEnemy::Serialized()
{
	string serialString = "";

	serialString += "row:" + to_string(row) + ",";
	serialString += "col:" + to_string(col) + ",";
	serialString += "isDefeated:" + btos(isDefeated) + ",";
	serialString += "isBoss:" + btos(isBoss) + ",";
	serialString += "isFinalBoss:" + btos(isFinalBoss) + ",";

	return serialString;
}