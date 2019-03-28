#pragma once
#include <string>

using namespace std;
class Dialogue
{
public:
	Dialogue(int ID, string text, string speaker);
	const int m_ID;
	const string m_Text;
	const string m_Speaker;
};

