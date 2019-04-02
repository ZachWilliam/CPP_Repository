#include "MapMain.h"

MapMain::MapMain(Database &p_database):
	database(p_database)
{}


int MapMain::main() {
	//SetColorAndBackground();
	//curMap.map[playerR][playerC] = 'P'; 
	
	
	//DrawGUI();
	//DrawRight();
	
	while (true) {
		DrawScreen();
		Input();
		Logic();
		Sleep(1);
	}

	//_getch();
}

void MapMain::Setup(int p_mapID, int p_row, int p_col) {
	bool mapFound = false;
	for (int i = 0; i < mapManager.mapList.size(); i++)
	{
		if (mapManager.mapList[i].mapID == p_mapID) {
			curMap = mapManager.mapList[i];
			mapFound = true;
			break;
		}
	}
	//If we didnt find the map then set it to the town map
	if (!mapFound) {
		for (int i = 0; i < mapManager.mapList.size(); i++)
		{
			if (mapManager.mapList[i].mapID == 6) {
				curMap = mapManager.mapList[i];
				break;
			}
		}
	}

	if (p_row == 0 || p_col == 0) {
		playerR = curMap.defaultPR;
		 playerC = curMap.defaultPC;
	}
	else {
		playerR = p_row;
		playerC = p_col;
	}

	char lastChar = curMap.map[playerR][playerC];

	//Prep screen
	Logic();
	SetColorAndBackground();

	//Put player on the map if its not the intro screen
	if(curMap.mapID != 1) curMap.map[playerR][playerC] = 'P';

	//Draw screens
	DrawGUI();
	if(curMap.mapID != 1) DrawScreen();
	else {
		SetColorAndBackground(LIGHTGRAY);
		for (int i = 0; i < SCREEN_HEIGHT; i++)
		{
			GoToXY(1 + i, 1);
			cout << string(SCREEN_WIDTH, ' ');
		}
		SetColorAndBackground();
	}
	DrawRight();

	//If map is intro screen do trans effect
	if (curMap.mapID == 1) {
		PlaySound("Sound/trans_sfx2.wav", NULL, SND_FILENAME | SND_ASYNC);
		PlayMapTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT, curMap, rowMove, columnMove, false);
	}

	SoundManager::Instance().PlayMusic(curMap.mapMusic);

	//Play flavour text if it hasnt been played before
	if (!curMap.playedFlavorTxt) {
		string name = database.ReturnName(curMap.v_npcs[0].nameID);
		string speech = database.ReturnDialogue(curMap.mapID, curMap.v_npcs[0].nameID, curMap.v_npcs[0].dialogueID);

		OutputSpeech(speech, name, SCREEN_WIDTH, BOT_START_ROW);
		curMap.playedFlavorTxt = true;

		for (int i = 0; i < mapManager.mapList.size(); i++)
		{
			if (curMap.mapID == mapManager.mapList[i].mapID) {
				mapManager.mapList[i].playedFlavorTxt = true;
				break;
			}
		}
	}

	//Go straight to introIsland if map is the intro map
	if (curMap.mapID == 1) {
		SetMap(curMap.v_transitionPoints[0].nextMapR, curMap.v_transitionPoints[0].nextMapC, curMap.v_transitionPoints[0].nextMapID);
	}
}

void MapMain::Input() {
	aKey = GetKeyState('A') & 0x8000;
	sKey = GetKeyState('S') & 0x8000;
	dKey = GetKeyState('D') & 0x8000;
	wKey = GetKeyState('W') & 0x8000;

	if (aKey) cDir = LEFT;	if (dKey) cDir = RIGHT;
	if ((aKey && dKey) || (!aKey && !dKey)) cDir = NEUTRAL;

	if (wKey) rDir = UP; if (sKey) rDir = RIGHT;
	if ((wKey && sKey) || (!wKey && !sKey)) rDir = NEUTRAL;

	if (_kbhit()) {
		switch (_getch()) {
		case ' ':
			interact = true;
			break;
		}
	}
}

