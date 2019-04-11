#include "Armor.h"
#include "ConvertHelper.h"
#include "DeserializeHelper.h"

ArmorType::ArmorType() {}

ArmorType::ArmorType(string armor_type, int damageResist, int magicResist, int avoidance, int statUsed, int wieghted)
{
	m_Name = armor_type;
	m_DamageResist = damageResist;
	m_StatUsed = stat(statUsed);
	m_Wieghted = wieght(wieghted);
	m_MagicResist = magicResist;
	m_Avoidance = avoidance;
}


string ArmorType::ToString()
{
	return m_Name;
}

ArmorType::ArmorType(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			m_Name = helper.ParsedValue();
			break;
		case 1:
			m_DamageResist = stoi(helper.ParsedValue());
			break;
		case 2:
			m_MagicResist = stoi(helper.ParsedValue());
			break;
		case 3:
			m_Avoidance = stoi(helper.ParsedValue());
			break;
		case 4:
			m_StatUsed = (stat)stoi(helper.ParsedValue());
			break;
		case 5:
			m_Wieghted = (wieght)stoi(helper.ParsedValue());
			break;
		}
	}
}

string ArmorType::Serialized()
{
	string serialString = "";

	serialString += "Name:" + m_Name + ",";
	serialString += "DamageResist:" + to_string(m_DamageResist) + ",";
	serialString += "MagicResist:" + to_string(m_MagicResist) + ",";
	serialString += "Avoidance:" + to_string(m_Avoidance) + ",";
	serialString += "StatUsed:" + etos((int)m_StatUsed) + ",";
	serialString += "Wieghted:" + etos((int)m_Wieghted) + ",";

	return serialString;
}




ElementType::ElementType(int isfor = 0, int ele = 0)
{
	m_WhoIsFor = WhoIsFor(isfor);
	m_Enhancement = ele;
}
string ElementType::ToString(bool magic)
{
	string temp = " armor";
	if (magic == true)
	{
		temp = " armor of " + Element[m_Enhancement];
	}
	return temp;
}

ElementType::ElementType(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			m_WhoIsFor = (WhoIsFor)stoi(helper.ParsedValue());
			break;
		case 1:
			m_Enhancement = stoi(helper.ParsedValue());
			break;
		}
	}
}

string ElementType::Serialized()
{
	string serialString = "";

	serialString += "WhoIsFor:" + etos((int)m_WhoIsFor) + ",";
	serialString += "Enhancement:" + to_string(m_Enhancement) + ",";

	return serialString;
}




Armor::Armor(int ArmorChoice, int prefix_name)
{
	m_Armor_Type = ARMOR_TYPES[ArmorChoice];
	m_DamageResist = ARMOR_TYPES[ArmorChoice].m_DamageResist;
	m_MagicResist = ARMOR_TYPES[ArmorChoice].m_MagicResist;
	m_Avoidance = ARMOR_TYPES[ArmorChoice].m_Avoidance;
	GetName(prefix_name);
	ID = uniqueID++;
}

const string Armor::PREFIX_NAMES[NUM_PREFIX_NAMES] = { "Legendarily bad", "Bad", "Basic", "Good", "Great", "Legendary", "Super Fantastic" };

