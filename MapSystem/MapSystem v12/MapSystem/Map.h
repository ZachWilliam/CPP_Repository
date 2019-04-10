#pragma once
#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>
#include "Coord.h"
#include "NPC.h"
#include "QuestNPC.h"
#include "Chest.h"
#include "MapEnemy.h"
#include "Backpack.h"
#include "Format.h"
#include "SoundManager.h"
#include "GameManager.h"
#include "QuestManager.h"
#include "Database.h"
using namespace std;

class Map
{
public:
	Map(const string &p_name, const vector<vector<char> > &p_map, int p_mapID, bool p_canBattle, vector<Coord> p_transPoints, vector<NPC> p_npcs, vector<Chest> p_chests,
		vector<MapEnemy> p_mapEnemies, vector<QuestNPC> p_questNPCs, int p_defPR, int p_defPC, int p_spaceColor, string p_mapMusic);
	Map(string serialString);

	string Serialized();

	vector<vector<char> > map;
	int mapID;
	string name;
	bool canBattle = false;
	vector<Coord> v_transitionPoints;
	vector<NPC> v_NPCs;
	vector<Chest> v_chests;
	vector<MapEnemy> v_mapEnemies;
	vector<QuestNPC> v_questNPCs;
	int defaultPR, defaultPC;
	int spaceColor;
	string mapMusic;
	bool playedFlavorTxt = false;

	int OpenChest(int p_row, int p_col, Database &p_database, QuestManager &p_qManager);
};

#endif