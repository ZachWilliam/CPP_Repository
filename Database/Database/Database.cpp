#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
//#include <iomanop>
#include <fstream>

using namespace std;

class Monster
{
public:

	Monster(int ID, string name, string desc, string type, int min, int str, int dex, int con, int intel, int wis, int agi, int luk,
		int str_G, int dex_G, int con_G, int intel_G, int wis_G, int agi_G, int luk_G, float pierce, float slash, float bludgeon,
		float fire, float ice, float water, float thunder, float wind, float earth, float dark, float light, int target);
	const int m_ID;
	const string m_Name;
	const string m_Desc;
	const string m_Type;
	const int m_Min;
	const int m_Str, m_Dex, m_Con, m_Intel, m_Wis, m_Agi, m_Luk, m_Str_G,
		m_Dex_G, m_Con_G, m_Intel_G, m_Wis_G, m_Agi_G, m_Luk_G;
	const float m_PierceRes, m_SlashRes, m_BludgeonRes, m_FireRes, m_IceRes, m_WaterRes,
		m_ThunderRes, m_WindRes, m_EarthRes, m_DarkRes, m_LightRes;
	const int m_Target;


private:





};

/*
class Item
{

};
*/
class Dialogue
{
public:
	Dialogue(int id, string text,string speaker);

	
private:
	int m_ID;
	string m_Text;
	string m_NPCName;
};

class Database
{
public:
	void Start();
	void DisplayBeastiary();
private:
	vector<Monster>Beastiary;
	vector<Dialogue>Scenes;
	void Load();//loads all data from CSV and puts information into Beastiary/Item/Diaglogue vector
};
int main()
{
	Database beast;
	beast.Start();


	beast.DisplayBeastiary();
	_getch();
	return 0;
}


Monster::Monster(int ID, string name, string desc, string type, int min, int str, int dex, int con, int intel, int wis, int agi, int luk,
	int str_G, int dex_G, int con_G, int intel_G, int wis_G, int agi_G, int luk_G, float pierce, float slash, float bludgeon,
	float fire, float ice, float water, float thunder, float wind, float earth, float dark, float light,
	int target) :
	m_ID(ID), m_Name(name), m_Desc(desc), m_Type(type), m_Min(min), m_Str(str), m_Dex(dex), m_Con(con), m_Intel(intel),
	m_Wis(wis), m_Agi(agi), m_Luk(luk), m_Str_G(str_G), m_Dex_G(dex_G), m_Con_G(con_G), m_Intel_G(intel_G), m_Wis_G(wis_G),
	m_Agi_G(agi_G), m_Luk_G(luk_G), m_PierceRes(pierce), m_SlashRes(slash), m_BludgeonRes(bludgeon), m_FireRes(fire), m_IceRes(ice), m_WaterRes(water),
	m_ThunderRes(thunder), m_WindRes(wind), m_EarthRes(earth), m_DarkRes(dark), m_LightRes(light), m_Target(target) {}

void Database::Start()
{
	Load();
}

void Database::Load()
{
	cout << "Load Start\n";
	int tID;
	string tName;
	string tDesc;
	string tType;
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
			for (int i = 0; i < line.length(); i++)
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
		cout << "It broke Jim.\n";
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






