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

void Map::GenerateMap() {
	string path = "Maps/";
	string searchPattern = "*.txt";
	string fullSearchPath = path + searchPattern;

	WIN32_FIND_DATA FindData;
	HANDLE hFind;

	hFind = FindFirstFile(fullSearchPath.c_str(), &FindData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Error searching directory\n";
		return;
	}

	do
	{
		string filePath = path + FindData.cFileName;
		ifstream in(filePath.c_str());
		if (in)
		{
			SearchForMapByID(in);
		}
		else
		{
			cout << "Problem opening file " << FindData.cFileName << "\n";
		}
	} while (FindNextFile(hFind, &FindData) > 0);

	if (GetLastError() != ERROR_NO_MORE_FILES)
	{
		cout << "Something went wrong during searching\n";
	}


}

void Map::SearchForMapByID(ifstream &p_fileToRead) {
	vector<vector<char> > tempMap;
	bool foundID = false;

	string line;
	//ifstream myfile("introisland.txt");
	if (p_fileToRead.is_open())
	{
		int i = 0;
		while (getline(p_fileToRead, line))
		{
			vector<char>temp;
			for (int j = 0; j < line.size(); j++)
			{
				//Checking ID, break method if not matching
				if (i == 0) { 
					if (stoi(line) != mapID)return;
					else foundID = true;
					break; 
				}

			}
			if (i > 10)tempMap.push_back(temp);
			i++;
		}
		p_fileToRead.close();
	}

	//Reset map
	map = tempMap;

	//Update chests on map
	for (int i = 0; i < v_chests.size(); i++)
	{
		if (v_chests[i].opened == true) {
			map[v_chests[i].row][v_chests[i].col] = ' ';
		}
	}

	//Update trigger enemies on map
	for (int i = 0; i < v_mapEnemies.size(); i++)
	{
		if (v_mapEnemies[i].isDefeated == true) {
			map[v_mapEnemies[i].row][v_mapEnemies[i].col] = ' ';
		}
	}
}

