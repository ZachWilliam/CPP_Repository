#include "Database.h"




Database::Database()
{}


void Database::LoadMonsters()
{
	cout << "Loading monsters\n";
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

			cout << Beastiary[loopCount].m_Name << " loaded\n";
			loopCount++;
		}

	}
	else
	{
		cout << "Monsters broke Jim.\n";
	}
	myFile.close();


	_getch();
	system("CLS");
}

void Database::LoadText()
{
	cout << "Loading story and dialogue\n";
	//dialogue exclusive variables
	int tID;
	string tText;
	string tSpeaker;

	int loopCount = 0;
	string line;
	ifstream myFile("Database_Text.csv");
	if (myFile.is_open())
	{
		cout << "Inside if";
		//getline(myFile, line);
		while (getline(myFile, line))
		{
			string data[3];
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

			tID = stoi(data[0]);
			tText = data[1];
			tSpeaker = data[2];

			Dialogue temp(tID, tText, tSpeaker);
			Scenes.push_back(temp);
			cout << "line: " << Scenes[loopCount].m_ID << " loaded\n";
			loopCount++;
		}
	}
	else
	{
		cout << "Story broke Jim.\n";
	}
	myFile.close();

	_getch();
	system("CLS");
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
		cout << (*iter).m_ID << ":\n";
		cout << (*iter).m_Text << endl;
		cout << (*iter).m_Speaker << endl;
	}
}