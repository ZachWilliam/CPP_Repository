#include "Map.h"



Map::Map(const string &p_name, const vector<vector<char> > &p_map, int p_mapID, bool p_canBattle, vector<Coord> p_transPoints, int p_defPR, int p_defPC) :
	name(p_name),
	map(p_map),
	mapID(p_mapID),
	canBattle(p_canBattle),
	transitionPoints(p_transPoints),
	defaultPR(p_defPR),
	defaultPC(p_defPC)
{
}



