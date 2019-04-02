#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<windows.h>
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work

using namespace std;

void Setup()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 930, 790, TRUE);
}




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
Quest::Quest(string p_name, bool p_isActive, bool p_isFinished, int p_mapID, int p_questID)
{
	questName = p_name;
	isQuestActive = p_isActive;
	isQuestFinished = p_isFinished;
	mapID = p_mapID;
	questID = p_questID;


}


class QuestManager 
{
public:
	vector<Quest>questList;
	void questSetup();
	
};

QuestManager::QuestManager()
{
	questSetup();
}

void QuestManager::questSetup()
{
	Quest questOne("QuestOne", false, false, 0, 1);
	questList.push_back(questOne);
}




int main()
{
	Setup();
	
}