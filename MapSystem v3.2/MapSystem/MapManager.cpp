#include "MapManager.h"



MapManager::MapManager()
{
	LoadAllMaps();
}

void MapManager::LoadAllMaps() {
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
			LoadMap(in);
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

void MapManager::LoadMap(ifstream &p_fileToRead) {
	vector<vector<char> > tempMap;
	vector<Coord> tempCoords;
	string name;
	bool canBattle;
	int id;
	int defaultCoords[2];

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
				//Getting ID
				if (i == 0) { id = stoi(line); break; }
				//Getting Name
				if (i == 1) { name = line;  break;	}
				//Getting can battke
				if (i == 2) {canBattle = stoi(line); break;	}
				//Getting transition coords
				if (i == 3) {
					tempCoords = GetCoords(line);
					break;
				}
				//Get default coords
				if (i == 4) { 
					int posInLine = 0;
					for (int i = 0; i < 2; i++)
					{
						string tempNum;
						while (line[posInLine] != ',' && posInLine < line.size()) {
							tempNum += line[posInLine];
							posInLine++;
						}

						defaultCoords[i] = stoi(tempNum);
						posInLine++;
					}
					break;
				}


				//At end of line
				if (line[j] == 'e') break;

				temp.push_back(line[j]);

			}
			if (i > 4)tempMap.push_back(temp);
			i++;
		}
		p_fileToRead.close();

		Map newMap(name, tempMap, id, canBattle, tempCoords, defaultCoords[0], defaultCoords[1]);
		mapList.push_back(newMap);
	}

	else cout << "Unable to open file";
}

vector<Coord> MapManager::GetCoords(const string &p_line) {
	int posInLine = 0;
	vector<Coord> v_tempCoords;

	//While we havent hit the end of the line
	while (p_line[posInLine] != 'e') {
		vector<int> v_curInfo;
		//While were in the current set of coords aka 21,6,21,6,2
		while (p_line[posInLine] != ' ' && p_line[posInLine] != 'e') {
			//while were getting a set of number(s)
			string tempNum;
			while (p_line[posInLine] != ',' && p_line[posInLine] != ' ' && p_line[posInLine] != 'e') {
				tempNum += p_line[posInLine];
				posInLine++;
			}
			int num = stoi(tempNum);
			v_curInfo.push_back(num);
			if(p_line[posInLine] != 'e' && p_line[posInLine] != ' ') posInLine++;
		}
		Coord newCoord(v_curInfo[0], v_curInfo[1], v_curInfo[2], v_curInfo[3], v_curInfo[4]);
		v_tempCoords.push_back(newCoord);
		if (p_line[posInLine] != 'e') posInLine++;
	}
	
	return v_tempCoords;
}