void Armor::SetResistanceType(int EleChoice = -1)
{
	int temp;
	if (m_Armor_Type.m_Name == "silk" || m_Armor_Type.m_Name == "cotton" || m_Armor_Type.m_Name == "polyester" || m_Armor_Type.m_Name == "leather")
	{
		temp = 0;
	}
	else if (m_Armor_Type.m_Name == "studded" || m_Armor_Type.m_Name == "chainmail" || m_Armor_Type.m_Name == "ringmail" || m_Armor_Type.m_Name == "plate")
	{
		temp = 1;
	}
	else if (m_Armor_Type.m_Name == "titanium" || m_Armor_Type.m_Name == "steel" || m_Armor_Type.m_Name == "silver" || m_Armor_Type.m_Name == "onix")
	{
		temp = 2;
	}
	else if (m_Armor_Type.m_Name == "ruby" || m_Armor_Type.m_Name == "emerald" || m_Armor_Type.m_Name == "amethyst" || m_Armor_Type.m_Name == "diamond")
	{
		temp = 3;
	}

	int eleChance;
	if ((EleChoice <= -1 || EleChoice > 10) && EleChoice != 666)
	{
		eleChance = (rand() % 101);
		int temp2;
		if (temp != 3)
		{
			if (eleChance < 60)
			{
				temp2 = 0;
			}
			else if (eleChance < 66)
			{
				temp2 = 1;
			}
			else if (eleChance < 72)
			{
				temp2 = 2;
			}
			else if (eleChance < 78)
			{
				temp2 = 3;
			}
			else if (eleChance < 84)
			{
				temp2 = 4;
			}
			else if (eleChance < 90)
			{
				temp2 = 5;
			}
			else if (eleChance < 96)
			{
				temp2 = 6;
			}
			else if (eleChance < 98)
			{
				temp2 = 7;
			}
			else
			{
				temp2 = 8;
			}
		}
		else
		{
			if (eleChance < 2)
			{
				temp2 = 0;
			}
			else if (eleChance < 15)
			{
				temp2 = 1;
			}
			else if (eleChance < 28)
			{
				temp2 = 2;
			}
			else if (eleChance < 41)
			{
				temp2 = 3;
			}
			else if (eleChance < 54)
			{
				temp2 = 4;
			}
			else if (eleChance < 67)
			{
				temp2 = 5;
			}
			else if (eleChance < 80)
			{
				temp2 = 6;
			}
			else if (eleChance < 90)
			{
				temp2 = 7;
			}
			else
			{
				temp2 = 8;
			}
		}

		m_ElementType = ElementType(temp, temp2);
		if (temp2 != 0)
		{
			m_Magic = true;
			m_MagicResist += 5;
			m_Avoidance += 10;
		}
		else
		{
			m_Magic = false;
		}
	}
	else
	{
		switch (EleChoice)
		{
		case 0://entrophy
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 1://fire
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 2://ice
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 3://water
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 4://thunder
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 5://wind
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 6://earth
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 7://darkness
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 8://light
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 9://healing
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			if (eleChance != 0 || temp == 3)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_MagicResist += 5;
					m_Avoidance += 10;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 10://no magic
			eleChance = EleChoice;
			m_ElementType = ElementType(temp, eleChance);
			m_Magic = false;
			break;
		case 666:
			eleChance = 8;//of light
			m_ElementType = ElementType(temp, eleChance);
			m_Magic = true;
			m_MagicResist += 15;
			m_Avoidance += 20;
			break;
		}
	}
}

string Armor::GetName(int Choice = -1)
{
	int namePick;
	if ((Choice <= -1 || Choice > 5) && Choice != 666)
	{
		namePick = (rand() % 101);
		if (namePick == 0)//default
		{
			m_Prefix_Name = PREFIX_NAMES[0];
			m_DamageResist = _Max_value(m_DamageResist - 5, 0);
			m_MagicResist = _Max_value(m_MagicResist - 5, 0);
			m_Avoidance -= 5;
		}
		else if (namePick < 15)//bad
		{
			m_Prefix_Name = PREFIX_NAMES[1];
			m_DamageResist = _Max_value(m_DamageResist - 3, 0);
			m_MagicResist = _Max_value(m_MagicResist - 3, 0);
			m_Avoidance -= 3;
		}
		else if (namePick < 55)//basic no bonus
		{
			m_Prefix_Name = PREFIX_NAMES[2];
		}
		else if (namePick < 80)//good
		{
			m_Prefix_Name = PREFIX_NAMES[3];
			m_DamageResist += 5;
			m_MagicResist += 5;
			m_Avoidance += 3;
		}
		else if (namePick < 95)//great
		{
			m_Prefix_Name = PREFIX_NAMES[4];
			m_DamageResist += 7;
			m_MagicResist += 7;
			m_Avoidance += 5;
		}
		else//legendary
		{
			m_Prefix_Name = PREFIX_NAMES[5];
			m_DamageResist += 10;
			m_MagicResist += 10;
			m_Avoidance += 7;
		}
	}
	else
	{
		switch (Choice)
		{
		case 0://default
			m_Prefix_Name = PREFIX_NAMES[0];
			m_DamageResist = _Max_value(m_DamageResist - 5, 0);
			m_MagicResist = _Max_value(m_MagicResist - 5, 0);
			m_Avoidance -= 5;
			namePick = Choice;
			break;
		case 1://badd
			m_Prefix_Name = PREFIX_NAMES[1];
			m_DamageResist = _Max_value(m_DamageResist - 3, 0);
			m_MagicResist = _Max_value(m_MagicResist - 3, 0);
			m_Avoidance -= 3;
			namePick = Choice;
			break;
		case 2://basic
			m_Prefix_Name = PREFIX_NAMES[2];
			namePick = Choice;
			break;
		case 3://good
			m_Prefix_Name = PREFIX_NAMES[3];
			m_DamageResist += 5;
			m_MagicResist += 5;
			m_Avoidance += 3;
			namePick = Choice;
			break;
		case 4://great
			m_Prefix_Name = PREFIX_NAMES[4];
			m_DamageResist += 7;
			m_MagicResist += 7;
			m_Avoidance += 5;
			namePick = Choice;
			break;
		case 5://legendary
			m_Prefix_Name = PREFIX_NAMES[5];
			m_DamageResist += 10;
			m_MagicResist += 10;
			m_Avoidance += 7;
			namePick = Choice;
			break;
		case 666://specific
			m_Prefix_Name = PREFIX_NAMES[6];
			m_DamageResist += 250;
			m_MagicResist += 250;
			m_Avoidance += 150;
			namePick = Choice;
			break;
		}
	}
	return m_Prefix_Name;
}

