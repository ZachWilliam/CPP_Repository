#pragma once
#ifndef NPC_H
#define NPC_H
#include<string>
using namespace std;

class NPC
{
public:
	NPC(int p_row, int p_col, int p_mapID, int p_nameID, int p_dID);
	
	int row;
	int col;
	int mapID;
	int nameID;
	int dialogueID;
};

#endif 