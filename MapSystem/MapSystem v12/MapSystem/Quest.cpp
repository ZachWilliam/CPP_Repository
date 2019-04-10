#include "Quest.h"
#include "ConvertHelper.h"


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
	// TODO - DESERIALIZE CONSTRUCTOR
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