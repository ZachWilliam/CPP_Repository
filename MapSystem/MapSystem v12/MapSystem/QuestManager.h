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
	QuestManager();
	/*static QuestManager& Instance() {
		static QuestManager instance;
		return instance;
	}*/
	QuestManager(string serialString);

	string Serialized();

	vector<Quest>questList;

	void questSetup();
};

