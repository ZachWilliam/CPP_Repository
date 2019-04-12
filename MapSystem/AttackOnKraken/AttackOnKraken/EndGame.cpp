#include "EndGame.h"



EndGame::EndGame(Database p_textDatabase):
	textDatabase(p_textDatabase)
{
	endingText = textDatabase.ReturnDialogue(9, 0, 1);
	if (GManager.gameState == GManager.GAME_OVER) GameOver();
	else if (GManager.gameState == GManager.GAME_WON) PlayEnding();
	else GameOver();
}

void EndGame::AnimateBigText(vector<string>p_vtext) {
	//Find dead space
	int topSpace = (GManager.SCREEN_HEIGHT + 1 - p_vtext.size()) / 2;
	int leftSpace = (GManager.SCREEN_WIDTH + 1 - p_vtext[0].size()) / 2;

	SetColorAndBackground(BLACK, DARKGRAY);
	for (int i = 0; i < p_vtext.size(); i++)
	{
		GoToXY(topSpace + i, leftSpace);
		cout << p_vtext[i];
		Sleep(30);
	}
	SetColorAndBackground(BLACK, LIGHTGRAY);
	for (int i = 0; i < p_vtext.size(); i++)
	{
		GoToXY(topSpace + i, leftSpace);
		cout << p_vtext[i];
		Sleep(30);
	}
	SetColorAndBackground(BLACK, WHITE);
	for (int i = 0; i < p_vtext.size(); i++)
	{
		GoToXY(topSpace + i, leftSpace);
		cout << p_vtext[i];
		Sleep(30);
	}
}

void EndGame::GameOver() {
	PlaySound("Sound/dead_theme.wav", NULL, SND_FILENAME | SND_ASYNC);
	SetColorAndBackground();
	DrawGUI();
	DrawRight();

	AnimateBigText(gameOver);

	OutputSpeech("Thanks for Trying!!!", "The Dev's");
}

void EndGame::PlayEnding() {
	PlaySound("Sound/ending_theme.wav", NULL, SND_LOOP | SND_ASYNC);
	SetColorAndBackground();
	DrawGUI();
	DrawRight();

	OutputSpeech(endingText, "Narrator");

	AnimateBigText(theEnd);

	OutputSpeech("Thanks for Playing!!!", "The Dev's");
}

void EndGame::DrawRight() {
	SetColorAndBackground();

	//Map Name
	GoToXY(2, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("Location", GManager.SIDE_WIDTH - 2);
	GoToXY(3, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("------------", GManager.SIDE_WIDTH - 2);
	GoToXY(4, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("The End", GManager.SIDE_WIDTH - 2);

	//Legend
	GoToXY(10, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("Legend", GManager.SIDE_WIDTH - 2);
	GoToXY(11, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("------------", GManager.SIDE_WIDTH - 2);
	GoToXY(12, GManager.RIGHT_START_COL + 1);
	cout << "          ";
	SetColorAndBackground(RED); cout << " ";
	SetColorAndBackground(); cout << " Player";
	GoToXY(13, GManager.RIGHT_START_COL + 1);
	cout << "          ";
	SetColorAndBackground(YELLOW); cout << " ";
	SetColorAndBackground(); cout << " Chest";
	GoToXY(14, GManager.RIGHT_START_COL + 1);
	cout << "           ";
	SetColorAndBackground(LIGHTMAGENTA); cout << " ";
	SetColorAndBackground(); cout << " NPC";
	GoToXY(15, GManager.RIGHT_START_COL + 1);
	cout << "        ";
	SetColorAndBackground(LIGHTCYAN); cout << " ";
	SetColorAndBackground(); cout << " Save Point";
	GoToXY(16, GManager.RIGHT_START_COL + 1);
	cout << "          ";
	SetColorAndBackground(LIGHTRED); cout << " ";
	SetColorAndBackground(); cout << " Enemy";


	//Controls
	GoToXY(21, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("Controls", GManager.SIDE_WIDTH - 2);
	GoToXY(22, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("------------", GManager.SIDE_WIDTH - 2);
	GoToXY(23, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("Arrow Keys = Move", GManager.SIDE_WIDTH - 2);
	GoToXY(24, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("Z = Interact", GManager.SIDE_WIDTH - 2);
	GoToXY(25, GManager.RIGHT_START_COL + 1); cout << CenterPhrase("X = Back", GManager.SIDE_WIDTH - 2);
}