void MapMain::Logic() {
	//Transition Maps
	//Check to see if the player has moved onto a transition point
	if (lastChar == '?') {//lastChar would be the spot the player just moved too, aka why we check to see if its a ?
		int posInCoordVec = -1;
		for (int i = 0; i < curMap.v_transitionPoints.size(); i++)
		{
			if (playerR == curMap.v_transitionPoints[i].thisMapR && playerC == curMap.v_transitionPoints[i].thisMapC) {
				posInCoordVec = i;
				break;
			}
		}
		
		//If we found the coords
		if (posInCoordVec != -1) {
			Coord nextCoord = curMap.v_transitionPoints[posInCoordVec];
			SetMap(nextCoord.nextMapR, nextCoord.nextMapC, nextCoord.nextMapID);
		}
		else//Couldnt find the coords, send to default of the map
		{
			SetMap(curMap.defaultPR, curMap.defaultPC, curMap.mapID);
			return;
		}
	}


	//Interact
	if (interact) {
		DoInteraction();
	}

	//Move
	if (rDir != NEUTRAL) {
		if (!CheckCollision(curMap.map[playerR + rDir][playerC])) {
			//Reset char of where player is standing
			curMap.map[playerR][playerC] = lastChar;
			lastChar = curMap.map[playerR + rDir][playerC];

			//Set player
			curMap.map[playerR + rDir][playerC] = 'P';
			playerR += rDir;
		}
	}
	if (cDir != NEUTRAL) {
		if (!CheckCollision(curMap.map[playerR][playerC + cDir])) {
			curMap.map[playerR][playerC] = lastChar;
			lastChar = curMap.map[playerR][playerC + cDir];

			curMap.map[playerR][playerC + cDir] = 'P';
			playerC += cDir;
		}
	}

	//Check for battle if the player moved in a battle area
	if (curMap.canBattle) {
		if (rDir != NEUTRAL || cDir != NEUTRAL) {
			stepCount++;
			if (stepCount % CHECK_EVERY_STEPS == 0) CheckForBattle();
		}
	}


	//Update Screen vector
	if (playerC - DIST_FROM_MID_C >= 0 && curMap.map[0].size() - playerC >= DIST_FROM_MID_C) columnMove = playerC - DIST_FROM_MID_C;
	else if (curMap.map[0].size() - playerC < DIST_FROM_MID_C) columnMove = curMap.map[0].size() - SCREEN_WIDTH;

	if (playerR - DIST_FROM_MID_R >= 0 && curMap.map.size() - playerR >= DIST_FROM_MID_R) rowMove = playerR - DIST_FROM_MID_R;
	else if (curMap.map.size() - playerR < DIST_FROM_MID_R) rowMove = curMap.map.size() - SCREEN_HEIGHT;
}



