#pragma once
#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>
#include "Coord.h"
#include "NPC.h"
#include "Chest.h"
#include "MapEnemy.h"
#include "Backpack.h"
#include "Format.h"
using namespace std;

class Map
{
public:
	Map(const string &p_name, const vector<vector<char> > &p_map, int p_mapID, bool p_canBattle, vector<Coord> p_transPoints, vector<NPC> p_npcs, vector<Chest> p_chests, 
		vector<MapEnemy> p_mapEnemies, int p_defPR, int p_defPC, int p_spaceColor, string p_mapMusic);

	vector<vector<char> > map;
	int mapID;
	string name;
	bool canBattle = false;
	vector<Coord> v_transitionPoints;
	vector<NPC> v_npcs;
	vector<Chest> v_chests;
	vector<MapEnemy> v_mapEnemies;
	int defaultPR, defaultPC;
	int spaceColor;
	string mapMusic;
	bool playedFlavorTxt = false;

	int OpenChest(int p_row, int p_col, int p_sWidth, int p_botStartRow);
};

#endif