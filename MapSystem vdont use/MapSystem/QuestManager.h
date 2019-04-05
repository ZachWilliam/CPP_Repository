#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include"Quest.h"

using namespace std;


class QuestManager
{
public:
	static QuestManager& Instance() {
		static QuestManager instance;
		return instance;
	}


	vector<Quest>questList;

	void questSetup();
private:
	QuestManager();
};

