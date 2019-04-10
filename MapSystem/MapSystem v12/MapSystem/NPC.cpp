#include "NPC.h"



NPC::NPC(int p_row, int p_col, int p_mapID, int p_nameID, int p_dID) :
	row(p_row),
	col(p_col),
	dialogueID(p_dID),
	mapID(p_mapID),
	nameID(p_nameID)
{
}

NPC::NPC(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string NPC::Serialized()
{
	string serialString = "";

	serialString += "row:" + to_string(row) + ",";
	serialString += "col:" + to_string(col) + ",";
	serialString += "mapID:" + to_string(mapID) + ",";
	serialString += "nameID:" + to_string(nameID) + ",";
	serialString += "dialogueID:" + to_string(dialogueID) + ",";

	return serialString;
}