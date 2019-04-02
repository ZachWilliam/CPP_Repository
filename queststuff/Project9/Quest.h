#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>

using namespace std;


class Quest
{
public:
	
	Quest(string p_name, bool p_isActive, bool p_isFinished, int p_mapID, int p_questID);
	string questName;
	bool isQuestActive;
	bool isQuestFinished;
	int mapID;
	int questID;
	
};

