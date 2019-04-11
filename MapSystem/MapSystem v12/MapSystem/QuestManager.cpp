#include "QuestManager.h"
#include "DeserializeHelper.h"


QuestManager::QuestManager()
{
	questSetup();
}

void QuestManager::questSetup()
{
	Quest questOne("QuestOne", false, false, 0, 1);
	questList.push_back(questOne);
	
}

QuestManager::QuestManager(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			questList.push_back(Quest(helper.ParsedClassSString()));
			break;
		}
	}
}

string QuestManager::Serialized()
{
	string serialString = "";

	serialString += "questList[";
	if (questList.size() > 0)
	{
		for (size_t i = 0; i < questList.size(); ++i)
		{
			serialString += "{";
			serialString += questList[i].Serialized();
			serialString += "},";
		}
	}
	serialString += "],";

	return serialString;
}