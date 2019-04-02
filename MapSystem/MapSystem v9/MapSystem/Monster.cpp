#include "Monster.h"



Monster::Monster(int ID, string name, string desc, string type, int min, int str, int dex, int con, int intel, int wis, int agi, int luk,
	int str_G, int dex_G, int con_G, int intel_G, int wis_G, int agi_G, int luk_G, float pierce, float slash, float bludgeon,
	float fire, float ice, float water, float thunder, float wind, float earth, float dark, float light,
	int target) :
	m_ID(ID), m_Name(name), m_Desc(desc), m_Type(type), m_Min(min), m_Str(str), m_Dex(dex), m_Con(con), m_Intel(intel),
	m_Wis(wis), m_Agi(agi), m_Luk(luk), m_Str_G(str_G), m_Dex_G(dex_G), m_Con_G(con_G), m_Intel_G(intel_G), m_Wis_G(wis_G),
	m_Agi_G(agi_G), m_Luk_G(luk_G), m_PierceRes(pierce), m_SlashRes(slash), m_BludgeonRes(bludgeon), m_FireRes(fire), m_IceRes(ice), m_WaterRes(water),
	m_ThunderRes(thunder), m_WindRes(wind), m_EarthRes(earth), m_DarkRes(dark), m_LightRes(light), m_Target(target) {}




