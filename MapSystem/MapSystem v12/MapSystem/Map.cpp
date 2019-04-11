#include "Map.h"
#include "ConvertHelper.h"
#include "DeserializeHelper.h"


Map::Map(const string &p_name, const vector<vector<char> > &p_map, int p_mapID, bool p_canBattle, vector<Coord> p_transPoints, vector<NPC> p_npcs, vector<Chest> p_chests,
	vector<MapEnemy> p_mapEnemies, vector<QuestNPC> p_questNPCs, int p_defPR, int p_defPC, int p_spaceColor, string p_mapMusic) :
	name(p_name),
	map(p_map),
	mapID(p_mapID),
	canBattle(p_canBattle),
	v_transitionPoints(p_transPoints),
	v_NPCs(p_npcs),
	v_chests(p_chests),
	v_mapEnemies(p_mapEnemies),
	v_questNPCs(p_questNPCs),
	defaultPR(p_defPR),
	defaultPC(p_defPC),
	spaceColor(p_spaceColor),
	mapMusic(p_mapMusic)
{
	playedFlavorTxt = false;
}


int Map::OpenChest(int p_row, int p_col, Database &p_database, QuestManager& p_qManager, PartyInventory& p_inventory) {
	//Find chest
	int locInChestVec = -1;
	for (int i = 0; i < v_chests.size(); i++)
	{
		if (v_chests[i].row == p_row && v_chests[i].col == p_col)
			locInChestVec = i;
	}

	//If we found the chest
	if (locInChestVec != -1) {
		//Make sure chest isnt opened
		if (!v_chests[locInChestVec].opened) {
			string tempText = "If this displays something went wrong";
			if (v_chests[locInChestVec].itemType == 1) {
				tempText = p_inventory.AddWeapon(v_chests[locInChestVec].id1, v_chests[locInChestVec].id2, v_chests[locInChestVec].id3);
			}
			else if (v_chests[locInChestVec].itemType == 2) {
				tempText = p_inventory.AddArmor(v_chests[locInChestVec].id1, v_chests[locInChestVec].id2, v_chests[locInChestVec].id3);
			}
			else if (v_chests[locInChestVec].itemType == 3) {//Quest item
				p_qManager.questList[0].isQuestFinished = true;
				PlaySound("Sound/chest_fanfare.wav", NULL, SND_LOOP | SND_SYNC);
				SoundManager::Instance().PlayMusic(mapMusic);
				tempText = p_database.ReturnDialogue(7, 0, 2);
			}
			OutputSpeech(tempText, "Chest");
		}
	}

	return locInChestVec;
}


Map::Map(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			//map		/*vector<vector<char>>*/ //TODO - find a work-around
			break;
		case 1:
			mapID = stoi(helper.ParsedValue());
			break;
		case 2:
			name = helper.ParsedValue();
			break;
		case 3:
			canBattle = stob(helper.ParsedValue());
			break;
		case 4:
			v_transitionPoints.push_back(Coord(helper.ParsedClassSString()));
			break;
		case 5:
			v_NPCs.push_back(NPC(helper.ParsedClassSString()));
			break;
		case 6:
			v_chests.push_back(Chest(helper.ParsedClassSString()));
			break;
		case 7:
			v_mapEnemies.push_back(MapEnemy(helper.ParsedClassSString()));
			break;
		case 8:
			v_questNPCs.push_back(QuestNPC(helper.ParsedClassSString()));
			break;
		case 9:
			defaultPR = stoi(helper.ParsedValue());
			break;
		case 10:
			defaultPC = stoi(helper.ParsedValue());
			break;
		case 11:
			spaceColor = stoi(helper.ParsedValue());
			break;
		case 12:
			mapMusic = helper.ParsedValue();
			break;
		case 13:
			playedFlavorTxt = stob(helper.ParsedValue());
			break;
		}
	}
}

string Map::Serialized()
{
	string serialString = "";

	// TODO - find a workaround for a vector<vector<type>> data member, 
	{
		serialString += "map[";
		serialString += "],";
		//serialString += ":" + /*???*/ + ",";
	}

	serialString += "mapID:" + to_string(mapID) + ",";
	serialString += "name:" + name + ",";
	serialString += "canBattle:" + btos(canBattle) + ",";
	{
		serialString += "transitionPoints[";
		if (v_transitionPoints.size() > 0)
		{
			for (size_t i = 0; i < v_transitionPoints.size(); ++i)
			{
				serialString += "{";
				serialString += v_transitionPoints[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	{
		serialString += "NPCs[";
		if (v_NPCs.size() > 0)
		{
			for (size_t i = 0; i < v_NPCs.size(); ++i)
			{
				serialString += "{";
				serialString += v_NPCs[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	{
		serialString += "chests[";
		if (v_chests.size() > 0)
		{
			for (size_t i = 0; i < v_chests.size(); ++i)
			{
				serialString += "{";
				serialString += v_chests[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	{
		serialString += "mapEnemies[";
		if (v_mapEnemies.size() > 0)
		{
			for (size_t i = 0; i < v_mapEnemies.size(); ++i)
			{
				serialString += "{";
				serialString += v_mapEnemies[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	{
		serialString += "questNPCs[";
		if (v_questNPCs.size() > 0)
		{
			for (size_t i = 0; i < v_questNPCs.size(); ++i)
			{
				serialString += "{";
				serialString += v_questNPCs[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	serialString += "defaultPR:" + to_string(defaultPR) + ",";
	serialString += "defaultPC:" + to_string(defaultPC) + ",";
	serialString += "spaceColor:" + to_string(spaceColor) + ",";
	serialString += "mapMusic:" + mapMusic + ",";
	serialString += "playedFlavorTxt:" + btos(playedFlavorTxt) + ",";

	return serialString;
}