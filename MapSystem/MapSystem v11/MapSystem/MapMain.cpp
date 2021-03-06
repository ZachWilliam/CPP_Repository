#include "MapMain.h"

MapMain::MapMain(Database &p_database):
	database(p_database)
{}


int MapMain::main() {

	while (true) {
		DrawScreen();
		Input();
		Logic();
		Sleep(1);
	}

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

	
	lastChar = curMap.map[playerR][playerC];

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
		for (int i = 0; i < screen_height; i++)
		{
			GoToXY(1 + i, 1);
			cout << string(screen_width, ' ');
		}
		SetColorAndBackground();
	}
	DrawRight();

	//If map is intro screen do trans effect
	if (curMap.mapID == 1) {
		PlaySound("Sound/trans_sfx2.wav", NULL, SND_FILENAME | SND_ASYNC);
		PlayMapTransEffect(curMap, rowMove, columnMove, false);
	}

	SoundManager::Instance().PlayMusic(curMap.mapMusic);

	//Play flavour text if it hasnt been played before
	if (!curMap.playedFlavorTxt) {
		string name = database.ReturnName(curMap.v_NPCs[0].nameID);
		string speech = database.ReturnDialogue(curMap.mapID, curMap.v_NPCs[0].nameID, curMap.v_NPCs[0].dialogueID);

		OutputSpeech(speech, name);
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
	if (playerC - dist_from_mid_c >= 0 && curMap.map[0].size() - playerC >= dist_from_mid_c) columnMove = playerC - dist_from_mid_c;
	else if (curMap.map[0].size() - playerC < dist_from_mid_c) columnMove = curMap.map[0].size() - screen_width;

	if (playerR - dist_from_mid_r >= 0 && curMap.map.size() - playerR >= dist_from_mid_r) rowMove = playerR - dist_from_mid_r;
	else if (curMap.map.size() - playerR < dist_from_mid_r) rowMove = curMap.map.size() - screen_height;
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
		
		int locInChestVec = curMap.OpenChest(charRow, charCol, database);
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
			OutputSpeech("Could not find Chest associated with these coordinates", "ERROR");
	}

	//NPC
	if (interactChar == '#' || interactChar == '+' || interactChar == '*' || interactChar == '&' || interactChar == '%') {
		//Find npc
		int locInNPCVec = -1;
		if (interactChar != '*') {
			for (int i = 0; i < curMap.v_NPCs.size(); i++)
			{
				if (curMap.v_NPCs[i].row == charRow && curMap.v_NPCs[i].col == charCol)
					locInNPCVec = i;
			}
		}
		else {
			for (int i = 0; i < curMap.v_questNPCs.size(); i++)
			{
				if (curMap.v_questNPCs[i].row == charRow && curMap.v_questNPCs[i].col == charCol)
					locInNPCVec = i;
			}
		}

		//If we found the npc
		if (locInNPCVec != -1) {
			if (interactChar == '*') {

				if (QuestManager::Instance().questList[0].isQuestFinished) {
					curMap.v_questNPCs[locInNPCVec].locInDialogueVec = 2;
				}

				string name = database.ReturnName(curMap.v_questNPCs[locInNPCVec].nameID);
				string speech = database.ReturnDialogue(curMap.mapID, curMap.v_questNPCs[locInNPCVec].nameID, curMap.v_questNPCs[locInNPCVec].dialogueIDs[curMap.v_questNPCs[locInNPCVec].locInDialogueVec]);

				OutputSpeech(speech, name);

				if (curMap.v_questNPCs[locInNPCVec].locInDialogueVec == 1) {
					if(QuestManager::Instance().questList[0].isQuestFinished != true)
						QuestManager::Instance().questList[0].isQuestActive = true;
				}

				if (curMap.v_questNPCs[locInNPCVec].locInDialogueVec == 0) {
					curMap.v_questNPCs[locInNPCVec].locInDialogueVec = 1;
				}

				


			}
			else if (interactChar == '#') {
				string name = database.ReturnName(curMap.v_NPCs[locInNPCVec].nameID);
				string speech = database.ReturnDialogue(curMap.mapID, curMap.v_NPCs[locInNPCVec].nameID, curMap.v_NPCs[locInNPCVec].dialogueID);

				OutputSpeech(speech, name);
			}
			else if (interactChar == '&') {
				//Call Inn Function and stuff
				OutputSpeech("Welcome to the inn, inn stuff would happen here.", "Inn Keeper");
			}
			else if (interactChar == '+') {
				//Call Weapon shop function and stuff
				OutputSpeech("Weapon shop function call would be here.", "Weapon Shop");
			}
			else if (interactChar == '%') {
				//Call Armor shop function and stuff
				OutputSpeech("Armor shop function call would be here.", "Armor Shop");
			}
		}
		else
			OutputSpeech("Could not find NPC associated with these coordinates.", "ERROR");
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
			if(curMap.v_mapEnemies[locInEnemyVec].isBoss) PlayBossBattleTransEffect(false);
			else if (curMap.v_mapEnemies[locInEnemyVec].isFinalBoss) PlayBossBattleTransEffect(true);
			else PlayBattleTransEffect();

			OutputSpeech("This is where the battle would take place", "The Battle");
			//Send for battle with specific id's
			SoundManager::Instance().PlayMusic(curMap.mapMusic);
		}
		else {
			PlayBattleTransEffect();
			OutputSpeech("This is where the battle would take place, but we didn't find the targeted enemy so heres a random one", "The Battle");
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
		OutputSpeech("Call the save function here.", "Save Point");
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


		PlayBattleTransEffect();
		OutputSpeech("This is where the battle would take place", "The Battle");
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
	PlayMapTransEffect(curMap,rowMove, columnMove, true);
	   	

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
	if (playerR - dist_from_mid_r < 0) rowMove = 0;
	else if (curMap.map.size() - playerR < dist_from_mid_r) rowMove = curMap.map.size() - screen_height;
	else {
		if (playerR - dist_from_mid_r >= 0 && curMap.map.size() - playerR >= dist_from_mid_r) rowMove = playerR - dist_from_mid_r;
		else if (curMap.map.size() - playerR < dist_from_mid_r) rowMove = curMap.map.size() - screen_height;
	}
	//Column
	if (playerC - dist_from_mid_c < 0) columnMove = 0;
	else if (curMap.map[0].size() - playerC < dist_from_mid_c) columnMove = curMap.map[0].size() - screen_width;
	else {
		if (playerC - dist_from_mid_c >= 0 && curMap.map[0].size() - playerC >= dist_from_mid_c) columnMove = playerC - dist_from_mid_c;
		else if (curMap.map[0].size() - playerC < dist_from_mid_c) columnMove = curMap.map[0].size() - screen_width;
	}
	PlaySound("Sound/trans_sfx2.wav", NULL, SND_FILENAME | SND_ASYNC);
	PlayMapTransEffect(curMap, rowMove, columnMove, false);

	SoundManager::Instance().PlayMusic(curMap.mapMusic);
	DrawRight(); //So the map name gets updated
	DrawScreen();

	//Play flavour text if it hasnt been played before
	if (!curMap.playedFlavorTxt) {
		string name = database.ReturnName(curMap.v_NPCs[0].nameID);
		string speech = database.ReturnDialogue(curMap.mapID, curMap.v_NPCs[0].nameID, curMap.v_NPCs[0].dialogueID);

		OutputSpeech(speech, name);
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
	cout << string(screen_width + border, '#') << endl;
	for (size_t i = 0; i < screen_height; i++)
		cout << "#" << string(screen_width, ' ') << "#" << endl;
	cout << string(screen_width + border, '#') << endl;

	//Draw right border
	GoToXY(0, right_start_col); cout << string(side_width, '#') << endl;
	for (size_t i = 0; i < screen_height; i++) {
		GoToXY(i + 1, right_start_col);
		cout << "#" << string(side_width - border, ' ') << "#" << endl;
	}
	GoToXY(screen_height + 1, right_start_col); cout << string(side_width, '#') << endl;
}

void MapMain::DrawScreen() {
	for (int i = 0; i < screen_height; i++)
	{
		GoToXY(i + 1, 1);
		for (int j = 0; j < screen_width; j++) {
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
	GoToXY(2, right_start_col + 1); cout << CenterPhrase("Location", side_width - 2);
	GoToXY(3, right_start_col + 1); cout << CenterPhrase("------------", side_width - 2);
	GoToXY(4, right_start_col + 1); cout << CenterPhrase(curMap.name, side_width - 2);
	
	//Legend
	GoToXY(10, right_start_col + 1); cout << CenterPhrase("Legend", side_width - 2);
	GoToXY(11, right_start_col + 1); cout << CenterPhrase("------------", side_width - 2);
	GoToXY(12, right_start_col + 1);
		cout << "          ";
		SetColorAndBackground(RED); cout << " ";
		SetColorAndBackground(); cout << " Player";
	GoToXY(13, right_start_col + 1);
		cout << "          ";
		SetColorAndBackground(YELLOW); cout << " ";
		SetColorAndBackground(); cout << " Chest";
	GoToXY(14, right_start_col + 1);
		cout << "           ";
		SetColorAndBackground(LIGHTMAGENTA); cout << " ";
		SetColorAndBackground(); cout << " NPC";
	GoToXY(15, right_start_col + 1);
		cout << "        ";
		SetColorAndBackground(LIGHTCYAN); cout << " ";
		SetColorAndBackground(); cout << " Save Point";
	GoToXY(16, right_start_col + 1);
		cout << "          ";
		SetColorAndBackground(LIGHTRED); cout << " ";
		SetColorAndBackground(); cout << " Enemy";
	
	
	//Controls
	GoToXY(22, right_start_col + 1); cout << CenterPhrase("Controls", side_width - 2);
	GoToXY(23, right_start_col + 1); cout << CenterPhrase("------------", side_width - 2);
	GoToXY(24, right_start_col + 1); cout << CenterPhrase("ASDW = Move", side_width - 2);
	GoToXY(25, right_start_col + 1); cout << CenterPhrase("Spacebar = Interact", side_width - 2);
}