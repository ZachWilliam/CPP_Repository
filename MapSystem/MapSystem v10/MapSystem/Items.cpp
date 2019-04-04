#include "Items.h"

Purse::Purse(int gold, int buildingMaterials, bool questItem)
{
	m_Gold = gold;
	m_BuildingMaterials = buildingMaterials;
	m_QuestItem = questItem;
}

void Purse::SetPurse(int setGold = 0, int setBuildingMaterials = 0, bool setQuestItem = false)
{
	int x = setGold;
	int y = setBuildingMaterials;
	bool z = setQuestItem;
	AddGold(x);
	AddBuildingMaterials(y);
	SetQuestItem(z);
}
void Purse::Status()
{
	cout << "wallet: " << m_Gold << " gold, and " << m_BuildingMaterials << " building materials" << endl;
	cout << QuestToString();
}
void Purse::ResetAll()
{
	m_Gold = 0;
	m_BuildingMaterials = 0;
	m_QuestItem = false;
}
int Purse::GetGold()
{
	return m_Gold;
}
int Purse::AddGold(int gold = 1)//add one by default
{
	int x = m_Gold;
	int y = gold;
	int z = x + y;
	m_Gold = z;
	return m_Gold;
}
int Purse::RemoveGold(int gold = 1)//wont remove any if num to high, remove 1 by default
{
	int x = m_Gold;
	int y = gold;
	int z = x - y;
	if (y > x)
	{
		m_Gold = x;
	}
	else
	{
		m_Gold = z;
	}
	return m_Gold;
}

int Purse::GetBuildingMaterials()
{
	return m_BuildingMaterials;
}
int Purse::AddBuildingMaterials(int buildingMaterials = 1)//add one by default
{
	int x = m_BuildingMaterials;
	int y = buildingMaterials;
	int z = x + y;
	m_BuildingMaterials = z;
	return m_BuildingMaterials;
}
int Purse::RemoveBuildingMaterials(int buildingMaterials = 1)//wont remove any if num to high, remove 1 by default
{
	int x = m_BuildingMaterials;
	int y = buildingMaterials;
	int z = x - y;
	if (y > x)
	{
		m_BuildingMaterials = x;
	}
	else
	{
		m_BuildingMaterials = z;
	}
	return m_BuildingMaterials;
}

bool Purse::GetQuestItem()
{
	return m_QuestItem;
}
bool Purse::SwitchQuestYesNo()
{
	if (m_QuestItem != false)
	{
		m_QuestItem = false;
	}
	else
	{
		m_QuestItem = true;
	}
	return m_QuestItem;
}
string Purse::QuestToString()
{
	string yesNo;
	if (m_QuestItem != false)
	{
		yesNo = "does indeed have the quest item.";
	}
	else
	{
		yesNo = "does not have the quest item.";
	}
	return yesNo;
}
bool Purse::SetQuestItem(bool hasItem = false)
{
	if (hasItem == false)
	{
		m_QuestItem = false;
	}
	else
	{
		m_QuestItem = true;
	}
	return m_QuestItem;
}


Potion::Potion(int PotionName)
{
	int potionPick;
	if (PotionName <= -1 || PotionName > 12)
	{
		potionPick = (rand() % 12);
		m_Name = POTION_TYPES[potionPick];
		if (potionPick == 0)//small healing
		{
			m_HealAmount = 5;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 1)//medium healing
		{
			m_HealAmount = 10;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 2)//large healing
		{
			m_HealAmount = 20;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 3)//small damaging
		{
			m_HealAmount = 0;
			m_DamageAmount = 5;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 4)//medium damaging
		{
			m_HealAmount = 0;
			m_DamageAmount = 10;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 5)//large damaging
		{
			m_HealAmount = 0;
			m_DamageAmount = 20;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 6)//small magic resist
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 5;
			m_MagicAttack = 0;
		}
		else if (potionPick == 7)//medium magic resist
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 10;
			m_MagicAttack = 0;
		}
		else if (potionPick == 8)//large magic resist
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 20;
			m_MagicAttack = 0;
		}
		else if (potionPick == 9)//small magic attack
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 5;
		}
		else if (potionPick == 10)//medium magic attack
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 10;
		}
		else if (potionPick == 11)//large magic attack
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 20;
		}
	}
	else
	{
		switch (PotionName)
		{
		case 0://small healing
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 5;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 1://medium healing
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 10;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 2://large healing
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 20;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 3://small damaging
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 5;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 4://medium damaging
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 10;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 5://large damaging
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 20;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 6://small magic resist
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 5;
			m_MagicAttack = 0;
			break;
		case 7://medium magic resist
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 10;
			m_MagicAttack = 0;
			break;
		case 8://large magic resist
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 20;
			m_MagicAttack = 0;
			break;
		case 9://small magic attack
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 5;
			break;
		case 10://medium magic attack
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 10;
			break;
		case 11://large magic attack
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 20;
			break;
		case 12://no potion
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		}
	}
}

