#include "Database.h"




Database::Database()
{}


void Database::LoadMonsters()
{
	//cout << "Loading monsters\n";
	int tID;//used in all
	string tName;//used in Monsters and items
	string tDesc;//used in Monsters and items
	string tType;//used in Monsters and items
	//Monster exclusive variables
	int tMin;
	int tStr, tDex, tCon, tIntel, tWis, tAgi, tLuk, tStr_G,
		tDex_G, tIntel_G, tCon_G, tWis_G, tAgi_G, tLuk_G;
	float tPierceRes, tSlashRes, tBludgeonRes, tFireRes, tIceRes, tWaterRes,
		tThunderRes, tWindRes, tEarthRes, tDarkRes, tLightRes;
	int tTarget;

	int loopCount = 0;
	string line;
	ifstream myFile("Database_Enemies.csv");
	if (myFile.is_open())
	{
		getline(myFile, line);
		//cout << "Inside if.\n";
		while (getline(myFile, line))
		{
			//cout << "Inside while\n";
			string data[31];
			int count = 0;
			for (unsigned int i = 0; i < line.length(); i++)
			{
				if (line[i] == '"' && line[i + 1] == '"' && line[i + 2] == '"')
				{
					i += 2;
				}
				else if (line[i] == '"' && line[i + 1] == '"')
				{
					i += 1;
				}
				//cout << "Inside for loop\n";
				if (line[i] == ',')
				{
					count++;
					continue;
				}
				data[count] += line[i];
			}
			//cout << "Loading to temp.\n";
			//basic info
			tID = stoi(data[0]);
			tName = data[1];
			tDesc = data[2];
			tType = data[3];
			tMin = stoi(data[4]);
			//stats
			tStr = stoi(data[5]);
			tDex = stoi(data[6]);
			tCon = stoi(data[7]);
			tIntel = stoi(data[8]);
			tWis = stoi(data[9]);
			tAgi = stoi(data[10]);
			tLuk = stoi(data[11]);
			//stat growth
			tStr_G = stoi(data[12]);
			tDex_G = stoi(data[13]);
			tCon_G = stoi(data[14]);
			tIntel_G = stoi(data[15]);
			tWis_G = stoi(data[16]);
			tAgi_G = stoi(data[17]);
			tLuk_G = stoi(data[18]);
			//resistance
			tPierceRes = stof(data[19]);
			tSlashRes = stof(data[20]);
			tBludgeonRes = stof(data[21]);
			tFireRes = stof(data[22]);
			tIceRes = stof(data[23]);
			tWaterRes = stof(data[24]);
			tThunderRes = stof(data[25]);
			tWindRes = stof(data[26]);
			tEarthRes = stof(data[27]);
			tDarkRes = stof(data[28]);
			tLightRes = stof(data[29]);
			//target
			tTarget = stoi(data[30]);
			//cout << "starting constructor.\n";
			Monster temp(tID, tName, tDesc, tType, tMin, tStr, tDex, tCon, tIntel,
				tWis, tAgi, tLuk, tStr_G, tDex_G, tCon_G, tIntel_G, tWis_G,
				tAgi_G, tLuk_G, tPierceRes, tSlashRes, tBludgeonRes, tFireRes,
				tIceRes, tWaterRes, tThunderRes, tWindRes, tEarthRes, tDarkRes, tLightRes, tTarget);
			//cout << "pushback\n";
			Beastiary.push_back(temp);

			//cout << Beastiary[loopCount].m_Name << " loaded\n";
			loopCount++;
		}

	}
	else
	{
		cout << "Monsters broke Jim.\n";
	}
	myFile.close();

	//cout << "Monsters loaded.\n\n";
	//_getch();
	//system("CLS");
}

void Database::LoadText()
{
	//cout << "Loading story and dialogue\n";
	//dialogue exclusive variables
	int tMapID;
	int tSpeakerID;
	int tTextID;
	string tText;
	string tSpeaker;

	int loopCount = 0;
	string line;
	ifstream myFile("Database_Text.csv");
	if (myFile.is_open())
	{
		//cout << "Inside if";
		//getline(myFile, line);
		while (getline(myFile, line))
		{
			string data[5];
			int count = 0;
			for (unsigned int i = 0; i < line.length(); i++)
			{
				if (line[i] == ';')
				{
					count++;
					continue;
				}
				data[count] += line[i];
			}

			tMapID = stoi(data[0]);
			tSpeakerID = stoi(data[1]);
			tTextID = stoi(data[2]);
			tText = data[3];
			tSpeaker = data[4];

			Dialogue temp(tMapID,tSpeakerID,tTextID, tText, tSpeaker);
			Scenes.push_back(temp);
			//cout << "line: " << Scenes[loopCount].m_MapID << Scenes[loopCount].m_SpeakerID << Scenes[loopCount].m_TextID << " loaded\n";
			loopCount++;
		}
	}
	else
	{
		cout << "Story broke Jim.\n";
	}
	myFile.close();
	//cout << "Text and Dialogue loaded\n";
	//_getch();
	//system("CLS");
}

void Database::DisplayBeastiary()
{
	vector<Monster>::iterator iter;
	for (iter = Beastiary.begin(); iter != Beastiary.end(); iter++)
	{
		cout << endl << (*iter).m_Name << " - " << (*iter).m_Type << endl;
		cout << (*iter).m_Desc << endl;
		cout << endl;
	}

}

void Database::DisplayText()
{
	vector<Dialogue>::iterator iter;
	for (iter = Scenes.begin(); iter != Scenes.end(); iter++)
	{
		cout << (*iter).m_MapID << (*iter).m_SpeakerID << (*iter).m_TextID << ":\n";
		cout << (*iter).m_Text << endl;
		cout << (*iter).m_Speaker << endl;
	}
}

string Database::ReturnName(int speakerID)
{
	vector<Dialogue>::iterator iter;

	for (iter = Scenes.begin();iter != Scenes.end(); iter++)
	{
		if ((*iter).m_SpeakerID == speakerID)
		{
			return (*iter).m_Speaker;
		}
	}
	cout << "Name not found.\n";

	return "";
}

string Database::ReturnDialogue(int sceneID, int speakerID, int textID)
{
	vector<Dialogue>::iterator iter;

	for (iter = Scenes.begin(); iter != Scenes.end(); iter++)
	{
		if ((*iter).m_MapID == sceneID &&
			(*iter).m_SpeakerID == speakerID &&
			(*iter).m_TextID == textID)
		{
			return (*iter).m_Text;
		}
	}
	cout << "Information missing.\n";
	return "";
}
