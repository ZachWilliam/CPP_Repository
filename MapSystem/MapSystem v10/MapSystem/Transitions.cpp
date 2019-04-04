#include "Transitions.h"

void PlayMapTransEffect(int p_sWidth, int p_sHeight, const Map &p_map, int rowMove, int rowCol, bool p_close) {
	if (p_close) {
		//Play map transition effect function Close
		SetColorAndBackground(LIGHTGRAY);
		for (int i = 0; i <= p_sHeight / 2; i++)
		{
			for (size_t j = 0; j < p_sWidth; j++)
			{
				GoToXY(i + 1, 1 + j); //+1 to account for the border
				cout << ' ';

				GoToXY(p_sHeight - i, 1 + j);
				cout << ' ';
			}
			Sleep(40);
		}
	}
	else {
		//Play map transition effect function open
		int u = p_sHeight / 2;
		for (int i = p_sHeight / 2; i >= 0; i--)
		{
			//int u = 1;
			for (size_t j = 0; j < p_sWidth; j++)
			{
				GoToXY(i + 1, 1 + j); //+1 to account for the border
				if (p_map.map[rowMove + i][rowCol + j] == ' ')
					SetColorAndBackground(p_map.spaceColor);
				else
					SetColorAndBackground(GetColorValue(p_map.map[rowMove + i][rowCol + j]));

				cout << ' ';

				GoToXY(p_sHeight - i, 1 + j);
				if (p_map.map[rowMove + u][rowCol + j] == ' ')
					SetColorAndBackground(p_map.spaceColor);
				else
					SetColorAndBackground(GetColorValue(p_map.map[rowMove + u][rowCol + j]));

				cout << ' ';

			}
			u++;
			Sleep(40);
		}
		Sleep(300);
	}
}

void PlayBattleTransEffect(int p_sWidth, int p_sHeight) {
	PlaySound("Sound/battle_intro.wav", NULL, SND_FILENAME | SND_ASYNC);
	SetColorAndBackground(LIGHTGRAY);
	int k = p_sWidth;
	for (int j = 0; j < p_sWidth; j++)
	{
		for (int i = 0; i < p_sHeight; i++)
		{
			if (i % 2 == 0) {
				GoToXY(i + 1, j + 1);
				cout << " ";
			}
			if (i % 2 == 1) {
				GoToXY(i + 1, k);
				cout << " ";
			}
		}
		k--;
		Sleep(10);
	}
	Sleep(50);
}

void PlayBossBattleTransEffect(int p_sWidth, int p_sHeight, bool p_isFinalBoss) {
	SetColorAndBackground(LIGHTGRAY);
	int leftBorder = 1;
	int topBorder = 1;
	int rightBorder = p_sWidth;
	int bottomBorder = p_sHeight;

	if (p_isFinalBoss) {
		PlaySound("Sound/final_boss_intro.wav", NULL, SND_FILENAME | SND_ASYNC);

		for (int k = 0; k < 13; k++)
		{
			for (int i = leftBorder; i <= rightBorder; i++)
			{
				GoToXY(topBorder, i);
				cout << " ";
				Sleep(1);
			}
			topBorder++;
			for (int i = topBorder; i <= bottomBorder; i++)
			{
				GoToXY(i, rightBorder);
				cout << " ";
				Sleep(1);
			}
			rightBorder--;
			for (int i = rightBorder; i >= leftBorder; i--) {
				GoToXY(bottomBorder, i);
				cout << " ";
				Sleep(1);
			}
			bottomBorder--;
			for (int i = bottomBorder; i >= topBorder; i--) {
				GoToXY(i, leftBorder);
				cout << " ";
				Sleep(1);
			}
			leftBorder++;
		}

		for (int i = leftBorder; i <= rightBorder; i++)
		{
			GoToXY(topBorder, i);
			cout << " ";
			Sleep(1);
		}
	}
	else if (!p_isFinalBoss) {
		PlaySound("Sound/boss_intro.wav", NULL, SND_FILENAME | SND_ASYNC);
		for (int k = 0; k < 7; k++)
		{
			for (int i = leftBorder; i <= rightBorder; i++)
			{
				GoToXY(topBorder, i);
				cout << " ";
				GoToXY(topBorder + 1, i);
				cout << " ";
				Sleep(2);
			}
			topBorder += 2;
			for (int i = topBorder; i <= bottomBorder; i++)
			{
				GoToXY(i, rightBorder);
				cout << " ";
				GoToXY(i, rightBorder - 1);
				cout << " ";
				Sleep(2);
			}
			rightBorder -= 2;
			for (int i = rightBorder; i >= leftBorder; i--) {
				GoToXY(bottomBorder, i);
				cout << " ";
				GoToXY(bottomBorder - 1, i);
				cout << " ";
				Sleep(2);
			}
			bottomBorder -= 2;
			for (int i = bottomBorder; i >= topBorder; i--) {
				GoToXY(i, leftBorder);
				cout << " ";
				GoToXY(i, leftBorder + 1);
				cout << " ";
				Sleep(2);
			}
			leftBorder += 2;
		}
	}
}



