#include "Chest.h"
#include "ConvertHelper.h"
#include "DeserializeHelper.h"


Chest::Chest(int p_row, int p_col, bool p_opened, int p_id1, int p_id2, int p_id3, int p_itemID) :
	row(p_row),
	col(p_col),
	opened(p_opened),
	id1(p_id1),
	id2(p_id2),
	id3(p_id3),
	itemType(p_itemID)
{
}

Chest::Chest(string serialString)
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
			opened = stob(helper.ParsedValue());
			break;
		case 3:
			id1 = stoi(helper.ParsedValue());
			break;
		case 4:
			id2 = stoi(helper.ParsedValue());
			break;
		case 5:
			id3 = stoi(helper.ParsedValue());
			break;
		case 6:
			itemType = stoi(helper.ParsedValue());
			break;
		}
	}
}

string Chest::Serialized()
{
	string serialString = "";

	serialString += "row:" + to_string(row) + ",";
	serialString += "col:" + to_string(col) + ",";
	serialString += "opened:" + btos(opened) + ",";
	serialString += "id1:" + to_string(id1) + ",";
	serialString += "id2:" + to_string(id2) + ",";
	serialString += "id3:" + to_string(id3) + ",";
	serialString += "itemType:" + to_string(itemType) + ",";

	return serialString;
}