string Potion::DisplayName()
{
	return m_Name;
}
int Potion::GetHeal()
{
	return m_HealAmount;
}
int Potion::GetDamage()
{
	return m_DamageAmount;
}
int Potion::GetMagicResist()
{
	return m_MagicResist;
}
int Potion::GetMagicAttack()
{
	return m_MagicAttack;
}
void Potion::SetPotion(int PotionName = -1)
{
	int potionPick;
	if (PotionName <= -1 || PotionName > 12)
	{
		potionPick = (rand() % 12);
		m_Name = POTION_TYPES[potionPick];
		if (potionPick == 0)//small healing
		{
			m_HealAmount = 5;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 1)//medium healing
		{
			m_HealAmount = 10;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 2)//large healing
		{
			m_HealAmount = 20;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 3)//small damaging
		{
			m_HealAmount = 0;
			m_DamageAmount = 5;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 4)//medium damaging
		{
			m_HealAmount = 0;
			m_DamageAmount = 10;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 5)//large damaging
		{
			m_HealAmount = 0;
			m_DamageAmount = 20;
			m_MagicResist = 0;
			m_MagicAttack = 0;
		}
		else if (potionPick == 6)//small magic resist
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 5;
			m_MagicAttack = 0;
		}
		else if (potionPick == 7)//medium magic resist
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 10;
			m_MagicAttack = 0;
		}
		else if (potionPick == 8)//large magic resist
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 20;
			m_MagicAttack = 0;
		}
		else if (potionPick == 9)//small magic attack
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 5;
		}
		else if (potionPick == 10)//medium magic attack
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 10;
		}
		else if (potionPick == 11)//large magic attack
		{
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 20;
		}
	}
	else
	{
		switch (PotionName)
		{
		case 0://small healing
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 5;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 1://medium healing
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 10;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 2://large healing
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 20;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 3://small damaging
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 5;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 4://medium damaging
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 10;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 5://large damaging
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 20;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		case 6://small magic resist
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 5;
			m_MagicAttack = 0;
			break;
		case 7://medium magic resist
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 10;
			m_MagicAttack = 0;
			break;
		case 8://large magic resist
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 20;
			m_MagicAttack = 0;
			break;
		case 9://small magic attack
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 5;
			break;
		case 10://medium magic attack
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 10;
			break;
		case 11://large magic attack
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 20;
			break;
		case 12://no potion
			m_Name = POTION_TYPES[PotionName];
			m_HealAmount = 0;
			m_DamageAmount = 0;
			m_MagicResist = 0;
			m_MagicAttack = 0;
			break;
		}
	}
}
void Potion::Status()
{
	if ((m_HealAmount != 0) && (m_DamageAmount == 0) && (m_MagicResist == 0) && (m_MagicAttack == 0))
	{
		cout << m_Name << " potion (";
		cout << m_HealAmount << ") healing.";
	}
	if ((m_HealAmount == 0) && (m_DamageAmount != 0) && (m_MagicResist == 0) && (m_MagicAttack == 0))
	{
		cout << m_Name << " potion (";
		cout << m_DamageAmount << ") damage.";
	}
	if ((m_HealAmount == 0) && (m_DamageAmount == 0) && (m_MagicResist != 0) && (m_MagicAttack == 0))
	{
		cout << m_Name << " potion (";
		cout << m_MagicResist << ") magical resistance.";
	}
	if ((m_HealAmount == 0) && (m_DamageAmount == 0) && (m_MagicResist == 0) && (m_MagicAttack != 0))
	{
		cout << m_Name << " potion (";
		cout << m_MagicAttack << ") magic damage.";
	}
	if ((m_HealAmount == 0) && (m_DamageAmount == 0) && (m_MagicResist == 0) && (m_MagicAttack == 0))
	{
		cout << m_Name << " potion";
	}
	cout << endl;
}
int Potion::UsePotion()
{
	int numOutPut = (m_HealAmount + m_DamageAmount + m_MagicResist + m_MagicAttack);
	SetPotion(12);
	return numOutPut;
}
int Potion::GetSellValue()
{
	int sellValue;
	sellValue = (m_HealAmount + m_DamageAmount + m_MagicResist + m_MagicAttack) / 1.5;
	if (sellValue < 0)
	{
		sellValue = 0;
	}
	return sellValue;
}
int Potion::GetBuyValue()
{
	int buyValue;
	buyValue = (m_HealAmount + m_DamageAmount + m_MagicResist + m_MagicAttack) * 3;
	return buyValue;
}