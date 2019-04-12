#include "Quest.h"



Quest::Quest(string p_name, bool p_isActive, bool p_isFinished, int p_mapID, int p_questID)
{
	questName = p_name;
	isQuestActive = p_isActive;
	isQuestFinished = p_isFinished;
	mapID = p_mapID;
	questID = p_questID;


}



