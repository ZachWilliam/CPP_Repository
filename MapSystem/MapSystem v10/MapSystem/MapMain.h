#pragma once
#ifndef MAP_MAIN_H
#define MAP_MAIN_H
#include <cstdlib>
#include <time.h>
#include "Format.h"
#include "Database.h"
#include "MapManager.h"
#include "SoundManager.h"
#include "Transitions.h"
#include <vector>
#include <conio.h>
using namespace std;

class MapMain
{
public:
	MapMain(Database &p_database);

	const int BORDER = 2;
	const int SCREEN_WIDTH = 69;
	const int SCREEN_HEIGHT = 27;
	const int DIST_FROM_MID_C = SCREEN_WIDTH / 2 + SCREEN_WIDTH % 2;
	const int DIST_FROM_MID_R = SCREEN_HEIGHT / 2 + SCREEN_HEIGHT % 2;
	const int BOT_START_ROW = SCREEN_HEIGHT + BORDER;
	const int RIGHT_START_COL = SCREEN_WIDTH + BORDER;
	const int SIDE_WIDTH = 30;


	MapManager mapManager;
	Map curMap = mapManager.mapList[0];

	Database database;

	//Player Info
	enum eDirection { LEFT = -1, RIGHT = 1, UP = -1, DOWN = 1, NEUTRAL = 0 };
	eDirection cDir = NEUTRAL;
	eDirection rDir = NEUTRAL;
	int playerR = curMap.defaultPR;
	int playerC = curMap.defaultPC;
	char lastChar = curMap.map[playerR][playerC];
	bool interact = false;

	//Battle Info
	const int CHECK_EVERY_STEPS = 4;
	const int MIN_ENCOUNTER_CHANCE = 2;
	const int MAX_ENCOUNTER_CHANCE = 12;
	int curEncounterChance = MAX_ENCOUNTER_CHANCE;
	int stepCount = 0;

	

	vector<char> v_collisionChars = { 'W', 'T', 'B', 'D', 'G', 'R', 'U', 'L','=', '#', '&', '+', '*', '%', '!', '$'};
	vector<char> v_interactChars = { '=','#' ,'&', '+', '*', '%','!','$'};

	//Input
	bool aKey = false;
	bool sKey = false;
	bool dKey = false;
	bool wKey = false;
	int columnMove = 0, rowMove = 0;


	//Protoypes
	int main();
	void Setup(int p_mapID, int p_row = 0, int p_col = 0);
	void Input();
	void Logic();

	bool CheckCollision(char p_nextChar);
	void SetMap(int p_pRow, int p_pCol, int p_mapID);
	void DoInteraction();
	void CheckForBattle();

	void DrawGUI();
	void DrawScreen();
	void DrawRight();
};

#endif