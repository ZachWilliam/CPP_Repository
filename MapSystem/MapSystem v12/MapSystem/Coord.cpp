#include "Coord.h"
#include "DeserializeHelper.h"


Coord::Coord(int p_thisMapR, int p_thisMapC, int p_nextMapR, int p_nextMapC, int p_nextMapID) :
	thisMapR(p_thisMapR),
	thisMapC(p_thisMapC),
	nextMapR(p_nextMapR),
	nextMapC(p_nextMapC),
	nextMapID(p_nextMapID)
{
}

Coord::Coord(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			thisMapR = stoi(helper.ParsedValue());
			break;
		case 1:
			thisMapC = stoi(helper.ParsedValue());
			break;
		case 2:
			nextMapR = stoi(helper.ParsedValue());
			break;
		case 3:
			nextMapC = stoi(helper.ParsedValue());
			break;
		case 4:
			nextMapID = stoi(helper.ParsedValue());
			break;
		}
	}
}

string Coord::Serialized()
{
	string serialString = "";

	serialString += "thisMapR:" + to_string(thisMapR) + ",";
	serialString += "thisMapC:" + to_string(thisMapC) + ",";
	serialString += "nextMapR:" + to_string(nextMapR) + ",";
	serialString += "nextMapC:" + to_string(nextMapC) + ",";
	serialString += "nextMapID:" + to_string(nextMapID) + ",";

	return serialString;
}