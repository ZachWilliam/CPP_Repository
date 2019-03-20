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





/*void DrawRight(const Hero &p_hero1, const Hero &p_hero2) {
const int INFO_DISTANCE = 10;


GoToXY(3, COL_RIGHT); cout << CenterPhrase("Legend", SIDE_WIDTH);
GoToXY(4, COL_RIGHT); cout << CenterPhrase("------------", SIDE_WIDTH);
GoToXY(5, COL_RIGHT); cout << CenterPhrase("Something", SIDE_WIDTH);
GoToXY(6, COL_RIGHT); cout << CenterPhrase("Another", SIDE_WIDTH);
GoToXY(7, COL_RIGHT); cout << CenterPhrase("Thing", SIDE_WIDTH);

Hero a_heroes[2] = { p_hero1, p_hero2 };

for (size_t i = 0; i < 2; i++)
{
GoToXY(11 + i * INFO_DISTANCE, COL_RIGHT); cout << CenterPhrase(a_heroes[i].name, SIDE_WIDTH) << endl;
GoToXY(12 + i * INFO_DISTANCE, COL_RIGHT); cout << CenterPhrase(string(a_heroes[i].name.size() + 6, '-'), SIDE_WIDTH);
GoToXY(13 + i * INFO_DISTANCE, COL_RIGHT); cout << CenterPhrase("Level: " + to_string(a_heroes[i].level), SIDE_WIDTH) << endl;
GoToXY(14 + i * INFO_DISTANCE, COL_RIGHT); cout << CenterPhrase("Health " + to_string(a_heroes[i].health), SIDE_WIDTH) << endl;
GoToXY(15 + i * INFO_DISTANCE, COL_RIGHT); cout << CenterPhrase("Mana " + to_string(a_heroes[i].mana), SIDE_WIDTH) << endl;
GoToXY(16 + i * INFO_DISTANCE, COL_RIGHT); cout << CenterPhrase("Exp " + to_string(a_heroes[i].exp), SIDE_WIDTH) << endl;
}
}*/