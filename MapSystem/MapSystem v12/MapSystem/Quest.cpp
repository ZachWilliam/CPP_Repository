#include "Quest.h"
#include "ConvertHelper.h"
#include "DeserializeHelper.h"


Quest::Quest(string p_name, bool p_isActive, bool p_isFinished, int p_mapID, int p_questID)
{
	questName = p_name;
	isQuestActive = p_isActive;
	isQuestFinished = p_isFinished;
	mapID = p_mapID;
	questID = p_questID;


}

Quest::Quest(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			questName = helper.ParsedValue();
			break;
		case 1:
			isQuestActive = stob(helper.ParsedValue());
			break;
		case 2:
			isQuestFinished = stob(helper.ParsedValue());
			break;
		case 3:
			mapID = stoi(helper.ParsedValue());
			break;
		case 4:
			questID = stoi(helper.ParsedValue());
			break;
		}
	}
}

string Quest::Serialized()
{
	string serialString = "";

	serialString += "questName:" + questName + ",";
	serialString += "isQuestActive:" + btos(isQuestActive) + ",";
	serialString += "isQuestFinished:" + btos(isQuestFinished) + ",";
	serialString += "mapID:" + to_string(mapID) + ",";
	serialString += "questID:" + to_string(questID) + ",";

	return serialString;
}