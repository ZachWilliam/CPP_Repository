#include "MapEnemy.h"
#include "ConvertHelper.h"
#include "DeserializeHelper.h"

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
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			row = stoi(helper.ParsedValue());
			break;
		case 1:
			col = stoi(helper.ParsedValue());
			break;
		case 2:
			isDefeated = stob(helper.ParsedValue());
			break;
		case 3:
			isBoss = stob(helper.ParsedValue());
			break;
		case 4:
			isFinalBoss = stob(helper.ParsedValue());
			break;
		}
	}
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