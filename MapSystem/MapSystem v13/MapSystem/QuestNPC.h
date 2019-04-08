#pragma once
#include <string>
#include <vector>
using namespace std;

class QuestNPC
{
public:
	QuestNPC(int p_row, int p_col, int p_mapID, int p_locInVec, int p_nameID, vector<int> p_dIDs);

	int row;
	int col;
	int mapID;
	int nameID;
	vector<int> dialogueIDs;
	int locInDialogueVec = 0;

};

