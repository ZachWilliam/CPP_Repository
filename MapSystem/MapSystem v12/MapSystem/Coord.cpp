#include "Coord.h"



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
	// TODO - DESERIALIZE CONSTRUCTOR
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