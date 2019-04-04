#include "Dialogue.h"


Dialogue::Dialogue(int mapID, int speakerID, int textID, string text, string speaker) :
	m_MapID(mapID), m_SpeakerID(speakerID), m_Text(text), m_TextID(textID), m_Speaker(speaker) {}
