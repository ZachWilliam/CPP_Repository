#include <iostream>
#include "Player.h"
#include "PartyManager.h"
#include <time.h>
#include "ConvertHelper.h"
#pragma once

using namespace std;

class Party
{
public:
	Player Leader;
	Party(Player MC = Player("NULL_NAME"))
	{
		Leader = MC;
		Container.push_back(Player("NULL_NAME"));
		Container.push_back(Player(MC));
		Container.push_back(Player("NULL_NAME"));
		Container.push_back(Player("NULL_NAME"));
		Container.push_back(Player("NULL_NAME"));
		Container.push_back(Player("NULL_NAME"));
	}
	inline Party(string serialString);

	inline string Serialized();

    void AddToParty(Player PM, int Pos)
    {
        if (Container[Pos].name == "NULL_NAME")
        {
            Container[Pos] = PM;
        }
        else
        {
            RemoveFromParty(Pos);
            Container[Pos] = PM;
        }
    }
    void RemoveFromParty(int Pos)
    {
        Container[Pos] = Player("NULL_NAME");
    }
    void GenPartyFromClass(Player PC)
    {

        if (PC.Job.name == "Knight")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(1), 5);
        }
        else if (PC.Job.name == "Wizard")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(0), 5);
        }
        else if (PC.Job.name == "Archer")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(1), 5);
        }
        else if (PC.Job.name == "Lancer")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(7), 5);
        }
        else if (PC.Job.name == "Fighter")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(7), 5);
        }
        else if (PC.Job.name == "Brawler")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(1), 5);
        }
        else if (PC.Job.name == "Rogue")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(7), 5);
        }
        else if (PC.Job.name == "Mage")
        {
            AddToParty(Par.GetPartyMember(8), 3);
            AddToParty(Par.GetPartyMember(6), 5);
        }
        else if (PC.Job.name == "Clergy")
        {
            
            int choice2 = rand() % 3 + 1;
            AddToParty(Par.GetPartyMember(7), 3);

            AddToParty(Par.GetPartyMember(choice2), 5);
        }

    }
    void DisplayParty()
    {
		int counter = 1;
        for (size_t i = 0; i < Container.size(); i++)
        {
			
            if (Container[i].name != "NULL_NAME")
            {
                cout << endl;
                cout <<  counter << ": " << Container[i].name << ", the " << Container[i].Job.name << endl;
				cout << "Level: " << Container[i].Level << " | EXP: " << Container[i].CurrentEXP << "/" << Container[i].OnTheLevel[Container[i].Level] << endl;
                cout << "STR: " << Container[i].CurrentStats.STRENGTH << " | ";
                cout << "DEX: " << Container[i].CurrentStats.DEXTERITY << " | ";
                cout << "CON: " << Container[i].CurrentStats.CONSTITUTION << " | ";
                cout << "AGI: " << Container[i].CurrentStats.AGILITY << " | ";
                cout << "INT: " << Container[i].CurrentStats.INTELLIGENCE << " | ";
                cout << "WIS: " << Container[i].CurrentStats.WISDOM << " | ";
                cout << "LUK: " << Container[i].CurrentStats.LUCK << " | " << endl;
                cout << "Wielding ";
                Container[i].PlayerInventory.m_Weapon.DisplayName();
				cout << endl;
				cout << "Spell Slots: " << Container[i].PlayerInventory.m_Weapon.SpellSlot << endl;
				cout << "Wearing ";
				Container[i].PlayerInventory.m_Armor.DisplayName();
                cout << endl;
				counter++;
            }
        }
    }
    Backpack GetPartyBackpacks(int which)
    {
        vector<Backpack> RetVals;
        for (size_t i = 0; i < Container.size(); i++)
        {
            if (Container[i].name != "NULL_NAME")
            {
                RetVals.push_back(Container[i].PlayerInventory);
            }
        }
        return RetVals[which];
    }
	vector<Player> Container;
	PartyManager Par = PartyManager();
	bool isBank;
	

};

Party::Party(string serialString)
{
	// TODO - DESERIALIZE CONSTRUCTOR
}

string Party::Serialized()
{
	string serialString = "";

	serialString += "Leader{" + Leader.Serialized() + "},";
	{
		serialString += "Container[";
		if (Container.size() > 0)
		{
			for (size_t i = 0; i < Container.size(); ++i)
			{
				serialString += "{";
				serialString += Container[i].Serialized();
				serialString += "},";
			}
		}
		serialString += "],";
	}
	//serialString += "Par{" +  + "},";
	serialString += "isBank:" + btos(isBank) + ",";

	return serialString;
}