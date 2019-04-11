#include "QuestNPC.h"
#include "DeserializeHelper.h"



QuestNPC::QuestNPC(int p_row, int p_col, int p_mapID, int p_locInVec, int p_nameID, vector<int> p_dIDs) :
	row(p_row),
	col(p_col),
	dialogueIDs(p_dIDs),
	mapID(p_mapID),
	nameID(p_nameID),
	locInDialogueVec(p_locInVec)
{
}

QuestNPC::QuestNPC(string serialString)
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
			mapID = stoi(helper.ParsedValue());
			break;
		case 3:
			nameID = stoi(helper.ParsedValue());
			break;
		case 4:
			dialogueIDs.push_back(stoi(helper.ParsedValue()));
			break;
		case 5:
			locInDialogueVec = stoi(helper.ParsedValue());
			break;
		}
	}
}

string QuestNPC::Serialized()
{
	string serialString = "";

	serialString += "row:" + to_string(row) + ",";
	serialString += "col:" + to_string(col) + ",";
	serialString += "mapID:" + to_string(mapID) + ",";
	serialString += "nameID:" + to_string(nameID) + ",";
	{
		serialString += "dialogueIDs[";
		if (dialogueIDs.size() > 0)
		{
			for (size_t i = 0; i < dialogueIDs.size(); ++i)
			{
				serialString += "diaID:" + to_string(dialogueIDs[i]) + ",";
			}
		}
		serialString += "],";
	}
	serialString += "locInDialogueVec:" + to_string(locInDialogueVec) + ",";

	return serialString;
}