void MapMain::DoInteraction() {
	char interactChar = ' ';
	int charRow, charCol;
	for (int i = 0; i < v_interactChars.size(); i++)
	{
		if (curMap.map[playerR - 1][playerC] == v_interactChars[i]) {
			interactChar = v_interactChars[i];
			charRow = playerR - 1; charCol = playerC;
		}
		else if (curMap.map[playerR + 1][playerC] == v_interactChars[i]) {
			interactChar = v_interactChars[i];
			charRow = playerR + 1; charCol = playerC;
		}
		else if (curMap.map[playerR][playerC - 1] == v_interactChars[i]) {
			interactChar = v_interactChars[i];
			charRow = playerR; charCol = playerC - 1;
		}
		else if (curMap.map[playerR][playerC + 1] == v_interactChars[i]) {
			interactChar = v_interactChars[i];
			charRow = playerR; charCol = playerC + 1;
		}
	}

	//Chest
	if (interactChar == '=') {
		
		int locInChestVec = curMap.OpenChest(charRow, charCol, SCREEN_WIDTH, BOT_START_ROW);
		if (locInChestVec != -1) {
			//Change data in local map copy
			curMap.map[charRow][charCol] = ' ';
			curMap.v_chests[locInChestVec].opened = true;

			//Find actual map data in mapmanager and change the values their too
			for (int i = 0; i < mapManager.mapList.size(); i++)
			{
				if (mapManager.mapList[i].mapID == curMap.mapID) {
					mapManager.mapList[i].map[charRow][charCol] = ' ';
					mapManager.mapList[i].v_chests[locInChestVec].opened = true;
					break;
				}
			}
		}
		else
			OutputSpeech("Could not find Chest associated with these coordinates", "ERROR", SCREEN_WIDTH, BOT_START_ROW);
	}

	//NPC
	if (interactChar == '#' || interactChar == '+' || interactChar == '*' || interactChar == '&' || interactChar == '%') {
		//Find npc
		int locInNPCVec = -1;
		for (int i = 0; i < curMap.v_npcs.size(); i++)
		{
			if (curMap.v_npcs[i].row == charRow && curMap.v_npcs[i].col == charCol)
				locInNPCVec = i;
		}

		//If we found the npc
		if (locInNPCVec != -1) {
			if (interactChar == '*') {

				string name = database.ReturnName(curMap.v_npcs[locInNPCVec].nameID);
				string speech = database.ReturnDialogue(curMap.mapID, curMap.v_npcs[locInNPCVec].nameID, curMap.v_npcs[locInNPCVec].dialogueID);

				OutputSpeech(speech, name, SCREEN_WIDTH, BOT_START_ROW);

				
				if (interactChar == '*') {
					//Do quest stuff
				}
			}
			else if (interactChar == '#') {
				OutputSpeech("This is where the text for npc and quest npc would be.", "NPC & Quest NPC", SCREEN_WIDTH, BOT_START_ROW);
			}
			else if (interactChar == '&') {
				//Call Inn Function and stuff
				OutputSpeech("Welcome to the inn, inn stuff would happen here.", "Inn Keeper", SCREEN_WIDTH, BOT_START_ROW);
			}
			else if (interactChar == '+') {
				//Call Weapon shop function and stuff
				OutputSpeech("Weapon shop function call would be here.", "Weapon Shop", SCREEN_WIDTH, BOT_START_ROW);
			}
			else if (interactChar == '%') {
				//Call Armor shop function and stuff
				OutputSpeech("Armor shop function call would be here.", "Armor Shop", SCREEN_WIDTH, BOT_START_ROW);
			}
		}
		else
			OutputSpeech("Could not find NPC associated with these coordinates.", "ERROR", SCREEN_WIDTH, BOT_START_ROW);
	}

	//Enemy
	if (interactChar == '!') {
		//Find enemy
		int locInEnemyVec = -1;
		bool isDefeated = true;
		for (int i = 0; i < curMap.v_mapEnemies.size(); i++)
		{
			if (curMap.v_mapEnemies[i].row == charRow && curMap.v_mapEnemies[i].col == charCol)
				locInEnemyVec = i;
		}

		//Trigger Battle
		if (locInEnemyVec != -1) {
			if(curMap.v_mapEnemies[locInEnemyVec].isBoss) PlayBossBattleTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT, false);
			else if (curMap.v_mapEnemies[locInEnemyVec].isFinalBoss) PlayBossBattleTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT, true);
			else PlayBattleTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT);

			OutputSpeech("This is where the battle would take place", "The Battle", SCREEN_WIDTH, BOT_START_ROW);
			//Send for battle with specific id's
			SoundManager::Instance().PlayMusic(curMap.mapMusic);
		}
		else {
			PlayBattleTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT);
			OutputSpeech("This is where the battle would take place, but we didn't find the targeted enemy so heres a random one", "The Battle", SCREEN_WIDTH, BOT_START_ROW);
			SoundManager::Instance().PlayMusic(curMap.mapMusic);
		}

		//Update Map based on win/lose
		if (isDefeated) {
			if (locInEnemyVec != -1) {
				curMap.map[charRow][charCol] = ' ';
				curMap.v_mapEnemies[locInEnemyVec].isDefeated = true;

				//Find actual map data in mapmanager and change the values their too
				for (int i = 0; i < mapManager.mapList.size(); i++)
				{
					if (mapManager.mapList[i].mapID == curMap.mapID) {
						mapManager.mapList[i].map[charRow][charCol] = ' ';
						mapManager.mapList[i].v_mapEnemies[locInEnemyVec].isDefeated = true;
						break;
					}
				}
			}
			else { //Couldnt find enemy, 
				curMap.map[charRow][charCol] = ' ';
			}
		}
	}

	//Save Point
	if (interactChar == '$') {
		PlaySound("Sound/save_music.wav", NULL, SND_FILENAME | SND_SYNC);
		//Call save function

		SoundManager::Instance().PlayMusic(curMap.mapMusic);
		OutputSpeech("Call the save function here.", "Save Point", SCREEN_WIDTH, BOT_START_ROW);
	}

	interactChar = ' ';
	interact = false;
}

