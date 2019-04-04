#pragma once
#include <string>

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
};

