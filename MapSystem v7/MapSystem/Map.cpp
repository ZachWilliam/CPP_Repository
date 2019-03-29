#include "Map.h"



Map::Map(const string &p_name, const vector<vector<char> > &p_map, int p_mapID, bool p_canBattle, vector<Coord> p_transPoints, vector<NPC> p_npcs, vector<Chest> p_chests, int p_defPR, int p_defPC, int p_spaceColor) :
	name(p_name),
	map(p_map),
	mapID(p_mapID),
	canBattle(p_canBattle),
	v_transitionPoints(p_transPoints),
	v_npcs(p_npcs),
	v_chests(p_chests),
	defaultPR(p_defPR),
	defaultPC(p_defPC),
	spaceColor(p_spaceColor)
{
}



