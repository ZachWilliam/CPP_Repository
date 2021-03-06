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
	bool Victory = false;
	int TotalXP;
	enum BattleStats { ATTACK = 0, DEFENSE, MAGIC, RESISTANCE, SPEED, HIT, AVOID, CRIT };


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
    void GenerateEncounter(Party Players)
    {
        PlayerParty = Players;
        CalculateInitiative();
		FrontRow = { Enemy(AllEnemies[0],Level), Enemy(AllEnemies[1],Level), Enemy(AllEnemies[2],Level) };
		BackRow = { Enemy(AllEnemies[3],Level), Enemy(AllEnemies[4],Level), Enemy(AllEnemies[5],Level) };
		for (size_t i = 0; i < 3; i++)
		{
			if (!FrontRow[i].NullEnemy)
			{
				TotalXP += FrontRow[i].GetXP();
			}
			if (!BackRow[i].NullEnemy)
			{
				TotalXP += BackRow[i].GetXP();
			}
		}
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
        }
    }
    void DoAttack(Combatant User, Enemy& Target)
    {
        int HitChance = ((User.BattleStats[6] - Target.BattleStats[7]) * 5) + 10;

        if (rand() % 100 > HitChance)
        {
            Damage = User.PlayerInventory.m_Weapon.Attack();
            Damage += User.CurrentStats.ValueFromStatIn(User.PlayerInventory.m_Weapon.m_Weapon_Type.m_StatUsed);
            Damage = float(Damage) * (float(AttackUsed.power) / float(100));
            if (User.PlayerInventory.m_Weapon.m_Weapon_Type.magic && User.PlayerInventory.m_Weapon.m_Weapon_Type.m_Name != "staff")
            {
                Damage -= Target.BattleStats[RESISTANCE];
            }
            else
            {
                Damage -= Target.BattleStats[DEFENSE];
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
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 1)
            {
                Damage *= Target.Resistances[0];
            }
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 2)
            {
                Damage *= Target.Resistances[1];
            }
            if (User.PlayerInventory.m_Weapon.m_DamageType.m_Technique == 3 || User.PlayerInventory.m_Weapon.m_Weapon_Type.staff)
            {
                Damage *= Target.Resistances[2];
            }
            Damage = _Max_value(Damage, 1);
			
            Target.CurrentHP -= Damage;
            Target.CurrentHP = _Max_value(0, Target.CurrentHP);
            cout << Target.name << " took " << Damage << " damage! ";
            cout << Effect << endl;
        }
        else
        {
            cout << Target.name << " avoided the attack!" << endl;
        }

        _getch();
        Effect = "";

    }

    void DoHeal(Combatant User, Combatant & Target)
    {

        Damage = User.PlayerInventory.m_Weapon.Attack();
        Damage += User.CurrentStats.ValueFromStatIn(User.PlayerInventory.m_Weapon.m_Weapon_Type.m_StatUsed);
        Target.CurrentHP += Damage;
        Target.CurrentHP = _Min_value(Target.MaxHP, Target.CurrentHP);
        cout << Target.name << " healed " << Damage << " health! " << endl;
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
        _getch();
    }

    void DoAttack(Enemy User)
    {

        Damage = 1;
        Damage += User.BattleStats[0];
        if (User.AI == 0)
        {
            while (true)
            {
                int dir = rand() % 6;
                if (PlayerParty.Container[dir].name != "NULL_NAME" && PlayerParty.Container[dir].CurrentHP > 0)
                {
                    int HitChance = ((((PlayerParty.Container[dir].BattleStats[7] * 5 + PlayerParty.Container[dir].PlayerInventory.m_Armor.m_Avoidance)) - User.BattleStats[6] * 5)) + 10;
                    if (rand() % 100 > HitChance)
                    {
                        Damage -= PlayerParty.Container[dir].BattleStats[1];
                        Damage -= PlayerParty.Container[dir].PlayerInventory.m_Armor.m_DamageResist;
                        Damage = _Max_value(Damage, 0);
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
    void TakeTurn()
    {
        Order.clear();
        CalculateInitiative();
        if (InitiativeOrder > Order.size())
        {
            InitiativeOrder--;
        }
        for (int i = Order.size() - 1; i >= 0; i--)
        {
            if (Order[i].combatantValue.PlayerControl == false)
            {

                if (Order[i].combatantValue.CurrentHP <= 0)
                {
                    _getch();
                    Order.erase(Order.begin() + i);
                    if (i <= InitiativeOrder)
                    {
                        InitiativeOrder--;
                    }
                }
            }
        }
        Battling = false;
        Victory = true;
        for (int i = Order.size() - 1; i >= 0; i--)
        {
            if (!Order[i].combatantValue.PlayerControl)
            {
                Battling = true;
            }
        }
		if (!Battling && Victory)
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
			int temp = 0;
			for (size_t i = 0; i < 3; i++)
			{
				
			}
			for (size_t i = 0; i < PlayerParty.Container.size(); i++)
			{
				if (PlayerParty.Container[i].name != "NULL_NAME" && PlayerParty.Container[i].CurrentHP != 0)
				{
					cout << PlayerParty.Container[i].name << " gained " << TotalXP << " experience points!" << endl;
					PlayerParty.Container[i].CurrentEXP += TotalXP;
				}
			}
			_getch();
		}
        if (Battling)
        {
            Battling = false;
            Victory = false;
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
            if (Victory)
            {
                for (size_t i = 0; i < PlayerParty.Container.size(); i++)
                {
                    if (PlayerParty.Container[i].CurrentHP == 0)
                    {
                        PlayerParty.Container[i].CurrentHP = 1;
                    }
                }
            }
            return;
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
                gotoxy(3 + (23 * i), 11);
                cout << BackRow[i].name;
                for (size_t e = 0; e < 19; e++)
                {
                    if (e > BackRow[i].name.size())
                    {
                        cout << ".";
                    }
                }
                gotoxy(3 + (23 * i), 12);
                int chunk = BackRow[i].MAX_HP / 17;
                for (size_t e = 0; e < 18; e++)
                {
                    if (BackRow[i].CurrentHP >= chunk * e)
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
                            cout << "           Item           ";
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
                            for (size_t e = 0; e < 27; e++)
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
                    cout << "Used an item!                                                      ";
                }
                else if (Flee)
                {
                    cout << "You have fled the battle!                                                ";
                    //Order.erase(Order.begin() + InitiativeOrder);
                    //PlayerParty.Container.erase(std::remove(PlayerParty.Container.begin(), PlayerParty.Container.end(), Order[InitiativeOrder]));
                    InitiativeOrder--;
                    _getch();
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
                        Flee = true;
                        Selection = 0;
                    }
                    else if (AtkMenu)
                    {
                        AtkMenu = false;
                        ChooseTarget = true;
                        AttackUsed = Order[InitiativeOrder].combatantValue.CurrentMoves[Selection];
                        Selection = 0;
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
    }
};
