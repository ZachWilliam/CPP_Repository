#pragma once
#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>
#include "Coord.h"
using namespace std;

class Map
{
public:
	Map(const string &p_name, const vector<vector<char> > &p_map, int p_mapID, bool p_canBattle, vector<Coord> p_transPoints, int p_defPR, int p_defPC);
	vector<vector<char> > map;
	int mapID;
	string name;
	bool canBattle = false;
	vector<Coord> transitionPoints;
	int defaultPR, defaultPC;
};

#endif