bool MapMain::CheckCollision(char p_nextChar) {
	bool isColliding = false;
	for (int i = 0; i < v_collisionChars.size(); i++)
	{
		if (p_nextChar == v_collisionChars[i]) {
			isColliding = true;
			break;
		}
	}

	return isColliding;
}

void MapMain::CheckForBattle() {
	const int BATTLE_NUMBER = 1;
	int num = rand() % curEncounterChance + 1;

	//Trigger battle
	if (num == BATTLE_NUMBER) {
		//Reset battle variables
		curEncounterChance = MAX_ENCOUNTER_CHANCE;
		stepCount = 0;


		PlayBattleTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT);
		OutputSpeech("This is where the battle would take place", "The Battle", SCREEN_WIDTH, BOT_START_ROW);
		//Send for battle 
		SoundManager::Instance().PlayMusic(curMap.mapMusic);
	}
	else {
		//Make it more likely to get a encounter next battle check
		if (curEncounterChance > MIN_ENCOUNTER_CHANCE)
			curEncounterChance--;
	}
}



void MapMain::SetMap(int p_pRow, int p_pCol, int p_mapID) {
	PlaySound("Sound/trans_sfx.wav", NULL, SND_FILENAME | SND_ASYNC);
	PlayMapTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT,curMap,rowMove, columnMove, true);
	   	

	//Find map to change to by ID
	for (int i = 0; i < mapManager.mapList.size(); i++)
	{
		if (mapManager.mapList[i].mapID == p_mapID) {
			curMap = mapManager.mapList[i];
		}
	}

	playerR = p_pRow;
	playerC = p_pCol;
	lastChar = curMap.map[playerR][playerC];
	curMap.map[playerR][playerC] = 'P';

	//ORIENT SCREEN
	/*This may be buggy. If screens dont orient right or crash, the error is here. rowMove = 0 is def right though*/
	//Row
	if (playerR - DIST_FROM_MID_R < 0) rowMove = 0;
	else if (curMap.map.size() - playerR < DIST_FROM_MID_R) rowMove = curMap.map.size() - SCREEN_HEIGHT;
	else {
		if (playerR - DIST_FROM_MID_R >= 0 && curMap.map.size() - playerR >= DIST_FROM_MID_R) rowMove = playerR - DIST_FROM_MID_R;
		else if (curMap.map.size() - playerR < DIST_FROM_MID_R) rowMove = curMap.map.size() - SCREEN_HEIGHT;
	}
	//Column
	if (playerC - DIST_FROM_MID_C < 0) columnMove = 0;
	else if (curMap.map[0].size() - playerC < DIST_FROM_MID_C) columnMove = curMap.map[0].size() - SCREEN_WIDTH;
	else {
		if (playerC - DIST_FROM_MID_C >= 0 && curMap.map[0].size() - playerC >= DIST_FROM_MID_C) columnMove = playerC - DIST_FROM_MID_C;
		else if (curMap.map[0].size() - playerC < DIST_FROM_MID_C) columnMove = curMap.map[0].size() - SCREEN_WIDTH;
	}
	PlaySound("Sound/trans_sfx2.wav", NULL, SND_FILENAME | SND_ASYNC);
	PlayMapTransEffect(SCREEN_WIDTH, SCREEN_HEIGHT, curMap, rowMove, columnMove, false);

	SoundManager::Instance().PlayMusic(curMap.mapMusic);
	DrawRight(); //So the map name gets updated
	DrawScreen();

	//Play flavour text if it hasnt been played before
	if (!curMap.playedFlavorTxt) {
		string name = database.ReturnName(curMap.v_npcs[0].nameID);
		string speech = database.ReturnDialogue(curMap.mapID, curMap.v_npcs[0].nameID, curMap.v_npcs[0].dialogueID);

		OutputSpeech(speech, name, SCREEN_WIDTH, BOT_START_ROW);
		curMap.playedFlavorTxt = true;

		for (int i = 0; i < mapManager.mapList.size(); i++)
		{
			if (curMap.mapID == mapManager.mapList[i].mapID) {
				mapManager.mapList[i].playedFlavorTxt = true;
				break;
			}
		}
	}
}



