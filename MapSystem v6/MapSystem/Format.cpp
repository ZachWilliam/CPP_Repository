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

string CenterPhrase(string p_phrase, const int p_maxSize) {
	if (p_phrase.size() > p_maxSize) return p_phrase.erase(p_maxSize);

	int blankSpaces = p_maxSize - p_phrase.size();
	string newPhrase = "";
	newPhrase += string(blankSpaces / 2, ' ');
	newPhrase += p_phrase;
	newPhrase += string(blankSpaces / 2 + blankSpaces % 2, ' '); //extra space goes on the right

	return newPhrase;
}

void OutputSpeech(vector <string> p_vSpeech, const string &p_npcName, const int p_screenWidth, const int p_drawRow) {
	string newSpeech = "";
	for (size_t i = 0; i < p_vSpeech.size(); i++)
	{
		newSpeech += " " + p_vSpeech[i];
	}

	OutputSpeech(newSpeech, p_npcName, p_screenWidth, p_drawRow);
}

void OutputSpeech(string p_speech, const string &p_npcName, const int p_screenWidth, const int p_bottomStartRow) {
	SetColorAndBackground();
	const int SPEECH_WIDTH = p_screenWidth - 2;
	const int LINES_PER_PANE = 5;
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
		ClearBottom(p_bottomStartRow, p_screenWidth);
		GoToXY(p_bottomStartRow, 0);

		int iter;
		if (vecSizeLeft > LINES_PER_PANE) iter = LINES_PER_PANE;
		else iter = vecSizeLeft;

		cout << "\n\n" << CenterPhrase(p_npcName, p_screenWidth + 2) << "\n\n";
		for (size_t j = 0; j < iter; j++)
		{
			cout << CenterPhrase(v_speech[j + (i * LINES_PER_PANE)], p_screenWidth + 2) << endl;
			vecSizeLeft--;
		}

		cout << "\n" << CenterPhrase("Press any key to continue...", p_screenWidth + 2);
		_getch();
	}

	ClearBottom(p_bottomStartRow, p_screenWidth);
}

void ClearBottom(int p_bottomStartRow, int p_screenWidth) {
	const int LINES_TO_CLEAR = 14;

	GoToXY(p_bottomStartRow, 0);

	string line(p_screenWidth + 2, ' ');

	for (size_t i = 0; i < LINES_TO_CLEAR; i++)
	{
		cout << line << endl;
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
	else if (displayChar == '#') return LIGHTMAGENTA;
	else return BLACK;
}