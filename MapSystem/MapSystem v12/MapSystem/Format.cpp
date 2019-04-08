#include "Format.h"

void GoToXY(int line, int column)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

string CenterPhrase(string p_phrase, const int p_maxSize) {
	if (p_phrase.size() > p_maxSize) return p_phrase.erase(p_maxSize);

	int blankSpaces = p_maxSize - p_phrase.size();
	string newPhrase = "";
	newPhrase += string(blankSpaces / 2, ' ');
	newPhrase += p_phrase;
	newPhrase += string(blankSpaces / 2 + blankSpaces % 2, ' '); //extra space goes on the right

	return newPhrase;
}

void OutputSpeech(vector <string> p_vSpeech, const string &p_npcName) {
	string newSpeech = "";
	for (size_t i = 0; i < p_vSpeech.size(); i++)
	{
		newSpeech += " " + p_vSpeech[i];
	}

	OutputSpeech(newSpeech, p_npcName);
}

void OutputSpeech(string p_speech, const string &p_npcName) {
	SetColorAndBackground();
	const int SPEECH_WIDTH = GameManager::instance().SCREEN_WIDTH - 2;
	const int LINES_PER_PANE = 4;
	const int START_POINT = 0;
	int endPoint = SPEECH_WIDTH;
	vector<string> v_speech;

	//Put speech in vector to output
	while (true)
	{
		if (p_speech.size() > SPEECH_WIDTH) endPoint = SPEECH_WIDTH;
		else endPoint = p_speech.size();


		string tempString = p_speech.substr(START_POINT, endPoint); //For finding /n
		int slashNPos = tempString.find("\n");
		if (slashNPos != string::npos) {
			v_speech.push_back(p_speech.substr(START_POINT, slashNPos));
			p_speech.erase(START_POINT, slashNPos + 1);
		}
		else if (endPoint >= SPEECH_WIDTH) {
			int posToBreak = 0;
			for (size_t i = endPoint; i > START_POINT; i--)
			{
				if (p_speech[i] == ' ') {
					posToBreak = i;
					break;
				}
			}
			v_speech.push_back(p_speech.substr(START_POINT, posToBreak));
			p_speech.erase(START_POINT, posToBreak + 1);//+1 gets rid of the space
		}
		else {
			v_speech.push_back(p_speech);
			break;
		}
	}

	//output speech
	int amtOfChatPanes;
	if (v_speech.size() == LINES_PER_PANE) amtOfChatPanes = 1;
	else amtOfChatPanes = v_speech.size() / LINES_PER_PANE + 1;
	int vecSizeLeft = v_speech.size();
	for (size_t i = 0; i < amtOfChatPanes; i++)
	{
		ClearBottom();
		GoToXY(GameManager::instance().BOT_START_ROW, 0);

		int iter;
		if (vecSizeLeft > LINES_PER_PANE) iter = LINES_PER_PANE;
		else iter = vecSizeLeft;

		cout << "\n\n" << CenterPhrase(p_npcName, GameManager::instance().SCREEN_WIDTH + 2) << "\n\n";
		for (size_t j = 0; j < iter; j++)
		{
			cout << CenterPhrase(v_speech[j + (i * LINES_PER_PANE)], GameManager::instance().SCREEN_WIDTH + 2) << endl;
			vecSizeLeft--;
		}

		cout << "\n" << CenterPhrase("Press 'Z' to continue...", GameManager::instance().SCREEN_WIDTH + 2);
		while (_getch() != 'z');
	}

	ClearBottom();
}

void ClearBottom() {
	const int LINES_TO_CLEAR = 17;

	string line(GameManager::instance().SCREEN_WIDTH + 2, ' ');
	
	for (size_t i = 0; i < LINES_TO_CLEAR; i++)
	{
		GoToXY(GameManager::instance().BOT_START_ROW + i, 0);
		cout << line;
	}

	GoToXY(GManager.BOT_START_ROW, 0);
}

void ClearRight() {
	string line (GManager.SIDE_WIDTH, ' ');

	for (int i = 0; i < GManager.SCREEN_HEIGHT; i++)
	{
		GoToXY(i + 1, GManager.RIGHT_START_COL);
		cout << line;
	}
}

void SetColorAndBackground(int backC, int textC) {
	//Make sure color choice isnt above 15
	if (backC > 15 || textC > 15 || backC < 0 || textC < 0) {
		cout << "Invalid choice(s)" << endl;
		return;
	}

	//Convert backC to binary and back (as a byte) so 15 = 11110000, not 00001111
	int remainder = 0, newBackC = 0, multiplier = 1;
	while (backC > 0)
	{
		remainder = backC % 2;
		if (remainder % 2 != 0) newBackC += 16 * multiplier;
		multiplier *= 2;
		backC /= 2;
	}

	//Change colors
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newBackC + textC);
}

int GetColorValue(char displayChar) {
	if (displayChar == 'W' || displayChar == 'w') return BLUE;
	else if (displayChar == 'l' || displayChar == 'L') return LIGHTBLUE;
	else if (displayChar == 'B' || displayChar == 'b') return BROWN;
	else if (displayChar == 'T' || displayChar == 't') return GREEN;
	else if (displayChar == 'd' || displayChar == 'D' || displayChar == '?') return BLACK;
	else if (displayChar == 'g' || displayChar == 'G') return LIGHTGRAY;
	else if (displayChar == 'r' || displayChar == 'R') return DARKGRAY;
	else if (displayChar == 'P') return RED;
	else if (displayChar == '=') return YELLOW;
	else if (displayChar == '#' || displayChar == '&' || displayChar == '+' || displayChar == '*' || displayChar == '%') return LIGHTMAGENTA;
	else if (displayChar == '$') return LIGHTCYAN;
	else if (displayChar == '!') return LIGHTRED;
	else if (displayChar == '@') return WHITE;
	else return BLACK;
}

void DrawGUI() {
	system("CLS");
	GoToXY(0, 0);
	//Draw screen border
	cout << string(GManager.SCREEN_WIDTH + GManager.BORDER, '#') << endl;
	for (size_t i = 0; i < GManager.SCREEN_HEIGHT; i++)
		cout << "#" << string(GManager.SCREEN_WIDTH, ' ') << "#" << endl;
	cout << string(GManager.SCREEN_WIDTH + GManager.BORDER, '#') << endl;

	//Draw right border
	GoToXY(0, GManager.RIGHT_START_COL); cout << string(GManager.SIDE_WIDTH, '#') << endl;
	for (size_t i = 0; i < GManager.SCREEN_HEIGHT; i++) {
		GoToXY(i + 1, GManager.RIGHT_START_COL);
		cout << "#" << string(GManager.SIDE_WIDTH - GManager.BORDER, ' ') << "#" << endl;
	}
	GoToXY(GManager.SCREEN_HEIGHT + 1, GManager.RIGHT_START_COL); cout << string(GManager.SIDE_WIDTH, '#') << endl;
	gotoxy(0, 30);
}

void FadeToBlack() {
	for (int i = 0; i < 3; i++)
	{
		if (i == 0) SetColorAndBackground(LIGHTGRAY);
		else if (i == 1) SetColorAndBackground(DARKGRAY);
		else if (i == 2) SetColorAndBackground(BLACK);

		for (int j = 0; j < GManager.SCREEN_HEIGHT; j++)
		{
			GoToXY(j + 1, 1);
			cout << string(GManager.SCREEN_WIDTH, ' ');
		}
		Sleep(300);
	}
}


