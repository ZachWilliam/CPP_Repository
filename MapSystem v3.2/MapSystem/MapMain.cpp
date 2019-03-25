#include "MapMain.h"

MapMain::MapMain()
{}


int MapMain::main() {
	SetColorAndBackground();
	curMap.map[playerR][playerC] = 'P'; curMap.map[playerR][playerC] = 'P';

	//Setup();
	DrawGUI();
	DrawRight();

	while (true) {
		Draw();
		Input();
		Logic();
		Sleep(1);
	}

	_getch();
}


void MapMain::Draw() {
	DrawScreen();
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
}

void MapMain::Logic() {
	//Check to see if the player has moved onto a transition point
	if (lastChar == '?') {//lastChar would be the spot the player just moved too, aka why we check to see if its a ?
		int posInCoordVec = -1;
		for (int i = 0; i < curMap.transitionPoints.size(); i++)
		{
			if (playerR == curMap.transitionPoints[i].thisMapR && playerC == curMap.transitionPoints[i].thisMapC) {
				posInCoordVec = i;
				break;
			}
		}
		
		//If we found the coords
		if (posInCoordVec != -1) {
			Coord nextCoord = curMap.transitionPoints[posInCoordVec];
			SetMap(nextCoord.nextMapR, nextCoord.nextMapC, nextCoord.nextMapID);
		}
		else//Couldnt find the coords, send to default of the map
		{
			SetMap(curMap.defaultPR, curMap.defaultPC, curMap.mapID);
		}
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

	
	//Update Screen vector
	if (playerC - DIST_FROM_MID_C >= 0 && curMap.map[0].size() - playerC >= DIST_FROM_MID_C) columnMove = playerC - DIST_FROM_MID_C;
	else if (curMap.map[0].size() - playerC < DIST_FROM_MID_C) columnMove = curMap.map[0].size() - screen[0].size();

	if (playerR - DIST_FROM_MID_R >= 0 && curMap.map.size() - playerR >= DIST_FROM_MID_R) rowMove = playerR - DIST_FROM_MID_R;
	else if (curMap.map.size() - playerR < DIST_FROM_MID_R) rowMove = curMap.map.size() - screen.size();
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


void MapMain::SetMap(int p_pRow, int p_pCol, int p_mapID) {
	PlayMapTransEffect(true);

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
		else if (curMap.map.size() - playerR < DIST_FROM_MID_R) rowMove = curMap.map.size() - screen.size();
	}
	//Column
	if (playerC - DIST_FROM_MID_C < 0) columnMove = 0;
	else if (curMap.map[0].size() - playerC < DIST_FROM_MID_C) columnMove = curMap.map[0].size() - SCREEN_WIDTH;
	else {
		if (playerC - DIST_FROM_MID_C >= 0 && curMap.map[0].size() - playerC >= DIST_FROM_MID_C) columnMove = playerC - DIST_FROM_MID_C;
		else if (curMap.map[0].size() - playerC < DIST_FROM_MID_C) columnMove = curMap.map[0].size() - screen[0].size();
	}

	PlayMapTransEffect(false);

	DrawScreen();
}


void MapMain::PlayMapTransEffect(bool p_close) {
	if (p_close) {
		//Play map transition effect function Close
		SetColorAndBackground(DARKGRAY);
		for (int i = 0; i <= SCREEN_HEIGHT / 2; i++)
		{
			for (size_t j = 0; j < SCREEN_WIDTH; j++)
			{
				GoToXY(i + 1, 1 + j); //+1 to account for the border
				cout << ' ';

				GoToXY(SCREEN_HEIGHT - i, 1 + j);
				cout << ' ';
			}
			Sleep(40);
		}
	}
	else {
		//Play map transition effect function open
		int u = SCREEN_HEIGHT / 2;
		for (int i = SCREEN_HEIGHT / 2; i >= 0; i--)
		{
			//int u = 1;
			for (size_t j = 0; j < SCREEN_WIDTH; j++)
			{
				GoToXY(i + 1, 1 + j); //+1 to account for the border
				SetColorAndBackground(GetColorValue(curMap.map[rowMove + i][columnMove + j]));
				cout << ' ';

				GoToXY(SCREEN_HEIGHT - i, 1 + j);
				SetColorAndBackground(GetColorValue(curMap.map[rowMove + u][columnMove + j]));
				cout << ' ';

			}
			u++;
			Sleep(40);
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
			SetColorAndBackground(GetColorValue(curMap.map[rowMove + i][columnMove + j]));
			cout << ' ';
		}
	}
}

void MapMain::DrawRight() {
	GoToXY(3, RIGHT_START_COL + 1); cout << CenterPhrase("Legend", SIDE_WIDTH - 2);
	GoToXY(4, RIGHT_START_COL + 1); cout << CenterPhrase("------------", SIDE_WIDTH - 2);
	GoToXY(5, RIGHT_START_COL + 1); cout << CenterPhrase("Something", SIDE_WIDTH - 2);
	GoToXY(6, RIGHT_START_COL + 1); cout << CenterPhrase("Another", SIDE_WIDTH - 2);
	GoToXY(7, RIGHT_START_COL + 1); cout << CenterPhrase("Thing", SIDE_WIDTH - 2);
}