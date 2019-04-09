#include "Weapon.h"

WeaponType::WeaponType(string weapon_type, int damageMIN, int damageMAX, int statUsed, int wielded)
{
	m_Name = weapon_type;
	m_DamageMIN = damageMIN;
	m_DamageMAX = damageMAX;
	m_StatUsed = stat(statUsed);
	m_Wielded = wield(wielded);
}
WeaponType::WeaponType() {}

string WeaponType::ToString()
{
	return m_Name;
}


DamageType::DamageType(int hit = 0, int ele = 0)
{
	m_Technique = HitType(hit);
	m_Enhancement = ele;
}
string DamageType::ToString(bool magic)
{
	string temp = "";
	if (magic == true)
	{
		temp = " of " + Element[m_Enhancement];
	}
	return temp;
}

Weapon::Weapon(int WeaponChoice, int prefix_name)
{
	m_Weapon_Type = WEAPON_TYPES[WeaponChoice];
	m_DamageMIN = WEAPON_TYPES[WeaponChoice].m_DamageMIN;
	m_DamageMAX = WEAPON_TYPES[WeaponChoice].m_DamageMAX;
	GetName(prefix_name);
	ID = uniqueID++;
}


const string Weapon::PREFIX_NAMES[NUM_PREFIX_NAMES] = { "legendarily bad", "bad", "basic", "good", "great", "legendary", "Super Fantastic" };

