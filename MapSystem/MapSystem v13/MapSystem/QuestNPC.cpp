#include "QuestNPC.h"



QuestNPC::QuestNPC(int p_row, int p_col, int p_mapID, int p_locInVec, int p_nameID, vector<int> p_dIDs):
	row(p_row),
	col(p_col),
	dialogueIDs(p_dIDs),
	mapID(p_mapID),
	nameID(p_nameID),
	locInDialogueVec(p_locInVec)
{
}
