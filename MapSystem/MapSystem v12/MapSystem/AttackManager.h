#pragma once
#include <iostream>
#include "Attack.h"
#include "Weapon.h"

using namespace std;

class AttackManager
{
public:
    AttackManager()
    {
        GenerateAttacks();
    }
    vector<Attack> GenerateMovesFromWeapon(Weapon self)
    {
        vector<Attack> RetVal = vector<Attack>(4);

        if (self.m_Weapon_Type.m_Name == "lance" || self.m_Weapon_Type.m_Name == "rapier")
        {
            RetVal[0] = PhysMoves[0];
        }
        else if (self.m_Weapon_Type.m_Name == "sword" || self.m_Weapon_Type.m_Name == "glaive" || self.m_Weapon_Type.m_Name == "axe")
        {
            RetVal[0] = PhysMoves[1];
        }
        else if (self.m_Weapon_Type.m_Name == "warhammer" || self.m_Weapon_Type.m_Name == "club" || self.m_Weapon_Type.m_Name == "fists" || self.m_Weapon_Type.m_Name == "mace" || self.m_Weapon_Type.m_Name == "staff")
        {
            RetVal[0] = PhysMoves[2];
        }
        else if (self.m_Weapon_Type.m_Name == "daggers")
        {
            RetVal[0] = PhysMoves[3];
        }
        else if (self.m_Weapon_Type.m_Name == "bow")
        {
            RetVal[0] = PhysMoves[4];
        }
        else if (self.m_Weapon_Type.m_Name == "shuriken")
        {
            RetVal[0] = PhysMoves[5];
        }
        if (self.m_Weapon_Type.m_Name == "wand")
        {
            if (self.m_Prefix_Name == "Bad" || self.m_Prefix_Name == "Basic" || self.m_Prefix_Name == "Legendarily bad")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][0];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][1];
                }
            }
            if (self.m_Prefix_Name == "Good")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][1];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][2];
                }
            }
            if (self.m_Prefix_Name == "Great")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][3];
                }
            }
            if (self.m_Prefix_Name == "Legendary" || self.m_Prefix_Name == "Super Fantastic")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][4];
                }
            }
        }
        else if (self.m_Weapon_Type.m_Name == "scroll")
        {
            if (self.m_Prefix_Name == "Bad" || self.m_Prefix_Name == "Basic" || self.m_Prefix_Name == "Legendarily bad" || self.m_Prefix_Name == "Good")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][0];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][1];
                }
            }
            if (self.m_Prefix_Name == "Great")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][1];
                if (self.SpellSlot > 1)
                {
                    if (self.m_DamageType.m_Enhancement == 0)
                    {
                        RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                    }
                    else
                    {
                        RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][6];
                    }

                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][2];
                }
            }
            if (self.m_Prefix_Name == "Legendary" || self.m_Prefix_Name == "Super Fantastic")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
                if (self.SpellSlot > 1)
                {
                    if (self.m_DamageType.m_Enhancement == 0)
                    {
                        RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][5];
                    }
                    else
                    {
                        RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][6];
                    }

                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][3];
                }
            }
        }
        else if (self.m_Weapon_Type.m_Name == "tome")
        {
            if (self.m_Prefix_Name == "Bad" || self.m_Prefix_Name == "Basic" || self.m_Prefix_Name == "Legendarily bad")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][0];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][1];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][2];
                }
            }
            if (self.m_Prefix_Name == "Good" || self.m_Prefix_Name == "Great")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][1];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][3];
                }
            }
            if (self.m_Prefix_Name == "Legendary" || self.m_Prefix_Name == "Super Fantastic")
            {
                RetVal[0] = SpellBook[self.m_DamageType.m_Enhancement][2];
                if (self.SpellSlot > 1)
                {
                    RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][3];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][4];
                }
            }
        }
        if (self.m_Weapon_Type.m_Name == "staff" && self.m_DamageType.m_Enhancement != 9)
        {
            if (self.m_Prefix_Name != "Legendary" && self.m_Prefix_Name != "Super Fantastic")
            {
                RetVal[1] = PhysMoves[6];
                if (self.SpellSlot > 1)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[3] = SpellBook[self.m_DamageType.m_Enhancement][6];
                }
            }
            else
            {
                RetVal[1] = SpellBook[self.m_DamageType.m_Enhancement][6];
                if (self.SpellSlot > 1)
                {
                    RetVal[2] = SpellBook[self.m_DamageType.m_Enhancement][5];
                }
                if (self.SpellSlot > 2)
                {
                    RetVal[3] = SpellBook[self.m_DamageType.m_Enhancement][7];
                }
            }
        }
        else if (self.m_Weapon_Type.m_Name == "staff")
        {
            RetVal[1] = PhysMoves[6];
            if (self.SpellSlot > 1)
            {
                RetVal[2] = PhysMoves[7];
            }
            if (self.SpellSlot > 2)
            {
                RetVal[3] = PhysMoves[8];
            }
        }
        return RetVal;
    }
    void GenerateAttacks()
    {

        PhysMoves.push_back(Attack("Skewer", 100, 0));
		PhysMoves[0].desc = "A basic attack that deals piercing damage.";
        PhysMoves.push_back(Attack("Strike", 100, 0));
		PhysMoves[1].desc = "A basic attack that deals slashing damage.";
        PhysMoves.push_back(Attack("Bash", 100, 0));
		PhysMoves[2].desc = "A basic attack that deals bludgeoning damage.";
        PhysMoves.push_back(Attack("Multiattack", 50, 1));
		PhysMoves[3].desc = "An attack that deals piercing damage twice.";
        PhysMoves.push_back(Attack("Shoot", 100, 2));
		PhysMoves[4].desc = "A basic attack that deals piercing damage.";
        PhysMoves.push_back(Attack("Multistrike", 50, 3));
		PhysMoves[5].desc = "An attack that deals slashing damage twice.";
        PhysMoves.push_back(Attack("Heal", 100, 7));
        PhysMoves.push_back(Attack("Cure Ailment", 100, 7));
        PhysMoves.push_back(Attack("Heal More", 100, 7));
		PhysMoves[6].desc = "A spell that heals a single target.";
		PhysMoves[7].desc = "A spell that slightly heals a single target and reverts any\nlowered stats.";
		PhysMoves[8].desc = "A spell that heals the whole party.";
		SpellBook.push_back({ Attack("Break", 100, 2),
                             Attack("Spacial Rift", 100, 4),
                             Attack("Rupture", 150, 2),
                             Attack("Collapse", 100, 6),
                             Attack("Panta Rei", 200, 2),
                             Attack("Debilitate", 0, 2) });
		SpellBook[0][0].desc = "A spell that shatters the space that an enemy's body occupies.";
		SpellBook[0][1].desc = "A spell that tears through the space that an enemy occupies, rending their body apart.";
		SpellBook[0][2].desc = "A spell that causes space to rapidly expand, damaging anything that it touches.";
		SpellBook[0][3].desc = "A spell that causes space to impode upon itself, sucking in nearby enemies.";
		SpellBook[0][4].desc = "A spell that pulls on the enemy's soul, pulling them towards the afterlife.";
		SpellBook[0][5].desc = "A spell that disrupts the molecular bonds of an enemy's being, weakening them thoroughly.";

        SpellBook[0][5].effect = 8;
        SpellBook.push_back({ Attack("Fireball", 100, 2),
                             Attack("Firewall", 75, 4),
                             Attack("Hellfire", 150, 2),
                             Attack("Lava Plume", 80, 6),
                             Attack("Ashenheit", 150, 6),
                             Attack("Aggro", 0, 7),
                             Attack("Hearthfire", 100, 8),
                             Attack("Blazing Soul", 100, 7) });
		SpellBook[1][0].desc = "A spell that casts a projectile ball of fire at an enemy.";
		SpellBook[1][1].desc = "A spell that summons a wall of fire that engulfs the front row of enemies.";
		SpellBook[1][2].desc = "A spell that creates a vicious pillar of fire around a single enemy.";
		SpellBook[1][3].desc = "A spell that causes an eruption of flames that engulfs all enemies.";
		SpellBook[1][4].desc = "A spell that heats the battlefield until the air catches fire, burning enemies from the inside out.";
		SpellBook[1][5].desc = "A spell that causes an ally to go into a fever pitch, increasing their offensive power.";
		SpellBook[1][6].desc = "A spell that creates a warm aura through your whole party, healing the entire team.";
		SpellBook[1][7].desc = "A spell that imbues an ally with a fiery warmth, healing them and raising their attack.";

        SpellBook[1][5].effect = 1;
        SpellBook[1][7].effect = 1;
        SpellBook.push_back({ Attack("Ice Shard", 100, 2),
                             Attack("Blizzard", 75, 4),
                             Attack("Cryosphere", 150, 2),
                             Attack("Glaciate", 100, 4),
                             Attack("Aurora", 150, 6),
                             Attack("Winterveil", 0, 7),
                             Attack("Cool Breeze", 100, 8),
                             Attack("Ice Palace", 100, 7) });
		SpellBook[2][0].desc = "A spell that launches a spear of ice at the enemy. The freezing\ncold lowers their attack.";
		SpellBook[2][1].desc = "A spell that calls on a blizzard that hits the enemy front row.\nThe freezing cold lowers their attack.";
		SpellBook[2][2].desc = "A spell that freezes a ball of air around a single enemy. The\nfreezing cold lowers their attack.";
		SpellBook[2][3].desc = "A spell that causes a wall of freezing mist blasts the front row\nof enemies. The freezing cold lowers their attack.";
		SpellBook[2][4].desc = "A spell that drops the temperature of the battlefield far below the point of\nfreezing, causing a display of polar lights above the enemies. The freezing cold causes\ntheir attack to drop.";
		SpellBook[2][5].desc = "A spell that wraps an ally in icy energy, weakening incoming attacks.";
		SpellBook[2][6].desc = "A spell that calls on a cool breeze to heal all of your allies.";
		SpellBook[2][7].desc = "A spell that creates a shield of solid ice around an ally to raise their defense.\nThe spell also restores some of their HP.";

		SpellBook[2][0].effect = 6;
		SpellBook[2][1].effect = 6;
		SpellBook[2][2].effect = 6;
		SpellBook[2][3].effect = 6;
		SpellBook[2][4].effect = 6;
        SpellBook[2][5].effect = 3;
        SpellBook[2][7].effect = 3;
        SpellBook.push_back({ Attack("Bubble", 100, 2),
                             Attack("Riptide", 75, 4),
                             Attack("Geyser", 150, 2),
                             Attack("Water Cannon", 100, 5),
                             Attack("Bloodburst", 250, 2),
                             Attack("Oegis", 0, 7),
                             Attack("Fountain", 100, 8),
                             Attack("Wishing Well", 100, 8) });

		SpellBook[3][0].desc = "A spell that hurls a ball of water at an enemy.";
		SpellBook[3][1].desc = "A spell that summons a vicious wave to pummel the front row of enemies.";
		SpellBook[3][2].desc = "A spell that creates a pillar of water under a single enemy.";
		SpellBook[3][3].desc = "A spell that drenches the computer's CPU in water, causing the game to\ncrash.";
		SpellBook[3][4].desc = "A spell that compresses steam isnide of the enemy's body, causing it to\n burst from within.";
		SpellBook[3][5].desc = "A spell that wraps an ally in a shield of rushing water, increasing their\ndefenses.";
		SpellBook[3][6].desc = "A spell that creates a spray of pure water that heals the entire party.";
		SpellBook[3][7].desc = "A spell that creates a pool of water surrounding your party, weakening\nincoming attacks.";

        SpellBook[3][5].effect = 3;
        SpellBook[3][7].effect = 3;
        SpellBook.push_back({ Attack("Shock", 100, 2),
                             Attack("Plasma Burst", 75, 4),
                             Attack("Thunderbolt", 150, 2),
                             Attack("Discharge", 100, 6),
                             Attack("Thunderhead", 150, 6),
                             Attack("Excite", 0, 7),
                             Attack("Charge", 0, 7),
                             Attack("Supersedence", 0, 7) });

		SpellBook[4][0].desc = "A spell that shoots an electric beam at an enemy.";
		SpellBook[4][1].desc = "A spell that shoots a ball of energy at the foes, bursting across the\nentire front row.";
		SpellBook[4][2].desc = "A spell that summons a bolt from the sky to smite the enemy.";
		SpellBook[4][3].desc = "A spell that blasts the enemy with a flurry of electrical energy,\nengulfing all enemies.";
		SpellBook[4][4].desc = "A spell that summons a dark cloud above the enemy party that rains\nlightning down upon all of the enemies.";
		SpellBook[4][5].desc = "A spell that embues an ally with electrical energy, increasing\ntheir mobility.";
		SpellBook[4][6].desc = "A spell that charges an ally with electrical energy, increasing\ntheir attack power.";
		SpellBook[4][7].desc = "A spell that awakens dormant magical powers inside of an ally,\nincreasing all of their stats.";

        SpellBook[4][5].effect = 5;
        SpellBook[4][6].effect = 1;
        SpellBook[4][7].effect = 7;
        SpellBook.push_back({ Attack("Gust", 100, 2),
                             Attack("Vorpal Wind", 75, 4),
                             Attack("Tornado", 50, 6),
                             Attack("Hurricane", 100, 5),
                             Attack("Miasmaime", 150, 3),
                             Attack("Stormguard", 0, 7),
                             Attack("Storm Song", 0, 8),
                             Attack("Lunar Rondo", 100, 8) });

		SpellBook[5][0].desc = "A spell that blasts a gust of wind at an enemy. The draft\nreduces the enemy's mobility.";
		SpellBook[5][1].desc = "A spell that summons a tearing wind to rend through the front\nrow of enemies. The draft reduces the enemy's mobility.";
		SpellBook[5][2].desc = "A spell that summons a whirlwind that tears through the enemy ranks.\nThe draft reduces the enemy's mobility.";
		SpellBook[5][3].desc = "A spell that creates a massive cyclone of wind that ravages the entire\nenemy party. The draft reduces the enemy's mobility.";
		SpellBook[5][4].desc = "A spell that launches a vicious ball of rending wind that hits a target twice.\nThe draft reduces the enemy's mobility.";
		SpellBook[5][5].desc = "A spell that wraps an ally in a shield of wind, increasing their mobility.";
		SpellBook[5][6].desc = "A song that summons violent winds that make it harder for enemy attacks to\nconnect with your party.";
		SpellBook[5][7].desc = "A song that summons soothing winds that heal your whole party, and increase\ntheir attack.";

		SpellBook[5][0].effect = 6;
		SpellBook[5][1].effect = 6;
		SpellBook[5][2].effect = 6;
		SpellBook[5][3].effect = 6;
		SpellBook[5][4].effect = 6;
        SpellBook[5][5].effect = 5;
        SpellBook[5][6].effect = 5;
        SpellBook[5][7].effect = 1;
        SpellBook.push_back({ Attack("Venom Sting", 100, 2),
                             Attack("Vine Grip", 150, 2),
                             Attack("Virus Wave", 80, 4),
                             Attack("Earthquake", 100, 6),
                             Attack("Blightstorm", 150, 6),
                             Attack("Poison Cloud", 30, 6),
                             Attack("Healing Sap", 100, 7),
                             Attack("Resonance", 50, 8) });

		SpellBook[6][0].desc = "A spell that creates a poison spear to impale an enemy with venomous energy. The poison\nreduces the enemy's defense.";
		SpellBook[6][1].desc = "A spell that summons vines to constrict a target, squeezing the life out of them.";
		SpellBook[6][2].desc = "A spell that creates a wave of toxic energy that engulfs the enemy's front row.\nThe poison reduces the enemy's defense.";
		SpellBook[6][3].desc = "A spell that summons violent tremors to damage the entire enemy party.";
		SpellBook[6][4].desc = "A spell that summons a whirlwind of poisonous wind to ravage the entire enemy\nparty. The poison reduces the enemy's defense.";
		SpellBook[6][5].desc = "A spell that summons a poisonous mist around the enemies. The poison reduces\nthe enemy's defense.";
		SpellBook[6][6].desc = "A spell that creates a healing aura around a single party member,\nincreasing their defense.";
		SpellBook[6][7].desc = "A spell that summons a natural energy from the earth that heals your party\nand increases their defense.";

		SpellBook[6][0].effect = 4;
		SpellBook[6][2].effect = 4;
		SpellBook[6][4].effect = 4;
		SpellBook[6][5].effect = 4;
		SpellBook[6][6].effect = 3;
        SpellBook[6][7].effect = 3;
        SpellBook.push_back({ Attack("Ruin", 100, 2),
                             Attack("Decay Wave", 80, 4),
                             Attack("Life Drain", 150, 2),
                             Attack("Netherrend", 150, 4),
                             Attack("Hel Vertigo", 150, 6),
                             Attack("Nosferatu", 100, 2),
                             Attack("Nethergate", 0, 7),
                             Attack("Sacred Poetry", 100, 6) });

		SpellBook[7][0].desc = "A spell that summons dark spires underneath an enemy to impale them.";
		SpellBook[7][1].desc = "A spell that creates a wave of deathly energy that engulfs the enemy's front row.\nThe poison reduces the enemy's defense.";
		SpellBook[7][2].desc = "A spell that creates a dark spear of vampiric energy that drains an enemy's\nhealth and heals the user.";
		SpellBook[7][3].desc = "A spell that creates a portal to the Underworld that tears through the enemy's front row.";
		SpellBook[7][4].desc = "A spell that summons a portal to the Underworld that drags the enemy party\nthrough the hellscape before dropping them back into the mortal world.";
		SpellBook[7][5].desc = "A spell that wraps the target in vampiric energy that drains the enemy's health\nand heals the user.";
		SpellBook[7][6].desc = "A spell that summons a portal to the Underworld that spews negative energy around\na single party member, reducing the damage they take from incoming attacks.";
		SpellBook[7][7].desc = "A reading of Vogon poetry that heals your whole party. Sheer exposure to\nthe poetry rends the minds of any enemy that hears it.";

		SpellBook[7][1].effect = 4;
		SpellBook[7][2].effect = 9;
		SpellBook[7][5].effect = 9;
        SpellBook[7][6].effect = 3;
        SpellBook[7][7].effect = 10;
        SpellBook.push_back({ Attack("Purge", 100, 2),
                             Attack("Radiance", 80, 4),
                             Attack("Smite", 150, 2),
                             Attack("God's Hand", 200, 2),
                             Attack("Edenbeam", 200, 6),
                             Attack("Purify", 100, 7),
                             Attack("Restore", 100, 7),
                             Attack("Heavensend", 200, 8) });

		SpellBook[8][0].desc = "A spell that blasts the enemy with holy energy.";
		SpellBook[8][1].desc = "A spell that sheds holy light over the enemy front row.";
		SpellBook[8][2].desc = "A spell that summons a bolt of holy energy from the sky onto an enemy.";
		SpellBook[8][3].desc = "A spell that summons a shining fist from the sky that crashes down on an enemy.";
		SpellBook[8][4].desc = "A spell that summons a pillar of holy energy that drowns the entire enemy party in light.";
		SpellBook[8][5].desc = "A spell that purges irregularities from an ally's body, restoring their\nhealth and increasing their defense.";
		SpellBook[8][6].desc = "A spell that revitalizes a party member, restoring their health and\nraising all of their stats.";
		SpellBook[8][7].desc = "A spell that shines holy light on the party, greatly restoring their\nhealth and raising all of their stats.";

        SpellBook[8][5].effect = 3;
        SpellBook[8][6].effect = 7;
        SpellBook[8][7].effect = 7;
		SpellBook.push_back({ Attack("Heal", 100, 7),
							  Attack("Cure Ailment", 100, 7),
							  Attack("Heal More", 100, 8) });
		SpellBook[9][0].desc = "A spell that heals a single target.";
		SpellBook[9][1].desc = "A spell that slightly heals a single target and reverts any\nlowered stats.";
		SpellBook[9][2].desc = "A spell that heals the whole party.";
    }
	vector<Attack> PhysMoves;
	vector<vector<Attack>> SpellBook;
};
