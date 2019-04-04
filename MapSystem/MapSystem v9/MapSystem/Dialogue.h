#pragma once
#include <string>

using namespace std;
class Dialogue
{
public:
	Dialogue(int mapID, int speakerID, int textID, string text, string speaker);
	const int m_MapID;
	const int m_SpeakerID;
	const int m_TextID;
	const string m_Text;
	const string m_Speaker;
};

