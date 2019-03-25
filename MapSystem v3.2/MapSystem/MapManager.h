#pragma once
#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H
#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Map.h"
using namespace std;

class MapManager
{
public:
	MapManager();
	vector <Map> mapList;


	vector<Coord> GetCoords(const string &p_line);
	void LoadAllMaps();
	void LoadMap(ifstream &p_fileToRead);
};

#endif
