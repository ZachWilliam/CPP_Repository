#include "Map.h"



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


int Map::OpenChest(int p_row, int p_col, Database &p_database, QuestManager& p_qManager) {
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
				//Find item by ID
				Weapon newItem;
				newItem.SetWeapon(v_chests[locInChestVec].id1, v_chests[locInChestVec].id2, v_chests[locInChestVec].id3);

				//string name
				tempText = "You have picked up a " + newItem.DisplayNameText();

				//Call AddWeapon(?,?,?) instead of set weapon

			}
			else if (v_chests[locInChestVec].itemType == 2) {
				//Find item by ID
				Armor newItem;
				newItem.SetArmor(v_chests[locInChestVec].id1, v_chests[locInChestVec].id2, v_chests[locInChestVec].id3);

				//string name
				tempText = "You have picked up a " + newItem.DisplayNameText();

				//Call AddArmor(?,?,?) instead of set weapon

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