void MapMain::DrawGUI() {
	system("CLS");
	GoToXY(0, 0);
	//Draw screen border
	cout << string(SCREEN_WIDTH + BORDER, '#') << endl;
	for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		cout << "#" << string(SCREEN_WIDTH, ' ') << "#" << endl;
	cout << string(SCREEN_WIDTH + BORDER, '#') << endl;

	//Draw right border
	GoToXY(0, RIGHT_START_COL); cout << string(SIDE_WIDTH, '#') << endl;
	for (size_t i = 0; i < SCREEN_HEIGHT; i++) {
		GoToXY(i + 1, RIGHT_START_COL);
		cout << "#" << string(SIDE_WIDTH - BORDER, ' ') << "#" << endl;
	}
	GoToXY(SCREEN_HEIGHT + 1, RIGHT_START_COL); cout << string(SIDE_WIDTH, '#') << endl;
}

void MapMain::DrawScreen() {
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		GoToXY(i + 1, 1);
		for (int j = 0; j < SCREEN_WIDTH; j++) {
			if (curMap.map[rowMove + i][columnMove + j] == ' ')
				SetColorAndBackground(curMap.spaceColor);
			else
				SetColorAndBackground(GetColorValue(curMap.map[rowMove + i][columnMove + j]));

			cout << ' ';
		}
	}
}

void MapMain::DrawRight() {
	SetColorAndBackground();

	//Map Name
	GoToXY(2, RIGHT_START_COL + 1); cout << CenterPhrase("Location", SIDE_WIDTH - 2);
	GoToXY(3, RIGHT_START_COL + 1); cout << CenterPhrase("------------", SIDE_WIDTH - 2);
	GoToXY(4, RIGHT_START_COL + 1); cout << CenterPhrase(curMap.name, SIDE_WIDTH - 2);
	
	//Legend
	GoToXY(10, RIGHT_START_COL + 1); cout << CenterPhrase("Legend", SIDE_WIDTH - 2);
	GoToXY(11, RIGHT_START_COL + 1); cout << CenterPhrase("------------", SIDE_WIDTH - 2);
	GoToXY(12, RIGHT_START_COL + 1);
		cout << "          ";
		SetColorAndBackground(RED); cout << " ";
		SetColorAndBackground(); cout << " Player";
	GoToXY(13, RIGHT_START_COL + 1);
		cout << "          ";
		SetColorAndBackground(YELLOW); cout << " ";
		SetColorAndBackground(); cout << " Chest";
	GoToXY(14, RIGHT_START_COL + 1);
		cout << "           ";
		SetColorAndBackground(LIGHTMAGENTA); cout << " ";
		SetColorAndBackground(); cout << " NPC";
	GoToXY(15, RIGHT_START_COL + 1);
		cout << "        ";
		SetColorAndBackground(LIGHTCYAN); cout << " ";
		SetColorAndBackground(); cout << " Save Point";
	GoToXY(16, RIGHT_START_COL + 1);
		cout << "          ";
		SetColorAndBackground(LIGHTRED); cout << " ";
		SetColorAndBackground(); cout << " Enemy";
	
	
	//Controls
	GoToXY(22, RIGHT_START_COL + 1); cout << CenterPhrase("Controls", SIDE_WIDTH - 2);
	GoToXY(23, RIGHT_START_COL + 1); cout << CenterPhrase("------------", SIDE_WIDTH - 2);
	GoToXY(24, RIGHT_START_COL + 1); cout << CenterPhrase("ASDW = Move", SIDE_WIDTH - 2);
	GoToXY(25, RIGHT_START_COL + 1); cout << CenterPhrase("Spacebar = Interact", SIDE_WIDTH - 2);
}