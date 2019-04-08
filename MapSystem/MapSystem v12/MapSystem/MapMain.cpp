#include "MapMain.h"

MapMain::MapMain(Database &p_database, Database &p_beastiary, Party &p_party, PartyInventory &p_inventory) :
	database_text(p_database),
	database_monsters(p_beastiary),
	TheGroup(p_party),
	Inventory(p_inventory)
{}


int MapMain::main() {

	while (GManager.gameState != GManager.GAME_OVER && GManager.gameState != GManager.GAME_WON) {
		DrawScreen();
		Input();
		Logic();
		Sleep(1);
	}

	return 0;
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
		string name = database_text.ReturnName(curMap.v_NPCs[0].nameID);
		string speech = database_text.ReturnDialogue(curMap.mapID, curMap.v_NPCs[0].nameID, curMap.v_NPCs[0].dialogueID);

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
	leftKey = GetAsyncKeyState(VK_LEFT);
	downKey = GetAsyncKeyState(VK_DOWN);
	rightKey = GetAsyncKeyState(VK_RIGHT);
	upKey = GetAsyncKeyState(VK_UP);

	if (leftKey) cDir = LEFT;	if (rightKey) cDir = RIGHT;
	if ((leftKey && rightKey) || (!leftKey && !rightKey)) cDir = NEUTRAL;

	if (upKey) rDir = UP; if (downKey) rDir = RIGHT;
	if ((upKey && downKey) || (!upKey && !downKey)) rDir = NEUTRAL;

	if (_kbhit()) {
		switch (_getch()) {
		case 'z':
			interact = true;
			break;
		case 'p':
			openInventory = true;
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

	//Inventory
	if (openInventory) {
		openInventory = false;
		PauseMenu();
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

void MapMain::PauseMenu() {

	SetColorAndBackground();
	GoToXY(GManager.BOT_START_ROW, 0);

	char again = 'y';
	while (again != 'n')
	{
		ClearBottom();
		int choice;
		cout << "Make a selection:\n\n";
		cout << "1.     Display Inventory\n";
		cout << "2.     Display Equiped Weapons and Armor\n";
		cout << "3.     Swap Weapon\n";
		cout << "4.     Swap Armor\n";
		cout << "5.     Display Beastiary\n";
		cout << "Choice: ";
		cin >> choice;
		if ((choice <= 0) || (choice > 5))
		{
			cout << "Invalid selection. Reselect:\n";
			cin >> choice;
		}
		else
		{
			switch (choice)
			{
			case 1:
				//cout << "Display Inventory\n";
				Inventory.DisplayPartyInventory();
				break;
			case 2:
				TheGroup.Container[1].PlayerInventory.EquipedWeapon();
				TheGroup.Container[1].PlayerInventory.EquipedArmor();
				TheGroup.Container[3].PlayerInventory.EquipedWeapon();
				TheGroup.Container[3].PlayerInventory.EquipedArmor();
				TheGroup.Container[5].PlayerInventory.EquipedWeapon();
				TheGroup.Container[5].PlayerInventory.EquipedArmor();
				break;
			case 3:
				//cout << "Swap Weapon\n";
				//display characters
				Inventory.SwapEquipedWeapon(TheGroup.Container[1].PlayerInventory, TheGroup.Container[3].PlayerInventory, TheGroup.Container[5].PlayerInventory);
				break;
			case 4:
				//cout << "Swap Armor\n";
				//display characters
				Inventory.SwapEquipedArmor(TheGroup.Container[1].PlayerInventory, TheGroup.Container[3].PlayerInventory, TheGroup.Container[5].PlayerInventory);
				break;
			case 5:
				//cout << "Display Beastiary\n";
				//this is where beastiary goes
				database_monsters.DisplayBeastiary();
				break;
			}
		}
		cout << "More? (y/n): ";
		cin >> again;
	};

	ClearBottom();

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
		
		int locInChestVec = curMap.OpenChest(charRow, charCol, database_text, questManager, Inventory);
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

				//Quest is finished, play finish text once
				if (questManager.questList[0].isQuestFinished && questManager.questList[0].isQuestActive) {
					questManager.questList[0].isQuestActive = false;
					curMap.v_questNPCs[locInNPCVec].locInDialogueVec = 3;
				}

				string name = database_text.ReturnName(curMap.v_questNPCs[locInNPCVec].nameID);
				string speech = database_text.ReturnDialogue(curMap.mapID, curMap.v_questNPCs[locInNPCVec].nameID, curMap.v_questNPCs[locInNPCVec].dialogueIDs[curMap.v_questNPCs[locInNPCVec].locInDialogueVec]);

				OutputSpeech(speech, name);

				//Activate quest on speech dialogue 2
				if (curMap.v_questNPCs[locInNPCVec].locInDialogueVec == 1 && !questManager.questList[0].isQuestFinished) {
					//Activate quest
					questManager.questList[0].isQuestActive = true;

					//Update town map to open gate (we can safely assume were on the town map and can use curMap
					curMap.map[18][131] = 'g';
					curMap.map[19][131] = 'g';

					for (size_t i = 0; i < mapManager.mapList.size(); i++)
					{
						if (curMap.mapID == mapManager.mapList[i].mapID) {
							mapManager.mapList[i].map[18][131] = 'g';
							mapManager.mapList[i].map[19][131] = 'g';
							break;
						}
					}
				}
				//Change dialogue to perm stay 2 after its 3
				if (curMap.v_questNPCs[locInNPCVec].locInDialogueVec == 3)
					curMap.v_questNPCs[locInNPCVec].locInDialogueVec = 2;

				//Increment locInDialogueVec if less than 2
				if (curMap.v_questNPCs[locInNPCVec].locInDialogueVec < 2 && !questManager.questList[0].isQuestFinished)
					curMap.v_questNPCs[locInNPCVec].locInDialogueVec++;

			}
			else if (interactChar == '#') {
				string name = database_text.ReturnName(curMap.v_NPCs[locInNPCVec].nameID);
				string speech = database_text.ReturnDialogue(curMap.mapID, curMap.v_NPCs[locInNPCVec].nameID, curMap.v_NPCs[locInNPCVec].dialogueID);

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
		bool isVictorious = true;
		for (int i = 0; i < curMap.v_mapEnemies.size(); i++)
		{
			if (curMap.v_mapEnemies[i].row == charRow && curMap.v_mapEnemies[i].col == charCol)
				locInEnemyVec = i;
		}

		//Trigger Battle
		if (locInEnemyVec != -1) {
			if (curMap.v_mapEnemies[locInEnemyVec].isBoss) {
				PlayBossBattleTransEffect(false);
				PlaySound("Sound/boss_theme.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if (curMap.v_mapEnemies[locInEnemyVec].isFinalBoss) {
				PlayBossBattleTransEffect(true);
				PlaySound("Sound/last_battle.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else {
				PlayBattleTransEffect();
				PlaySound("Sound/battle_theme.wav", NULL, SND_LOOP | SND_ASYNC);
			}

			bool inBattle = true;
			Encounter FirstBattle(4, database_monsters.GetMonster(-1), database_monsters.GetMonster(2), database_monsters.GetMonster(-1), database_monsters.GetMonster(-1), database_monsters.GetMonster(-1), database_monsters.GetMonster(-1));
			// FirstBattle = EncounterManager::GetEncounter(int)
			FirstBattle.GenerateEncounter(TheGroup);
			while (inBattle) {
				DrawCombatScreen();
				FirstBattle.TakeTurn();
				if (!FirstBattle.Battling) {
					inBattle = false;
				}
				//system("cls");
			}
			isVictorious = FirstBattle.Victory;
			//if (!isVictorious) GManager.gameState = GManager.GAME_OVER;
			if (!isVictorious  && curMap.mapID == 5) GManager.gameState = GManager.GAME_WON;
			if (isVictorious && curMap.mapID == 8) GManager.gameState = GManager.GAME_WON;
			FadeToBlack();
			ClearBottom();
			ClearRight();
			DrawRight();
			
		}
		else {
			PlayBattleTransEffect();
			OutputSpeech("This is where the battle would take place, but we didn't find the targeted enemy.", "The Battle");
		}
		SoundManager::Instance().PlayMusic(curMap.mapMusic);
		//Update Map based on win/lose
		if (isVictorious) {
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

	//Interactable Object (can safely assume its just the crank spot for the bridge in town
	if (interactChar == '@') {
		if (questManager.questList[0].isQuestFinished && curMap.map[35][65] != 'b') {
			string tempName = database_text.ReturnName(0);
			string tempText = database_text.ReturnDialogue(6, 0, 4);
			OutputSpeech(tempText, tempName);

			//Update town map to open gate (we can safely assume were on the town map and can use curMap
			curMap.map[35][65] = 'b';
			curMap.map[35][66] = 'b';
			curMap.map[35][67] = 'b';
			curMap.map[35][68] = 'b';

			curMap.map[36][65] = 'b';
			curMap.map[36][66] = 'b';
			curMap.map[36][67] = 'b';
			curMap.map[36][68] = 'b';

			curMap.map[37][65] = 'g';
			curMap.map[37][66] = 'g';
			curMap.map[37][67] = 'g';
			curMap.map[37][68] = 'g';

			for (size_t i = 0; i < mapManager.mapList.size(); i++)
			{
				if (curMap.mapID == mapManager.mapList[i].mapID) {
					mapManager.mapList[i].map[35][65] = 'b';
					mapManager.mapList[i].map[35][66] = 'b';
					mapManager.mapList[i].map[35][67] = 'b';
					mapManager.mapList[i].map[35][68] = 'b';

					mapManager.mapList[i].map[36][65] = 'b';
					mapManager.mapList[i].map[36][66] = 'b';
					mapManager.mapList[i].map[36][67] = 'b';
					mapManager.mapList[i].map[36][68] = 'b';

					mapManager.mapList[i].map[37][65] = 'g';
					mapManager.mapList[i].map[37][66] = 'g';
					mapManager.mapList[i].map[37][67] = 'g';
					mapManager.mapList[i].map[37][68] = 'g';
					break;
				}
			}

		}
		else if (questManager.questList[0].isQuestFinished && curMap.map[35][65] == 'b') {
			OutputSpeech("The bridge is lowered, destiny awaits.", "Narrator");
		}
		else {
			string tempName = database_text.ReturnName(0);
			string tempText = database_text.ReturnDialogue(6, 0, 3);
			OutputSpeech(tempText, tempName);
		}
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
	bool isVictorious = false;
	//Trigger battle
	if (num == BATTLE_NUMBER && stepCount > CHECK_EVERY_STEPS * 2) {
		//Reset battle variables
		curEncounterChance = MAX_ENCOUNTER_CHANCE;
		stepCount = 0;


		PlayBattleTransEffect();
		PlaySound("Sound/battle_theme.wav", NULL, SND_LOOP | SND_ASYNC);
		bool inBattle = true;
		Encounter FirstBattle(1, database_monsters.GetMonster(0), database_monsters.GetMonster(-1), database_monsters.GetMonster(0), database_monsters.GetMonster(-1), database_monsters.GetMonster(-1), database_monsters.GetMonster(-1));
		// FirstBattle = EncounterManager::GetEncounter(int)
		FirstBattle.GenerateEncounter(TheGroup);
		while (inBattle) {
			DrawCombatScreen();
			FirstBattle.TakeTurn();
			if (!FirstBattle.Battling) {
				inBattle = false;
			}
			//system("cls");
		}
		isVictorious = FirstBattle.Victory;
		//if (!isVictorious) GManager.gameState = GManager.GAME_OVER;
		FadeToBlack();
		ClearBottom();
		ClearRight();
		DrawRight();
		
		SoundManager::Instance().PlayMusic(curMap.mapMusic);
	}
	else {
		//Make it more likely to get a encounter next battle check
		if (curEncounterChance > MIN_ENCOUNTER_CHANCE)
			curEncounterChance--;
	}
}



void MapMain::SetMap(int p_pRow, int p_pCol, int p_mapID) {
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
	
	PlayMapTransEffect(curMap, rowMove, columnMove, false);

	SoundManager::Instance().PlayMusic(curMap.mapMusic);
	DrawRight(); //So the map name gets updated
	DrawScreen();

	//Play flavour text if it hasnt been played before
	if (!curMap.playedFlavorTxt) {
		string name = database_text.ReturnName(curMap.v_NPCs[0].nameID);
		string speech = database_text.ReturnDialogue(curMap.mapID, curMap.v_NPCs[0].nameID, curMap.v_NPCs[0].dialogueID);

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
	GoToXY(21, right_start_col + 1); cout << CenterPhrase("Controls", side_width - 2);
	GoToXY(22, right_start_col + 1); cout << CenterPhrase("------------", side_width - 2);
	GoToXY(23, right_start_col + 1); cout << CenterPhrase("Arrow Keys = Move", side_width - 2);
	GoToXY(24, right_start_col + 1); cout << CenterPhrase("Z = Interact", side_width - 2);
	GoToXY(25, right_start_col + 1); cout << CenterPhrase("X = Back", side_width - 2);
}

void MapMain::DrawCombatScreen()
{
	SetColorAndBackground();
	DrawGUI();
	gotoxy(1, 4);
	cout << "  __________________     __________________     __________________";
	gotoxy(1, 5);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 6);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 7);
	cout << "  \\________________/     \\________________/     \\________________/";
	gotoxy(1, 10);
	cout << "  __________________     __________________     __________________";
	gotoxy(1, 11);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 12);
	cout << " |                  |   |                  |   |                  |";
	gotoxy(1, 13);
	cout << "  \\________________/     \\________________/     \\________________/";
	gotoxy(1, 20);

	cout << "-------I-----------------I-----------------I-----------------I-------";
	gotoxy(1, 21);
	cout << "       |                 |                 |                 |       ";
	gotoxy(1, 22);
	cout << "       |                 |                 |                 |       ";
	gotoxy(1, 23);
	cout << "-------I-----------------I-----------------I-----------------I-------";
	gotoxy(1, 24);
	cout << "       |                 |                 |                 |       ";
	gotoxy(1, 25);
	cout << "       |                 |                 |                 |       ";
	gotoxy(1, 26);
	cout << "-------I-----------------I-----------------I-----------------I-------";
}