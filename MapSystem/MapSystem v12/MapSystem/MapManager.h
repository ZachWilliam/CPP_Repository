#pragma once
#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H
#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Backpack.h"
#include "Map.h"
using namespace std;

class MapManager
{
public:
	MapManager();
	MapManager(string serialString);

	string Serialized();

	vector <Map> mapList;


	vector<Coord> GetCoords(const string &p_line);
	vector<NPC> GetNPCs(const string &p_line);
	vector<Chest> GetChests(const string &p_line);
	vector<MapEnemy> GetEnemies(const string &p_line);
	vector<QuestNPC> GetQuestNPCs(const string &p_line);
	void LoadAllMaps();
	void LoadMap(ifstream &p_fileToRead);
};

#endif
