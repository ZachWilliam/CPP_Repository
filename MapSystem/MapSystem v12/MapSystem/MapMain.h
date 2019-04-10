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
#include "QuestManager.h"
#include "GameManager.h"
#include "Encounter.h"
#include "EncounterManager.h"
#include <vector>
#include <conio.h>
using namespace std;

class MapMain
{
public:
	MapMain(Database &p_database, Database &p_beastiary, Party &p_party, PartyInventory &p_inventory);

	const int border = GameManager::instance().BORDER;
	const int screen_width = GameManager::instance().SCREEN_WIDTH;
	const int screen_height = GameManager::instance().SCREEN_HEIGHT;
	const int dist_from_mid_c = GameManager::instance().DIST_FROM_MID_C;
	const int dist_from_mid_r = GameManager::instance().DIST_FROM_MID_R;
	const int bot_start_row = GameManager::instance().BOT_START_ROW;
	const int right_start_col = GameManager::instance().RIGHT_START_COL;
	const int side_width = GameManager::instance().SIDE_WIDTH;


	MapManager mapManager;
	Map curMap = mapManager.mapList[0];

	QuestManager questManager;
	
	Database database_monsters;
	Database database_text;
	Party TheGroup;
	PartyInventory Inventory;
	EncounterManager RandomSpawn;

	//Player Info
	enum eDirection { LEFT = -1, RIGHT = 1, UP = -1, DOWN = 1, NEUTRAL = 0 };
	eDirection cDir = NEUTRAL;
	eDirection rDir = NEUTRAL;
	int playerR = curMap.defaultPR;
	int playerC = curMap.defaultPC;
	char lastChar = curMap.map[playerR][playerC];
	bool interact = false;
	bool openInventory = false;

	//Battle Info
	enum eVictorious {LOSE,WIN,FLEE};
	const int CHECK_EVERY_STEPS = 4;
	const int MIN_ENCOUNTER_CHANCE = 2;
	const int MAX_ENCOUNTER_CHANCE = 12;
	int curEncounterChance = MAX_ENCOUNTER_CHANCE;
	int stepCount = 0;

	

	vector<char> v_collisionChars = { 'W', 'T', 'B', 'D', 'G', 'R', 'U', 'L','=', '#', '&', '+', '*', '%', '!', '$','@'};
	vector<char> v_interactChars = { '=','#' ,'&', '+', '*', '%','!','$','@' };

	//Input
	bool leftKey = false;
	bool downKey = false;
	bool rightKey = false;
	bool upKey = false;
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
	void PauseMenu();

	void DrawScreen();
	void DrawRight();
	void DrawCombatScreen();

	void WriteToFile(string p_saveString);
};

#endif