void Armor::GetType(int Choice = -1)
{
	int typePick;
	if (Choice == -1)
	{
		typePick = (rand() % ARMOR_TYPES.size());
	}
	else
	{
		typePick = Choice;
	}
	m_Armor_Type = ARMOR_TYPES[typePick];
	m_DamageResist = m_Armor_Type.m_DamageResist;
	m_MagicResist = m_Armor_Type.m_MagicResist;
	m_Avoidance = m_Armor_Type.m_Avoidance;
}

void Armor::Status()
{
	cout << m_Prefix_Name << " " << m_Armor_Type.ToString() + m_ElementType.ToString(m_Magic);
	cout << "\ndamage resist: " + to_string(m_DamageResist) + ", magic resist: " + to_string(m_MagicResist) + ", avoidance: " + to_string(m_Avoidance);
}
void Armor::DisplayName()
{
	cout << m_Prefix_Name << " " << m_Armor_Type.ToString() + m_ElementType.ToString(m_Magic);
}
string Armor::DisplayNameText()
{
	return m_Prefix_Name + " " + m_Armor_Type.ToString() + m_ElementType.ToString(m_Magic);
}
int Armor::GetSellValue()
{
	int sellValue;
	sellValue = (m_DamageResist + m_MagicResist + (m_Avoidance / 2)) / 1.5;
	if (sellValue < 1)
	{
		sellValue = 1;
	}
	return sellValue;
}
int Armor::GetBuyValue()
{
	int buyValue;
	buyValue = (m_DamageResist + m_MagicResist + (m_Avoidance / 2)) * 3;
	return buyValue;
}

void Armor::SetArmor(int setType = 0, int setName = 1, int setResType = 10)
{
	//default armor is bad silk (no magic)
	int x = setType;//type(0-15):(silk(0), cotton(1), polyester(2), leather(3), studded(4), chainmail(5), ringmail(6), plate(7), titanium(8), steel(9), silver(10), onix(11), ruby(12), emerald(13), amethyst(14), diamond(15))
	int y = setName;//prefix(0-5):(legendarily bad(0), bad(1), basic(2), good(3), great(4), legendary(5))
	int z = setResType;//of(0-10):(entrophy(0), fire(1), ice(2), water(3), thunder(4), wind(5), earth(6), darkness(7), light(8), healing(9), no magic(10))
	GetType(x);
	GetName(y);
	SetResistanceType(z);
}
void Armor::SetSuperArmor(int setType = 0)
{
	int x = setType;//type(0-15):(silk(0), cotton(1), polyester(2), leather(3), studded(4), chainmail(5), ringmail(6), plate(7), titanium(8), steel(9), silver(10), onix(11), ruby(12), emerald(13), amethyst(14), diamond(15))
	GetType(x);
	GetName(666);
	SetResistanceType(666);
}
void Armor::SetRandomArmor()
{
	GetType(-1);
	GetName(-1);
	SetResistanceType(-1);
}

Armor::Armor(string serialString)
{
	DeserializeHelper helper(serialString);

	while (helper.isActive)
	{
		helper.NextParse();

		switch (helper.ParseCount())
		{
		case 0:
			ID = stoi(helper.ParsedValue());
			break;
		case 1:
			m_Prefix_Name = helper.ParsedValue();
			break;
		case 2:
			m_Armor_Type = ArmorType(helper.ParsedClassSString());
			break;
		case 3:
			m_DamageResist = stoi(helper.ParsedValue());
			break;
		case 4:
			m_MagicResist = stoi(helper.ParsedValue());
			break;
		case 5:
			m_Avoidance = stoi(helper.ParsedValue());
			break;
		case 6:
			m_Magic = stob(helper.ParsedValue());
			break;
		case 7:
			m_ElementType = ElementType(helper.ParsedClassSString());
			break;
		}
	}
}

string Armor::Serialized()
{
	string serialString = "";

	serialString += "ID:" + to_string(ID) + ",";
	serialString += "PrefixName:" + m_Prefix_Name + ",";
	serialString += "ArmorType{" + m_Armor_Type.Serialized() + "},";
	serialString += "DamageResist:" + to_string(m_DamageResist) + ",";
	serialString += "MagicResist:" + to_string(m_MagicResist) + ",";
	serialString += "Avoidance:" + to_string(m_Avoidance) + ",";
	serialString += "Magic:" + btos(m_Magic) + ",";
	serialString += "ElementType{" + m_ElementType.Serialized() + "},";

	return serialString;
}
