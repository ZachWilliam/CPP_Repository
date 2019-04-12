#include "QuestManager.h"



QuestManager::QuestManager()
{
	questSetup();
}

void QuestManager::questSetup()
{
	Quest questOne("QuestOne", false, false, 0, 1);
	questList.push_back(questOne);
	
}