void Weapon::SetDamageType(int EleChoice = -1)
{
	int temp;
	if (m_Weapon_Type.m_Name == "wand" || m_Weapon_Type.m_Name == "staff" || m_Weapon_Type.m_Name == "tome" || m_Weapon_Type.m_Name == "scroll")
	{
		temp = 0;
		int tempSpell;
		tempSpell = (rand() % 10) + 1;
		if (tempSpell < 7)
		{
			SpellSlot = 1;
		}
		else if (tempSpell < 9)
		{
			SpellSlot = 2;
		}
		else
		{
			SpellSlot = 3;
		}
	}
	if (m_Weapon_Type.m_Name == "rapier" || m_Weapon_Type.m_Name == "lance" || m_Weapon_Type.m_Name == "daggers" || m_Weapon_Type.m_Name == "bow")
	{
		temp = 1;
	}
	if (m_Weapon_Type.m_Name == "sword" || m_Weapon_Type.m_Name == "glaive" || m_Weapon_Type.m_Name == "axe" || m_Weapon_Type.m_Name == "shuriken")
	{
		temp = 2;
	}
	if (m_Weapon_Type.m_Name == "fists" || m_Weapon_Type.m_Name == "warhammer" || m_Weapon_Type.m_Name == "mace" || m_Weapon_Type.m_Name == "club")
	{
		temp = 3;
	}

	int eleChance;
	if ((EleChoice <= -1 || EleChoice > 10) && EleChoice != 666)
	{
		eleChance = (rand() % 101);
		int temp2;
		if (temp != 0 || m_Weapon_Type.m_Name == "staff")
		{
			if (eleChance < 60)
			{
				temp2 = 0;
				if (m_Weapon_Type.m_Name == "staff")
				{
					temp2 = 9;
				}
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
		m_DamageType = DamageType(temp, temp2);
		if (temp2 != 0 || temp == 0)
		{
			m_Magic = true;
			if (temp != 0)
			{
				m_DamageMIN += 1;
				m_DamageMAX += 2;
			}
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
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 1://fire
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 2://ice
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 3://water
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 4://thunder
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 5://wind
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 6://earth
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 7://darkness
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 8://light
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 9://healing
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			if (eleChance != 0 || temp == 0)
			{
				m_Magic = true;
				if (temp != 0)
				{
					m_DamageMIN += 1;
					m_DamageMAX += 2;
				}
			}
			else
			{
				m_Magic = false;
			}
			break;
		case 10://no magic
			eleChance = EleChoice;
			m_DamageType = DamageType(temp, eleChance);
			m_Magic = false;
			break;
		case 666://special
			eleChance = 8;//of light
			m_DamageType = DamageType(temp, eleChance);
			m_Magic = true;
			m_DamageMIN += 10;
			m_DamageMAX += 15;
			break;
		}
	}
}


string Weapon::GetName(int Choice = -1)
{
	int namePick;
	if ((Choice <= -1 || Choice > 5) && Choice != 666)
	{
		namePick = (rand() % 101);
		if (namePick == 0)//default
		{
			m_Prefix_Name = PREFIX_NAMES[0];
			m_DamageMIN = _Max_value(m_DamageMIN - 3, 0);
			m_DamageMAX = _Max_value(m_DamageMAX - 3, 1);
		}
		else if (namePick < 15)//bad
		{
			m_Prefix_Name = PREFIX_NAMES[1];
			m_DamageMIN = _Max_value(m_DamageMIN - 1, 0);
			m_DamageMAX -= 1;
		}
		else if (namePick < 55)//basic no bonus
		{
			m_Prefix_Name = PREFIX_NAMES[2];
		}
		else if (namePick < 80)//good
		{
			m_Prefix_Name = PREFIX_NAMES[3];
			m_DamageMIN += 1;
			m_DamageMAX += 1;
		}
		else if (namePick < 95)//great
		{
			m_Prefix_Name = PREFIX_NAMES[4];
			m_DamageMIN += 2;
			m_DamageMAX += 3;
		}
		else//legendary
		{
			m_Prefix_Name = PREFIX_NAMES[5];
			m_DamageMIN += 3;
			m_DamageMAX += 5;
		}
	}
	else
	{
		switch (Choice)
		{
		case 0://default
			m_Prefix_Name = PREFIX_NAMES[0];
			m_DamageMIN = _Max_value(m_DamageMIN - 3, 0);
			m_DamageMAX = _Max_value(m_DamageMAX - 3, 1);
			namePick = Choice;
			break;
		case 1://bad
			m_Prefix_Name = PREFIX_NAMES[1];
			m_DamageMIN = _Max_value(m_DamageMIN - 1, 0);
			m_DamageMAX -= 1;
			namePick = Choice;
			break;
		case 2://basic
			m_Prefix_Name = PREFIX_NAMES[2];
			namePick = Choice;
			break;
		case 3://good
			m_Prefix_Name = PREFIX_NAMES[3];
			m_DamageMIN += 1;
			m_DamageMAX += 1;
			namePick = Choice;
			break;
		case 4://great
			m_Prefix_Name = PREFIX_NAMES[4];
			m_DamageMIN += 2;
			m_DamageMAX += 3;
			namePick = Choice;
			break;
		case 5://legendary
			m_Prefix_Name = PREFIX_NAMES[5];
			m_DamageMIN += 3;
			m_DamageMAX += 5;
			namePick = Choice;
			break;
		case 666://specific
			m_Prefix_Name = PREFIX_NAMES[6];
			m_DamageMIN += 150;
			m_DamageMAX += 250;
			namePick = Choice;
			break;
		}
	}
	return m_Prefix_Name;
}


void Weapon::GetType(int Choice = -1)
{
	int typePick;
	if (Choice <= -1 || Choice > 15)
	{
		typePick = (rand() % WEAPON_TYPES.size());
	}
	else
	{
		typePick = Choice;
	}
	m_Weapon_Type = WEAPON_TYPES[typePick];
	m_DamageMIN = m_Weapon_Type.m_DamageMIN;
	m_DamageMAX = m_Weapon_Type.m_DamageMAX;
}


void Weapon::Status()
{
	cout << m_Prefix_Name << " " << m_Weapon_Type.ToString() + m_DamageType.ToString(m_Magic);
	cout << "\nmin damage: " + to_string(m_DamageMIN) + " , max damage: " + to_string(m_DamageMAX);
}
int Weapon::Attack()
{
	int attackValue = (rand() % ((m_DamageMAX + 1) - m_DamageMIN)) + m_DamageMIN;
	return attackValue;
}
void Weapon::DisplayName()
{
	cout << m_Prefix_Name << " " << m_Weapon_Type.ToString() + m_DamageType.ToString(m_Magic);
}
string Weapon::DisplayNameText() {
	return  m_Prefix_Name + " " + m_Weapon_Type.ToString() + m_DamageType.ToString(m_Magic);
}
int Weapon::GetSellValue()
{
	int sellValue;
	sellValue = (((m_DamageMIN * 2) + m_DamageMAX) / 2) * (_Max_value(m_Magic * 2, 1)) * ((_Max_value(SpellSlot - 1, 0) * 2) + 1);
	if (sellValue < 1)
	{
		sellValue = 1;
	}
	return sellValue;
}
int Weapon::GetBuyValue()
{
	int buyValue;
	buyValue = (((m_DamageMIN * 2) + m_DamageMAX) * 2) * (_Max_value(m_Magic * 2, 1)) * ((_Max_value(SpellSlot - 1, 0) * 2) + 1);
	return buyValue;
}

void Weapon::SetWeapon(int setType = 0, int setName = 1, int setDamType = 10)
{
	//default weapon is bad fists (no magic)
	int x = setType;//type(0-15):(fists(0), sword(1), rapier(2), axe(3), warhammer(4), mace(5), club(6), lance(7), glaive(8), wand(9), tome(10), scroll(11), staff(12), shuriken(13), daggers(14), bow(15))
	int y = setName;//prefix(0-5):(legendarily bad(0), bad(1), basic(2), good(3), great(4), legendary(5))
	int z = setDamType;//of(0-10):(entrophy(0), fire(1), ice(2), water(3), thunder(4), wind(5), earth(6), darkness(7), light(8), healing(9), no magic(10))
	GetType(x);
	GetName(y);
	SetDamageType(z);
}
void Weapon::SetSuperWeapon(int setType = 0)
{
	int x = setType;//type(0-15):(fists(0), sword(1), rapier(2), axe(3), warhammer(4), mace(5), club(6), lance(7), glaive(8), wand(9), tome(10), scroll(11), staff(12), shuriken(13), daggers(14), bow(15))
	GetType(x);
	GetName(666);
	SetDamageType(666);
}
void Weapon::SetRandomWeapon()
{
	GetType(-1);
	GetName(-1);
	SetDamageType(-1);
}