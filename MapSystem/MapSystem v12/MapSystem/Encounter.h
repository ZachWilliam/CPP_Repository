#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Party.h"
#include <Windows.h>
#include "Format.h"
#include "Attack.h"
#include "AttackManager.h"
#include "Transitions.h"
#include "Backpack.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

struct MyStruct
{
	int key;
	Combatant combatantValue;

	MyStruct(int k, const Combatant& s) : key(k), combatantValue(s) {}

	bool operator < (const MyStruct& str) const
	{
		return (key > str.key);
	}
};

struct less_than_key
{
	inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
	{
		return (struct1.key < struct2.key);
	}
};

class Encounter
{
public:
	//Encounter(int, int, int, int, int, int);
	//void GenerateEncounter(Party);
	//void CalculateInitiative();
	//void TakeTurn();
	//void GenerateAttack(Combatant&, Attack, int);
	//void DoAttack(Combatant, Enemy&);
	//void DoAttack(Enemy);
	//void DoHeal(Combatant, Combatant&);
	vector<Monster> AllEnemies = {};
	Party PlayerParty;
	PartyInventory Inventory;
	vector<Enemy> FrontRow = { Enemy(-1), Enemy(-1), Enemy(-1) };
	vector<Enemy> BackRow = { Enemy(-1), Enemy(-1), Enemy(-1) };
	vector<MyStruct> Order;
	AttackManager Man = AttackManager();
	Attack AttackUsed = Attack();
	int UseAttack = 0;
	int InitiativeOrder = 0;
	int EnemyCounter = 1;
	int MinLevel;
	int Level;
	int Damage = 0;
	string Effect = "";
	int Selection = 0;
	int NextMove = 0;
	bool Battling = true;
	bool TopMenu = true;
	bool AtkMenu = false;
	bool ItmMenu = false;
	bool ChooseTarget = false;
	bool Flee = false;
	bool Report = false;
	int Victory = 0;
	int TotalXP = 0;
	enum BattleStats { ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT };

	Encounter()
	{

	}
	Encounter(int lvl, Monster FL_E, Monster FC_E, Monster FR_E, Monster BL_E, Monster BC_E, Monster BR_E)
    {
		Level = lvl;
		AllEnemies.push_back(FL_E);
		AllEnemies.push_back(FC_E);
		AllEnemies.push_back(FR_E);
		AllEnemies.push_back(BL_E);
		AllEnemies.push_back(BC_E);
		AllEnemies.push_back(BR_E);

    }
    void GenerateEncounter(Party& Players, PartyInventory &Inv)
    {
        PlayerParty = Players;
		Inventory = Inv;
        CalculateInitiative();
		FrontRow = { Enemy(AllEnemies[0],Level), Enemy(AllEnemies[1],Level), Enemy(AllEnemies[2],Level) };
		BackRow = { Enemy(AllEnemies[3],Level), Enemy(AllEnemies[4],Level), Enemy(AllEnemies[5],Level) };
		for (size_t i = 0; i < 3; i++)
		{
			if (!FrontRow[i].NullEnemy)
			{
				if (FrontRow[i].GetXP() > 0)
				{
					TotalXP += FrontRow[i].GetXP();
				}
				
			}
			if (!BackRow[i].NullEnemy)
			{
				if (BackRow[i].GetXP() > 0)
				{
					TotalXP += BackRow[i].GetXP();
				}
			}
		}
		//TotalXP = TotalXP * 4;
    }
    void CalculateInitiative()
    {
        int onMember = 0;
        for (size_t i = 0; i < PlayerParty.Container.size(); i++)
        {

            if (PlayerParty.Container[i].name != "NULL_NAME")
            {
                PlayerParty.Container[i].BattleStats = PlayerParty.Container[i].CurrentStats.BattleStats(PlayerParty.Container[i].PlayerInventory.m_Weapon.m_Weapon_Type.m_StatUsed);
                Order.push_back(MyStruct(PlayerParty.Container[i].BattleStats[SPEED], PlayerParty.Container[i]));
                Order[onMember].combatantValue.CurrentHP = PlayerParty.Container[i].CurrentHP;
                onMember++;
            }
        }
        for (size_t i = 0; i < 3; i++)
        {

            if (!FrontRow[i].NullEnemy && FrontRow[i].CurrentHP > 0)
            {
                Order.push_back(MyStruct(FrontRow[i].BattleStats[SPEED], FrontRow[i]));
            }
            if (!BackRow[i].NullEnemy && BackRow[i].CurrentHP > 0)
            {
                Order.push_back(MyStruct(BackRow[i].BattleStats[SPEED], BackRow[i]));
            }
        }
        sort(Order.begin(), Order.end());
    }
    void GenerateAttack(Combatant &User, Attack Used, int Choice)
    {
        if (Used.target <= 6)
        {
            if (Choice >= 3)
            {
                if (Used.target == 0)
                {
                    DoAttack(User, BackRow[Choice - 3]);
                }
                else if (Used.target == 1)
                {
                    DoAttack(User, BackRow[Choice - 3]);
                    DoAttack(User, BackRow[Choice - 3]);
                }
                else if (Used.target == 2)
                {
                    DoAttack(User, BackRow[Choice - 3]);
                }
                else if (Used.target == 3)
                {
                    DoAttack(User, BackRow[Choice - 3]);
                    DoAttack(User, BackRow[Choice - 3]);
                }
                cout << BackRow[Choice - 3].name << ": " << BackRow[Choice - 3].CurrentHP << "/" << BackRow[Choice - 3].MAX_HP;
            }
            else
            {
                if (Used.target == 0)
                {
                    DoAttack(User, FrontRow[Choice]);
                }
                else if (Used.target == 1)
                {
                    DoAttack(User, FrontRow[Choice]);
                    DoAttack(User, FrontRow[Choice]);
                }
                else if (Used.target == 2)
                {
                    DoAttack(User, FrontRow[Choice]);
                }
                else if (Used.target == 3)
                {
                    DoAttack(User, FrontRow[Choice]);
                    DoAttack(User, FrontRow[Choice]);
                }
                else if (Used.target == 4)
                {
                    DoAttack(User, FrontRow[0]);
                    DoAttack(User, FrontRow[1]);
                    DoAttack(User, FrontRow[2]);
                }
                else if (Used.target == 5)
                {
                    DoAttack(User, FrontRow[Choice]);
                    DoAttack(User, BackRow[Choice]);
                }
                else if (Used.target == 6)
                {
                    DoAttack(User, FrontRow[0]);
                    DoAttack(User, FrontRow[1]);
                    DoAttack(User, FrontRow[2]);
                    DoAttack(User, BackRow[0]);
                    DoAttack(User, BackRow[1]);
                    DoAttack(User, BackRow[2]);
					if (Used.effect == 10)
					{
						for (size_t i = 0; i < PlayerParty.Container.size(); i++)
						{
							if (PlayerParty.Container[i].name != "NULL_NAME")
							{
								DoHeal(User, PlayerParty.Container[i]);
							}
						}
					}
                }
                cout << FrontRow[Choice].name << ": " << FrontRow[Choice].CurrentHP << "/" << FrontRow[Choice].MAX_HP;
            }
            _getch();
        }
        else
        {
            if (Used.target == 7)
            {
                DoHeal(User, PlayerParty.Container[Selection]);
            }
            if (Used.target == 8)
            {
                for (size_t i = 0; i < PlayerParty.Container.size(); i++)
                {
                    if (PlayerParty.Container[i].name != "NULL_NAME")
                    {
                        DoHeal(User, PlayerParty.Container[i]);
                    }
                }
            }
			_getch();
        }
    }
    void DoAttack(Combatant& User, Enemy& Target)
    {
        int HitChance = ((Target.BattleStats[7] - User.BattleStats[6]) * 2);
		HitChance += HitChance / 2 * Target.MOBILITY;
		HitChance -= HitChance / 2 * User.MOBILITY;

        if (rand() % 100 > HitChance || AttackUsed.power == 0)
        {
            Damage = User.PlayerInventory.m_Weapon.Attack();
			if (AttackUsed.name == "Bash")
			{
				Damage += User.CurrentStats.STRENGTH;
			}
			else
			{
				Damage += User.CurrentStats.ValueFromStatIn(User.PlayerInventory.m_Weapon.m_Weapon_Type.m_StatUsed);
			}
			Damage += (Damage / 2) * User.OFFENSE;
            Damage = float(Damage) * (float(AttackUsed.power) / float(100));
			int Reduction;
            if (User.PlayerInventory.m_Weapon.m_Weapon_Type.magic && AttackUsed.name != "Bash")
            {
				Reduction = Target.BattleStats[RESISTANCE];
				Reduction += Reduction / 2 * Target.Combatant::DEFENSE;
                Damage -= Reduction;
            }
            else
            {
				Reduction = Target.BattleStats[DEFENSE];
				Reduction += Reduction / 2 * Target.Combatant::DEFENSE;
				Damage -= Reduction;
            }
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement > 0 && User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement < 9)
            {
                if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 0)
                {
                    Damage *= Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2];
                    if (Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2] > 1)
                    {
                        Effect = "It's super effective!";
                    }
                    else if (Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2] < 1)
                    {
                        Effect = "It's not very effective!";
                    }
                }
                else
                {
                    Damage *= (Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2] / float(2));
                    if (Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2] > 1)
                    {
                        Effect = "It's super effective!";
                    }
                    else if (Target.Resistances[User.PlayerInventory.m_Weapon.m_DamageType.m_Enhancement + 2] < 1)
                    {
                        Effect = "It's not very effective!";
                    }
                }

            }
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 1 && Target.Level > 4)
            {
				if (Target.Resistances[0] > 1)
				{
					if (Effect != "It's not very effective!") Effect = "It's super effective!";
					else Effect = "";
				}
				if (Target.Resistances[0] < 1)
				{
					if (Effect != "It's super effective!") Effect = "It's not very effective!";
					else Effect = "";
				}
                Damage *= Target.Resistances[0];
            }
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 2 && Target.Level > 4)
            {
				if (Target.Resistances[1] > 1)
				{
					if (Effect != "It's not very effective!") Effect = "It's super effective!";
					else Effect = "";
				}
				if (Target.Resistances[1] < 1)
				{
					if (Effect != "It's super effective!") Effect = "It's not very effective!";
					else Effect = "";
				}
                Damage *= Target.Resistances[1];
            }
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 3 && Target.Level > 4 || AttackUsed.name == "Bash")
            {
				if (Target.Resistances[2] > 1)
				{
					if (Effect != "It's not very effective!") Effect = "It's super effective!";
					else Effect = "";
				}
				if (Target.Resistances[2] < 1)
				{
					if (Effect != "It's super effective!") Effect = "It's not very effective!";
					else Effect = "";
				}
                Damage *= Target.Resistances[2];
            }
            Damage = _Max_value(Damage, 1);
			
			if (AttackUsed.power != 0)
			{
				int temp = rand() % 100;
				if (temp < User.CurrentStats.LUCK)
				{
					Damage = Damage * 2;
					SetColorAndBackground(0, 14);
					cout << "Critical hit!" << endl;
					SetColorAndBackground(0, 15);
				}
				Target.CurrentHP -= Damage;
				Target.CurrentHP = _Max_value(0, Target.CurrentHP);
				if (!Target.NullEnemy)
				{
					cout << Target.name << " took " << Damage << " damage! ";
					cout << Effect << endl;
					if (AttackUsed.effect == 9)
					{
						DoHeal(User, Damage);
					}
				}
			}
			if (AttackUsed.effect == 2 && Target.Combatant::OFFENSE > Target.DOWN || AttackUsed.effect == 8 && Target.Combatant::OFFENSE > Target.DOWN)
			{
				Target.Combatant::OFFENSE = Target.DOWN;
				cout << Target.name << "'s attack power has been lowered!" << endl;
			}
			if (AttackUsed.effect == 4 && Target.Combatant::DEFENSE > Target.DOWN || AttackUsed.effect == 8 && Target.Combatant::DEFENSE > Target.DOWN)
			{
				Target.Combatant::DEFENSE = Target.DOWN;
				cout << Target.name << "'s defenses have been lowered!" << endl;
			}
			if (AttackUsed.effect == 6 && Target.Combatant::MOBILITY > Target.DOWN || AttackUsed.effect == 8 && Target.Combatant::MOBILITY > Target.DOWN)
			{
				Target.Combatant::MOBILITY = Target.DOWN;
				cout << Target.name << "'s attack power has been lowered!" << endl;
			}
            
        }
        else
        {
            cout << Target.name << " avoided the attack!" << endl;
        }

       // _getch();
        Effect = "";

    }

    void DoHeal(Combatant User, Combatant & Target)
    {

        Damage = User.PlayerInventory.m_Weapon.Attack();
        Damage += User.CurrentStats.ValueFromStatIn(User.PlayerInventory.m_Weapon.m_Weapon_Type.m_StatUsed);
		Damage = float(float(Damage) * float(AttackUsed.power) / float(100));

		if (Damage > 0)
		{
			Target.CurrentHP += Damage;
			Target.CurrentHP = _Min_value(Target.MaxHP, Target.CurrentHP);
			cout << Target.name << " healed " << Damage << " health! " << endl;
		}
		
        if (AttackUsed.effect == 1 && Target.OFFENSE < Target.UP || AttackUsed.effect == 7 && Target.OFFENSE < Target.UP)
        {
            Target.OFFENSE = Target.UP;
            cout << Target.name << "'s attack power has been raised!" << endl;
        }
        if (AttackUsed.effect == 3 && Target.DEFENSE < Target.UP || AttackUsed.effect == 7 && Target.DEFENSE < Target.UP)
        {
            Target.DEFENSE = Target.UP;
            cout << Target.name << "'s defenses have been raised!" << endl;
        }
        if (AttackUsed.effect == 5 && Target.MOBILITY < Target.UP || AttackUsed.effect == 7 && Target.MOBILITY < Target.UP)
        {
            Target.MOBILITY = Target.UP;
            cout << Target.name << "'s mobility has been raised!" << endl;
        }
        //_getch();
    }
	void DoHeal(Combatant & Target, int amount)
	{

		Target.CurrentHP += amount;
		Target.CurrentHP = _Min_value(Target.MaxHP, Target.CurrentHP);
		cout << Target.name << " healed " << amount << " health! " << endl;

	}

    void DoAttack(Enemy User)
    {

        Damage = 1;
        Damage += User.BattleStats[0];
        if (User.AI == 0 || User.AI == 1 || User.AI == 2 || User.AI == 3)
        {
            while (true)
            {
                int dir = rand() % 6;
                if (PlayerParty.Container[dir].name != "NULL_NAME" && PlayerParty.Container[dir].CurrentHP > 0)
                {
                    int HitChance = ((((PlayerParty.Container[dir].BattleStats[7] * 5 + PlayerParty.Container[dir].PlayerInventory.m_Armor.m_Avoidance)) - User.BattleStats[6] * 2)) + 10;
                    if (rand() % 100 > HitChance)
                    {
                        Damage -= PlayerParty.Container[dir].BattleStats[1];
                        Damage -= PlayerParty.Container[dir].PlayerInventory.m_Armor.m_DamageResist;
                        Damage = _Max_value(Damage, 0);
						int temp = rand() % 100;
						if (temp < User.CurrentStats.LUCK)
						{
							Damage = Damage * 2;
							SetColorAndBackground(0, 14);
							cout << "Critical hit!" << endl;
							SetColorAndBackground(0, 15);
						}
                        cout << PlayerParty.Container[dir].name << " takes " << Damage << " damage!" << endl;
                        PlayerParty.Container[dir].CurrentHP -= Damage;
                        if (PlayerParty.Container[dir].CurrentHP <= 0)
                        {
                            PlayerParty.Container[dir].CurrentHP = 0;
                            cout << PlayerParty.Container[dir].name << " has been knocked unconcious!";
                        }
                    }
                    else
                    {
                        cout << PlayerParty.Container[dir].name << " avoided the attack!";
                    }

                    break;
                }
            }
        }
    }
	void CharacterPromotion(Player &self)
	{
		ClassManager Man = ClassManager();
		vector<PlayerClass> Selection;
		bool Promotion = true;
		int choice = 0;
		int counter = 0;
		int NextMove;
		string space = ".";
		for (int i = 0; i < int(Man.AllClasses.size()); i++)
		{
			if (Man.AllClasses[i].Prerequisite == self.Job.Current)
			{
				Selection.push_back(Man.AllClasses[i]);
			}
		}
		//DrawGUI();
		gotoxy(72, 1);
		cout << "                            ";
		gotoxy(72, 2);
		cout << "                            ";
		gotoxy(72, 3);
		cout << "                            ";
		gotoxy(0, 30);
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		cout << "                                                                                        " << endl;
		gotoxy(0, 30);
		while (Promotion)
		{
			if (Selection.size() == 2)
			{
				gotoxy(72, 1);
				cout << self.name << " has been promoted";
				counter = 0;
				for (size_t i = 0; i < 27; i++)
				{
					if (Selection[1].name == Man.AllClasses[i].name)
					{
						gotoxy(72, 2 + counter);
						if (choice == 1)
						{
							SetColorAndBackground(15, 0);
							cout << " > " << Selection[1].name;
							for (size_t i = 0; i < 25; i++)
							{
								if (i > Selection[1].name.size())
								{
									cout << space;
								}
							}
							SetColorAndBackground(0, 15);
						}
						else
						{
							cout << " " << Selection[1].name;
							for (size_t i = 0; i < 27; i++)
							{
								if (i > Selection[1].name.size())
								{
									cout << space;
								}
							}
							cout << endl;
						}
						counter++;
					}
					else if (Selection[0].name == Man.AllClasses[i].name)
					{
						gotoxy(72, 2 + counter);
						if (choice == 0)
						{
							SetColorAndBackground(15, 0);
							cout << " > " << Selection[0].name;
							for (size_t i = 0; i < 25; i++)
							{
								if (i > Selection[0].name.size())
								{
									cout << space;
								}
							}
							SetColorAndBackground(0, 15);
						}
						else
						{
							cout << " " << Selection[0].name;
							for (size_t i = 0; i < 27; i++)
							{
								if (i > Selection[0].name.size())
								{
									cout << space;
								}
							}
							cout << endl;
						}
						counter++;
					}
				}

				gotoxy(0, 30);
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				cout << "                                                                                        " << endl;
				gotoxy(0, 30);

				cout << Selection[choice].name;
				for (size_t i = 0; i < 82; i++)
				{
					if (i > Selection[choice].name.size())
					{
						cout << ".";
					}
				}
				cout << endl;
				cout << Selection[choice].Desc1;
				for (size_t i = 0; i < 82; i++)
				{
					if (i > Selection[choice].Desc1.size())
					{
						cout << " ";
					}
				}
				cout << endl;
				cout << Selection[choice].Desc2;
				for (size_t i = 0; i < 82; i++)
				{
					if (i > Selection[choice].Desc2.size())
					{
						cout << " ";
					}
				}
				cout << endl;
				cout << Selection[choice].Desc3;
				for (size_t i = 0; i < 82; i++)
				{
					if (i > Selection[choice].Desc3.size())
					{
						cout << " ";
					}
				}
				cout << endl;
				cout << endl;
				cout << ".............................." << "Press [Z] to Continue" << ".............................." << endl;

				NextMove = _getch();

				if (NextMove == KEY_UP)
				{
					choice--;
					if (choice < 0)
					{
						choice = 1;
					}

					continue;
				}
				else if (NextMove == KEY_DOWN)
				{
					choice++;

					if (choice > 1)
					{
						choice = 0;
					}

					continue;

				}
				else if (NextMove == 122)
				{
					self.Job = Selection[choice];
					self.CurrentStats.STRENGTH += Selection[choice].STR_BASE;
					self.CurrentStats.DEXTERITY += Selection[choice].DEX_BASE;
					self.CurrentStats.CONSTITUTION += Selection[choice].CON_BASE;
					self.CurrentStats.AGILITY += Selection[choice].AGI_BASE;
					self.CurrentStats.INTELLIGENCE += Selection[choice].INT_BASE;
					self.CurrentStats.WISDOM += Selection[choice].WIS_BASE;
					self.CurrentStats.LUCK += Selection[choice].LUK_BASE;
					gotoxy(0, 30);
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					cout << "                                                                                        " << endl;
					gotoxy(0, 30);
					cout << self.name << " the " << self.Job.name << ":" << endl;
					cout << "Strength ----------------------------------------------------------------- " << self.CurrentStats.STRENGTH;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].STR_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << "Dexterity ---------------------------------------------------------------- " << self.CurrentStats.DEXTERITY;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].DEX_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << "Constitution ------------------------------------------------------------- " << self.CurrentStats.CONSTITUTION;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].CON_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << "Agility ------------------------------------------------------------------ " << self.CurrentStats.AGILITY;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].AGI_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << "Intelligence ------------------------------------------------------------- " << self.CurrentStats.INTELLIGENCE;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].INT_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << "Wisdom ------------------------------------------------------------------- " << self.CurrentStats.WISDOM;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].WIS_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << "Luck --------------------------------------------------------------------- " << self.CurrentStats.LUCK;
					SetColorAndBackground(0, 3);
					cout << " (+" << Selection[choice].LUK_BASE << ")" << endl;
					SetColorAndBackground(0, 15);
					cout << endl;
					cout << ".............................." << "Press [Z] to Continue" << ".............................." << endl;
					gotoxy(72, 1);
					cout << "                            ";
					gotoxy(72, 2);
					cout << "                            ";
					gotoxy(72, 3);
					cout << "                            ";
					break;
				}
				else
				{
					NextMove = 0;
					continue;
				}
			}
		}
	}
	void PauseMenu() {

		SetColorAndBackground();
		GoToXY(GManager.BOT_START_ROW, 0);

		char again = 'y';
		while ((again != 'n') && (again != 'p'))
		{
			ClearBottom();
			int choice = 0;
			string wordChoice;

			cout << "Make a selection:\n\n";
			cout << "1.     Display Inventory\n";
			cout << "2.     Display Party Stats\n";
			cout << "3.     Swap Weapon\n";
			cout << "4.     Swap Armor\n";
			cout << "5.     Display Beastiary\n";
			cout << "6.     Exit\n";
			cout << "Choice: ";
			cin >> wordChoice;
			choice = wordChoice[0] - 48;

			while ((choice <= 0) || (choice > 6))
			{
				cout << "Invalid selection. Reselect:\n";
				cin >> wordChoice;
				choice = wordChoice[0] - 48;
			};
			switch (choice)
			{
			case 1:
				ClearBottom();
				Inventory.DisplayPartyInventory();
				break;
			case 2:
				ClearBottom();
				PlayerParty.DisplayParty();
				/*cout << "1. " << TheGroup.Container[1].name << endl;
				TheGroup.Container[1].PlayerInventory.EquipedWeapon();
				TheGroup.Container[1].PlayerInventory.EquipedArmor();
				cout << endl;
				cout << "2. " << TheGroup.Container[3].name << endl;
				TheGroup.Container[3].PlayerInventory.EquipedWeapon();
				TheGroup.Container[3].PlayerInventory.EquipedArmor();
				cout << endl;
				cout << "3. " << TheGroup.Container[5].name << endl;
				TheGroup.Container[5].PlayerInventory.EquipedWeapon();
				TheGroup.Container[5].PlayerInventory.EquipedArmor();
				cout << endl;*/
				break;
			case 3:
				ClearBottom();

				cout << "1. " << PlayerParty.Container[1].name << endl;
				PlayerParty.Container[1].PlayerInventory.EquipedWeapon();
				cout << endl;
				cout << "2. " << PlayerParty.Container[3].name << endl;
				PlayerParty.Container[3].PlayerInventory.EquipedWeapon();
				cout << endl;
				cout << "3. " << PlayerParty.Container[5].name << endl;
				PlayerParty.Container[5].PlayerInventory.EquipedWeapon();
				cout << endl;

				Inventory.SwapEquipedWeapon(PlayerParty.Container[1].PlayerInventory, PlayerParty.Container[3].PlayerInventory, PlayerParty.Container[5].PlayerInventory);
				break;
			case 4:
				ClearBottom();

				cout << "1. " << PlayerParty.Container[1].name << endl;
				PlayerParty.Container[1].PlayerInventory.EquipedArmor();
				cout << endl;
				cout << "2. " << PlayerParty.Container[3].name << endl;
				PlayerParty.Container[3].PlayerInventory.EquipedArmor();
				cout << endl;
				cout << "3. " << PlayerParty.Container[5].name << endl;
				PlayerParty.Container[5].PlayerInventory.EquipedArmor();
				cout << endl;

				Inventory.SwapEquipedArmor(PlayerParty.Container[1].PlayerInventory, PlayerParty.Container[3].PlayerInventory, PlayerParty.Container[5].PlayerInventory);
				break;
			default:
				break;
			}
			cout << "More? (y/n): ";
			cin >> again;
		};

		ClearBottom();

	}
    Party TakeTurn()
    {
        Order.clear();
		CalculateInitiative();
        if (InitiativeOrder >= Order.size())
        {
            InitiativeOrder = 0;
        }
        for (int i = Order.size() - 1; i >= 0; i--)
        {
            if (Order[i].combatantValue.PlayerControl == false)
            {

                if (Order[i].combatantValue.CurrentHP <= 0)
                {
                    //_getch();
                    Order.erase(Order.begin() + i);
                    if (i <= InitiativeOrder)
                    {
                        InitiativeOrder = 0;
                    }
                }
            }
        }
        Battling = false;
        Victory = 1;
        for (int i = Order.size() - 1; i >= 0; i--)
        {
            if (!Order[i].combatantValue.PlayerControl)
            {
                Battling = true;
            }
        }
		if (!Battling && Victory == 1)
		{
			PlaySound("Sound/fanfare_theme.wav", NULL, SND_FILENAME | SND_ASYNC);
			gotoxy(0, 30);
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			cout << "                                                                                        " << endl;
			gotoxy(0, 30);
			int temp = 0;
			for (size_t i = 0; i < 3; i++)
			{
				
			}
			PlayerParty.Leader.CurrentEXP += TotalXP;
			while (true)
			{
				if (PlayerParty.Leader.OnTheLevel[PlayerParty.Leader.Level] <= PlayerParty.Leader.CurrentEXP)
				{
					PlayerParty.Leader.Level++;
					
				}
				else 
				{
					break;
				}
			}
			
			for (size_t i = 0; i < PlayerParty.Container.size(); i++)
			{
				if (PlayerParty.Container[i].name != "NULL_NAME" && PlayerParty.Container[i].CurrentHP != 0)
				{
					cout << PlayerParty.Container[i].name << " gained " << TotalXP << " experience points!" << endl;
					PlayerParty.Container[i].CurrentEXP += TotalXP;
					while (true)
					{
						if (PlayerParty.Container[i].OnTheLevel[PlayerParty.Container[i].Level] <= PlayerParty.Container[i].CurrentEXP)
						{
							cout << "Level Up! " << PlayerParty.Container[i].name << " has reached level " << PlayerParty.Container[i].Level + 1 << "!" << endl;
							PlayerParty.Container[i].LevelUp();
							if (PlayerParty.Container[i].Level == 10)
							{
								_getch();
								CharacterPromotion(PlayerParty.Container[i]);
							}
							

						}
						else
						{
							break;
						}
						_getch(); 
						gotoxy(0, 30);
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						cout << "                                                                                        " << endl;
						gotoxy(0, 30);
					}
					
				}
			}
			//_getch();
		}
        if (Battling)
        {
            Battling = false;
            Victory = 0;
            for (int i = Order.size() - 1; i >= 0; i--)
            {
                if (Order[i].combatantValue.PlayerControl)
                {
                    if (Order[i].combatantValue.CurrentHP > 0)
                    {
                        Battling = true;
                    }
                }
            }
        }
        if (!Battling)
        {
            if (Victory == 1)
            {
                for (size_t i = 0; i < PlayerParty.Container.size(); i++)
                {
                    if (PlayerParty.Container[i].CurrentHP == 0)
                    {
                        PlayerParty.Container[i].CurrentHP = 1;
                    }
                }
            }
            return PlayerParty;
        }
        //if (Order[InitiativeOrder].combatantValue.name == "")
        //{
        //	return;
        //}
        for (size_t i = 0; i < FrontRow.size(); i++)
        {
            if (!FrontRow[i].NullEnemy && FrontRow[i].CurrentHP > 0)
            {
                gotoxy(3 + (23 * i), 11);
                cout << FrontRow[i].name;
                for (size_t e = 0; e < 19; e++)
                {
                    if (e > FrontRow[i].name.size())
                    {
                        cout << ".";
                    }
                }
                gotoxy(3 + (23 * i), 12);
                float chunk = float(FrontRow[i].MAX_HP) / float(17);
                for (size_t e = 0; e < 18; e++)
                {
                    if (float(FrontRow[i].CurrentHP) >= chunk * float(e))
                    {
                        SetColorAndBackground(10, 0);
                    }
                    else
                    {
                        SetColorAndBackground(12, 0);
                    }
                    cout << " ";
                    SetColorAndBackground(0, 15);
                }
            }
            else if (!FrontRow[i].NullEnemy)
            {
                FrontRow[i].NullEnemy = true;
                FrontRow[i].name = "";
            }
        }
        for (int i = 0; i < PlayerParty.Container.size(); i++)
        {
            if (PlayerParty.Container[i].name != "NULL_NAME")
            {
                gotoxy(9 + (18 * (i % 3)), 21 + 3 * (i / 3));
                cout << PlayerParty.Container[i].name;
                cout << " " << PlayerParty.Container[i].CurrentHP << "/" << PlayerParty.Container[i].Max_HP;
                gotoxy(9 + (18 * (i % 3)), 22 + 3 * (i / 3));
                float chunk = float(PlayerParty.Container[i].Max_HP) / float(17);

                for (size_t e = 0; e < 17; e++)
                {
                    if (float(PlayerParty.Container[i].CurrentHP) > chunk * float(e))
                    {
                        SetColorAndBackground(10, 0);
                    }
                    else
                    {
                        SetColorAndBackground(12, 0);
                    }
                    cout << " ";
                    SetColorAndBackground(0, 15);
                }
            }
        }
        for (size_t i = 0; i < BackRow.size(); i++)
        {
            if (!BackRow[i].NullEnemy && BackRow[i].CurrentHP > 0)
            {
                gotoxy(3 + (23 * i), 5);
                cout << BackRow[i].name;
                for (size_t e = 0; e < 19; e++)
                {
                    if (e > BackRow[i].name.size())
                    {
                        cout << ".";
                    }
                }
                gotoxy(3 + (23 * i), 6);
				float chunk = float(BackRow[i].MAX_HP) / float(17);
                for (size_t e = 0; e < 18; e++)
                {
					if (float(BackRow[i].CurrentHP) >= chunk * float(e))
                    {
                        SetColorAndBackground(10, 0);
                    }
                    else
                    {
                        SetColorAndBackground(12, 0);
                    }
                    cout << " ";
                    SetColorAndBackground(0, 15);
                }
            }
            else if (!BackRow[i].NullEnemy)
            {
                BackRow[i].NullEnemy = true;
                BackRow[i].name = "";
            }
        }
        for (size_t i = 0; i < Order.size(); i++)
        {
            gotoxy(73, 2 + i);
            if (i == InitiativeOrder) {
                SetColorAndBackground(15, 0);
            }
            cout << Order[i].combatantValue.name;
            for (size_t e = 0; e < 27; e++)
            {
                if (e > Order[i].combatantValue.name.size())
                {
                    cout << ".";
                }
            }
            SetColorAndBackground(0, 15);
        }
        if (Order[InitiativeOrder].combatantValue.PlayerControl && Order[InitiativeOrder].combatantValue.CurrentHP != 0)
        {
            Selection = 0;
            NextMove = 0;
            TopMenu = true;
            AtkMenu = false;
            ItmMenu = false;
            Flee = false;
            while (true)
            {
                gotoxy(0, 30);
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                cout << "                                                                                        " << endl;
                gotoxy(0, 30);
                if (TopMenu)
                {
                    cout << Order[InitiativeOrder].combatantValue.name << "'s turn! Select your action:                                     " << endl;
                    for (size_t i = 0; i < 3; i++)
                    {
                        cout << "|";
                        if (Selection == i)
                        {
                            SetColorAndBackground(15, 0);
                        }
                        else
                        {
                            SetColorAndBackground(0, 15);
                        }
                        if (i == 0)
                        {
                            cout << "           Fight          ";
                        }
                        if (i == 1)
                        {
                            cout << "         Inventory        ";
                        }
                        if (i == 2)
                        {
                            cout << "           Flee           ";
                        }
                        SetColorAndBackground(0, 15);
                    }
                    cout << "|" << endl;
                }
                else if (AtkMenu)
                {
                    cout << Order[InitiativeOrder].combatantValue.name << " attacks with " << Order[InitiativeOrder].combatantValue.PlayerInventory.m_Weapon.DisplayNameText() << endl;
                    for (size_t i = 0; i < Order[InitiativeOrder].combatantValue.CurrentMoves.size(); i++)
                    {

                        if (Order[InitiativeOrder].combatantValue.CurrentMoves[i].name != "NULL_ATTACK")
                        {
                            cout << "|";
                            if (Selection == i)
                            {
                                SetColorAndBackground(15, 0);
                            }
                            else
                            {
                                SetColorAndBackground(0, 15);
                            }
                            cout << Order[InitiativeOrder].combatantValue.CurrentMoves[i].name;
                            for (size_t e = 0; e < 22; e++)
                            {
                                if (e > Order[InitiativeOrder].combatantValue.CurrentMoves[i].name.size())
                                {
                                    cout << " ";
                                }
                            }
                        }
                        SetColorAndBackground(0, 15);
                    }
                    cout << "|" << endl;
                }
                else if (ItmMenu)
                {
					PauseMenu();
					ItmMenu = false;
					TopMenu = true;
					continue;
                }
                else if (Flee)
                {
					PlaySound("Sound/runaway_sfx.wav", NULL, SND_FILENAME | SND_ASYNC);
                    cout << "You have fled the battle!                                                ";
                    //Order.erase(Order.begin() + InitiativeOrder);
                    //PlayerParty.Container.erase(std::remove(PlayerParty.Container.begin(), PlayerParty.Container.end(), Order[InitiativeOrder]));
                    InitiativeOrder--;
					Sleep(200);
                    Battling = false;
                    break;
                }
                else if (ChooseTarget)
                {
                    cout << "Select your target:                                                                    " << endl;
                    if (AttackUsed.target <= 6)
                    {
                        for (size_t i = 0; i < 3; i++)
                        {

                            if (BackRow[i].name != "NULL_NAME")
                            {
                                cout << "|";
                                if (Selection == i + 3)
                                {
                                    SetColorAndBackground(15, 0);
                                }
                                else
                                {
                                    SetColorAndBackground(0, 15);
                                }
                                cout << BackRow[i].name;
                                for (size_t e = 0; e < 27; e++)
                                {
                                    if (e > BackRow[i].name.size())
                                    {
                                        cout << " ";
                                    }
                                }
                            }
                            else
                            {
                                cout << "|                          ";
                            }

                            SetColorAndBackground(0, 15);
                        }
                        cout << "|" << endl;
                        for (size_t i = 0; i < 3; i++)
                        {

                            if (FrontRow[i].name != "NULL_NAME")
                            {
                                cout << "|";
                                if (Selection == i)
                                {
                                    SetColorAndBackground(15, 0);
                                }
                                else
                                {
                                    SetColorAndBackground(0, 15);
                                }
                                cout << FrontRow[i].name;
                                for (size_t e = 0; e < 27; e++)
                                {
                                    if (e > FrontRow[i].name.size())
                                    {
                                        cout << " ";
                                    }
                                }
                            }
                            else
                            {
                                cout << "|                          ";
                            }

                            SetColorAndBackground(0, 15);
                        }
                    }
                    else
                    {
                        for (size_t i = 0; i < 6; i++)
                        {

                            if (PlayerParty.Container[i].name != "NULL_NAME")
                            {
                                cout << "|";
                                if (Selection == i)
                                {
                                    SetColorAndBackground(15, 0);
                                }
                                else
                                {
                                    SetColorAndBackground(0, 15);
                                }
                                cout << PlayerParty.Container[i].name;
                                for (size_t e = 0; e < 27; e++)
                                {
                                    if (e > PlayerParty.Container[i].name.size())
                                    {
                                        cout << " ";
                                    }
                                }
                            }
                            else
                            {
                                cout << "|";
                                if (Selection == i)
                                {
                                    SetColorAndBackground(15, 0);
                                }
                                else
                                {
                                    SetColorAndBackground(0, 15);
                                }
                                cout << "                          ";
                            }
                            if (i == 2)
                            {
                                cout << endl;
                            }
                            SetColorAndBackground(0, 15);
                        }
                    }

                    cout << "|" << endl;
                }
                NextMove = _getch();
                int temp = 0;
                for (size_t i = 0; i < Order[InitiativeOrder].combatantValue.CurrentMoves.size(); i++)
                {
                    if (Order[InitiativeOrder].combatantValue.CurrentMoves[i].name != "NULL_ATTACK")
                    {
                        temp++;
                    }
                }

                if (NextMove == KEY_LEFT)
                {
                    if (TopMenu)
                    {
                        Selection--;
                        if (Selection < 0)
                        {
                            Selection = 2;
                        }

                        continue;
                    }
                    else if (AtkMenu)
                    {
                        Selection--;
                        if (Selection < 0)
                        {
                            Selection = temp - 1;
                        }

                        continue;
                    }
                    else if (ChooseTarget)
                    {
                        Selection--;

                        if (Selection == -1)
                        {
                            Selection = 2;
                        }
                        else if (Selection == 2)
                        {
                            Selection = 5;
                        }

                        continue;
                    }

                }
                else if (NextMove == KEY_RIGHT)
                {
                    if (TopMenu)
                    {
                        Selection++;

                        if (Selection == 3)
                        {
                            Selection = 0;
                        }
                        else if (Selection == 6)
                        {
                            Selection = 3;
                        }

                        continue;
                    }
                    else if (AtkMenu)
                    {
                        Selection++;

                        if (Selection > temp - 1)
                        {
                            Selection = 0;
                        }

                        continue;
                    }
                    else if (ChooseTarget)
                    {
                        Selection++;

                        if (Selection == 3)
                        {
                            Selection = 0;
                        }
                        if (Selection == 6)
                        {
                            Selection = 3;
                        }

                        continue;
                    }

                }
                else if (NextMove == KEY_UP || NextMove == KEY_DOWN)
                {
                    if (ChooseTarget)
                    {
                        Selection += 3;
                        if (Selection > 5)
                        {
                            Selection = Selection - 6;
                        }
                    }
                }
                else if (NextMove == 122)
                {
                    if (Selection == 0 && TopMenu)
                    {
                        TopMenu = false;
                        AtkMenu = true;
                        Selection = 0;
                    }
                    else if (Selection == 1 && TopMenu)
                    {
                        TopMenu = false;
                        ItmMenu = true;
                        Selection = 0;
                    }
                    else if (Selection == 2 && TopMenu)
                    {
                        TopMenu = false;
						Victory = 2;
                        Flee = true;
                        Selection = 0;
                    }
                    else if (AtkMenu)
                    {
                        
                        AttackUsed = Order[InitiativeOrder].combatantValue.CurrentMoves[Selection];
						Selection = 0;
						if (AttackUsed.target == 4 || AttackUsed.target == 6 || AttackUsed.target == 6)
						{
							GenerateAttack(Order[InitiativeOrder].combatantValue, AttackUsed, Selection);
							AtkMenu = false;
							break;
						}
						else
						{
							AtkMenu = false;
							ChooseTarget = true;
						}
						
                    }
                    else if (ChooseTarget)
                    {
                        if (AttackUsed.target < 7)
                        {
                            if (Selection <= 2)
                            {
                                if (FrontRow[Selection].NullEnemy != true)
                                {
                                    GenerateAttack(Order[InitiativeOrder].combatantValue, AttackUsed, Selection);
                                    ChooseTarget = false;
                                    Selection = 0;
                                    Damage = 0;
                                    break;
                                }
                            }
                            else if (Selection <= 5)
                            {
                                if (BackRow[Selection - 3].NullEnemy != true)
                                {
                                    GenerateAttack(Order[InitiativeOrder].combatantValue, AttackUsed, Selection);
                                    ChooseTarget = false;
                                    Selection = 0;
                                    Damage = 0;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            if (PlayerParty.Container[Selection].name != "NULL_NAME")
                            {
                                GenerateAttack(Order[InitiativeOrder].combatantValue, AttackUsed, Selection);
                                ChooseTarget = false;
                                Selection = 0;
                                Damage = 0;
                                break;
                            }
                        }



                    }


                }
                else if (NextMove == 120)
                {
                    if (ItmMenu || AtkMenu)
                    {
                        ItmMenu = false;
                        AtkMenu = false;
                        TopMenu = true;
                    }
                    else if (ChooseTarget)
                    {
                        ChooseTarget = false;
                        AtkMenu = true;
                    }
                }
                else
                {
                    NextMove = 0;
                    continue;
                }

            }
            InitiativeOrder++;
            if (InitiativeOrder >= Order.size())
            {
                InitiativeOrder = 0;
            }
        }
        else if (Order[InitiativeOrder].combatantValue.PlayerControl)
        {
            gotoxy(0, 33);
            cout << Order[InitiativeOrder].combatantValue.name << " is unconcious!";
            _getch();
            InitiativeOrder++;
            if (InitiativeOrder >= Order.size())
            {
                InitiativeOrder = 0;
            }
        }
        else
        {
            gotoxy(0, 33);
            cout << Order[InitiativeOrder].combatantValue.name << " attacks!                                                                     " << endl;
            bool done = false;
            for (size_t i = 0; i < FrontRow.size(); i++)
            {
                if (FrontRow[i].name == Order[InitiativeOrder].combatantValue.name && Order[InitiativeOrder].combatantValue.PlayerControl == false && !done)
                {
                    DoAttack(FrontRow[i]);
                    done = true;
                }
            }
            for (size_t i = 0; i < BackRow.size(); i++)
            {
                if (BackRow[i].name == Order[InitiativeOrder].combatantValue.name && Order[InitiativeOrder].combatantValue.PlayerControl == false && !done)
                {
                    DoAttack(BackRow[i]);
                    done = true;
                }
            }
            _getch();
            InitiativeOrder++;
            if (InitiativeOrder >= Order.size())
            {
                InitiativeOrder = 0;
            }
        }
		return PlayerParty;
    }
};